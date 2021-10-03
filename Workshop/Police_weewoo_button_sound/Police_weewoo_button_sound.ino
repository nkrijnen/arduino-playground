#include <math.h>

#define LED_PIN_A 5
#define LED_PIN_B 3
#define BUZZER_PIN 9
#define BUTTON_PIN 2
#define POT_PIN 2
#define PI 3.1415926535897932384626433832795

const int blinkDelayNormal = 180;
const int blinkDelayFast = 80;

int buttonState = 0;
float potVal = 0;

void setup() {
  pinMode(LED_PIN_A, OUTPUT);
  pinMode(LED_PIN_B, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);
  potVal = analogRead(POT_PIN) / 1024.;
  if (buttonState == HIGH) {
    tone(BUZZER_PIN, 600, 250);
    blink(blinkDelayFast);
    tone(BUZZER_PIN, 300, 250);
    blink(blinkDelayFast);
  } else {
    noTone(BUZZER_PIN);
    blink(blinkDelayNormal);
  }
}

void blink(int blinkDelay) {
//  int intensity = sin(millis() % PI);
//  Serial.println(intensity);
//  digitalWrite(LED_PIN_A, HIGH);
  int delayMs = round(blinkDelay * potVal);
  int intensity = 256 - round(256. * potVal);
  Serial.println(intensity);
  analogWrite(LED_PIN_A, intensity);
  analogWrite(LED_PIN_B, LOW);
  delay(delayMs);
  analogWrite(LED_PIN_A, LOW);
//  digitalWrite(LED_PIN_B, HIGH);
  analogWrite(LED_PIN_B, intensity);
  delay(delayMs);
}
