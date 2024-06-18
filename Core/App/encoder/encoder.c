/**
 * @file 编码器驱动
 */

#include "encoder.h"

// 定义编码器脉冲数每转一圈
#define ENCODER_COUNT_PER_REV_L 937  // 编码器5，左轮
#define ENCODER_COUNT_PER_REV_R 940  // 编码器2，右轮

// 轮子的周长（单位为毫米）
#define WHEEL_CIRCUMFERENCE_MM 194

// 读取编码器数值
uint16_t encoder_count_l;
uint16_t encoder_count_r;
static uint16_t last_count_l;
static uint16_t last_count_r;
int16_t delta_count_l;
int16_t delta_count_r;
const double time_interval = 0.005; // 编码器采样定时器周期

/**
 * @brief 对编码器数值进行清0
 */
void encoder_close(void)
{
    encoder_count_l = 0;
    encoder_count_r = 0;
}

/**
 * @brief 每隔5ms读取一次编码器5(左轮)和2(右轮)的数值，在main函数中打开了编码器；
 * @brief 5前进为-，2前进为+；编码器5转一圈940；编码器2转一圈940；
 * @brief pwm = 10时，转一圈7.5秒，此时速度为0.133 r/s，1pwm对应的速度为0.0133 r/s；
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM14) {
        // 编码器5
        encoder_count_l = __HAL_TIM_GetCounter(&htim5);//获取计数值
        delta_count_l = -(encoder_count_l - last_count_l);
        last_count_l = encoder_count_l;
        // 编码器2
        encoder_count_r = __HAL_TIM_GetCounter(&htim2);//获取计数值
        delta_count_r = encoder_count_r - last_count_r;
        last_count_r = encoder_count_r;
    }
}

/**
 * @brief 计算小车行驶的距离
 * @param encoder_l 左轮编码器的脉冲量
 * @param encoder_r 右轮编码器的脉冲量
 * @return 小车行驶的距离（单位：毫米）
 */
int distance_get(uint16_t encoder_l, uint16_t encoder_r)
{
    // 计算左轮和右轮行驶的距离（单位：毫米）
    int distance_l = ((65535-encoder_l) * WHEEL_CIRCUMFERENCE_MM) / ENCODER_COUNT_PER_REV_L;
    int distance_r = (encoder_r * WHEEL_CIRCUMFERENCE_MM) / ENCODER_COUNT_PER_REV_R;

    // 返回平均距离
    return (distance_l + distance_r) / 2;
}

/**
 * @brief 计算小车左轮的速度
 * @param delta_l 左编码器的脉冲增量
 * @return 小车左轮的速度（单位：毫米每秒）
 */
int speed_get_l(uint16_t delta_l)
{
    // 计算左轮的速度（单位：毫米每秒）
    int speed_l = (delta_l * WHEEL_CIRCUMFERENCE_MM) / (ENCODER_COUNT_PER_REV_L * time_interval);
    // 返回速度
    return speed_l;
}

/**
 * @brief 计算小车右轮的速度
 * @param delta_r 右编码器的脉冲增量
 * @return 小车右轮的速度（单位：毫米每秒）
 */
int speed_get_r(uint16_t delta_r)
{
    // 计算右轮的速度（单位：毫米每秒）
    int speed_r = (delta_r * WHEEL_CIRCUMFERENCE_MM) / (ENCODER_COUNT_PER_REV_R * time_interval);
    // 返回速度
    return speed_r;
}

/**
 * @brief 计算小车左右轮的平均速度
 *
 * 该函数计算左右轮的速度，并返回其平均值。编码器脉冲数
 * 转化为实际行驶距离，再根据时间间隔计算速度。
 * pwm == 10时，速度为；pwm == 20时，速度为；pwm == 30时，速度为；
 *
 * @param delta_l 左轮编码器的脉冲增量
 * @param delta_r 右轮编码器的脉冲增量
 * @return 左右轮的平均速度（单位：毫米每秒）
 */
int speed_get(uint16_t delta_l, uint16_t delta_r)
{
    // 计算左轮和右轮的速度（单位：毫米每秒）
    int speed_l = (delta_l * WHEEL_CIRCUMFERENCE_MM) / (ENCODER_COUNT_PER_REV_L * time_interval);
    int speed_r = (delta_r * WHEEL_CIRCUMFERENCE_MM) / (ENCODER_COUNT_PER_REV_R * time_interval);

    // 返回平均速度
    return (speed_l + speed_r) / 2;
}

