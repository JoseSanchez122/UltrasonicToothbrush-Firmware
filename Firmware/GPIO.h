#ifndef GPIO_H
#define GPIO_H

#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_port.h"
#include "fsl_common.h"
#include "fsl_gpio.h"
#include "UART.h"

#define HIGH 1U
#define LOW 0U
#define IN1 2U
#define IN2 1U
#define SLEEP 8U
#define TOUCH 7U



extern void GPIO_INIT();

#endif /*GPIO_H*/