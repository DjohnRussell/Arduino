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

//---------------------------------------------------Functions---------------------------------------------------------



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
