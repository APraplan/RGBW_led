#include "main.h"

void TimerHandler();

void setup() { 

  LED_RGBW.setup();
  LED_RGBW.clear();
  
  Com.setup(BAUD_RATE, TIMEOUTE);

  ITimer1.init();
  ITimer1.attachInterruptInterval(TIMER_INTERVAL_MS, TimerHandler);
  
}

void loop(){
  
  while (!Com.available()){
    LED_RGBW.update();
  }
  Com.handler(); // TO DO : add a handler for the message
}

void TimerHandler()
{
  LED_RGBW.animate();
}
