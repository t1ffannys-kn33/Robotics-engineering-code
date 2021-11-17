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
        if (slidevalue < brightness) // if the light is higher then the slide
        {
            analogWrite(activePin, (brightness / 3)); // light the active light accordingly
        }
    }
    else // turn off the lights when not on
    {
        analogWrite(9, 0);
        analogWrite(10, 0);
        analogWrite(11, 0);
    }
}