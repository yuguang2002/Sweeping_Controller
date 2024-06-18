/**
 * @file 底盘移动模块
 */

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

void turn_Left(uint8_t speed,uint8_t angle)
{
    GetImuEuler(mag_euler+3);
    float angle_update = mag_euler[5];
    float ae = 0;
    while(ae > 2)
    {
        GetImuEuler(mag_euler+3);
        speed = pid_controller(angle,mag_euler[5],&integral,&prev_error);
        HAL_Delay(10);
        Move_Left(speed);
        ae = mag_euler[5] - angle_update;
    }
}

void turn_Right(uint8_t speed,uint8_t angle)
{
    GetImuEuler(mag_euler+3);
    float angle_update = mag_euler[5];
    float ae = 0;
    while(ae > 2)
    {
        GetImuEuler(mag_euler+3);
        speed = pid_controller(angle,mag_euler[5],&integral,&prev_error);
        HAL_Delay(10);
        Move_Right(speed);
        ae = mag_euler[5] - angle_update;
    }
}

void Move_Forward_d(uint8_t speed,float distance)
{
    int distance_update = distance_get(encoder_count_l,encoder_count_r);
    float de = 0;
    while(de < distance)
    {
        Move_Forward(speed);
        HAL_Delay(10);
        HAL_Delay(10);
        de = distance_get(encoder_count_l,encoder_count_r) - distance_update;
    }
}

void Move_Back_d(uint8_t speed,float distance)
{
    int distance_update = distance_get(encoder_count_l,encoder_count_r);
    float de = 0;
    while(de < distance)
    {
        Move_Back(speed);
        HAL_Delay(10);
        de = distance_get(encoder_count_l,encoder_count_r) - distance_update;
    }
}