// Tomas Turbek
//i wrote this code to get a good grade on unit one summarative assesment
//i wrote it really late at night
//the program is supposed to let the user pick an input on the digital sandbox
//then view the output of that 

int buttonpin = 12;
int selectedpin = 0;
//const int sensorpins[] = { 0, 1, 2, 3 };

void setup()
{
  Serial.begin(9600);
  /*
  for(int i=0; i<=3; i++){
    pinMode(i, OUTPUT);
  }
*/
pinMode(0, OUTPUT);
pinMode(1, OUTPUT);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);

pinMode(5, OUTPUT);

pinMode(12, INPUT);
pinMode(2, INPUT);
}

void loop()
{
  // first of all, print the greeting
  Serial.println("Hi! use the push button to pick which sensor to use!");
  do{
    if (digitalRead(12) == HIGH){
      selectedpin++;
      Serial.println("youve picked pin "+selectedpin);
      if (selectedpin == 4){ // checking oob
        selectedpin = 0;
      }
      delay(100);// make sure the user has time to react
    }
  } while (digitalRead(2) == LOW); //do that stuff while the switch is off


  do{
    int analogReadResult = analogRead(selectedpin);
    Serial.print("the value of pin");
    Serial.print(selectedpin);
    Serial.print("is");
    Serial.print(analogReadResult);
    analogWrite(5, (analogReadResult / 5) * 1.2); 
    //this converts the analogRead results 0-1023 to a value that works for analogWrite 0-255
    delay(50);
  } while (digitalRead(2) == LOW); // do that stuff while the switch is still on
}
//(1023/5)1.2