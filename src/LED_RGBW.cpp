#include "LED_RGBW.h"

ledController LED_RGBW;

// Public

ledController::ledController(){
}
ledController::~ledController(){
}

void ledController::setup(){
    FastLED.addLeds<WS2812B, DATA_PIN, RGB>(m_rgb_leds, getRGBWsize(NUM_LEDS));
    FastLED.clear(true);
}

void ledController::update(){
    FastLED.show();
}

void ledController::animate(){

    switch (m_animation)
    {
    case RAINBOW:
        rainbow(&m_leds[0], NUM_LEDS);
        break;
    case LIGHTNING:
        lightning(&m_leds[0], NUM_LEDS);
        break;

    default:
        break;
    }
}

void ledController::setBrightness(uint8_t brightness){
    FastLED.setBrightness(brightness);
}

uint8_t ledController::getBrightness(){
    return FastLED.getBrightness();
}

void ledController::clear(){
    FastLED.clear(true);
}



