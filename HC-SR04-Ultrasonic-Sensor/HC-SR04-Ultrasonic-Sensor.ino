/*
------------ HC-SR04 Ultrasonic sensor ------------
Simple circit HC-SR04 4 pins GND -> GND, echo -> 10, trig -> 9, Vcc -> 5V
this is to check the distance and give a red ot green light to check it u are getting close 
or far away from the sensor.
*/
const int trigPin = 9;
const int echoPin = 10;

float duration, distance;



void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
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
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(1000);
}
