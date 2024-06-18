/**
 * @file pid库
 */

#ifndef VET6_PID_H
#define VET6_PID_H

#include "main.h"

extern float integral;
extern float prev_error;

float pid_controller(int target, int current, float *integral, float *prev_error);

#endif //VET6_PID_H
