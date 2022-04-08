// Your Name
// Your Robotics Course Section
// Title (Name of Tutorial/Project)
// Description: Restate the purpose of the program in your own words
// Date Started - Date Completed

int buttonPin = 2;              // set variables for component pins
int redLED = 4;
int buttonPress;                // declare variable for the button state

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(redLED, OUTPUT);
}

void loop() {
  buttonPress = digitalRead(buttonPin); // set variable to button pin reading
  if (buttonPress == HIGH) {            // if button is pressed, turn LED on
    digitalWrite(redLED, HIGH);
  } else {
    digitalWrite(redLED, LOW);          // otherwise, LED is off
  }
}