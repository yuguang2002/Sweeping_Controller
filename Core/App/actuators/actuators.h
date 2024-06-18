/**
 * @file 执行机构驱动
 */

#ifndef VET6_ACTUATORS_H
#define VET6_ACTUATORS_H


#include "main.h"

void Vacuum_Motor_ON(void);
void Vacuum_Motor_OFF(void);

void Sweep_Motor_ON(void);
void Sweep_Motor_OFF(void);
void Sweep_Motor(uint8_t speed);

void Clean_Motor_ON(void);
void Clean_Motor_OFF(void);
void Clean_Motor(uint8_t speed);

#endif //VET6_ACTUATORS_H
