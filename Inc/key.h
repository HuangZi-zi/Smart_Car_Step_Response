#ifndef __KEY_H__
#define __KEY_H__

//�йذ����ĺ궨����cube���ɣ������main.h��
//#define Key_Pin 					GPIO_PIN_2
//#define Key_GPIO_Port 		GPIOC
#include "main.h"

//�ú궨������ȡ����
#define KEY HAL_GPIO_ReadPin(Key_GPIO_Port,Key_Pin)

//��������
void keyscan(void);


#endif
