//--------------------------------------------------Variables---------------------------------------------------------
const int PHOTO_PIN = A0;
const int GREEN = 7;
const int RED = 8;
int photoValue = 0;
int THRESHOLD = 600;


//--------------------------------------------------------------------------------------------------------------------

void setup() {
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  Serial.begin(9600);
}

//--------------------------------------------------- the curcut---------------------------------------------------------
// arduino = ar, breadboard = bb, photoreststor = photo, led green = green, led red = red
// ar 5V -> bb, ar GND -> bb
// red nagative -> 220 ohm -> GND and positive -> pin 8
// green nagative -> 220 ohm -> GND and positive -> pin 7
// photo one leg to 5V and the other led to A0 and 10K omh -> GND
//----------------------------------------------------------------------------------------------------------------------

void loop() {
  
  photoValue = analogRead(PHOTO_PIN);
  Serial.println(photoValue);
  if (photoValue > THRESHOLD) {
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED,LOW);
  } else {
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
  }
  
  
}
