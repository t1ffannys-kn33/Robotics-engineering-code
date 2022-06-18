// Tomas Turbek
// liquid crystal

#include <LiquidCrystal.h>

// LCD pins <--> Arduino pins
const int RS = 11, EN = 12, D4 = 2, D5 = 3, D6 = 4, D7 = 5;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

String userinput
void setup()
{
  lcd.begin(16, 2); // set up number of columns and rows

  Serial.begin(9600);

}


void loop()
{
  Serial.println("type what you want printed, under 16 chars")
  while (!Serial.available()) { }
  userinput = Serial.readString();
  lcd.setCursor(0, 0);
  lcd.print(userinput);
}