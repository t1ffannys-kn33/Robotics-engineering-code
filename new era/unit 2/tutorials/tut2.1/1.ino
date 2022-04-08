// Tomas Turbek
// Title (Name of Tutorial/Project)
// Date Started - Date Completed

void setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

}

void blink(int whichpin){
    //function to blink the 
  digitalWrite(whichpin, HIGH);
  delay(1000);
  digitalWrite(whichpin, LOW);
  delay(1000);
}


void loop(){ 
	blink(4);
  	blink(5);
  	blink(6);
  	blink(7);
}