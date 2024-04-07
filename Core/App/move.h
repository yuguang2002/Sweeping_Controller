//
// Created by 22855 on 2024/3/26.
//

#ifndef VET6_MOVE_H
#define VET6_MOVE_H

#include "stm32f4xx_hal.h"
#include "gpio.h"
#include "tim.h"
#include "main.h"


#define OUTAIN1_ON HAL_GPIO_WritePin(OUTAIN1_GPIO_Port,OUTAIN1_Pin,GPIO_PIN_SET)
#define OUTAIN1_OFF HAL_GPIO_WritePin(OUTAIN1_GPIO_Port,OUTAIN1_Pin,GPIO_PIN_RESET)
#define OUTAIN2_ON HAL_GPIO_WritePin(OUTAIN2_GPIO_Port,OUTAIN2_Pin,GPIO_PIN_SET)
#define OUTAIN2_OFF HAL_GPIO_WritePin(OUTAIN2_GPIO_Port,OUTAIN2_Pin,GPIO_PIN_RESET)
#define OUTBIN1_ON HAL_GPIO_WritePin(OUTBIN1_GPIO_Port,OUTBIN1_Pin,GPIO_PIN_SET)
#define OUTBIN1_OFF HAL_GPIO_WritePin(OUTBIN1_GPIO_Port,OUTBIN1_Pin,GPIO_PIN_RESET)
#define OUTBIN2_ON HAL_GPIO_WritePin(OUTBIN2_GPIO_Port,OUTBIN2_Pin,GPIO_PIN_SET)
#define OUTBIN2_OFF HAL_GPIO_WritePin(OUTBIN2_GPIO_Port,OUTBIN2_Pin,GPIO_PIN_RESET)
#define STBY(x) HAL_GPIO_WritePin(STBY_GPIO_Port,STBY_Pin,(GPIO_PinState)(x))

void Move_Forward(uint8_t speed);
void Move_Back(uint8_t speed);
void Move_Left(uint8_t speed);
void Move_Right(uint8_t speed);
void Move_Stop(void);

#endif //VET6_MOVE_H
