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
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(A3, INPUT);


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
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
        digitalWrite(12, LOW);  
        Serial.println("even, so i will light the blue led");
  
        }
    if (phoneNumber.toInt() % 2 == 1)
    {
        Serial.println("odd, so i will light the red led");
        digitalWrite(10, HIGH);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);    }
    if (phoneNumber[9] == '0')
    {
        Serial.println("zero, so i will light the green led");
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, HIGH);
    }
    for (int i = 0; i < 10; i++)
    {
        PushNumToSSD(phoneNumber[i]);
        delay(analogRead(potentpin));
        // range is 0 to 1023, so thats a nice way to controll how fast to show the nums
    }
    //turn everything off for next time
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
                WriteSegments(0, 0, 0, 0, 0, 0, 0);

        }



void WriteSegments(int aVal, int bVal, int cVal, int dVal, int eVal, int fVal, int gVal)
{
    digitalWrite(2, aVal);
    digitalWrite(3, bVal);
    digitalWrite(4, cVal);
    digitalWrite(5, dVal);
    digitalWrite(6, eVal);
    digitalWrite(7, fVal);
    digitalWrite(8, gVal);
}

void PushNumToSSD(char number)
{
    switch (number)
    {
    case '0':
    {
            WriteSegments(1, 1, 1, 1, 1, 1, 0);

    break;
    }
    case '1':
    {
    WriteSegments(0, 1, 1, 0, 0, 0, 0);

        break;

    }
    case '2':
    {
            WriteSegments(1, 1, 0, 1, 1, 0, 1);


    break;

    }
    case '3':
    {
        WriteSegments(1, 1, 1, 1, 0, 0, 1);

                break;

    }
    case '4':
    {
        WriteSegments(0, 1, 1, 0, 0, 1, 1);
        break;
    }
    case '5':
    {
        WriteSegments(1, 0, 1, 1, 0, 1, 1);
                break;

    }
    case '6':
    {
        WriteSegments(1, 0, 1, 1, 1, 1, 1);
                break;

    }
    case '7':
    {
        WriteSegments(1, 1, 1, 0, 0, 0, 0);
                break;

    }
    case '8':
    {
        WriteSegments(1, 1, 1, 1, 1, 1, 1);
                break;

    }
    case '9':
    {
        WriteSegments(1, 1, 1, 1, 0, 1, 1);
                break;

    }
    }
}