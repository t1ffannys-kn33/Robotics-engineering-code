void setup()
{
	pinMode(4, OUTPUT);	// Set pin D4 as an OUTPUT
	pinMode(5, OUTPUT);	// Set pin D5 as an OUTPUT
	pinMode(7, OUTPUT);	// Set pin D7 as an OUTPUT
	pinMode(8, OUTPUT);	// Set pin D8 as an OUTPUT

}

// The loop function will be used to blink each of our LEDs in succession.
void loop()
{
	digitalWrite(4, HIGH);	      // Turn the D4 LED on (HIGH)
	delay(500);				// Wait half a second (500 ms)
	digitalWrite(4, LOW);	      // Turn the D4 LED off (LOW)
	delay(500);				// Wait half a second (500 ms)
  
	digitalWrite(5, HIGH);	      // Turn the D5 LED on (HIGH)
	delay(500);				// Wait half a second (500 ms)
	digitalWrite(5, LOW);	      // Turn the D5 LED off (LOW)
	delay(500);				// Wait half a second (500 ms)
	
	digitalWrite(6, HIGH);	      // Turn the D6 LED on (HIGH)
	delay(500);				// Wait half a second (500 ms)
	digitalWrite(6, LOW);	      // Turn the D6 LED off (LOW)
	delay(500);				// Wait half a second (500 ms)
	
	digitalWrite(7, HIGH);	      // Turn the D7 LED on (HIGH)
	delay(500);				// Wait half a second (500 ms)
	digitalWrite(7, LOW);	      // Turn the D7 LED off (LOW)
	delay(500);				// Wait half a second (500 ms)
	
	digitalWrite(8, HIGH);	      // Turn the D8 LED on (HIGH)
	delay(500);				// Wait half a second (500 ms)
	digitalWrite(8, LOW);	      // Turn the D8 LED off (LOW)
	delay(500);				// Wait half a second (500 ms)
}