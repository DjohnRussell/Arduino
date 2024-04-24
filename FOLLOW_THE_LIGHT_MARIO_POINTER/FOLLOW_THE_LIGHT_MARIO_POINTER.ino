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


Servo myServo;



void setup() {
   myServo.attach(servoPin); 
   Serial.begin(9600);
}


// Making a function to check the hights int value, witch will be called in the loop.
// The int values that will be pass to it as params is the read value of the poto resistor.
void highesValue(int valueOne, int valueTwo, int valueThree) {
  if( valueOne > valueTwo && valueOne > valueThree ) {
    myServo.write(90);
  }

  else if(valueTwo > valueOne && valueTwo > valueThree ) {
    myServo.write(60);
  }

  else if (valueThree > valueOne && valueThree > valueTwo ) {
    myServo.write(30);
  }

}

void loop() {
  
  
  photoValueA0 = analogRead(photoPin_A0);
  photoValueA1 = analogRead(photoPin_A1);
  photoValueA2 = analogRead(photoPin_A2);
 

  // Calling the function as writen above, it will also chage angle of the servo to point at the senser with the hights value.
  highesValue(photoValueA0, photoValueA1, photoValueA2);

  /*
  if(photoValueA0 > photoValueA1 && photoValueA0 > photoValueA2 ) {
    myServo.write(90);
  }

  else if(photoValueA1 > photoValueA0 && photoValueA1 > photoValueA2 ) {
    myServo.write(60);
  }

  else if (photoValueA2 > photoValueA0 && photoValueA2 > photoValueA1 ) {
    myServo.write(30);
  }
  */

  
}