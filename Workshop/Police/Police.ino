#define LED_B 3

const int blinkDelay = 150;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_B, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(LED_B, LOW); 
  delay(blinkDelay);                     
  digitalWrite(LED_BUILTIN, LOW); 
  digitalWrite(LED_B, HIGH);
  delay(blinkDelay);                     
}
