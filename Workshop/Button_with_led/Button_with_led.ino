#define LED_A 13
#define LED_B 3

const int buttonPin = 2;     // the number of the pushbutton pin
const int blinkDelayNormal = 150;
const int blinkDelayFast = 50;

int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  pinMode(LED_A, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    blink(blinkDelayFast);
  } else {
    blink(blinkDelayNormal);
  }
}

void blink(int blinkDelay) {
    digitalWrite(LED_A, HIGH);
    digitalWrite(LED_B, LOW);
    delay(blinkDelay);
    digitalWrite(LED_A, LOW);
    digitalWrite(LED_B, HIGH);
    delay(blinkDelay);
}
