/***************************************************************************** 
  liblts546awc.h
  This is a library for the LTS-546AWC single digit led module
  Allows to manage single segments and digits

  https://github.com/diamond2016/lts546awc
  Written by Riccardo G Corsi - 1st release april 2019.  
  GNU General Public License v3.0
*****************************************************************************/

#ifndef LIBLTS546AWC_H
#define LIBLTS546AWC_H


#include "Arduino.h"

// constants won't change. They're used here to set pins. 

const int ledPinDP = 9;      // the number of the LED pin decimal point
const int ledPinG =  8;      // the number of the LED pin segment G
const int ledPinF =  7;      // the number of the LED pin segment F
const int ledPinE =  6;      // the numero of the LED pin segment E
const int ledPinD =  5;      // the segment of the LED pin segment D
const int ledPinC =  4;      // the number of the LED pin segment C
const int ledPinB =  3;      // the number of the LED pin segment B
const int ledPinA =  2;      // the number of the LED pin segment A

const int digitDelay = 300;         // variable for refreshing ms

class LTS546AWC {
 public:
  LTS546AWC();
   
  void begin();  // initialize leds and pins
  void setSegment(char s);
  void clearSegment(char s);
  void setDigit(int n);
  void setChar(char n);
  void clearAll();
  void diag();
 
 private:
 
}; // LTS546AWC class


#endif //  LIBLTS546AWC_H
