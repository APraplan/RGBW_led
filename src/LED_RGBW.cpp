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
    ITimer1.attachInterrupt(FPS_MAX, animationHandler);

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
    default:
        break;
    }
}

void ledController::setFPS(float fps){

    if(fps > FPS_MAX)
        fps = FPS_MAX;
    else if(fps < 0)
        fps = 0;

    ITimer1.setFrequency((float) fps, animationHandler);
}

void ledController::setBrightness(uint8_t brightness){
    FastLED.setBrightness(brightness);
}

uint8_t ledController::getBrightness(){
    return FastLED.getBrightness();
}

void ledController::clear(){
    m_animation = OFF;
    FastLED.clear(true);
}

void ledController::setColor(CRGBW c){
    m_animation = OFF;
    colorFill(c, m_leds, NUM_LEDS);
}

void ledController::setAnimation(animationType animation){
    m_animation = animation;
}



