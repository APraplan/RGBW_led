// #include "animations.h"

// CLED::CLED(){
// 	;
// }

// void CLED::addLeds(){
// 	FastLED.addLeds<WS2812B, DATA_PIN, RGB>(ledsRGB, getRGBWsize(NUM_LEDS));
// }

// void colorFill(CRGBW c, CRGBW *leds, uint8_t numLeds){
// 	for(int i = 0; i < numLeds; i++){
// 		leds[i] = c;
// 	}
// }

// void rainbow(CRGBW *leds, uint8_t numLeds){
// 	static uint8_t hue;
// 	for(int i = 0; i < numLeds; i++){
// 		leds[i] = CHSV((i * 256 / numLeds) + hue, 255, 255);
// 	}
// 	FastLED.show();
// 	hue++;
// }

// void rainbowLoop(CRGBW *leds, uint8_t numLeds){
// 	long millisIn = millis();
// 	long loopTime = 20000; // 5 seconds
// 	while(millis() < millisIn + loopTime){
// 		rainbow(leds, numLeds);
// 		delay(5);
// 	}
// }

// void lightning(CRGBW *leds, uint8_t numLeds){
// 	static uint8_t position = 0;

// 	colorFill(CRGBW(0, 0, 0, 0), leds, numLeds);
// 	leds[(position+(numLeds-1))%numLeds] = CRGBW(127, 0, 0, 0);
// 	leds[position] = CRGBW(255, 0, 0, 0);
// 	leds[(position+1)%numLeds] = CRGBW(127, 0, 0, 0);

// 	position++;
// 	position = position % numLeds;
// }