// Tomas Turbek
// liquid crystal

#include <LiquidCrystal.h>

// LCD pins <--> Arduino pins
const int RS = 11, EN = 12, D4 = 2, D5 = 3, D6 = 4, D7 = 5;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup()
{
  lcd.begin(16, 2); // set up number of columns and rows

  lcd.setCursor(0, 0);         // move cursor to   (0, 0)
  lcd.print("What did the");        // print message at (0, 0)
  lcd.setCursor(2, 1);         // move cursor to   (2, 1)
  lcd.print("fish say when he"); // print message at (2, 1)
  delay(1000);

  lcd.setCursor(0, 0);         // move cursor to   (0, 0)
  lcd.print("swam into awall?");        // print message at (0, 0)
  lcd.setCursor(2, 1);         // move cursor to   (2, 1)
  lcd.print("dam"); // print message at (2, 1)
  delay(1000);



  lcd.setCursor(0, 0);         // move cursor to   (0, 0)
  lcd.print("every calenders");        // print message at (0, 0)
  lcd.setCursor(2, 1);         // move cursor to   (2, 1)
  lcd.print("days arenumbered"); // print message at (2, 1)
  delay(1000);



  lcd.setCursor(0, 0);         // move cursor to   (0, 0)
  lcd.print("decimals have");        // print message at (0, 0)
  lcd.setCursor(2, 1);         // move cursor to   (2, 1)
  lcd.print("a point"); // print message at (2, 1)
  delay(1000);

}


void loop()
{
}