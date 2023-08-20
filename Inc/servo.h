#ifndef __SERVO_H_
#define __SERVO_H_

//#define Servo_Pitch_PWM_Pin 						GPIO_PIN_6
//#define Servo_Pitch_PWM_GPIO_Port 			GPIOA
//#define Servo_Ultrasonic_PWM_Pin 				GPIO_PIN_7
//#define Servo_Ultrasonic_PWM_GPIO_Port 	GPIOA
//#define Servo_Pan_PWM_Pin 							GPIO_PIN_1
//#define Servo_Pan_PWM_GPIO_Port 				GPIOB


//���Ӻ�Ϊ��չ���ϵĶ��Ӻ�
#define Servo_Ultrasonic 			2								//TIM3 CH2
#define Servo_Pitch						12							//TIM3 CH1
#define Servo_Pan							5								//TIM3 CH4

void Servo_PWM_Start(void);
void SetJointAngle(int ID, float angle);
void pan_left(void);//���Ҷ������
void pan_right(void);//���Ҷ������
void pitch_up(void);//���¶����
void pitch_down(void);//���¶����

#endif
