#ifndef __IR_TRACING_H_
#define __IR_TRACING_H_

#include "main.h"
//#define Tracing_L_Pin 				GPIO_PIN_0
//#define Tracing_L_GPIO_Port 	GPIOB
//#define Tracing_R_Pin 				GPIO_PIN_0
//#define Tracing_R_GPIO_Port 	GPIOA

#define READ_TRACING_R 	HAL_GPIO_ReadPin(Tracing_R_GPIO_Port,Tracing_R_Pin)
#define READ_TRACING_L	HAL_GPIO_ReadPin(Tracing_L_GPIO_Port,Tracing_L_Pin)

#define BLACK_AREA 			1
#define WHITE_AREA 			0

//ָ���
#define COMM_BRAKE  		'E'//ֹͣ
#define COMM_FORWARD    'A'//ǰ��
#define COMM_BACK  			'B'//����
#define COMM_LEFT  			'C'//��ת
#define COMM_RIGHT 			'D'//��ת
#define COMM_SPIN_LEFT	'F'//����ת
#define COMM_SPIN_RIGHT	'G'//����ת

char TracingRun(void);

#endif

