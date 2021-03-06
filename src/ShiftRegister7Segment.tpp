
#include <Arduino.h>

//This is a template + data file


static const byte digitCodeMap[] = {
//        GF EDCBA  Segments      7-segment map:
        0b00111111, // 0   "0"          AAA
        0b00000110, // 1   "1"         F   B
        0b01011011, // 2   "2"         F   B
        0b01001111, // 3   "3"          GGG
        0b01100110, // 4   "4"         E   C
        0b01101101, // 5   "5"         E   C
        0b01111101, // 6   "6"          DDD
        0b00000111, // 7   "7"
        0b01111111, // 8   "8"
        0b01110111, // 9   "9"
};

/**
 * A generic print digit function that takes an input and format it to a relevant array taken as another input
 * @tparam N Number of digits, template parameter, same as numberOfDigits defined in .h file
 * @param input Input value to be converted to digits
 * @param digitArray An empty array of digit, will be changed in the function to a full array of digits
 * @param decimalPoint position of the decimal point
 */
template<int N>
void printDigits(double input, byte *digitArray, int decimalPoint){
    int digit;
    for(int i=0;i<N;i++){
        digit = ((int)(input/pow(10,decimalPoint-i)))%10;
        digitArray[i] = digitCodeMap[digit];
    }
    if(decimalPoint<(N-1)){
        digitArray[decimalPoint] = digitArray[decimalPoint] | 0b10000000;
    }
}