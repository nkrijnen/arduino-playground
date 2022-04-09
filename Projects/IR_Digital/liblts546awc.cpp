/*
  Liblts546awc

  Controls one digit element LED
  Type common anode
  Model LTS-546AWC but pins are easily adaptable to layout
  Turns on and off a light emitting diode(LED) connected to digital pin
  Layout is with 3 or 8 common anode

  The circuit:
  - Common anode 3 (+5V)
  - Resistor 220Ohm for every led input
  - Arduino pins from 2 (A) to 8 (G) and 9 = DP (decimal point)
  - Displays segments snd numbers in direct and reverse order

  created april 2019
  by Riccardo G Corsi
  last modified 27 apr 2019

  This example code is in the public domain.

*/

#include "liblts546awc.h"


// default constructor 
LTS546AWC::LTS546AWC(void){}

const int ledOn = HIGH;
const int ledOff = LOW;

// init the chip
void LTS546AWC::begin()
{ 
  pinMode(ledPinA, OUTPUT);
  pinMode(ledPinB, OUTPUT);
  pinMode(ledPinC, OUTPUT);
  pinMode(ledPinD, OUTPUT);
  pinMode(ledPinE, OUTPUT);
  pinMode(ledPinF, OUTPUT);
  pinMode(ledPinG, OUTPUT);
  pinMode(ledPinDP, OUTPUT);
                
  // initialize LED pin ledOff to turn off
  clearAll();
}

void LTS546AWC::clearAll() {
  digitalWrite(ledPinA, ledOff);
  digitalWrite(ledPinB, ledOff);
  digitalWrite(ledPinC, ledOff);
  digitalWrite(ledPinD, ledOff);
  digitalWrite(ledPinE, ledOff);
  digitalWrite(ledPinF, ledOff);
  digitalWrite(ledPinG, ledOff);
  digitalWrite(ledPinDP, ledOff);
}

void LTS546AWC::diag() {
  clearAll();
  setSegment('A');
  delay(digitDelay);
  clearSegment('A');
  setSegment('B');
  delay(digitDelay);
  clearSegment('B');
  setSegment('C');
  delay(digitDelay);
  clearSegment('C');
  setSegment('D');
  delay(digitDelay);
  clearSegment('D');
  setSegment('E');
  delay(digitDelay);
  clearSegment('E');
  setSegment('F');
  delay(digitDelay);
  clearSegment('F');
  setSegment('G');
  delay(digitDelay);
  clearSegment('G');
  setSegment('.');
  delay(digitDelay);
  clearSegment('.'); 
  delay(digitDelay);             
}

void LTS546AWC::setDigit(int n) {
  clearAll();
  switch (n) {
    case 0:
      setSegment('A');
      setSegment('B');
      setSegment('C');
      setSegment('D');
      setSegment('E');
      setSegment('F');
      clearSegment('G');
      clearSegment('.');
      break;
    case 1:
      clearSegment('A');
      setSegment('B');
      setSegment('C');
      clearSegment('D');
      clearSegment('E');
      clearSegment('F');
      clearSegment('G');
      clearSegment('.');
      break;    
     case 2:
      setSegment('A');
      setSegment('B');
      clearSegment('C');
      setSegment('D');
      setSegment('E');
      clearSegment('F');
      setSegment('G');
      clearSegment('.');
      break;  
     case 3:
      setSegment('A');
      setSegment('B');
      setSegment('C');
      setSegment('D');
      clearSegment('E');
      clearSegment('F');
      setSegment('G');
      clearSegment('.');
      break;
     case 4:
      clearSegment('A');
      setSegment('B');
      setSegment('C');
      clearSegment('D');
      clearSegment('E');
      setSegment('F');
      setSegment('G');
      clearSegment('.');
      break;   
     case 5:
      setSegment('A');
      clearSegment('B');
      setSegment('C');
      setSegment('D');
      clearSegment('E');
      setSegment('F');
      setSegment('G');
      clearSegment('.');
      break;
     case 6:
      setSegment('A');
      clearSegment('B');
      setSegment('C');
      setSegment('D');
      setSegment('E');
      setSegment('F');
      setSegment('G');
      clearSegment('.');
      break;  
     case 7:
      setSegment('A');
      setSegment('B');
      setSegment('C');
      clearSegment('D');
      clearSegment('E');
      clearSegment('F');
      clearSegment('G');
      clearSegment('.');
      break;      
     case 8:
      setSegment('A');
      setSegment('B');
      setSegment('C');
      setSegment('D');
      setSegment('E');
      setSegment('F');
      setSegment('G');
      clearSegment('.');
      break;
     case 9:
      setSegment('A');
      setSegment('B');
      setSegment('C');
      setSegment('D');
      clearSegment('E');
      setSegment('F');
      setSegment('G');
      clearSegment('.');
      break;                                   
    default:
      break;
  }
} // setDigit


void LTS546AWC::setChar(char n) {
  clearAll();
  switch (n) {
    case '0':
      setSegment('A');
      setSegment('B');
      setSegment('C');
      setSegment('D');
      setSegment('E');
      setSegment('F');
      clearSegment('G');
      clearSegment('.');
      break;
    case '1':
      clearSegment('A');
      setSegment('B');
      setSegment('C');
      clearSegment('D');
      clearSegment('E');
      clearSegment('F');
      clearSegment('G');
      clearSegment('.');
      break;    
    case '2':
      setSegment('A');
      setSegment('B');
      clearSegment('C');
      setSegment('D');
      setSegment('E');
      clearSegment('F');
      setSegment('G');
      clearSegment('.');
      break;  
    case '3':
      setSegment('A');
      setSegment('B');
      setSegment('C');
      setSegment('D');
      clearSegment('E');
      clearSegment('F');
      setSegment('G');
      clearSegment('.');
      break;
    case '4':
      clearSegment('A');
      setSegment('B');
      setSegment('C');
      clearSegment('D');
      clearSegment('E');
      setSegment('F');
      setSegment('G');
      clearSegment('.');
      break;   
    case '5':
      setSegment('A');
      clearSegment('B');
      setSegment('C');
      setSegment('D');
      clearSegment('E');
      setSegment('F');
      setSegment('G');
      clearSegment('.');
      break;
    case '6':
      setSegment('A');
      clearSegment('B');
      setSegment('C');
      setSegment('D');
      setSegment('E');
      setSegment('F');
      setSegment('G');
      clearSegment('.');
      break;  
    case '7':
      setSegment('A');
      setSegment('B');
      setSegment('C');
      clearSegment('D');
      clearSegment('E');
      clearSegment('F');
      clearSegment('G');
      clearSegment('.');
      break;      
    case '8':
      setSegment('A');
      setSegment('B');
      setSegment('C');
      setSegment('D');
      setSegment('E');
      setSegment('F');
      setSegment('G');
      clearSegment('.');
      break;
    case '9':
      setSegment('A');
      setSegment('B');
      setSegment('C');
      setSegment('D');
      clearSegment('E');
      setSegment('F');
      setSegment('G');
      clearSegment('.');
      break;
    case 'w':
      setSegment('A');
      clearSegment('B');
      clearSegment('C');
      clearSegment('D');
      clearSegment('E');
      clearSegment('F');
      clearSegment('G');
      clearSegment('.');
      break;
    case 's':
      clearSegment('A');
      clearSegment('B');
      clearSegment('C');
      setSegment('D');
      clearSegment('E');
      clearSegment('F');
      clearSegment('G');
      clearSegment('.');
      break;
    case 'a':
      clearSegment('A');
      clearSegment('B');
      clearSegment('C');
      clearSegment('D');
      setSegment('E');
      setSegment('F');
      clearSegment('G');
      clearSegment('.');
      break;
    case 'd':
      clearSegment('A');
      setSegment('B');
      setSegment('C');
      clearSegment('D');
      clearSegment('E');
      clearSegment('F');
      clearSegment('G');
      clearSegment('.');
      break;
    case '#':
      clearSegment('A');
      clearSegment('B');
      clearSegment('C');
      clearSegment('D');
      clearSegment('E');
      clearSegment('F');
      clearSegment('G');
      setSegment('.');
      break;
    default:
      break;
  }
}
// in order to use single segment remember to clearAll
void LTS546AWC::setSegment(char s) {
  switch (s) {
    case 'A':
      digitalWrite(ledPinA, ledOn);
      break;  
    case 'B':
      digitalWrite(ledPinB, ledOn);
      break;
    case 'C':
      digitalWrite(ledPinC, ledOn);
      break;
    case 'D':
      digitalWrite(ledPinD, ledOn);
      break;
    case 'E':
      digitalWrite(ledPinE, ledOn);
      break;
    case 'F':
      digitalWrite(ledPinF, ledOn);
      break;
    case 'G':
      digitalWrite(ledPinG, ledOn);
      break;                                          
    case '.':
      digitalWrite(ledPinDP, ledOn);
      break; 
    default:
      break;
    }
  } // setSegment

// in order to use single segment remember to clearAll
void LTS546AWC::clearSegment(char s) {
  switch (s) {
    case 'A':
      digitalWrite(ledPinA, ledOff);
      break;  
    case 'B':
      digitalWrite(ledPinB, ledOff);
      break;
    case 'C':
      digitalWrite(ledPinC, ledOff);
      break;
    case 'D':
      digitalWrite(ledPinD, ledOff);
      break;
    case 'E':
      digitalWrite(ledPinE, ledOff);
      break;
    case 'F':
      digitalWrite(ledPinF, ledOff);
      break;
    case 'G':
      digitalWrite(ledPinG, ledOff);
      break;                                          
    case '.':
      digitalWrite(ledPinDP, ledOff);
      break; 
    default:
      break;
    }
} // clearSegment
