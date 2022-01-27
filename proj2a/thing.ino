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
    delay(1000);
    digitalWrite(whiteledpin, LOW);
    delay(1000);
  }
}



void updateleds(int redvalue, int bluvalue, int grnvalue){
  analogWrite(redledpin, redvalue);
  analogWrite(bluledpin, bluvalue);
  analogWrite(grnledpin, grnvalue);
}

void loop(){
    digitalWrite(whiteledpin, HIGH); // make sure the led is off
    if(digitalRead(buttonpin)==LOW){
      delay(1);
    }

    digitalWrite(whiteledpin, LOW); // make sure the led is off

    for (int i = 0; i < 255; i++) {
      updateleds(0, 255-i, i); // g to b
      delay(10);
    }
    blink(2);

    for (int i = 0; i < 255; i++) {
      updateleds(i, 0, 255-i); // b to r
      delay(10);
    }
    blink(1);
    
    for (int i = 0; i < 255; i++) {
      updateleds(255-i, i, 0); // r to g
      delay(10);
    }
    blink(3);


    
}