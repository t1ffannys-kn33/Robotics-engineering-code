// Joseph Isaacs
// Sec 62
// 2.A
// Description: Functional RGB
// 1/20 - 1/20


// SPARKFUN PINS LAYOUT - I did this so i can just copypaste
namespace pins {

    // digital inputs
    static const int slideSwitch = 2;
    static const int button = 12;
    
    // digital outputs
    static const int whiteLEDS[5] = {4, 5, 6, 7, 8};
    static const int RGBLEDS[3] = {9, 10, 11};
      static const int indicLED = 13;
    
    // analog inputs
    static const int thermistor = 0;
    static const int microphone = 2;
    static const int slidePotentiometer = 3;
    static const int photoresistor = 1;
   
    // analog outputs

    void initialize() {
      // digital inputs
      pinMode(slideSwitch, INPUT);
      pinMode(button, INPUT);

      // digital outputs
      for (int i = 0; i < 5; i++)
        pinMode(whiteLEDS[i], OUTPUT);
      for (int i = 0; i < 3; i++)
        pinMode(RGBLEDS[i], OUTPUT);
      pinMode(indicLED, OUTPUT);

      // analog inputs
      pinMode(thermistor, INPUT);
      pinMode(microphone, INPUT);
      pinMode(slidePotentiometer, INPUT);
      pinMode(photoresistor, INPUT);
    }
}
// -------------------------------------------------------


void writeRGB(int,int,int);
void blinkTimes(int, int);

void setup() {
  Serial.begin(9600);
  pins::initialize();
}

int indic = 8;    // substitutes for pins::indicLED

void loop() {
  Serial.println("Loop");
 
  if (digitalRead(pins::button)) {
    Serial.println("pressed");
    
    blinkTimes(indic, 1); // R->G
    Serial.println("Fading R->G");
    for (int i = 0; i < 255; i++) {
      writeRGB(255-i, i, 0);
      delay(10);
    }
    delay(500);

    blinkTimes(indic, 2); // G-B
    Serial.println("Fading G->B");
    for (int i = 0; i < 255; i++) {
      writeRGB(0, 255-i, i);
      delay(10);
    }
    delay(500);

    blinkTimes(indic, 3); // B-R
    Serial.println("Fading B->R");
    for (int i = 0; i < 255; i++) {
      writeRGB(i, 0, 255-i);
      delay(10);
    }
    delay(500);
  }
 
  delay(10);
}

void writeRGB(int r, int g, int b) {
      // simply analogWrites the arguments into the RGB LED
      int M = map(analogRead(pins::slidePotentiometer),0,1024,0,255);
    analogWrite(pins::RGBLEDS[0], min(r,M));
      analogWrite(pins::RGBLEDS[1], min(g,M));
      analogWrite(pins::RGBLEDS[2], min(b,M));
}    

void blinkTimes(int L, int times) {
      // blink a pin a number of times
      for (int i = 0; i < times; i++) {
        digitalWrite(L, HIGH);
        delay(300);
          digitalWrite(L, LOW);
          delay(300);
      }
}