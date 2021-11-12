int pincount = 9;

void setup()
{
    pinMode(12, INPUT);
    Serial.begin(9600);
    pinMode(2, INPUT);
}

void loop()
{

    pincount = (pincount % 3) + 9;

    if (digitalRead(12) == HIGH)
    {
        pincount++;
    }

    delay(100);
}