#include "H_Bridge.h"

volatile int Period;

void ENABLE_H_BRIDGE(){
    GPIO_INIT();
    TIMER_INIT_INTERRUPT_EVERY_10us();
    GPIO_PinWrite(GPIOA, 8U, HIGH);
    GPIO_PinWrite(GPIOB, 2U, HIGH);
    GPIO_PinWrite(GPIOB, 1U, LOW);
}

void DISABLE_H_BRIDGE(){
    GPIO_PinWrite(GPIOA, 8U, LOW);
}

void H_BRIDGE_SET_FREC(float _frequency){
    Period = (int)((1000000.0/_frequency)/2.0);
    Period /= 10;
} 

void START_H_BRIDGE(){
    
    if (us_Counts >= Period)
    {
        us_Counts = 0;
        GPIO_PortToggle(GPIOB, 1u << 1U);
        GPIO_PortToggle(GPIOB, 2u << 1U);
    }
}