const int slidePin = A3;
const int micPin = A2;

const int ledPins[3] = {9, 10, 11};

void setup()
{
	pinMode(slidePin, INPUT);
	pinMode(micPin, INPUT);

	for (int i = 0; i < 3; i++)
	{

		pinMode(ledPins[i], OUTPUT);
	}
}

void loop()
{
	int maximum = analogRead(slidePin);
	int micReading = analogRead(micPin);
	if (micReading < (maximum / 3))
	{

		if (micReading < ((maximum / 3)) * 2)
		{

			if (micReading > ((maximum / 3) * 2))
			{
				digitalWrite(9, HIGH);
				goto ending;
			}
			digitalWrite(11, HIGH);
			goto ending;
		}
		digitalWrite(10, HIGH);
	}

ending:
}