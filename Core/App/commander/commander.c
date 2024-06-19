/**
 * @file 任务调度
 */

#include "commander.h"

/* USER CODE BEGIN Header_StartCommanderTask */
/**
* @brief 任务调度进程
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartCommanderTask */
void StartCommanderTask(void const * argument)
{
    /* USER CODE BEGIN StartCommanderTask */
    vTaskSuspend(AutoSweepTaskHandle);
//    vTaskSuspend(LedTaskHandle);
//    vTaskSuspend(BleTaskHandle);
    /* Infinite loop */
    for(;;)
    {
//        Move_Forward(20);
        Imu_Test();
//        GetImuEuler(mag_euler+3);
//        printf("Euler:%.2f %.2f %.2f \r\n",mag_euler[3],mag_euler[4],mag_euler[5]);
        vTaskDelay(100);
//        printf("distance:%d speed_l:%d speed_r:%d \r\n",distance_get(encoder_count_l,encoder_count_r),speed_get_l(delta_count_l),speed_get_r(delta_count_r));
//        vTaskDelay(500);
//        printf("encoder_count_l:%d encoder_count_r:%d \r\n",encoder_count_l,encoder_count_r);
//        vTaskDelay(500);
//        printf("1:%d 2:%d 3:%d 4:%d \r\n",ADC_buff[0],ADC_buff[1],ADC_buff[2],ADC_buff[3]);
//        vTaskDelay(500);

    }
    /* USER CODE END StartCommanderTask */
}

/* USER CODE BEGIN Header_StartBleTask */
/**
* @brief 蓝牙通信进程
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartBleTask */
void StartBleTask(void const * argument)
{
    /* USER CODE BEGIN StartBleTask */
    /* Infinite loop */
    for(;;)
    {
        bluetooth();
    }
    /* USER CODE END StartBleTask */
}

/* USER CODE BEGIN Header_StartAutoSweepTask */
/**
  * @brief  自动清扫进程
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartAutoSweepTask */
void StartAutoSweepTask(void const * argument)
{
    /* USER CODE BEGIN StartAutoSweepTask */
    ObstacleType obstacle;
    Sweep_Motor_ON();
    Vacuum_Motor_ON();
    Clean_Motor_ON();
    /* Infinite loop */
    for(;;)
    {
        Move_Forward(20);
        obstacle = detect_obstacle(&robot);
        if (obstacle != NO_OBSTACLE)
        {
            avoid_obstacle(&robot, obstacle);
        }
    }
    /* USER CODE END StartAutoSweepTask */
}

/* USER CODE BEGIN Header_StartLedTask */
/**
* @brief Function implementing the LedTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartLedTask */
void StartLedTask(void const * argument)
{
    /* USER CODE BEGIN StartLedTask */
    /* Infinite loop */
    for(;;)
    {
        LED2_ON;
        vTaskDelay(500);
        LED2_OFF;
        vTaskDelay(500);
    }
    /* USER CODE END StartLedTask */
}

