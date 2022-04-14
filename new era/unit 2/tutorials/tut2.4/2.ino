int redLED = 9, greenLED = 10, blueLED = 11;

void setup()
{
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}

void loop()
{
  while(digitalRead)
  for (int i = 0; i < 255; i++)
  {
    RGBwrite(i, 255-i, 0);
    delay(50);
  }
  
}
void RGBwrite(int r, int g, int b)
{
  analogWrite(redLED, r);
  analogWrite(greenLED, g);
  analogWrite(blueLED, b); 
}