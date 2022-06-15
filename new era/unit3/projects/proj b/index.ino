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
    if ((phoneNumber.toInt() % 2 == 0) && (phoneNumber[9] != '0'))
    {
        // note: ^^ needs to be single quoptes as we want to compare chars
        // not const char pointers
        Serial.println("even, so i will light the blue led");
        digitalWrite(redLedPin, LOW);
        digitalWrite(bluLedPin, HIGH);
        digitalWrite(grnLedPin, LOW);    }
    if (phoneNumber.toInt() % 2 == 1)
    {
        Serial.println("odd, so i will light the red led");
        digitalWrite(redLedPin, HIGH);
        digitalWrite(bluLedPin, LOW);
        digitalWrite(grnLedPin, LOW);    }
    if (phoneNumber[9] == '0')
    {
        Serial.println("zero, so i will light the green led");
        digitalWrite(redLedPin, LOW);
        digitalWrite(bluLedPin, LOW);
        digitalWrite(grnLedPin, HIGH);
    }
    for (int i = 0; i < 10; i++)
    {
        PushNumToSSD(phoneNumber[i]);
        delay(analogRead(potentpin));
        // range is 0 to 1023, so thats a nice way to controll how fast to show the nums
    }
        digitalWrite(redLedPin, LOW);
        digitalWrite(bluLedPin, LOW);
        digitalWrite(grnLedPin, LOW);}



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