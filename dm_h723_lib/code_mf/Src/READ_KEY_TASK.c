#include "cmsis_os.h"
#include "main.h"

//
// Created by PC on 2026/9/2.
//
void READ_KEY_TASK()
{
    while(1)
    {
        KEY_STATE = HAL_GPIO_ReadPin(KEY_GPIO_Port, KEY_Pin);
        osDelay(1);
    }
}