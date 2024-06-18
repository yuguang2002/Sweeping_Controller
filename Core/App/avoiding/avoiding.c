/**
 * @file 避障模块
 */

#include "avoiding.h"

/**
 * @brief 避障算法
 */
void Avoiding_Run(uint8_t avoid_speed,uint8_t avoid_angle)
{
    if(LS_OFF)
    {
        LED3_ON;
        Move_Back(avoid_speed);
        HAL_Delay(300);
        Move_Right(avoid_speed);
        HAL_Delay(500);
        LED3_OFF;
    }
    else if(RS_OFF)
    {
        LED1_ON;
        Move_Back(avoid_speed);
        HAL_Delay(300);
        Move_Left(avoid_speed);
        HAL_Delay(500);
        LED1_OFF;
    }
    else
    {
        Move_Forward(avoid_speed);
    }
}
