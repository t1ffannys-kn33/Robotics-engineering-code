int potentPin = A3, potentRead, colorindex;

// an array of characters is styled as a string
char rainbow[] = "ROYGBIV";

void setup() {
  pinMode(potentPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  //set potentRead to values inputted from potentiometer
  potentRead = analogRead(potentPin);

  //convert potentiometer reading range 0-1023 to available indexes from rainbow.
  colorindex = map(potentRead, 0, 1023, 0, 6);

  //prints the raw values and the color with index mapped to potentiometer
  Serial.print("Potentiometer value: ");
  Serial.print(potentRead);
  Serial.print(", Color: ");
  Serial.println(rainbow[colorindex]);
}