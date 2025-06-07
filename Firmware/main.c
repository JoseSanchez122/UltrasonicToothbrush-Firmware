#include "board.h"
#include "app.h"
#include "fsl_lpuart.h"
#include "fsl_debug_console.h"
#include "GPIO.h"
#include "TIMER.h"
#include "H_Bridge.h"
#include "UART.h"

int main(void)
{
    bool H_Bridge_State = false
    BOARD_InitHardware();
    UART_INIT_115200_BAUD();
    ENABLE_H_BRIDGE();
    H_BRIDGE_SET_FREC(240.0);
    
    while (1)
    {
        if(!GPIO_PinRead(GPIOB, TOUCH)){
             while(!GPIO_PinRead(GPIOB, TOUCH));
            H_Bridge_State = !H_Bridge_State;
        }

        if(H_Bridge_State)
            START_H_BRIDGE();
        
    }
}


