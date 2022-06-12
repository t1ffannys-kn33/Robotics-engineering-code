int potentPin = A3, potentRead, colorindex;
int ledbrightness;
// an array of characters is styled as a string
char rainbow[] = "ROYGBIV";

void setup() {
  pinMode(potentPin, INPUT);
  pinMode(A2, OUTPUT); // led
  Serial.begin(9600);
}

void loop() {
  //set potentRead to values inputted from potentiometer
  potentRead = analogRead(potentPin);

  //convert potentiometer reading range 0-1023 to available indexes from rainbow.
  colorindex = map(potentRead, 0, 1023, 0, 6);
  ledbrightness = map(potentRead, 0, 1023, 0, 255);
  // writes values to led
  analogWrite(ledbrightness, A2);
  
  //prints the raw values and the color with index mapped to potentiometer
    Serial.print("led value: ");
  Serial.print(ledbrightness);

  Serial.print("Potentiometer value: ");
  Serial.print(potentRead);
  Serial.print(", Color: ");
  Serial.println(rainbow[colorindex]);
}
