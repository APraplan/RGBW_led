#ifndef MAIN_H
#define MAIN_H
#include <Arduino.h>

#define USE_TIMER_1     true
#define USE_TIMER_2     false  

#include <TimerInterrupt.h>
#include <ISR_Timer.h>

#include "LED_RGBW.h"
#include "communication.h"

#define TIMER_INTERVAL_MS 5L

#endif // MAIN_H

// VID:PID
// 1A86 8040