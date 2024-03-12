#include <Servo.h>

//the servo motor has three wires(red, white, black)
//red = 5v
//white = digital (13-0)
//black = GND

Servo myServo;

int const potPin = A0;
int angle90 = 90;
int angle30 = 30;
int angle180 = 180;


void setup() {
  myServo.attach(9);

  

}

void loop() {
  //potVal = analogRead(potPin);
  

  myServo.write(angle90);
  delay(2000);
  myServo.write(angle30);
  delay(2000);
  myServo.write(angle180);
  delay(2000);


}
