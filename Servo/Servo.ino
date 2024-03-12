#include <Servo.h>

Servo myServo;

int const potPin = A0;
int potVal;
int angle;


void setup() {
  myServo.attach(9);
  Serial.begin(9600);

}

void loop() {
  potVal = analogRead(potPin);
  Serial.print("potVal:");
  Serial.print(potVal);

  angle = map(potVal, 0, 1023, 0, 179);
  //To cange this up and dont use a potentimeter, we can aslo give the angel or angels diffrent values and, 
  //programmaticlly move the servo based on this: 90DegAngel = 90; 180DegAngel = 180;, this would also move it!
  Serial.print(", angle: ");
  Serial.print(angle);

  myServo.write(angle);
  delay(15);


}
