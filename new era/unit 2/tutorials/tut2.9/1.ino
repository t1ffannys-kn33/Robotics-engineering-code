String thing;
int age;

void setup(){
  Serial.begin(9600);
}

void loop() {
  Serial.println("Enter your thing??");
  while(Serial.available()==0) { }
  thing = Serial.readString();      //readString function collects user’s name
  if (thing == "3.14") {
    Serial.println("nice");
  }
  else {
    Serial.println(":(");
  }

}