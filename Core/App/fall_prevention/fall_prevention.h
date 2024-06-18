/**
 * @file 防跌落模块
 */

#ifndef VET6_FALL_PREVENTION_H
#define VET6_FALL_PREVENTION_H

#include "main.h"

extern uint16_t ADC_buff[4];

uint16_t Get_ADC();
void Update_ADC();
void Fall_Prevention_Run(uint8_t fp_speed);

#endif //VET6_FALL_PREVENTION_H
