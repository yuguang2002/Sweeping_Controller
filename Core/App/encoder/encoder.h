/**
 * @file 编码器驱动
 */

#ifndef VET6_ENCODER_H
#define VET6_ENCODER_H

#include "main.h"

extern int16_t delta_count_l;
extern int16_t delta_count_r;
extern uint16_t encoder_count_l;
extern uint16_t encoder_count_r;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
void encoder_close(void);
int distance_get(uint16_t delta_l, uint16_t delta_r);
int speed_get_l(uint16_t delta_l);
int speed_get_r(uint16_t delta_r);
int speed_get(uint16_t delta_l, uint16_t delta_r);

#endif //VET6_ENCODER_H
