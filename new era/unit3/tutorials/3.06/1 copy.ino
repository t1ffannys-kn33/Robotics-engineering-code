#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

// declare an array of characters with 4 rows and 3 columns
byte hexaKeys[ROWS][COLS] = {
    {1, 2, 3, 2},
    {4, 5, 6, 4},
    {7, 8, 9, 1},
    {9, 8, 15, 9}};

void setup()
{
  Serial.begin(9600);
}

void loop()
{

  for (int i = 0; i < 4; i++)
  {
    for (int x = 0; x < 4; x++)
    {
      Serial.println(2 * hexaKeys[i][x]);
    }
  }
}