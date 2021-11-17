void setup()
{
    pinMode(2, HIGH);
}

void loop()
{
    bool isActive = (digitalRead(2)==HIGH);
}