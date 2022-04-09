//#include <liblts546awc.h>
#include "liblts546awc.h"
#include <IRremote.hpp>

LTS546AWC ledModule = LTS546AWC();
int animationDelay = 70;

const int RECV_PIN = 12;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  
   ledModule.begin();
  // initialize LED pin HIGH to turn off
   ledModule.clearAll();
}

void loop(){
  if (irrecv.decode(&results)){
      if(results.value != 0xFFFFFFFF) {
        Serial.println(results.value, HEX);

        char value = fromIrCode(results.value);
        Serial.println(value);

        if (value == 'k') {
          animate();
        }

        ledModule.setChar(value);
      }
      
      irrecv.resume();
  }
}

void animate() {
  int repeat = 8;
  int segCount = 6;
  char segments[] = {'A', 'B', 'C', 'D', 'E', 'F'};
  ledModule.clearAll();
  for (int i = 0; i < segCount * repeat; i++) {
    int idx = i % segCount;
    int idxOff = (idx - 2 + segCount) % segCount;
    Serial.print(idx);
    Serial.print(' ');
    Serial.println(idxOff);
    ledModule.setSegment(segments[idx]);
    ledModule.clearSegment(segments[idxOff]);
    if (idx % 5 == 0)
      ledModule.setSegment('.');
    else if (idx % 1 == 0)
      ledModule.clearSegment('.');
    delay(animationDelay);
  }
}

char fromIrCode(uint32_t irCode) {
  if (irCode == 0xFF6897) return '1';
  if (irCode == 0xFF9867) return '2';
  if (irCode == 0xFFB04F) return '3';
  if (irCode == 0xFF30CF) return '4';
  if (irCode == 0xFF18E7) return '5';
  if (irCode == 0xFF7A85) return '6';
  if (irCode == 0xFF10EF) return '7';
  if (irCode == 0xFF38C7) return '8';
  if (irCode == 0xFF5AA5) return '9';
  if (irCode == 0xFF4AB5) return '0';
  if (irCode == 0xFF629D) return 'w';
  if (irCode == 0xFFA857) return 's';
  if (irCode == 0xFF22DD) return 'a';
  if (irCode == 0xFFC23D) return 'd';
  if (irCode == 0xFF52AD) return '#';
  if (irCode == 0xFF02FD) return 'k';
  return ' ';
}

void sample() {
  ledModule.clearAll();
  ledModule.diag();     
  ledModule.clearAll();
  count();
  ledModule.clearAll();
  reverse();   
  delay(2*digitDelay);
}

void count() {
  for (int i = 0; i < 10; i++) {
    ledModule.setDigit(i);
    delay(digitDelay);
  }             
}

void reverse() {
  for (int i = 9; i >= 0; i--) {
    ledModule.setDigit(i);
    delay(digitDelay);
  }             
}
