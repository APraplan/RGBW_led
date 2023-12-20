#ifndef LED_RGBW_H
#define LED_RGBW_H

#include "../lib/FastLED-3.6.0/src/FastLED.h"
#include "../lib/FastLED-3.6.0/src/FastLED_RGBW.h"

#include "animations.h"

#define FPS_MAX 200 // ms

#define NUM_LEDS 129
#define DATA_PIN 2

class ledController
{
private:

    animationType m_animation = OFF;

    CRGBW m_leds[NUM_LEDS];
    CRGB* m_rgb_leds = (CRGB *) &m_leds[0];

    void static animationHandler();

    /* data */
public:
    ledController();
    ~ledController();

    void setup();
    void update();
    void animate();
    void setFPS(float fps);
    void setBrightness(uint8_t brightness);
    uint8_t getBrightness();
    void clear();

    void setColor(CRGBW c);
    void setAnimation(animationType animation);

};

extern ledController LED_RGBW;

#endif // LED_RGBW_H