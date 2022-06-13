String thing;
int age;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println("Knock knock");
  while (Serial.available() == 0)
  {
  }
  thing = Serial.readString();
  if (thing == "Whos there" || "whos there")
  {
    Serial.println("tank");
  }
  else
  {
    Serial.println("your not dioing it right!!");
  }

  while (Serial.available() == 0)
  {
  }
  thing = Serial.readString();
  if (thing == "Tank who" || "tank who")
  {
    Serial.println("you welcome");
  }
  else
  {
    Serial.println("your not dioing it right!!");
  }
}