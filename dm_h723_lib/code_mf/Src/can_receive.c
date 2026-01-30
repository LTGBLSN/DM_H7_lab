//
// Created by 21481 on 2026/1/30.
//


#include "main.h"
#include "DJI_motors.h"

//motor data read
#define get_motor_measure(ptr, data)                                    \
    {                                                                   \
        (ptr)->last_ecd = (ptr)->ecd;                                   \
        (ptr)->ecd = (uint16_t)((data)[0] << 8 | (data)[1]);            \
        (ptr)->speed_rpm = (uint16_t)((data)[2] << 8 | (data)[3]);      \
        (ptr)->given_current = (uint16_t)((data)[4] << 8 | (data)[5]);  \
        (ptr)->temperate = (data)[6];                                   \
    }
/**
  * @brief          HAL库FDCAN接收回调函数
  * @param[in]      hfdcan: FDCAN句柄指针
  * @param[in]      RxFifo0ITs: 中断类型标识
  * @retval         none
  */
void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs)
{
    // 检查是否是“收到新消息”中断
    if ((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) != 0)
    {
        FDCAN_RxHeaderTypeDef rx_header;
        uint8_t rx_data[8];

        // 1. 从 FIFO0 获取报文
        if (HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &rx_header, rx_data) != HAL_OK)
        {
            return;
        }

        // 2. 判断是哪一路 CAN
        if (hfdcan->Instance == FDCAN1)
        {
            // FDCAN1 逻辑
            switch (rx_header.Identifier) // F4是StdId，H7是Identifier
            {
                case 0x201:
                case 0x202:
                case 0x203:
                case 0x204:
                case 0x205:
                case 0x206:
                case 0x207:
                {
                    uint8_t i = rx_header.Identifier - 0x201;
                    get_motor_measure(&motor_can1_data[i], rx_data);
                    break;
                }
                default:
                    break;
            }
        }
        else if (hfdcan->Instance == FDCAN2)
        {
            // FDCAN2 逻辑
            switch (rx_header.Identifier)
            {
                case 0x201:
                case 0x202:
                case 0x203:
                case 0x204:
                case 0x205:
                case 0x206:
                case 0x207:
                {
                    uint8_t i = rx_header.Identifier - 0x201;
                    get_motor_measure(&motor_can2_data[i], rx_data);
                    break;
                }
                default:
                    break;
            }
        }
        else if (hfdcan->Instance == FDCAN3)
        {
            // FDCAN3 逻辑
            switch (rx_header.Identifier)
            {
                case 0x201:
                case 0x202:
                case 0x203:
                case 0x204:
                case 0x205:
                case 0x206:
                case 0x207:
                {
                    uint8_t i = rx_header.Identifier - 0x201;
                    get_motor_measure(&motor_can2_data[i], rx_data);
                    break;
                }
                default:
                    break;
            }
        }
    }
}


