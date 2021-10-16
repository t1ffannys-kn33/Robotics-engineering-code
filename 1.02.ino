void setup()
{
    pinMode(5, OUTPUT);
}

void loop()
{

    analogWrite(5, 100);
    delay(1000);
    analogWrite(5, 254);
    delay(1000);
}