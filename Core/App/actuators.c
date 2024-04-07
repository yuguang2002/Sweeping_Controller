//
// Created by 22855 on 2024/3/27.
//

#include "actuators.h"

/**
 * @brief 吸尘电机驱动函数
 */
void Vacuum_Motor_ON(void)
{
    while (1)
    {
        HAL_GPIO_WritePin(VM_PWM_Y_GPIO_Port, VM_PWM_Y_Pin, GPIO_PIN_SET);
        HAL_Delay(100);
    }
}

void Vacuum_Motor_OFF(void)
{
    HAL_GPIO_WritePin(CONVACM_GPIO_Port, CONVACM_Pin, GPIO_PIN_SET);
}

/**
 * @brief 横向扫地电机驱动函数
 */
void Sweep_Motor_ON(void)
{
    while (1)
    {
        HAL_GPIO_WritePin(CONMM_GPIO_Port, CONMM_Pin, GPIO_PIN_SET);
        HAL_Delay(100);
    }
}

void Sweep_Motor_OFF(void)
{
    HAL_GPIO_WritePin(CONMM_GPIO_Port, CONMM_Pin, GPIO_PIN_SET);
}

void Sweep_Motor(uint8_t speed)
{
    if (speed == 0)
    {
        HAL_GPIO_WritePin(CONMM_GPIO_Port, CONMM_Pin, GPIO_PIN_SET);
    }
    else
    {

        HAL_GPIO_WritePin(CONMM_GPIO_Port, CONMM_Pin, GPIO_PIN_RESET);
    }
}

/**
 * @brief  两侧扫地电机驱动函数
 */
void Clean_Motor_ON(void)
{
    while (1)
    {
        HAL_GPIO_WritePin(CONRSWM_GPIO_Port, CONRSWM_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(CONLSWM_GPIO_Port, CONLSWM_Pin, GPIO_PIN_RESET);
        HAL_Delay(100);
    }
}

void Clean_Motor_OFF(void)
{
    HAL_GPIO_WritePin(CONRSWM_GPIO_Port, CONRSWM_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(CONLSWM_GPIO_Port, CONLSWM_Pin, GPIO_PIN_SET);
}

void Clean_Motor(uint8_t speed)
{
    if (speed == 0)
    {
        HAL_GPIO_WritePin(CONRSWM_GPIO_Port, CONRSWM_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(CONLSWM_GPIO_Port, CONLSWM_Pin, GPIO_PIN_SET);
    }
    else
    {
        HAL_GPIO_WritePin(CONRSWM_GPIO_Port, CONRSWM_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(CONLSWM_GPIO_Port, CONLSWM_Pin, GPIO_PIN_RESET);
    }
}