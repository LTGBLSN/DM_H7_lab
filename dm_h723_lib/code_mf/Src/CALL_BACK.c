//
// Created by 21481 on 2026/5/16.
//

#include "main.h"
#include "remote_control.h"
#include "string.h"


/* ========================== 统一回调函数部分 ========================== */

/**
  * @brief 串口接收空闲中断回调
  */
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
    if (huart->Instance == UART5)
    {
#if REMOTE_TYPE == SBUS
        {
            if (Size <= SBUS_BUFF_SIZE)
            {
                sbus_frame_parse(&sbus_remoter, rx_subs_buff);
            }
            else
            {
                memset(rx_subs_buff, 0, SBUS_BUFF_SIZE);
            }
            // 重新开启DMA接收，注意这里使用了传入的 huart
            HAL_UARTEx_ReceiveToIdle_DMA(huart, rx_subs_buff, SBUS_BUFF_SIZE);
        }
#elif REMOTE_TYPE == DBUS
{
    if (Size == DBUS_FRAME_SIZE)
    {
        dbus_frame_parse(&dbus_remoter, rx_dbus_buff);
    }
    // 重新开启DMA接收
    HAL_UARTEx_ReceiveToIdle_DMA(huart, rx_dbus_buff, DBUS_BUFF_SIZE);
}
#endif
    }


}

/**
  * @brief 串口错误回调
  */
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == UART5)
    {
#if REMOTE_TYPE == SBUS
        memset(rx_subs_buff, 0, SBUS_BUFF_SIZE);
        HAL_UARTEx_ReceiveToIdle_DMA(huart, rx_subs_buff, SBUS_BUFF_SIZE);
#elif REMOTE_TYPE == DBUS
        memset(rx_dbus_buff, 0, DBUS_BUFF_SIZE);
        HAL_UARTEx_ReceiveToIdle_DMA(huart, rx_dbus_buff, DBUS_BUFF_SIZE);
#endif
    }


}