/**
 * @file 避障模块
 */

#ifndef VET6_AVOIDING_H
#define VET6_AVOIDING_H

#include "main.h"

#define LS_ON HAL_GPIO_ReadPin(LS_DS_BL_GPIO_Port,LS_DS_BL_Pin)==GPIO_PIN_SET
#define LS_OFF HAL_GPIO_ReadPin(LS_DS_BL_GPIO_Port,LS_DS_BL_Pin)==GPIO_PIN_RESET
#define RS_ON HAL_GPIO_ReadPin(RS_DS_BL_GPIO_Port,RS_DS_BL_Pin)==GPIO_PIN_SET
#define RS_OFF HAL_GPIO_ReadPin(RS_DS_BL_GPIO_Port,RS_DS_BL_Pin)==GPIO_PIN_RESET

void Avoiding_Run(uint8_t avoid_speed,uint8_t avoid_angle);

#endif //VET6_AVOIDING_H
