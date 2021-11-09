bool LEDstate = false;

void setup()
{
    pinMode(13, OUTPUT);
    pinMode(2, INPUT);
    Serial.begin(9600);
}

void loop()
{
    if (digitalRead(2) == HIGH) {


        LEDstate = !LEDstate;
if  (LEDstate == true) {
        Serial.println('the light is on!');
}
else {
        Serial.println('the light is off!');
}
    }
if  (LEDstate == true) {
    digitalWrite(13, HIGH);
}
else {
    digitalWrite(13, LOW);
}

}