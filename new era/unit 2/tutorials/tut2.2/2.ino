// TOmas turbek tutorial 2.2
// april 8th

int buttonPin = 2; // set variables for component pins
int redLED = 4;
bool shouldbeon; // declare variable for the button state

int buttonPin2 = 3; // do all the things for the second thing
int redLED2 = 5;
bool shouldbeon2;

void setup()
{
  pinMode(buttonPin, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(redLED2, OUTPUT);
}

void loop()
{
  if (digitalRead(buttonPin) == HIGH)
  {
    shouldbeon = !shouldbeon; // if the button is pressed, toggle the bool
  }
  if (shouldbeon)
  { // the bool controlls the desired state of the LED, so adjust is accordingly
    digitalWrite(redLED, HIGH);
  }
  else
  {
    digitalWrite(redLED, LOW);
  }

  if (digitalRead(buttonPin2) == HIGH)
  {
    shouldbeon2 = !shouldbeon2; // if the button is pressed, toggle the bool
  }
  if (shouldbeon2)
  { // the bool controlls the desired state of the LED, so adjust is accordingly
    digitalWrite(redLED2, HIGH);
  }
  else
  {
    digitalWrite(redLED2, LOW);
  }
}