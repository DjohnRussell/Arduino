#include <Servo.h>
/*
----------------------- Description------------------------------
4 photo resistors
  - one led to 5V
  - the other leg to digitalPin (A0, A1, A2 and A3), and 10K ohm resister -> GND
  - servo wires red to 5V, black to GND and white to pin 9.
  - infront of the servi conection add a capacitor 100 uf..


*/
const int numPhotoresistors = 4;
const int servoPin = 9;

int photoValueA0 = 0;
const int photoPin_A0 = A0;

int photoValueA1 = 0;
const int photoPin_A1 = A1;

int photoValueA2 = 0;
const int photoPin_A2 = A2;

int photoValueA3 = 0;
const int photoPin_A3 = A3;

Servo myServo;



void setup() {
   myServo.attach(servoPin); 
   Serial.begin(9600);
}

void loop() {
  
  photoValueA0 = analogRead(photoPin_A0);
  photoValueA1 = analogRead(photoPin_A1);
  photoValueA2 = analogRead(photoPin_A2);
  photoValueA3 = analogRead(photoPin_A3);

  //Angels based on the value from the sensors (Tested angles to match the sensors placemeant).

  // A3
  if(photoValueA0 > photoValueA1 && photoValueA0 > photoValueA2 && photoValueA0 > photoValueA3 ) {
    myServo.write(160);
  }
  // A2
  else if(photoValueA1 > photoValueA0 && photoValueA1 > photoValueA2 && photoValueA1 > photoValueA3 ) {
    myServo.write(110);
  }
  // A1
  else if (photoValueA2 > photoValueA0 && photoValueA2 > photoValueA3 && photoValueA2 > photoValueA1) {
    myServo.write(57);
  }
  // A0
  else if (photoValueA3 > photoValueA0 && photoValueA3 > photoValueA1 && photoValueA3 > photoValueA2) {
    myServo.write(19); 
  }
  
}

 
