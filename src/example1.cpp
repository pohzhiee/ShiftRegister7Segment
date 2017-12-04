//
// Created by poh14 on 12/3/2017.
//
#include <Arduino.h>
#include "ShiftRegister7Segment.h"

//Go to the library header file and change number of digits if not 4
ShiftRegister7Segment display1(3,4,5,6,150);

void setup(){
    display1.begin();
}

void loop(){
    double a = 1.333;
    display1.display(a);
    a +=1;
    if(a<100) display1.blink();

}