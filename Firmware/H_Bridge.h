#ifndef H_Bridge_H
#define H_Bridge_H 

#include "GPIO.h"
#include "TIMER.h"

extern void ENABLE_H_BRIDGE();
extern void DISABLE_H_BRIDGE();
extern void H_BRIDGE_SET_FREC(float _frequency);
extern void START_H_BRIDGE();

#endif /*H_Bridge_H*/ 