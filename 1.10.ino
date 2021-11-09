int potentPin = A3, potentRead, voltage;
int counter = 0;
void setup() {
  pinMode(potentPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  potentRead = analogRead(potentPin);

  voltage = map(potentRead, 0, 1023, 0, 5);

  Serial.print("Potentiometer value: ");
  Serial.print(potentRead);
  Serial.print(", Approx. Voltage: ");
  Serial.println(voltage);

  digitalWrite(counter, HIGH);
  digitalWrite((counter - 1), HIGH);

  counter++;
  if (counter == 6)
  {
    counter = 0;
  }
  delay(voltage * 150);	
}