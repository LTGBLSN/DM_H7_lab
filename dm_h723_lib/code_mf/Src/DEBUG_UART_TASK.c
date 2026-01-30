//
// Created by 21481 on 2026/1/29.
//

#include "main.h"
#include "uart_printf.h"
#include "cmsis_os.h"
#include "remote_control.h"
#include "IMU_DATA_GET.h"

void DEBUG_UART_TASK()
{
    while (1)
    {
        usart1_printf("%f,%f,%f \r\n",
                      imu_data_from_board_BMI088_mahony.roll_degree_angle,
                      imu_data_from_board_BMI088_mahony.yaw_degree_angle,
                      imu_data_from_board_BMI088_mahony.pitch_degree_angle);
        osDelay(5);
    }
}
