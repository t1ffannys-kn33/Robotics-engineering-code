#define redledpin 3
#define bluledpin 5
#define grnledpin 6
#define whiteledpin 2
#define buttonpin 7

int rgbledvalues[] = {0, 0, 0};

void setup()
{
  Serial.begin(9600);
}

void blink(int howmanytimes) {
  for(int i = 0; i <= howmanytimes; i++){
    digitalWrite(whiteledpin, HIGH);
    delay(500);
    digitalWrite(whiteledpin, LOW);
    delay(500);
  }
}

void fade(int fromvalues[2], int tovalues[2]){


  int incrementby[] = {
      (fromvalues[0] - tovalues[0])/10,
      (fromvalues[1] - tovalues[1])/10,
      (fromvalues[2] - tovalues[2])/10,
  };
  // this array holds the diffrances between the from and to colors
  // we will use this to change the led each tick

  

}

void updateleds(int redvalue, int bluvalue, int grnvalue){
  analogWrite(redledpin, redvalue);
  analogWrite(bluledpin, bluvalue);
  analogWrite(grnledpin, grnvalue);
}

void loop()
{
    do{

    } while (digitalRead(buttonpin)==LOW);
    digitalWrite(whiteledpin, LOW); // make sure the led is off

    for (int i = 0; i < 255; i++) {
      updateleds(0, (255-i), i); // b to g
      delay(10);
    }
    

}