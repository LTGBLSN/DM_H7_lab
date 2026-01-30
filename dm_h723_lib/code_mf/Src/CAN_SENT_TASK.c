//
// Created by 21481 on 2026/1/30.
//



#include "cmsis_os.h"
#include "DJI_motors.h"
#include "remote_control.h"

void CAN_SENT_TASK()
{
    while (1)
    {
        if(sbus_remoter.rc.ch[4] > 1000)
        {
            FDCAN_DJI_motors(2000, 0, 0, 0, 0x200, CAN_CHANNEL_1);
        } else
        {
            FDCAN_DJI_motors(0, 0, 0, 0, 0x200, CAN_CHANNEL_1);
        }

        osDelay(1);
    }
}



