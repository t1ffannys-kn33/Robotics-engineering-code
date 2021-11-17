int activePin = 9;
int outputBrightness = 0;
void setup()
{
    pinMode(2, INPUT);

    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
}

void loop()
{
    bool isActive = (digitalRead(2) == HIGH); // sets the isActive to true if the switch is on

    // this bit handles incrementing the pin when the button is pressed
    // it also makes sure it doesnt get too high
    if (digitalRead(12) == HIGH)
    {
        activePin++;
        if (activePin == 12)
        {
            activePin = 9;
        }
    }

    if (isActive)
    {
        int brightness = analogRead(A1);
        int slidevalue = analogRead(A3);
        if (slidevalue < brightness)
        {
            analogWrite(activePin, (brightness/3))
        }
    }
}