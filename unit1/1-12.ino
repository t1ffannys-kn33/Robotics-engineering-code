
const int slidePin = A3;
const int micPin = A2;	

const int ledPins[5] = {4, 5, 6, 7, 8};


void setup()
{
	pinMode(slidePin, INPUT);
	pinMode(micPin, INPUT);
	

	for (int i=0; i<5; i++)
	{

		pinMode(ledPins[i], OUTPUT);
	}
}

void loop()
{
	int maximum = analogRead(slidePin);	
	int micReading = analogRead(micPin);
	
	for (int i=0; i<5; i++)
	{
		if (micReading > ((maximum / 5) * (i+1)))
		{
			digitalWrite(ledPins[i], HIGH);	
		}
		else
		{
			digitalWrite(ledPins[i], LOW);
		}
	}
}