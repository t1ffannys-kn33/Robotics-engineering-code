const int LED1 = 3;
const int LED2 = 5;
const int LED3 = 6;

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop()
{
  for (int i = 0; i <= 255; i++)
  {
    brightnesswrite(i, i, i);
    delay(200);
  }
}

void brightnesswrite(int pin1, int pin2, int pin3)
{
  analogWrite(LED1, pin1);
  analogWrite(LED2, pin2);
  analogWrite(LED3, pin3);
}

void blinkLedFast(int pin)
{
  blinkLed(pin, 100);
  blinkLed(pin, 100);
  blinkLed(pin, 100);
}
void blinkLedSlow(int pin)
{
  blinkLed(pin, 300);
  blinkLed(pin, 300);
  blinkLed(pin, 300);
  blinkLed(pin, 300);
  blinkLed(pin, 300);
}

void blinkLed(int led, int delayTime)
{
  digitalWrite(led, HIGH);
  delay(delayTime);
  digitalWrite(led, LOW);
  delay(delayTime);
}