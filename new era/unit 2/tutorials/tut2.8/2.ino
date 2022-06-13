#include <Servo.h>  //loads servo command library

Servo myservo;      // Declare servo variable "myservo"

int pos = 0;        // variable to store the servo position
int servopin = 9;   //variable to store servo pin

void setup() {
  myservo.attach(servopin);  // attaches the servo on pin 9 to the servo object
}

void loop() {

  for (int i = 0; i <= 180; i++)
  {
    myservo.write(i);
  }
  
}