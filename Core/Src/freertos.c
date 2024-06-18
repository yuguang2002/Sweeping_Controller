/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId AutoSweepTaskHandle;
osThreadId LedTaskHandle;
osThreadId BleTaskHandle;
osThreadId CommanderTaskHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartAutoSweepTask(void const * argument);
void StartLedTask(void const * argument);
void StartBleTask(void const * argument);
void StartCommanderTask(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* GetTimerTaskMemory prototype (linked to static allocation support) */
void vApplicationGetTimerTaskMemory( StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer, uint32_t *pulTimerTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/* USER CODE BEGIN GET_TIMER_TASK_MEMORY */
static StaticTask_t xTimerTaskTCBBuffer;
static StackType_t xTimerStack[configTIMER_TASK_STACK_DEPTH];

void vApplicationGetTimerTaskMemory( StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer, uint32_t *pulTimerTaskStackSize )
{
  *ppxTimerTaskTCBBuffer = &xTimerTaskTCBBuffer;
  *ppxTimerTaskStackBuffer = &xTimerStack[0];
  *pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
  /* place for user code */
}
/* USER CODE END GET_TIMER_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */

  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of AutoSweepTask */
  osThreadDef(AutoSweepTask, StartAutoSweepTask, osPriorityNormal, 0, 128);
  AutoSweepTaskHandle = osThreadCreate(osThread(AutoSweepTask), NULL);

  /* definition and creation of LedTask */
  osThreadDef(LedTask, StartLedTask, osPriorityNormal, 0, 128);
  LedTaskHandle = osThreadCreate(osThread(LedTask), NULL);

  /* definition and creation of BleTask */
  osThreadDef(BleTask, StartBleTask, osPriorityNormal, 0, 128);
  BleTaskHandle = osThreadCreate(osThread(BleTask), NULL);

  /* definition and creation of CommanderTask */
  osThreadDef(CommanderTask, StartCommanderTask, osPriorityRealtime, 0, 128);
  CommanderTaskHandle = osThreadCreate(osThread(CommanderTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartAutoSweepTask */
/**
  * @brief  Function implementing the AutoSweepTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartAutoSweepTask */
__weak void StartAutoSweepTask(void const * argument)
{
  /* USER CODE BEGIN StartAutoSweepTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
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
__weak void StartLedTask(void const * argument)
{
  /* USER CODE BEGIN StartLedTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartLedTask */
}

/* USER CODE BEGIN Header_StartBleTask */
/**
* @brief Function implementing the BleTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartBleTask */
__weak void StartBleTask(void const * argument)
{
  /* USER CODE BEGIN StartBleTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartBleTask */
}

/* USER CODE BEGIN Header_StartCommanderTask */
/**
* @brief Function implementing the CommanderTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartCommanderTask */
__weak void StartCommanderTask(void const * argument)
{
  /* USER CODE BEGIN StartCommanderTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartCommanderTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */
