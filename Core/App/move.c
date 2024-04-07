//
// Created by 22855 on 2024/3/26.
//

#include "move.h"

void Move_Forward(uint8_t speed)
{
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, speed);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, speed);
    OUTAIN1_OFF;
    OUTAIN2_ON;
    OUTBIN1_ON;
    OUTBIN2_OFF;
    STBY(1);
}

void Move_Back(uint8_t speed)
{
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, speed);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, speed);
    OUTAIN1_ON;
    OUTAIN2_OFF;
    OUTBIN1_OFF;
    OUTBIN2_ON;
    STBY(1);
}

void Move_Left(uint8_t speed)
{
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, speed);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, speed);
    OUTAIN1_ON;
    OUTAIN2_OFF;
    OUTBIN1_ON;
    OUTBIN2_OFF;
    STBY(1);
}

void Move_Right(uint8_t speed)
{
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, speed);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, speed);
    OUTAIN1_OFF;
    OUTAIN2_ON;
    OUTBIN1_OFF;
    OUTBIN2_ON;
    STBY(1);
}

void Move_Stop(void)
{
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
    OUTAIN1_OFF;
    OUTAIN2_OFF;
    OUTBIN1_OFF;
    OUTBIN2_OFF;
    STBY(0);
}