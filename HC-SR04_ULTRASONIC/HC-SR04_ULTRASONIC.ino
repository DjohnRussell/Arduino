/*
------------ HC-SR04 Ultrasonic sensor ------------

Simple circit HC-SR04 4 pins GND -> GND, echo -> 10, trig -> 9, Vcc -> 5V
-------------------------------------------------------------------------
Description
if u are in a "safe" distance its a green light if u get too close the light will change to red and give a buzz/piiippppp.
*/
const int trigPin = 9;
const int echoPin = 10;
const int RED = 3;
const int GREEN = 4;

const float ok_distance = 10.00;

const int buzz = 8;


float duration, distance;



void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzz, OUTPUT);

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
 

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  
    
  if(distance >= ok_distance) {
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED, LOW);
  }
  else if(distance < ok_distance) {
    tone(buzz, 1000);
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, HIGH);
    delay(2000);
    noTone(buzz);
    
  }
  
  delay(1000);
}