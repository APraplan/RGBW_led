#include "communication.h"
#include "LED_RGBW.h"

communication Com;

enum CommunicationState {
  CS_START,
  CS_READ,
  CS_WRITE,
  CS_ACKNOWLEDGE,
  CS_RElEASE,
};

// public

communication::communication(){
}

communication::~communication(){
    // Serial.end();
}

void communication::setup(uint32_t baud_rate, uint8_t timeoute){
    Serial.begin(baud_rate);
    Serial.setTimeout(timeoute);
}

bool communication::available(){
    return Serial.available();
}

void communication::release(String* message){


  int type = atoi(message->substring(0, 1).c_str());


  switch (type)
  {
    case PC_MESSAGE_LED_BRIGHTNESS:
    {
      int brightness = atoi(message->substring(1, 4).c_str());
      LED_RGBW.setBrightness(brightness);
      break;
    }

    case PC_MESSAGE_LED_COLOR:
    {
      int red = atoi(message->substring(1, 4).c_str());
      int green = atoi(message->substring(4, 7).c_str());
      int blue = atoi(message->substring(7, 10).c_str());
      int white = atoi(message->substring(10, 13).c_str());
      LED_RGBW.setColor(CRGBW(red, green, blue, white));
      break;
    }

    case PC_MESSAGE_SPEED:
    {
      int speed = atoi(message->substring(1, 4).c_str());
      LED_RGBW.setFPS(speed);
      break;
    }

    case PC_MESSAGE_ANIMATION:
    {
      animationType animation = (animationType) atoi(message->substring(1, 2).c_str());
      LED_RGBW.setAnimation(animation);
      break;
    }

    default:
      break;
  }
}

void communication::handler() {
  static CommunicationState state = CS_READ;

  static String message;
  static char tmpByte;

  String byte = Serial.readString().substring(0, 1);
  
  switch (state)
  {
  case CS_START:

    if(byte.charAt(0) == START){
      message = "";
      Serial.write(START);
      state = CS_READ;
    }else if(byte.charAt(0) == RELEASE){
      Serial.write(RELEASE);
    }
    break;
  case CS_READ:
    if (byte.charAt(0) == START){
      Serial.write(START);
    } else{
      tmpByte = byte.charAt(0);
      Serial.write(tmpByte);
      state = CS_WRITE;
    }
    break;
  case CS_WRITE:
    if(byte.charAt(0) == ACKNOWLEDGE){
      message += tmpByte;
      Serial.write(ACKNOWLEDGE);
      state = CS_ACKNOWLEDGE;
    } else if(byte.charAt(0) == RELEASE){
      message += tmpByte;
      release(&message);
      message = "";
      Serial.write(RELEASE);
      state = CS_START;
    } else {
      Serial.write(tmpByte);
    }
    break;
  case CS_ACKNOWLEDGE:
    if (byte.charAt(0) == ACKNOWLEDGE) {
      Serial.write(ACKNOWLEDGE);
    } else{
      state = CS_WRITE;
      tmpByte = byte.charAt(0);
      Serial.write(tmpByte);
      state = CS_WRITE;
    }
    break;

  default:
    break;
  }
}
