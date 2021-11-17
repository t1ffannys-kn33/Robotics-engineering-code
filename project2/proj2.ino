int pintouse = 9;
bool isactive = false;

void setup()
{
    Serial.begin(9600);

    pinMode(12, INPUT);
    pinMode(2, INPUT);
    pinMode(A1, INPUT);

    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
}

void loop()
{

    // this whole section is responsiple
    // for checking if the button is pressed and then incrementing the variable if it is.
    // it also does bounds checking
    if (digitalRead(12) == HIGH)
    {

        pintouse++;
        if (pintouse == 12) // make sure the variable doesnt get too high
        {
            pintouse = 9;
        }
    }

    // the decision to turn on the light is based on the bool isactive
    // this makes the switch change the value of the variable
    if (digitalRead(2) == HIGH)
    {
        isactive = true;
    }
    else
    {
        isactive = false;
    }

    if (isactive)
    {
        analogWrite(pintouse, analogRead(A1));
    }
    else
    {
        //turning off all the lights if the switch is off
        analogWrite(9, 0);
        analogWrite(10, 0);
        analogWrite(11, 0);
        analogWrite(12, 0);
    }

    delay(100);
}