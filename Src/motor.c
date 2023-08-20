#include "motor.h"

//����PWM���
void Motor_PWM_Start()
{
	HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_4);
}

//�Ͻ���PWM����Ӧ����PWMʩ�ӵ�ʹ�ܶ�
//L298N����ֵ�����£�
//ENA		IN1		IN2		STATUE
//0			X			X			ֹͣ
//1			0			0			�ƶ�
//1			0			1			��ת
//1			1			0			��ת
//1			1			1			�ƶ�
//��������IN1���Ʒ�����IN2ʩ��PWM�����Ƶ�����ƶ�������ת֮���л��Դﵽ����

//�����תʱ��ռ�ձȸߣ�ת�ٸߣ���תʱ��ռ�ձȵͣ�ת�ٸ�

void SetMotorSpeed(unsigned char ucChannel,signed char cSpeed)
{
		short sPWM;
	
		if (cSpeed>=100) 
			cSpeed = 100;
	  if (cSpeed<=-100) 
			cSpeed = -100;
		//cSpeed������ٶȰٷ�ֵ����Ҫ��������PWM��ֵ
		//����pwm����0-3599������ٶ�50%����Ҫ50%ռ�ձȣ�����ֵӦ�趨Ϊ1799
		/*__HAL_TIM_SetCompare��������ռ�ձȡ�
			���һ������������ֵ������������ֵ�������ֵ���бȽ�
			���ն�ʱ�����������õõ���Ӧ��PWM��*/
		
	switch(ucChannel)
	{
		case 0://����
			if (cSpeed>0) //��ת
			{
				sPWM = 3601 - cSpeed*36;
				__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_3,sPWM);
				RIGHT_MOTOR_RESET;
			}
			else if(cSpeed<0) //��ת
			{
				sPWM = 3601 - (100+cSpeed)*36;
				__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_3,sPWM);
				RIGHT_MOTOR_SET;	
			}	
			else//ɲ��
			{
				sPWM = 3599;
				__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_3,sPWM);
				RIGHT_MOTOR_RESET;
			}
			break;
			
		case 1://����
			if (cSpeed>0) //��ת
			{	
				sPWM = 3601 - cSpeed*36;
				__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,sPWM);
				LEFT_MOTOR_RESET;
			}
			else if (cSpeed<0)//��ת
			{
				sPWM = 3601 - (100+cSpeed)*36;
				__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,sPWM);
				LEFT_MOTOR_SET;
			}
			else//ɲ��
			{
				sPWM = 3599;
				__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,sPWM);
				RIGHT_MOTOR_RESET;
			}
			break;			
	}
}

//ǰ��ʱ��������ٶȣ���ǰ��Ϊ������
void forward(signed char speed, int time)//ǰ��
{
	SetMotorSpeed(1,speed);//������
	SetMotorSpeed(0,speed);//������
	HAL_Delay(time);                 //ʱ��Ϊ����
}

//����ʱ��������ٶȣ��Ժ���Ϊ������
void back(signed char speed,int time) //����
{

	  SetMotorSpeed(1,-speed);//���ָ�
	  SetMotorSpeed(0,-speed);//���ָ�
		HAL_Delay(time);                 //ʱ��Ϊ����  
}

void brake(int time)//ɲ��
{
	SetMotorSpeed(1,0);//����Ϊ0
	SetMotorSpeed(0,0);//����Ϊ0
  RIGHT_MOTOR_RESET;
  LEFT_MOTOR_RESET;
	HAL_Delay(time);             //ʱ��Ϊ����  
}

void turn_left(signed char speed,int time) //��ת��
{
	  SetMotorSpeed(1,0);//���ֲ���
	  SetMotorSpeed(0,speed);  //������
		HAL_Delay(time);            //ʱ��Ϊ����  
}

void spin_left(signed char speed,int time) //����ת
{
		SetMotorSpeed(1,100-speed);//���ָ�
	  SetMotorSpeed(0,speed-100);//������
		HAL_Delay(time);            //ʱ��Ϊ����  
}

void turn_right(signed char speed,int time)  //��ת��
{
	  SetMotorSpeed(1,speed);     //������
	  SetMotorSpeed(0,0);          //���ֲ���
		HAL_Delay(time);                   //ʱ��Ϊ����  
}

void spin_right(signed char speed,int time) //����ת����
{
		SetMotorSpeed(1,speed-100); //������
	  SetMotorSpeed(0,100-speed);//���ָ�
		HAL_Delay(time);                    //ʱ��Ϊ����  
}

//#define COMM_BRAKE  		'E'//ֹͣ
//#define COMM_FORWARD    'A'//ǰ��
//#define COMM_BACK  			'B'//����
//#define COMM_LEFT  			'C'//��ת
//#define COMM_RIGHT 			'D'//��ת
//#define COMM_SPIN_LEFT	'F'//����ת
//#define COMM_SPIN_RIGHT	'G'//����ת

void command_run(char ctrl_comm, int speed)
{
		switch(ctrl_comm)
		{
			case COMM_FORWARD:    forward(speed,500);break;
			case COMM_BACK:  			back(speed,30);break;
			case COMM_LEFT:  			turn_left(speed+20,30);break;
			case COMM_RIGHT: 			turn_right(speed+20,30);break;
			case COMM_BRAKE:  		brake(500);break;
			case COMM_SPIN_LEFT:	spin_left(speed+10,30);break;
			case COMM_SPIN_RIGHT:	spin_right(speed+10,30);break;
			case 'L':							pan_left();break;
			case 'I':							pan_right();break;
			case 'J':							pitch_up();break;
			case 'K':							pitch_down();break;
			default : 						break;
		}
}
