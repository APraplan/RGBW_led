#include "main.h"

// temp
#define NUM_LEDS 129
#define DATA_PIN 2

void colorFill(CRGBW c, CRGBW *leds, uint8_t numLeds){
	for(int i = 0; i < numLeds; i++){
		leds[i] = c;
	}
}
void rainbow(CRGBW *leds, uint8_t numLeds){
	static uint8_t hue;
	for(int i = 0; i < numLeds; i++){
		leds[i] = CHSV((i * 256 / numLeds) + hue, 255, 255);
	}
	hue++;
}
// 

CRGBW leds[NUM_LEDS];
CRGB *ledsRGB = (CRGB *) &leds[0];

void TimerHandler();

bool lightning_on = false;

void setup() { 
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(ledsRGB, getRGBWsize(NUM_LEDS));
  FastLED.clear(true);
  // FastLED.setMaxRefreshRate();
  
  Com.setup(BAUD_RATE, TIMEOUTE);

  ITimer1.init();
  ITimer1.attachInterruptInterval(TIMER_INTERVAL_MS, TimerHandler);
  
}

void loop(){
  
  while (!Com.available()){
    FastLED.show();
  }
  Com.handler();
}

void TimerHandler()
{
  if (lightning_on){
    rainbow(&leds[0], NUM_LEDS);
  }
}
