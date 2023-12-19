#include "LED_RGBW.h"

#define USE_TIMER_1     true
#define USE_TIMER_2     false 

#include <TimerInterrupt.h>
#include <ISR_Timer.h> 

ledController LED_RGBW;

// Private
void ledController::animationHandler(){
    LED_RGBW.animate();
}

// Public

ledController::ledController(){
}
ledController::~ledController(){
}

void ledController::setup(){
    FastLED.addLeds<WS2812B, DATA_PIN, RGB>(m_rgb_leds, getRGBWsize(NUM_LEDS));
    FastLED.clear(true);
  
    ITimer1.init();
    ITimer1.attachInterruptInterval(PERIOD_MIN, animationHandler);

}

void ledController::update(){
    FastLED.show();
}

void ledController::animate(){
    switch (m_animation)
    {
    case RAINBOW:
        rainbow(m_leds, NUM_LEDS);
        break;
    case LIGHTNING:
        lightning(m_leds, NUM_LEDS);
        break;
    case OFF:
        FastLED.clear(true);
        break;
    default:
        break;
    }
}

void ledController::setSpeed(uint8_t speed){
    uint32_t period = map(speed, 0, 100, 1000, PERIOD_MIN);
    ITimer1.setInterval(period, animationHandler);
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



