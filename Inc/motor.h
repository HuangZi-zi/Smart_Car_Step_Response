#ifndef __MOTOR_H_
#define __MOTOR_H_

#include "main.h"
#include "tim.h"
#include "IR_Tracing.h"
#include "servo.h"

//函数声明
void Motor_PWM_Start(void);
void SetMotorSpeed(unsigned char ucChannel,signed char cSpeed);
void forward(signed char speed, int time);
void back(signed char speed,int time);
void brake(int time);
void turn_left(signed char speed,int time);
void spin_left(signed char speed,int time);
void turn_right(signed char speed,int time);
void spin_right(signed char speed,int time);
void command_run(char ctrl_comm, int speed);

//IO接口定义
// 左电机 方向：PB7 PWM: PB8
// 右电机 方向：PA4 PWM: PB9
//#define Right_Motor_Pin 					GPIO_PIN_4
//#define Right_Motor_GPIO_Port 		GPIOA
//#define Left_Motor_Pin 						GPIO_PIN_7
//#define Left_Motor_GPIO_Port 			GPIOB
//#define Left_Motor_PWM_Pin 				GPIO_PIN_8
//#define Left_Motor_PWM_GPIO_Port 	GPIOB
//#define Right_Motor_PWM_Pin 			GPIO_PIN_9
//#define Right_Motor_PWM_GPIO_Port GPIOB

#define LEFT_MOTOR_SET							HAL_GPIO_WritePin(Left_Motor_GPIO_Port,Left_Motor_Pin,GPIO_PIN_SET)
#define LEFT_MOTOR_RESET						HAL_GPIO_WritePin(Left_Motor_GPIO_Port,Left_Motor_Pin,GPIO_PIN_RESET)

#define LEFT_MOTOR_PWM_SET					HAL_GPIO_WritePin(Left_Motor_PWM_GPIO_Port,Left_Motor_PWM_Pin,GPIO_PIN_SET)
#define LEFT_MOTOR_PWM_RESET				HAL_GPIO_WritePin(Left_Motor_PWM_GPIO_Port,Left_Motor_PWM_Pin,GPIO_PIN_RESET)

#define RIGHT_MOTOR_SET							HAL_GPIO_WritePin(Right_Motor_GPIO_Port,Right_Motor_Pin,GPIO_PIN_SET)
#define RIGHT_MOTOR_RESET						HAL_GPIO_WritePin(Right_Motor_GPIO_Port,Right_Motor_Pin,GPIO_PIN_RESET)

#define RIGHT_MOTOR_PWM_SET					HAL_GPIO_WritePin(Right_Motor_PWM_GPIO_Port,Right_Motor_PWM_Pin,GPIO_PIN_SET)
#define RIGHT_MOTOR_PWM_RESET				HAL_GPIO_WritePin(Right_Motor_PWM_GPIO_Port,Right_Motor_PWM_Pin,GPIO_PIN_RESET)
#endif
