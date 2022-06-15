// Tomas Turbek

String phoneNumber;
int potentpin = A3;
int redLedPin = 10;
int bluLedPin = 11;
int grnLedPin = 12;

int SSaPin = 2;
int SSbPin = 3;
int SScPin = 4;
int SSdPin = 5;
int SSePin = 6;
int SSfPin = 7;
int SSgPin = 8;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.println("enter a phone number");
    while (Serial.available() == 0)
    {
    }
    phoneNumber = Serial.readString();
    Serial.println("your number is ");
    if (phoneNumber[9] == '2' || '4' || '6' || '8')
    {
        // note: ^^ needs to be single quoptes as we want to compare chars
        // not const char pointers
        Serial.println("even, so i will light the blue led");
        turnOnLeds(1);
    }
    if (phoneNumber[9] == '1' || '3' || '5' || '7' || '9')
    {
        Serial.println("odd, so i will light the red led");
        turnOnLeds(0);
    }
    if (phoneNumber[9] == '0')
    {
        Serial.println("zero, so i will light the green led");
        turnOnLeds(2);
    }
    for (int i = 0; i < 10; i++)
    {
        PushNumToSSD(phoneNumber[i]);
        delay(analogRead(potentpin));
        // range is 0 to 1023, so thats a nice way to controll how fast to show the nums
    }
    turnOnLeds(3);
}

void turnOnLeds(int input)
{
    // 0 for red 1 for blue 2 for green. 3 for all off
    switch (input)
    {
    case 0:
    {
        digitalWrite(redLedPin, HIGH);
        digitalWrite(bluLedPin, LOW);
        digitalWrite(grnLedPin, LOW);
    }
    case 1:
    {
        digitalWrite(redLedPin, LOW);
        digitalWrite(bluLedPin, HIGH);
        digitalWrite(grnLedPin, LOW);
    }
    case 2:
    {
        digitalWrite(redLedPin, LOW);
        digitalWrite(bluLedPin, LOW);
        digitalWrite(grnLedPin, HIGH);
    }
    case 3:
    {
        digitalWrite(redLedPin, LOW);
        digitalWrite(bluLedPin, LOW);
        digitalWrite(grnLedPin, LOW);
    }
    }
}

void WriteSegments(int a, int b, int c, int d, int e, int f, int g)
{
    digitalWrite(SSaPin, a);
    digitalWrite(SSaPin, b);
    digitalWrite(SSaPin, c);
    digitalWrite(SSaPin, d);
    digitalWrite(SSaPin, e);
    digitalWrite(SSaPin, f);
    digitalWrite(SSaPin, g);
}

void PushNumToSSD(char number)
{
    switch (number)
    {
    case '0':
    {
        WriteSegments(1, 1, 1, 1, 1, 1, 0);
    }
    case '1':
    {
        WriteSegments(0, 1, 1, 0, 0, 0, 0);
    }
    case '2':
    {
        WriteSegments(1, 1, 0, 1, 1, 0, 1);
    }
    case '3':
    {
        WriteSegments(1, 1, 1, 1, 0, 0, 1);
    }
    case '4':
    {
        WriteSegments(0, 1, 1, 0, 0, 1, 1);
    }
    case '5':
    {
        WriteSegments(1, 0, 1, 1, 0, 1, 1);
    }
    case '6':
    {
        WriteSegments(1, 0, 1, 1, 1, 1, 1);
    }
    case '7':
    {
        WriteSegments(1, 1, 1, 0, 0, 0, 0);
    }
    case '8':
    {
        WriteSegments(1, 1, 1, 1, 1, 1, 1);
    }
    case '9':
    {
        WriteSegments(1, 1, 1, 1, 0, 1, 1);
    }
    }
}