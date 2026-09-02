//
// Created by PC on 2026/9/2.
//


#include "cmsis_os.h"
#include "main.h"
#include "uart_printf.h"
#include "usart.h"

void RS485_SENT_TASK()
{
    while (1)
    {
        HAL_UART_Transmit_DMA(&huart3, "HELLO_U3", 8);
        HAL_UART_Transmit_DMA(&huart2, "HELLO_U2", 8);
        osDelay(100);
        osDelay(1);
    }
}






