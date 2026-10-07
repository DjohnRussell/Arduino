// ------Photoresistor -------
// one leg to 5v the oter to A1 -> 10 k ohm -> GND
//------- DC- Motor ------
// -TIP120 tranistor
// - 1N4001 diode
// - battery 9V
// -DC motor

// TIP120 tranistor three legs  first leg -> GND, second(middel leg) -> to 1N4001 diode and pin 9
// 1N4001 diode in the middel leg as writting above opisite side -> black wire dc moror the other side og the 1N4001 diodebarrty connector and then red wire dc moror.


int photoValue = 0;
const int photoPin = A1;
const int THRESHOLD = 840; 
int motorControl = 9;

void setup() {
  Serial.begin(9600);
}

void loop() {
  photoValue = analogRead(photoPin);
  Serial.println(photoValue);

  if (photoValue < THRESHOLD) {
    analogWrite(motorControl, 255); 
  } else { /
    analogWrite(motorControl, 0); // Stop the motor
  }
}



  


