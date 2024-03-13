#include <Servo.h>

Servo myServo;

int const potPin = A0;
int potVal;
int angle;
int buttonState;
int buttonPin = 8;

int greenLED = 12;
int yellowLED = 11;
int redLED = 10;

// vinkler på servo
int angle90 = 60;
int angle0 = 0;
int angle180 = 120;


void setup() {
  // put your setup code here, to run once
  myServo.attach(9);
  
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH) {
    tone(5, 1000);
    delay(500);
    noTone(5);
    delay(500);
  }

  potVal = analogRead(potPin);
  Serial.print("potVal: ");
  Serial.print(potVal);
  angle = map(potVal, 0, 1023, 0, 179);
  Serial.print(", angle; ");
  Serial.print(angle);
  myServo.write(angle);

  // Control LEDs  med servi angle
  if (angle <= angle90) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
  } else if (angle < angle180) {
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);
  } else {
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);
  }

  delay(15);
}

