#include "main.h"


void setup() { 
  
  LED_RGBW.setup();
  LED_RGBW.clear();
  LED_RGBW.setFPS(FPS_MAX/8);
  
  Com.setup(BAUD_RATE, TIMEOUTE);
}

void loop(){
  
  while (!Com.available()){
    LED_RGBW.update();
  }
  Com.handler();
}
