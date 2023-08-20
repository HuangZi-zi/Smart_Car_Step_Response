#include "motor.h"

//开启PWM输出
void Motor_PWM_Start()
{
	HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_4);
}

//严谨的PWM调速应当将PWM施加到使能端
//L298N的真值表如下：
//ENA		IN1		IN2		STATUE
//0			X			X			停止
//1			0			0			制动
//1			0			1			正转
//1			1			0			反转
//1			1			1			制动
//本例中用IN1控制方向，在IN2施加PWM，控制电机在制动与正反转之间切换以达到调速

//因此正转时，占空比高，转速高；反转时，占空比低，转速高

void SetMotorSpeed(unsigned char ucChannel,signed char cSpeed)
{
		short sPWM;
	
		if (cSpeed>=100) 
			cSpeed = 100;
	  if (cSpeed<=-100) 
			cSpeed = -100;
		//cSpeed是相对速度百分值，需要换算成相对PWM阈值
		//比如pwm计数0-3599，相对速度50%，需要50%占空比，则阈值应设定为1799
		/*__HAL_TIM_SetCompare函数控制占空比。
			最后一个参数传入阈值，计数器计数值与这个阈值进行比较
			按照定时计数器的配置得到相应的PWM波*/
		
	switch(ucChannel)
	{
		case 0://右轮
			if (cSpeed>0) //正转
			{
				sPWM = 3601 - cSpeed*36;
				__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_3,sPWM);
				RIGHT_MOTOR_RESET;
			}
			else if(cSpeed<0) //反转
			{
				sPWM = 3601 - (100+cSpeed)*36;
				__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_3,sPWM);
				RIGHT_MOTOR_SET;	
			}	
			else//刹车
			{
				sPWM = 3599;
				__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_3,sPWM);
				RIGHT_MOTOR_RESET;
			}
			break;
			
		case 1://左轮
			if (cSpeed>0) //正转
			{	
				sPWM = 3601 - cSpeed*36;
				__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,sPWM);
				LEFT_MOTOR_RESET;
			}
			else if (cSpeed<0)//反转
			{
				sPWM = 3601 - (100+cSpeed)*36;
				__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,sPWM);
				LEFT_MOTOR_SET;
			}
			else//刹车
			{
				sPWM = 3599;
				__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,sPWM);
				RIGHT_MOTOR_RESET;
			}
			break;			
	}
}

//前进时输入相对速度，以前进为正方向
void forward(signed char speed, int time)//前进
{
	SetMotorSpeed(1,speed);//左轮正
	SetMotorSpeed(0,speed);//右轮正
	HAL_Delay(time);                 //时间为毫秒
}

//后退时输入相对速度，以后退为正方向
void back(signed char speed,int time) //后退
{

	  SetMotorSpeed(1,-speed);//左轮负
	  SetMotorSpeed(0,-speed);//右轮负
		HAL_Delay(time);                 //时间为毫秒  
}

void brake(int time)//刹车
{
	SetMotorSpeed(1,0);//左轮为0
	SetMotorSpeed(0,0);//右轮为0
  RIGHT_MOTOR_RESET;
  LEFT_MOTOR_RESET;
	HAL_Delay(time);             //时间为毫秒  
}

void turn_left(signed char speed,int time) //左转弯
{
	  SetMotorSpeed(1,0);//左轮不动
	  SetMotorSpeed(0,speed);  //右轮正
		HAL_Delay(time);            //时间为毫秒  
}

void spin_left(signed char speed,int time) //左旋转
{
		SetMotorSpeed(1,100-speed);//左轮负
	  SetMotorSpeed(0,speed-100);//右轮正
		HAL_Delay(time);            //时间为毫秒  
}

void turn_right(signed char speed,int time)  //右转弯
{
	  SetMotorSpeed(1,speed);     //左轮正
	  SetMotorSpeed(0,0);          //右轮不动
		HAL_Delay(time);                   //时间为毫秒  
}

void spin_right(signed char speed,int time) //右旋转函数
{
		SetMotorSpeed(1,speed-100); //左轮正
	  SetMotorSpeed(0,100-speed);//右轮负
		HAL_Delay(time);                    //时间为毫秒  
}

//#define COMM_BRAKE  		'E'//停止
//#define COMM_FORWARD    'A'//前进
//#define COMM_BACK  			'B'//后退
//#define COMM_LEFT  			'C'//左转
//#define COMM_RIGHT 			'D'//右转
//#define COMM_SPIN_LEFT	'F'//左旋转
//#define COMM_SPIN_RIGHT	'G'//右旋转

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
