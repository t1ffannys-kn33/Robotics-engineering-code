void setup()
{
    pinMode(5, OUTPUT);
}
int counter = 0;
void loop()
{
    analogWrite(5, counter);
    counter++;
    if (counter == 255)
    {
        counter = 0;
    }
}