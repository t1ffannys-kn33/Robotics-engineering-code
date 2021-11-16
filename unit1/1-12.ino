
const int slidePin = A3;
const int micPin = A2;	

const int ledPins[3] = {9, 10, 11};


void setup()
{
	pinMode(slidePin, INPUT);
	pinMode(micPin, INPUT);
	

	for (int i=0; i<3; i++)
	{

		pinMode(ledPins[i], OUTPUT);
	}
}

void loop()
{
	int maximum = analogRead(slidePin);	
	int micReading = analogRead(micPin);
	
	for (int i=0; i<3; i++)
	{
		if (micReading > ((maximum / 3) * (i+1)))
		{
			digitalWrite(ledPins[i], HIGH);	
		}
		else
		{
			digitalWrite(ledPins[i], LOW);
		}
	}
}