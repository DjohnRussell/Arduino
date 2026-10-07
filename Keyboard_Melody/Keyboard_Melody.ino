int buttons[6];
int notes[] = {262, 294, 330, 349};
int melody[] = {262, 330, 392, 523, 392, 330}; 


void setup() {
  buttons[0] = 2;
  Serial.begin(9600);

}


void loop() {
  int keyVal = analogRead(A0);
 
  Serial.println(keyVal);
  noTone(9);
  
  if(keyVal == 1023) {
    tone(8, notes[0]);
  }
  else if(keyVal >= 991 && keyVal <= 1002){
    tone(8, notes[1]);
  }
  else if(keyVal >= 500 && keyVal <= 512){
    tone(8, notes[2]);
  }
  else if(keyVal >= 960 && keyVal <= 990){
    tone(8, notes[3]);
  }
  else if(keyVal >= 900 && keyVal <= 940){ 
    // Play melody
    for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
      tone(8, melody[i]);
      delay(500); 
      noTone(8); 
      delay(50); 
    }
  }
  else{
    noTone(8);
  }
}
