//
// Created by poh14 on 12/3/2017.
//

#include "ShiftRegister7Segment.h"


ShiftRegister7Segment::ShiftRegister7Segment(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin,
                                             uint8_t OEPin, unsigned int interval):
mDataPin(dataPin),mClockPin(clockPin), mLatchPin(latchPin), mOEPin(OEPin), mInterval(interval)
{
}

/**
 * General case functions, will run a bit slower due to the need to check for decimal places
 * @param value value to be displayed by the seven segments
 */
void ShiftRegister7Segment::display(double value) {
    //determine how many digits are there to the left of decimal point
    auto magnitude = (int)floor(log10(value));
    int decimalPoint = magnitude < 0 ? 0 : magnitude;

    //Declare appropriate parameters, and then call function
    byte digitArray[numberOfDigits];

    printDigitFunc(value,digitArray, decimalPoint);

    //Send data out to shift register
    for (byte &digit: digitArray){
        shiftOut(mDataPin,mClockPin,LSBFIRST,digit);
    }
}

void ShiftRegister7Segment::begin() {
    pinMode(mDataPin, OUTPUT);
    pinMode(mClockPin, OUTPUT);
    pinMode(mLatchPin, OUTPUT);
    pinMode(mOEPin, OUTPUT);

}

void ShiftRegister7Segment::display(float value, uint8_t decimalPoint) {
    //Declareappropriate parameters, and then call function
    byte digitArray[numberOfDigits];

    printDigitFunc(value,digitArray, decimalPoint);

    //Send data out to shift register
    digitalWrite(mLatchPin, LOW);
    for (byte &digit: digitArray){
        shiftOut(mDataPin,mClockPin,LSBFIRST,digit);
    }
    digitalWrite(mLatchPin, HIGH);
}

/**
 * Blinks the seven segment display through output enable
 * Checks time elapsed and change state of output enable pin
 */
void ShiftRegister7Segment::blink(){
    if(millis()-previousTime > mInterval){
        OEState ? digitalWrite(mOEPin,HIGH) : digitalWrite(mOEPin,LOW);
        OEState = !OEState;
        previousTime = millis();
    }
}

void ShiftRegister7Segment::setInterval(unsigned int mInterval) {
    ShiftRegister7Segment::mInterval = mInterval;
}




