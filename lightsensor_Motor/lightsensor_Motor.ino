//--------------------------------------------------Variables---------------------------------------------------------
const int RED_LED_PIN = 7;
const int GREEN_LED_PIN = 8;
const int MOTOR_PIN = 9;
const int PHOTO_PIN = A0;
const int THRESHOLD = 500;
const int BLINK_DURATION = 1500;
const int ACTION_DELAY = 2000;
//--------------------------------------------------------------------------------------------------------------------

void setup() {
  //---------------LEDs-----------------------
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  //--------------DC Motor-------------------
  pinMode(MOTOR_PIN, OUTPUT);

  Serial.begin(9600);
}

//---------------------------------------------------Functions---------------------------------------------------------

void turnOnLed(int colorPin) {
  digitalWrite(colorPin, HIGH);
}

void turnOffLed(int colorPin) {
  digitalWrite(colorPin, LOW);
}

void blink(int colorPin) {
  for (int i = 0; i < 2; i++) {
    digitalWrite(colorPin, HIGH);
    delay(BLINK_DURATION);
    digitalWrite(colorPin, LOW);
    delay(BLINK_DURATION);
  }
}

void motorGo(int pin) {
  digitalWrite(pin, HIGH);
}

void motorStop(int pin){
  digitalWrite(pin, LOW);
}

void readPinAndAction(int photoPin, int motorPin) {
  int sensorValue = analogRead(photoPin);

  if (sensorValue < THRESHOLD) {
    blink(GREEN_LED_PIN);
    delay(ACTION_DELAY);
    motorGo(motorPin);
  }
  else {
    blink(RED_LED_PIN);
    delay(ACTION_DELAY);
    motorStop(motorPin);
  }
}

//----------------------------------------------------------------------------------------------------------------------

void loop() {
  readPinAndAction(PHOTO_PIN, MOTOR_PIN);
}

