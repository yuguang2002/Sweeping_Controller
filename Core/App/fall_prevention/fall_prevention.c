/**
 * @file 防跌落模块
 */

#include "fall_prevention.h"

//存储四个红外传感器返回数值，顺序从左到右
//1:2700  2:1300  3:1000 4:4000  检测到地面时返回值
//1:0  2:0  3:0  4:0  未检测到地面时返回值
uint16_t ADC_buff[4];

/**
 * @brief ADC红外采集函数
 */
uint16_t Get_ADC(){
    //开启ADC1
    HAL_ADC_Start(&hadc1);
    //等待ADC转换完成，超时为100ms
    HAL_ADC_PollForConversion(&hadc1,100);
    //判断ADC是否转换成功
    if(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc1),HAL_ADC_STATE_REG_EOC))
    {
        return HAL_ADC_GetValue(&hadc1);
    }
    return 0;
}

/**
 * @brief ADC数据记录
 */
void Update_ADC()
{
    for(uint8_t i=0;i<4;i++){
        ADC_buff[i]= Get_ADC();
    }
}

/**
 * @brief 防跌落算法
 */
void Fall_Prevention_Run(uint8_t fp_speed)
{
    Update_ADC();
    uint8_t flag = 0;
    if(ADC_buff[0] < 50 || ADC_buff[1] <50)
    {
        Move_Back(fp_speed);
        vTaskDelay(20*fp_speed);
        Move_Right(fp_speed);
        vTaskDelay(30*fp_speed);
        flag++;
    }
    else if(ADC_buff[2] < 50 || ADC_buff[3] <50)
    {
        Move_Back(fp_speed);
        vTaskDelay(20*fp_speed);
        Move_Left(fp_speed);
        vTaskDelay(30*fp_speed);
    }
}
