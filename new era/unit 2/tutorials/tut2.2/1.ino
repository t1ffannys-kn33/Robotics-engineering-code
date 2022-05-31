// Your Name
// Your Robotics Course Section
// Title (Name of Tutorial/Project)
// Description: Restate the purpose of the program in your own words
// Date Started - Date Completed

int buttonPin = 2; // set variables for component pins
int redLED = 4;
bool state; // declare variable for the button state

void setup()
{
  pinMode(buttonPin, INPUT);
  pinMode(redLED, OUTPUT);
}

void loop()
{
  if (digitalRead(buttonPin) == HIGH)
  { // if button is pressed, change state
    state = !state;
  }
  if (state)
  {
    digitalWrite(redLED, HIGH);
  }
  if (!state)
  {
    digitalWrite(redLED, LOW); // otherwise, LED is off
  }
  delay(200);
}
