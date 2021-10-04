int count = 0;  // variable to count the number of loops

void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()  {
  digitalWrite(13, digitalRead(12));  
  // Turn on LED on D13 based on button

  analogWrite(5, 255 - (analogRead(A3) / 4)); 
  // As you move the slider, LED on D6 will go down.

  analogWrite(6, analogRead(A3) / 4);     
  // As you move the slider, LED on D5 goes up.


  /* Control the RGB LED based on Temp, Light, and Sound */
  analogWrite(9, analogRead(A0) / 4);   // Tie Temp to the RED value
  analogWrite(10, analogRead(A1) / 4);  // Tie Light to the GREEN value
  analogWrite(11, analogRead(A2) / 4);  // Tie Sound to the BLUE value


  Serial.print("Count = ");   // Text
  Serial.print(count);        // Display the variable count
  Serial.print(" -- Slider = ");  // Display out text
  Serial.println(analogRead(A3)); // Display out the value of the slider
  // There's a lot going on in this code. Don't worry
  //if you don't understand any of it.  We'll get to
  // all of that in our 12 activities.

  count = count + 1;
}