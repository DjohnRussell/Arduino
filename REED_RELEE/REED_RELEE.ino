/*
------------ Reed relee ---------------
 The reed relee one side to 5v th eother side to pin 8 and 220 -> GND
 Led positve side to pin(1-13) in this case we are useing two leds pin 4 - 7 
*/

const int GREEN = 4;
const int RED = 7;
const int reedPin = 8;

void setup() {
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(reedPin, INPUT);
}



void loop() {
  //blinkTest(GREEN, RED);
  int reedState = digitalRead(reedPin);

  
  if (reedState == HIGH) {
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    
  } else {
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED, LOW);
  }
}

