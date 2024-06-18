/**
 * @file pid库
 */

#include "pid.h"

// PID控制器参数
#define Kp 1.0
#define Ki 0.1
#define Kd 0.01

// PID控制变量
float integral = 0;
float prev_error = 0;

// 时间间隔（单位：s）
const float dt = 0.005; // 5ms

/**
 * @brief PID控制器计算
 * @param target 目标速度
 * @param current 当前速度
 * @param integral 积分项
 * @param prev_error 上一次的误差
 * @return PID控制器输出
 */
float pid_controller(int target, int current, float *integral, float *prev_error)
{
    float error = target - current;
    *integral += error * dt;
    float derivative = (error - *prev_error) / dt;
    *prev_error = error;
    return Kp * error + Ki * *integral + Kd * derivative;
}

