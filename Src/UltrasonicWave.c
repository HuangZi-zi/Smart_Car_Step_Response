#include "UltrasonicWave.h"
#include "servo.h"

float UltrasonicWave_Distance; 

//��������������
int UltrasonicWave_StartMeasure(void)
{
  int u_temp;
	HAL_GPIO_WritePin(Trig_GPIO_Port,Trig_Pin,GPIO_PIN_SET); //����ߵ�ƽ
  delay_us(20);		                      //��ʱ20US
  HAL_GPIO_WritePin(Trig_GPIO_Port,Trig_Pin,GPIO_PIN_RESET);
	u_temp = UltrasonicWave_Distance;
	return u_temp;
}
//����ļ���λ��EXTI1_IRQHandler������

//������������תͷ
int front_detection(void)
{
	SetJointAngle(Servo_Ultrasonic,90);
	HAL_Delay(100);
	return UltrasonicWave_StartMeasure();
}

int left_detection(void)
{
	SetJointAngle(Servo_Ultrasonic,175);
	HAL_Delay(300);
	return UltrasonicWave_StartMeasure();
}

int right_detection(void)
{
	SetJointAngle(Servo_Ultrasonic,5);
	HAL_Delay(300);
	return UltrasonicWave_StartMeasure();
}
