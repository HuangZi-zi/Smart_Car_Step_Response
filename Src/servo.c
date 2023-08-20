#include "servo.h"
#include "main.h"
#include "tim.h"

//舵机的角度由PWM信号的占空比控制
//角度		0				45		90			135			180
//PWM			0.5ms		1ms		1.5ms		2ms			2.5ms

//用于控制舵机的PWM频率50HZ， 周期20ms (Tim5 Chn1)
//对应可调的占空比为2.5%～12.5%
//对应的比较值为100~500

void Servo_PWM_Start()
{
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);
	//HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_4);
}

void SetJointAngle(int ID,float angle)
{
	angle=(uint16_t)(20.0*angle/9.0+100.0);
	switch (ID)
	{
		case Servo_Ultrasonic:
			__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_2,angle);
			break;
		case Servo_Pitch:
			__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,angle);
			break;
		case Servo_Pan:
			__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_4,angle);
			break;
		default:
			break;
	}
}

//云台舵机控制
int pan_angle = 80;
int pitch_angle = 5;

void pan_left()//左右舵机靠左
{
    pan_angle =pan_angle+10;
	  if(pan_angle >= 175)
			pan_angle = 175;	
		SetJointAngle(Servo_Pan,pan_angle);
}
void pan_right()//左右舵机靠右
{
  	pan_angle =pan_angle-10;
	  if(pan_angle <= 1)
			pan_angle = 1;	
		SetJointAngle(Servo_Pan,pan_angle);
}
void pitch_up()//上下舵机上
{
 
    pitch_angle =pitch_angle-10;
	  if(pitch_angle <= 1)
			pitch_angle = 1;	
		SetJointAngle(Servo_Pitch,pitch_angle);
}
void pitch_down()//上下舵机下
{
    pitch_angle = pitch_angle+10;
	  if(pitch_angle >= 175)
			pitch_angle = 175;	
		SetJointAngle(Servo_Pitch,pitch_angle);
}
