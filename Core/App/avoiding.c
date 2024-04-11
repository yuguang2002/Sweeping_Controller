//
// Created by 22855 on 24-4-10.
//

#include "avoiding.h"


void Avoiding_Start(uint8_t avoid_speed)
{
    if(LS_OFF)
    {
        Move_Back(avoid_speed);
        HAL_Delay(300);
        Move_Right(avoid_speed);
        HAL_Delay(500);
    }
    else if(RS_OFF)
    {
        Move_Back(avoid_speed);
        HAL_Delay(300);
        Move_Left(avoid_speed);
        HAL_Delay(500);
    }
    else if(LS_OFF && RS_OFF)
    {
        Move_Back(avoid_speed);
        HAL_Delay(200);
        Move_Right(avoid_speed);
        HAL_Delay(500);
    }
    else
    {
        Move_Forward(avoid_speed);
    }
}