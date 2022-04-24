// Tomas Turbek
// Proj 3C
// 4/24/22
#include <LiquidCrystal.h> 
#include <Keypad.h>
const char secret[5] = "1337";

char keypadlayout[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'#','0','*','D'}
};

byte rowpins[ROWS] = {12, 11, 10, 9}; 
byte colpins[COLS] = {8, 7, 6, 5}; 

Keypad customKeypad = Keypad(makeKeymap(keypadlayout), rowpins, colpins, 4, 4); 
// thats all the stuff for the keypad, time for the LCD

const int RS = 11, EN = 12, D4 = 2, D5 = 3, D6 = 4, D7 = 5;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
//

const int redpin = 10, blupin = 11, yellowpin = 12;



void setup() {
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);

    lcd.begin(16, 2); 
    lcd.setCursor(0, 0);
    lcd.print("guessing game");
    
    
}

void loop(){ 

}