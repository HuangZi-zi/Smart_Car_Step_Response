/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
void Error_Handler_Distance(void);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Trig_Pin GPIO_PIN_0
#define Trig_GPIO_Port GPIOC
#define Key_Pin GPIO_PIN_2
#define Key_GPIO_Port GPIOC
#define Beeper_Pin GPIO_PIN_3
#define Beeper_GPIO_Port GPIOC
#define Tracing_R_Pin GPIO_PIN_0
#define Tracing_R_GPIO_Port GPIOA
#define Speed_Right_Pin GPIO_PIN_1
#define Speed_Right_GPIO_Port GPIOA
#define Speed_Right_EXTI_IRQn EXTI1_IRQn
#define Right_Motor_Pin GPIO_PIN_4
#define Right_Motor_GPIO_Port GPIOA
#define Servo_Pitch_PWM_Pin GPIO_PIN_6
#define Servo_Pitch_PWM_GPIO_Port GPIOA
#define Servo_Ultrasonic_PWM_Pin GPIO_PIN_7
#define Servo_Ultrasonic_PWM_GPIO_Port GPIOA
#define Tracing_L_Pin GPIO_PIN_0
#define Tracing_L_GPIO_Port GPIOB
#define Servo_Pan_PWM_Pin GPIO_PIN_1
#define Servo_Pan_PWM_GPIO_Port GPIOB
#define Speed_Left_Pin GPIO_PIN_8
#define Speed_Left_GPIO_Port GPIOA
#define Speed_Left_EXTI_IRQn EXTI9_5_IRQn
#define Left_Motor_Pin GPIO_PIN_7
#define Left_Motor_GPIO_Port GPIOB
#define Left_Motor_PWM_Pin GPIO_PIN_8
#define Left_Motor_PWM_GPIO_Port GPIOB
#define Right_Motor_PWM_Pin GPIO_PIN_9
#define Right_Motor_PWM_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
