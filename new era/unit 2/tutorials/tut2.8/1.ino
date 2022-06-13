#include <Servo.h>  //loads servo command library

Servo myservo;      // Declare servo variable "myservo"

int pos = 0;        // variable to store the servo position
int servopin = 9;   //variable to store servo pin

void setup() {
  myservo.attach(servopin);  // attaches the servo on pin 9 to the servo object
}

void loop() {

  //the following script hard codes positions for the servo to move to.
  myservo.write(0);
  delay(2000);

  myservo.write(45);
  delay(2000);

  myservo.write(90);
  delay(2000);

  myservo.write(135);
  delay(2000);

  myservo.write(180);
  delay(2000);
}