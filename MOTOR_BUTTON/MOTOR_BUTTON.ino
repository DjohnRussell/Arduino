// ------Photoresistor -------
// one leg to 5v the oter to A1 -> 10 k ohm -> GND
//------- DC- Motor ------
// -TIP120 tranistor
// - 1N4001 diode
// - battery 9V
// -DC motor

// TIP120 tranistor three legs  first leg -> GND, second(middel leg) -> to 1N4001 diode and pin 9
// 1N4001 diode in the middel leg as writting above opisite side -> black wire dc moror the other side og the 1N4001 diodebarrty connector and then red wire dc moror.




int motorControl = 9;
//first button
int buttonState_12;
int buttonPin_12 = 12;
//second button
int buttonState_11;
int buttonPin_11 = 11;
//theird button
int buttonState_10;
int buttonPin_10 = 10 ;

void start(int speed) {
  analogWrite(motorControl, speed); 
}

void stop() {
  analogWrite(motorControl, 0); 
}



void setup() {
  Serial.begin(9600);
  pinMode(buttonPin_12, INPUT_PULLUP);
  pinMode(buttonPin_11, INPUT_PULLUP);
  pinMode(buttonPin_10, INPUT_PULLUP);
}

void loop() {

  buttonState_12 = digitalRead(buttonPin_12);
  buttonState_11 = digitalRead(buttonPin_11);
  buttonState_10 = digitalRead(buttonPin_10);

  if(buttonState_12 == HIGH) {
    start(255);
  } 
  else if(buttonState_11 == HIGH) {
    stop();
  }
   else if(buttonState_10 == HIGH) {
    start(200);
  }
 
 
}

