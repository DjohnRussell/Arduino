#include <Servo.h>
/*
----------------------- Description------------------------------
4 photo resistors
  - one led to 5V
  - the other leg to digitalPin (A0, A1, A2 and A3), and 10K ohm resistor -> GND
  - servo wires red to 5V, black to GND, and white to pin 9.
  - in front of the servo connection add a capacitor 100 uF..

  There is also a button that will use an interrupt, so no matter what, we can press the button and it will return to the start position.
*/

const int numPhotoresistors = 4;
const int servoPin = 9;

int photoValueA0 = 0;
const int photoPin_A0 = A0;

int photoValueA1 = 0;
const int photoPin_A1 = A1;

int photoValueA2 = 0;
const int photoPin_A2 = A2;

const int returnBtn = 2;
int btnState;

Servo myServo;

void setup() {
   myServo.attach(servoPin); 
   pinMode(returnBtn, INPUT_PULLUP);
   // Interrupt - we will use pin 2 as it's one of the pins that support interrupts on Arduino UNO.
   attachInterrupt(digitalPinToInterrupt(returnBtn), btnISR, FALLING);
   Serial.begin(9600);
}

// Function to check the highest int value, which will be called in the loop.
// The int values that will be passed to it as params are the read value of the photoresistors.
void highesValue(int valueOne, int valueTwo, int valueThree) {
  if (valueOne > valueTwo && valueOne > valueThree) {
    myServo.write(90);
  }
  else if (valueTwo > valueOne && valueTwo > valueThree) {
    myServo.write(60);
  }
  else if (valueThree > valueOne && valueThree > valueTwo) {
    myServo.write(30);
  }
}

// Interrupt service routine function.
void btnISR() {
  myServo.write(60); // Set the servo to a specific angle when the button is pressed
}

void loop() {
  btnState = digitalRead(returnBtn); 
  photoValueA0 = analogRead(photoPin_A0);
  photoValueA1 = analogRead(photoPin_A1);
  photoValueA2 = analogRead(photoPin_A2);
  highesValue(photoValueA0, photoValueA1, photoValueA2);
}
