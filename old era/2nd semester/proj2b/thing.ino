#define redpin 10
#define blupin 11
#define grnpin 12

#define abuzz 4
#define pbuzz 3

#define buttonpin 7

int c = 262, d = 294, e = 330, f = 349;
int g = 392, a = 440, b = 494, C = 523;

int yankeedoodle[] = {c,c,d,e,c,e,d,};


String questions[3] = {"Swift won her first grammy for which song?",
                       "Swifts cats last name starting with Meredith", "Swifts alma mater is"};
String answers[3] = {"White Horse", "Grey", "Notre Dame"};

String input;

void setup()
{
  pinMode(7, INPUT);

  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  Serial.begin(9600);
}
// 1 is red 2 is grn 3 is blu
//default is get rid of color
void changeledcolor(int x){
  switch (x)
  {
  case 1:
    digitalWrite(redpin, 1);
    digitalWrite(grnpin, 0);
    digitalWrite(blupin, 0);
    break;
  case 2:
    digitalWrite(redpin, 0);
    digitalWrite(grnpin, 1);
    digitalWrite(blupin, 0);
    break;
  case 3:
    digitalWrite(redpin, 0);
    digitalWrite(grnpin, 0);
    digitalWrite(blupin, 1);
    break;
  default:
    digitalWrite(redpin, 0);
    digitalWrite(grnpin, 0);
    digitalWrite(blupin, 0);
    break;
  }

}

void buzz(bool iscorrect) {
  if (iscorrect == false) {
    digitalWrite(abuzz, HIGH);
    delay(500);
    digitalWrite(abuzz, LOW);
  }
  else
  {
    for(int i=0; i<7; i++){
      tone(pbuzz, yankeedoodle[i]);
      delay(100);
      noTone(pbuzz);
      delay(100);
    }
  }
}

void loop()
{
  do{
    1 + 1;
  } while (digitalRead(buttonpin) == LOW);

  for (int i = 0; i < 3; i++)
  {
      Serial.println(questions[i]);
      changeledcolor(3);
      while (Serial.available()<2){}
      input = Serial.readString();
     if(input == answers[i]){
       changeledcolor(2);
       buzz(true);
       changeledcolor(5);
     }
     else{
      changeledcolor(1);
      buzz(false);
      changeledcolor(3);
     }
  }
  




}