#include <Servo.h>  //loads servo command library

Servo myservo;      // Declare servo variable "myservo"

int pos = 0;        // variable to store the servo position
int servopin = 9;   //variable to store servo pin

void setup() {
  myservo.attach(servopin);  // attaches the servo on pin 9 to the servo object
  pinMode(potentPin, INPUT);

}

void loop() {
  myservo.write(map(analogRead(potentPin), 0, 1023, 0, 180));
  // oneliners ftw
}