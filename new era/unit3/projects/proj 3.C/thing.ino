// Tomas Turbek
// Proj 3C
// 4/24/22
#include <LiquidCrystal.h>
#include <Keypad.h>
const String secret = "c01d";

char keypadlayout[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'#', '0', '*', 'D'}};

byte rowpins[4] = {12, 11, 10, 9};
byte colpins[4] = {8, 7, 6, 5};

Keypad customKeypad = Keypad(makeKeymap(keypadlayout), rowpins, colpins, 4, 4);
// thats all the stuff for the keypad, time for the LCD

const int RS = 11, EN = 12, D4 = 2, D5 = 3, D6 = 4, D7 = 5;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
//

const int redpin = 10, blupin = 11, yellowpin = 12;

String guess = "";

void blinkLed(int pin)
{
    digitalWrite(pin, HIGH);
    delay(1000);
    digitalWrite(pin, LOW);
}

bool checkiscorrect()
{
    if (strcmp(guess.c_str(), secret.c_str()))
    {
        return true;
    }
}

void setup()
{
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);

    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("guessing game");
}

void loop()
{
    char whatspressed = customKeypad.getKey();

    if (whatspressed)
    {
        if (whatspressed == keypadlayout[4][1]) // compare w the secret
        {
            if (checkiscorrect()) // the guess is correct!
            {

            }
            else // guess is incorrect
            {
                blinkLed(redpin);
                guess = "";
            }
        }
        if (whatspressed == keypadlayout[3][0]) // clear the string
        {
            guess = ""; // reset the guess
        }
        else // append to the guess
        {
            guess.concat(whatspressed);
        }
    }
}