//----------- Tilt switch--------------

const int led = 4;
const int led_2 = 5;
const int tiltSwitchPin = 7;
 


void setup() {
  pinMode(tiltSwitchPin, INPUT_PULLUP); 
  pinMode(led, OUTPUT);
  pinMode(led_2, OUTPUT);
}

void loop() {
  int tiltSwitchState = digitalRead(tiltSwitchPin);

  if(tiltSwitchState == HIGH) {
  
    for(int i = 0; i < 10; i++) {
      digitalWrite(led, HIGH);
      delay(200);
      digitalWrite(led_2, HIGH);
      digitalWrite(led, LOW);
      delay(200);
      digitalWrite(led_2, LOW);
    }
   

    
  

  }
  else {
    digitalWrite(led, LOW);
  }
}

