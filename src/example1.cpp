//
// Created by poh14 on 12/3/2017.
//
#include <Arduino.h>
#include "ShiftRegister7Segment.h"

//Go to the library header file and change number of digits if not 4

//Constructor parameters:
//1) dataPin (DS)
//2) clockPin (SH_CP)
//3) latchPin (ST_CP)
//4) outputEnable pin (OE), optional
//5) blinkInterval(milliseconds), optional
ShiftRegister7Segment display1(3,6,5,4, 150);
void setup(){
    Serial.begin(9600);
}

void loop(){
    display1.display(0.0);
    delay(5000);
    display1.display(1.1);
    Serial.println(1.1);
    delay(5000);
    display1.display(2.2);
    Serial.println(2.2);
    delay(5000);
    display1.display(3.3);
    Serial.println(3.3);
    delay(5000);
    display1.display(4.4);
    Serial.println(4.4);
    delay(5000);
    display1.display(5.5);
    Serial.println(5.5);
    delay(5000);

}
