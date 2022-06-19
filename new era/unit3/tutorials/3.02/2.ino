int timedelay = 1000;
char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
String input;

void setup() {
    Serial.begin(9600);
 for (int pin=2; pin<9; pin++){
  pinMode(pin, OUTPUT);
 }
}

void loop() {
    while(!Serial.available()) {}
    input = Serial.readString();

    PushNumToSSD(input[0]);
    delay(500);

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