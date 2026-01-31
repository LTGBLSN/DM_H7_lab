//
// Created by 21481 on 2026/1/30.
//



#include "cmsis_os.h"
#include "DJI_motors.h"
#include "remote_control.h"
#include "can_receive.h"
#include "dm_motor.h"

void CAN_SENT_TASK()
{
    osDelay(3000);
    dm_motor_mode_set(CMD_ENABLE_MODE, DM4340_01.can_channel, DM4340_01.can_id);

    while (1)
    {

        Dm_Can_Send(DM4340_01.can_channel,DM4340_01.can_id,DM4340_01.motor_type,DM4340_01.give_tor);


//        FDCAN_DJI_motors(0, 0, 0, 0, 0x200, CAN_CHANNEL_1);

        osDelay(1);
    }
}



