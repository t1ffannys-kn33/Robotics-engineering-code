// Tomas Turbek
//i wrote this code to get a good grade on unit one summarative assesment
//i wrote it really late at night
//the program is supposed to let the user pick an input on the digital sandbox
//then view the output of that 

int buttonpin = 12;
int selectedpin = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT); // all the analog things to read from

  pinMode(5, OUTPUT); // the one led that gets outputted to

  pinMode(12, INPUT);// button and switch
  pinMode(2, INPUT);

  digitalWrite(4, HIGH); // this does the light show
  delay(200);
  digitalWrite(8, HIGH);
  delay(200);
  digitalWrite(5, HIGH);
  delay(200);
  digitalWrite(7, HIGH);
  delay(200);
  digitalWrite(6, HIGH);
  delay(1000);
  digitalWrite(6, LOW);
  delay(200);
  digitalWrite(7, LOW);
  delay(200);
  digitalWrite(5, LOW);
  delay(200);
  digitalWrite(8, LOW);
  delay(200);
  digitalWrite(4, LOW);
  delay(200);
}

void loop()
{
  // first of all, print the greeting
  Serial.println("Hi! use the push button to pick which sensor to use!");
  do{
    if (digitalRead(12) == HIGH){//if the button is on, increment
      selectedpin++;
      Serial.print("youve picked pin ");
      Serial.println(selectedpin);
      if (selectedpin == 4){ // checking oob
        selectedpin = 0;
      }
      delay(100);// make sure the user has time to react
    }
  } while (digitalRead(2) == LOW); //do that stuff while the switch is off


  do{
    int analogReadResult = analogRead(selectedpin);
    Serial.print("the value of pin ");
    Serial.print(selectedpin);
    Serial.print(" is ");

    if (analogReadResult < 255) {
      Serial.print("pretty low, the exact value is ");
    }
    if ((analogReadResult >= 255)&&(analogReadResult <=511)) {
      Serial.print("not too high not to low, the exact value is ");
    }
    if ((analogReadResult > 511)&&(analogReadResult <=767)) {
      Serial.print("getting pretty high, the exact value is ");
    }
    if (analogReadResult>767) {
      Serial.print("about as high as it gets, the exact value is ");
    }

    Serial.println(analogReadResult);
    analogWrite(5, (analogReadResult / 5) * 1.2); 
    //this converts the analogRead results 0-1023 to a value that works for analogWrite 0-255
    delay(50);
  } while (digitalRead(2) == HIGH); // do that stuff while the switch is still on
  
}
