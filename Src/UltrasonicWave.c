#include "UltrasonicWave.h"
#include "servo.h"

float UltrasonicWave_Distance; 

//超声传感器测量
int UltrasonicWave_StartMeasure(void)
{
  int u_temp;
	HAL_GPIO_WritePin(Trig_GPIO_Port,Trig_Pin,GPIO_PIN_SET); //发射高电平
  delay_us(20);		                      //延时20US
  HAL_GPIO_WritePin(Trig_GPIO_Port,Trig_Pin,GPIO_PIN_RESET);
	u_temp = UltrasonicWave_Distance;
	return u_temp;
}
//距离的计算位于EXTI1_IRQHandler函数中

//超声波传感器转头
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
