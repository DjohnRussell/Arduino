/*
--------------------------- H-Bridge DC-motor----------------------

-look up datasheet.

    Connect pin 1,2EN of the L298N module to digital pin 10 on the Arduino.
    Connect pin 1A of the L298N module to digital pin 9 on the Arduino.
    Connect pin 2A of the L298N module to digital pin 8 on the Arduino.
    Connect the red wire (positive terminal) of the DC motor to pin 1Y of the L298N module.
    Connect the black wire (negative terminal) of the DC motor to pin 2Y of the L298N module.
    Connect pin 5 (GND) of the L298N module to the negative terminal of the battery.
    Connect pin VCC2 of the L298N module to the positive terminal of the battery.
*/



const int enablePin = 10;  // Pin 1 (1,2EN)
const int in1Pin = 9;      // Pin 2 (1A)
const int in2Pin = 8;      // Pin 7 (2A)

void setup() {
  pinMode(enablePin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
}

void motorForward() {
  // Move motor forward
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, LOW);
}

void motorBackword() {
  // Move motor backwords
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, HIGH);
}

void motorStop() {
  // Move motor backwords
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, LOW);
}
void loop() {
  // Enable motor driver
  digitalWrite(enablePin, HIGH);


}
