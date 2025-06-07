/*
 * Copyright 2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/*${header:start}*/
#include "app.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_port.h"
#include "fsl_common.h"
#include "fsl_debug_console.h"
#include "TIMER.h"
#include "GPIO.h"
#include "UART.h"
/*${header:end}*/

/*${function:start}*/

void BOARD_InitHardware()
{
    BOARD_BootClockRUN();
    TIMER_INIT_INTERRUPT_EVERY_10us();

    #ifdef ENABLE_UART_PINS
        //------Habilitar estas funcoines si los pines PTB2 Y PTB1 SE usan en modo UART-------//
        BOARD_InitPins();
        CLOCK_SetLpuart0Clock(0x1U);
        //--------------------------------------------------------------------------------------//
    #endif
    #ifdef ENABLE_GPIO_PINS
        GPIO_INIT();
    #endif
    
    BOARD_InitDebugConsole();
}
/*${function:end}*/
