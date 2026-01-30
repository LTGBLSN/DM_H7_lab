//
// Created by 21481 on 2026/1/29.
//

#include "main.h"
#include "uart_printf.h"
#include "cmsis_os.h"
#include "remote_control.h"

void DEBUG_UART_TASK()
{
    while (1)
    {
        usart1_printf("%d,%d\r\n",
                      dbus_remoter.mouse.x,
                      dbus_remoter.mouse.y
                      );
        osDelay(1);
    }
}
