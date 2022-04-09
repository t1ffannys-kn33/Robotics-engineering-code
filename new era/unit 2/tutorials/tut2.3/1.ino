const int LED1 = 3;
const int LED2 = 5; 
 
void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}
 
void loop() {
  blinkLed(LED1, 200);
  blinkLed(LED1, 200);
  blinkLed(LED1, 200);
  blinkLed(LED2, 500);
  blinkLed(LED2, 500);
}
 
void blinkLed(int led, int delayTime) {
  digitalWrite(led, HIGH);   
  delay(delayTime);             
  digitalWrite(led, LOW);   
  delay(delayTime);             
}