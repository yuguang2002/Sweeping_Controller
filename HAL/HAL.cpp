//
// Created by MGshawn on 2024/4/7.
//
#include "HAL.h"


extern "C"
{
    void User_HalInit(void)
    {
        JY901S_Init();
    }

}


