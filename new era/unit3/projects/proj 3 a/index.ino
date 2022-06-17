// Tomas Turbek
// RGB NIGHTLIGH

int photoresistpin = A2;
int buttonPin = 4;

const int blupin = A3;
const int redpin = A4;
const int ylwpin = A5;

const int potentpin = A7;

String selectedcolor;

void setup()
{
    Serial.begin(9600);
    pinmode(photoresistpin, INPUT);
    pinmode(potentpin, INPUT);

    pinmode(blupin, OUTPUT);
    pinmode(redpin, OUTPUT);
    pinmode(ylwpin, OUTPUT);

    pinmode(buttonPin, INPUT)
}

int calcLed(int pin)
{
    if (selectedcolor[0] == 'b')
    {
        if (pin == 0)
        {
            return (map(analogRead(potentpin), 0, 1023, 0, 255));
        }
        else
        {
            return 0;
        }
    }
    if (selectedcolor[0] == 'r')
    {
        if (pin == 1)
        {
            return (map(analogRead(potentpin), 0, 1023, 0, 255));
        }
        else
        {
            return 0;
        }
    }
    if (selectedcolor[0] == 'y')
    {
        if (pin == 2)
        {
            return (map(analogRead(potentpin), 0, 1023, 0, 255));
        }
        else
        {
            return 0;
        }
    }
}

void turnOffAllLeds()
{
    analogWrite(blupin, 0);
    analogWrite(redpin, 0);
    analogWrite(ylwpin, 0);
}

void loop()
{
    if (analogRead(photoresistpin) < 500)
    {
        analogWrite(blupin, calcLed(0));
        analogWrite(redpin, calcLed(1));
        analogWrite(ylwpin, calcLed(2));
    }
    else
    {
        turnOffAllLeds();
    }
    if (digitalRead(buttonPin) == HIGH)
    {
        Serial.println("which color would you like");
        Serial.println("r for red b for blue y for yellow");
        do
        {
        } while (!Serial.available());
        selectedcolor = Serial.readString();
    }
}