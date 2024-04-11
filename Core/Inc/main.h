/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f4xx_hal.h"

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

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LS_DS_BL_Pin GPIO_PIN_14
#define LS_DS_BL_GPIO_Port GPIOC
#define VM_PWM_Y_Pin GPIO_PIN_15
#define VM_PWM_Y_GPIO_Port GPIOC
#define ADC8_Pin GPIO_PIN_1
#define ADC8_GPIO_Port GPIOC
#define ADC10_Pin GPIO_PIN_2
#define ADC10_GPIO_Port GPIOC
#define ADC11_Pin GPIO_PIN_3
#define ADC11_GPIO_Port GPIOC
#define ADC1_Pin GPIO_PIN_2
#define ADC1_GPIO_Port GPIOA
#define ADC2_Pin GPIO_PIN_3
#define ADC2_GPIO_Port GPIOA
#define ADC4_Pin GPIO_PIN_4
#define ADC4_GPIO_Port GPIOA
#define ADC3_Pin GPIO_PIN_6
#define ADC3_GPIO_Port GPIOA
#define ADC7_Pin GPIO_PIN_7
#define ADC7_GPIO_Port GPIOA
#define ADC9_Pin GPIO_PIN_4
#define ADC9_GPIO_Port GPIOC
#define ADC6_Pin GPIO_PIN_5
#define ADC6_GPIO_Port GPIOC
#define ADC12_Pin GPIO_PIN_0
#define ADC12_GPIO_Port GPIOB
#define ADC5_Pin GPIO_PIN_1
#define ADC5_GPIO_Port GPIOB
#define OUTAIN1_Pin GPIO_PIN_7
#define OUTAIN1_GPIO_Port GPIOE
#define OUTAIN2_Pin GPIO_PIN_8
#define OUTAIN2_GPIO_Port GPIOE
#define STBY_Pin GPIO_PIN_10
#define STBY_GPIO_Port GPIOE
#define OUTBIN1_Pin GPIO_PIN_12
#define OUTBIN1_GPIO_Port GPIOE
#define OUTBIN2_Pin GPIO_PIN_13
#define OUTBIN2_GPIO_Port GPIOE
#define LED2_Pin GPIO_PIN_14
#define LED2_GPIO_Port GPIOE
#define KEY1_Pin GPIO_PIN_15
#define KEY1_GPIO_Port GPIOE
#define CONMM_Pin GPIO_PIN_12
#define CONMM_GPIO_Port GPIOB
#define CONLSWM_Pin GPIO_PIN_13
#define CONLSWM_GPIO_Port GPIOB
#define CONRSWM_Pin GPIO_PIN_15
#define CONRSWM_GPIO_Port GPIOB
#define CONVACM_Pin GPIO_PIN_8
#define CONVACM_GPIO_Port GPIOD
#define KEY0_Pin GPIO_PIN_11
#define KEY0_GPIO_Port GPIOD
#define RS_DS_BL_Pin GPIO_PIN_12
#define RS_DS_BL_GPIO_Port GPIOD
#define LED3_Pin GPIO_PIN_13
#define LED3_GPIO_Port GPIOD
#define LED0_Pin GPIO_PIN_0
#define LED0_GPIO_Port GPIOD
#define LED1_Pin GPIO_PIN_1
#define LED1_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
