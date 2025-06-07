#include "GPIO.h" 

void GPIO_INIT(){
    CLOCK_EnableClock(kCLOCK_PortB);
    CLOCK_EnableClock(kCLOCK_PortA);

    gpio_pin_config_t OUTPUT_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = LOW
    };

    gpio_pin_config_t INPUT_config = {
        .pinDirection = kGPIO_DigitalInput,
    };

    #ifdef ENABLE_GPIO_PINS
    PORT_SetPinMux(PORTB, IN2, kPORT_MuxAsGpio);
    PORT_SetPinMux(PORTB, IN1, kPORT_MuxAsGpio);
    GPIO_PinInit(GPIOB, IN1, &OUTPUT_config);
    GPIO_PinInit(GPIOB, IN2, &OUTPUT_config);
    GPIO_PinWrite(GPIOB, IN1, LOW);
    GPIO_PinWrite(GPIOB, IN2, LOW);
    #endif

    PORT_SetPinMux(PORTA, SLEEP, kPORT_MuxAsGpio);
    GPIO_PinInit(GPIOA, SLEEP, &OUTPUT_config);
    GPIO_PinWrite(GPIOA, SLEEP, LOW);

    PORT_SetPinMux(PORTB, TOUCH, kPORT_MuxAsGpio);
    GPIO_PinInit(GPIOB, TOUCH, &INPUT_config);

}