#ifndef __ULTRASONICWAVE_H_
#define __ULTRASONICWAVE_H_

#include "servo.h"
#include "tim.h"
#include "main.h"
//#define Trig_Pin 					GPIO_PIN_0
//#define Trig_GPIO_Port 		GPIOC
//#define Echo_Pin 					GPIO_PIN_1
//#define Echo_GPIO_Port 		GPIOC
//#define Echo_EXTI_IRQn 		EXTI1_IRQn

int UltrasonicWave_StartMeasure(void);
int front_detection(void);
int left_detection(void);
int right_detection(void);

#endif

