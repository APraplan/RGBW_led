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
  
  Serial.begin(115200);
  Serial.setTimeout(1);

  ITimer1.init();
  // ITimer1.attachInterruptInterval(TIMER_INTERVAL_MS, TimerHandler);
  ITimer1.attachInterruptInterval(10L, TimerHandler);
  
}

void loop(){
  
  while (!Serial.available()){
    FastLED.show();
  }
  communicationHandler();
}

void TimerHandler()
{
  if (lightning_on){
    rainbow(&leds[0], NUM_LEDS);
  }
}

void communicationReleased(String* message){


  int type = atoi(message->substring(0, 1).c_str());


  switch (type)
  {
    case PC_MESSAGE_LED_BRIGHTNESS:
    {
      int brightness = atoi(message->substring(1, 4).c_str());
      FastLED.setBrightness(brightness);
      // FastLED.show();
      break;
    }

    case PC_MESSAGE_LED_COLOR:
    {
      int red = atoi(message->substring(1, 4).c_str());
      int green = atoi(message->substring(4, 7).c_str());
      int blue = atoi(message->substring(7, 10).c_str());
      int white = atoi(message->substring(10, 13).c_str());
      colorFill(CRGBW(red, green, blue, white), leds, NUM_LEDS);
      // FastLED.show();
      break;
    }

    case PC_MESSAGE_LOOP:
      lightning_on = true;
      break;

    case PC_MESSAGE_STOP:
      lightning_on = false;
      break;

    default:
      break;
  }
}

enum CommunicationState {
  START,
  READ,
  WRITE,
  ACKNOWLEDGE,
  RElEASE,
};

void communicationHandler() {
  static CommunicationState state = READ;

  static String message;
  static char tmpByte;

  String byte = Serial.readString().substring(0, 1);
  
  switch (state)
  {
  case START:

    if(byte.charAt(0) == 'S'){
      message = "";
      Serial.write('S');
      state = READ;
    }else if(byte.charAt(0) == 'E'){
      Serial.write('E');
    }
    break;
  case READ:
    if (byte.charAt(0) == 'S'){
      Serial.write('S');
    } else{
      tmpByte = byte.charAt(0);
      Serial.write(tmpByte);
      state = WRITE;
    }
    break;
  case WRITE:
    if(byte.charAt(0) == 'A'){
      message += tmpByte;
      Serial.write('A');
      state = ACKNOWLEDGE;
    } else if(byte.charAt(0) == 'E'){
      message += tmpByte;
      communicationReleased(&message);
      message = "";
      Serial.write('E');
      state = START;
    } else {
      Serial.write(tmpByte);
    }
    break;
  case ACKNOWLEDGE:
    if (byte.charAt(0) == 'A') {
      Serial.write('A');
    } else{
      state = WRITE;
      tmpByte = byte.charAt(0);
      Serial.write(tmpByte);
      state = WRITE;
    }
    break;

  default:
    break;
  }
}
