//
// Created by poh14 on 12/3/2017.
//
#ifndef SHIFTREGISTER7SEGMENT_SHIFTREGISTER7SEGMENT_H
#define SHIFTREGISTER7SEGMENT_SHIFTREGISTER7SEGMENT_H
#include <Arduino.h>
#include "ShiftRegister7Segment.tpp"

const int numberOfDigits = 4;

class ShiftRegister7Segment {
private:
    const uint8_t mDataPin,mClockPin,mLatchPin, mOEPin;
    unsigned int mInterval;
    bool OEState=true;
    unsigned long previousTime;
    void (*printDigitFunc)(double, byte*, int) = printDigits<numberOfDigits>;
public:
    ShiftRegister7Segment() = delete;
    ShiftRegister7Segment(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin,
                          uint8_t OEPin = 0, unsigned int interval = 100);

    void display(double value);
    void display(float value, uint8_t decimalPoint);
    void blink();
    void begin();

    void setInterval(unsigned int mInterval);


};


#endif //SHIFTREGISTER7SEGMENT_SHIFTREGISTER7SEGMENT_H
