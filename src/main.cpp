#include "main.h"


void setup() { 
  
  LED_RGBW.setup();
  LED_RGBW.clear();
  LED_RGBW.setSpeed(98.5);
  
  Com.setup(BAUD_RATE, TIMEOUTE);
}

void loop(){
  
  while (!Com.available()){
    LED_RGBW.update();
  }
  Com.handler(); // TO DO : add a handler for the message
}
