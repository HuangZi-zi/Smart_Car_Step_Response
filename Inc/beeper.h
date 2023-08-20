#ifndef __BEEPER_H__
#define __BEEPER_H__

//关于蜂鸣器的宏定义由Cube生成，存放在main.h
//#define Beeper_Pin 				GPIO_PIN_3
//#define Beeper_GPIO_Port 	GPIOC
#include "main.h"

#define BEEPER_SET		HAL_GPIO_WritePin(Beeper_GPIO_Port,Beeper_Pin,GPIO_PIN_SET)
#define BEEPER_RESET	HAL_GPIO_WritePin(Beeper_GPIO_Port,Beeper_Pin,GPIO_PIN_RESET)

#endif
