#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4; 

//declare an array of characters with 4 rows and 3 columns
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

//assign the row and column pins on the Arduino
byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

//declare a keypad that aligns the hexakey matrix with the pin arrays
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
}

void loop(){

  //sets variable customKey to a reading from the Keypad
  char customKey = customKeypad.getKey();
  
  //if the keypad is pressed, print the pressed key
  if (customKey){
    Serial.println(customKey);
  }
}