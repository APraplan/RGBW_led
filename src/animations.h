#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include <stdint.h>
#include "../lib/FastLED-3.6.0/src/FastLED.h"
#include "../lib/FastLED-3.6.0/src/FastLED_RGBW.h"

enum animationType {
    RAINBOW,
    LIGHTNING,
    OFF
};

void colorFill(CRGBW c, CRGBW *leds, uint8_t numLeds);
void rainbow(CRGBW *leds, uint8_t numLeds);
void lightning(CRGBW *leds, uint8_t numLeds);

#endif // ANIMATIONS_H