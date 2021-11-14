const int dark = 300;
const int middledark = 700;

void setup()
{
    pinMode(A1, INPUT);

    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);

    Serial.begin(9600);
}

void loop()
{
    int lightValue = analogRead(A1);

    Serial.println(lightValue);

    if ((lightValue <= dark) && (lightValue >= middledark))
    {
        analogWrite(9, 229);
        analogWrite(10, 235);
        analogWrite(11, 52);
    }
    else if (lightValue <= middledark)
    {
        analogWrite(9, 55);
        analogWrite(10, 235);
        analogWrite(11, 55);
    }

    else
    {
        analogWrite(9, 55);
        analogWrite(10, 55);
        analogWrite(11, 235);
    }

    delay(100);
}
