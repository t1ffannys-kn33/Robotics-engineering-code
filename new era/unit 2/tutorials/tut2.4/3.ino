int redLED = 9, greenLED = 10, blueLED = 11, buttonPin = 2;

void setup()
{
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop()
{
  Serial.println("aaa")
  while(digitalRead(buttonPin) == HIGH){  }
  for (int i = 0; i < 255; i++) // blue -> red
  {
    RGBwrite(i, 255-i, 0);
    delay(50);
  }
  while(digitalRead(buttonPin) == HIGH){  }
  for (int i = 0; i < 255; i++) // red ->green
  {
    RGBwrite(255-i, 0, i);
    delay(50);
  }
  while(digitalRead(buttonPin) == HIGH){  }
  for (int i = 0; i < 255; i++) // green -> blue
  {
    RGBwrite(0, 255-i, i);
    delay(50);
  }
}
void RGBwrite(int r, int g, int b)
{
  analogWrite(redLED, r);
  analogWrite(greenLED, g);
  analogWrite(blueLED, b); 
}