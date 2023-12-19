#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <Arduino.h>

#define BAUD_RATE 115200
#define TIMEOUTE 1

#define ACKNOWLEDGE 'A'
#define RELEASE 'R'
#define START 'S'

enum message
{
    PC_MESSAGE_LED_BRIGHTNESS = 0,
    PC_MESSAGE_LED_COLOR,

    PC_MESSAGE_LOOP,
    PC_MESSAGE_STOP
};

extern communication Com;

class communication
{
private:
    /* data */
public:
    communication();
    ~communication();

    bool communication::available();
    void communication::setup(uint32_t baud_rate, uint8_t timeoute);
    void communication::release(String* message);
    void communication::handler();
};

#endif // COMMUNICATION_H