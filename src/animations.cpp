#include "animations.h"

void colorFill(CRGBW c, CRGBW *leds, uint8_t numLeds){
	for(int i = 0; i < numLeds; i++){
		leds[i] = c;
	}
}

void rainbow(CRGBW *leds, uint8_t numLeds){
	static uint8_t hue;

    for(uint16_t i = 0; i < numLeds; i++){
        leds[i] = CHSV((i * 256 / numLeds) + hue, 255, 255);
    }
    hue++;
}

void lightning(CRGBW *leds, uint8_t numLeds){
	static uint8_t position = 0;

	colorFill(CRGBW(0, 0, 0, 0), leds, numLeds);
	leds[(position+(numLeds-1))%numLeds] = CRGBW(127, 0, 0, 0);
	leds[position] = CRGBW(255, 0, 0, 0);
	leds[(position+1)%numLeds] = CRGBW(127, 0, 0, 0);

	position++;
	position = position % numLeds;
}