#ifndef __KEY_H__
#define __KEY_H__

//有关按键的宏定义由cube生成，存放在main.h中
//#define Key_Pin 					GPIO_PIN_2
//#define Key_GPIO_Port 		GPIOC
#include "main.h"

//用宏定义来读取按键
#define KEY HAL_GPIO_ReadPin(Key_GPIO_Port,Key_Pin)

//函数声明
void keyscan(void);


#endif
