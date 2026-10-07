/*

----------------------------- Smart plant pot -------------------------------------------
---------Forklaring:------------------------
- valgene jeg har tatt:
Jeg har valgt og teste ut hvert av komponentene og få sette disse sammen, jeg har lagt en del fokus på koden og ønsker at det skal være lett leselig, 
dette er for min syld og de som skal gå over den.
ønsker å dele dette opp i funksjoiner slik at det er lettere og endre/gjøre små justeringer.

- Hvordan gikk jeg frem?:
Jeg merker jeg sliter med dette breadboardet jeg sliter med hvem rader som son har kontakt med hverandre, dette har tatt veldig mye tid og jeg har surra 
bort mye tid.

Jeg tester hvert av elementene for seg og setter disse sammen til en fullstending løsning, forhåpentlig ;P


- Hvordan den brukes: 
Jeg tenket at selve potten skal sitte på en arm, denne armen er motert på servoen som skal snu mot det beste lysforholdet dersom temraturen er optimalt dvs 
innenfor grenseverdien (TO_VARM).
Om ikke vil den snu seg mot det laveste lysforholdet. 
Det er kun koblet opp 3 photoresistorer men tanken var fler.

Jord fuktighets sensoren måler verdien og det er laget funksjonallitat som skal aktiverer pumpen dersom den er innenfor grenseverdien.
om jeg får pumpen til å fungere.

ting som ikke falt helt på plass:
- temp fungerer ikke slik den skal viser ikke korekte verider
- sevro fungerer ikke slik som jeg hadde tenkt.
- vannpumpa fikk jeg desverre ikke til, brukte for mye tid på ALT annet. merker je begynte litt feil og prioriterte ting feil.
----------------------------------------------------------------------------------------
*/
#include <Servo.h>

// Photo resistor
int photoValueA0;
const int PHOTO_PIN_AO = A0;

int photoValueA1;
const int PHOTO_PIN_A1 = A1;

int photoValueA2;
const int PHOTO_PIN_A2 = A2;

// Sevro
const int SERVO_PIN = 9;
Servo myServo;

//TMP36
const int tempSensorPin = A3;
// konstant for "for varmt"
const float TO_VARM = 25.00;

// Submerible 3V
const int pumpPin = 4;   

// Soil moisture Sensor
int val = 0;
int soil_pin = A4;
int soil_power = 7;
// konstant for fuktighets grense 
const int NEED_WATER = 500;





void setup() {
  
  myServo.attach(SERVO_PIN);
  pinMode(soil_power, OUTPUT);
  digitalWrite(soil_power, LOW);
  pinMode(pumpPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  
  // -----Tester Soil moist sensor -----
  Serial.print("soil moisture = ");
  Serial.println(readSoil());
  delay(1000);

  myServo.write(60);
  //Leser verdiene for lysforhold
  photoValueA0 = analogRead(PHOTO_PIN_AO);
  photoValueA1 = analogRead(PHOTO_PIN_A1);
  photoValueA2 = analogRead(PHOTO_PIN_A2);
  

  //Leser verdiene for tempratur
  int sensorValue = analogRead(tempSensorPin);
  float millivolts = (sensorValue / 1024.0) * 5000; // konverterer analog lesning til millivolts
  float temperatureC = (millivolts - 500) / 10; // konverterer millivolt til C

  //-----------Tester tem36-----------
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" C");
  delay(1000);
  /*
  --------Tesing av lysforhold--------
  Serial.println("value A0");
  Serial.println(photoValueA0);
  Serial.println("value A1");
  Serial.println(photoValueA1);
  Serial.println("value A2");
  Serial.println(photoValueA2);
  delay(2000);
  */

  /*
  Kaller funksjonen laget under og legger readSoil som parameter, nå vil den da sjekke verien og gjøre en if test, 
  ved å sammen ligne verdien mot konstanten NEED_WATER Dersom den er innenfor grenseveriden vil den da få vann.
  */
  CheckMoistLevel(readSoil()); 
  
  /*Bruker de funksjonen vi har laget, og legger inn verdien vi leser av photoresistoren.
  Vi har her en if test før kalling av funksjonene , om temp er lavere en grenseverdien (TO_VARM), vil den svige mot den sensoren med lavest lys forhold 
  om tempraturen er innenfor grenseverdien vil den svinge mot den med høyest verdi.
  */
  if(temperatureC < TO_VARM ) {
    highesValue(photoValueA0, photoValueA1, photoValueA2);
  }
  else if (temperatureC > TO_VARM ) {
    LowestValue(photoValueA0, photoValueA1, photoValueA2);
  }

}

/*
Denne funksjonen tar tre parametere, tre verdier som er lest fra photoresistoren,
samt at den vil få sevo armen til og peke mot den photoresistoren med høyest verdi(høyeste lysforhold)
*/
void highesValue(int valueOne, int valueTwo, int valueThree) {
  if (valueOne > valueTwo && valueOne > valueThree) {
    myServo.write(90);
    
  }
  else if (valueTwo > valueOne && valueTwo > valueThree) {
    myServo.write(60);
  }
  else if (valueThree > valueOne && valueThree > valueTwo) {
    myServo.write(30);
  }
}

/*
Denne funksjonen tar tre parametere, tre verdier som er lest fra photoresistoren,
samt at den vil få sevo armen til og peke mot den photoresistoren med laveste verdi(laveste lysforhold)
*/
void LowestValue(int valueOne, int valueTwo, int valueThree) {
  if (valueOne < valueTwo && valueOne < valueThree) {
    myServo.write(90);
    
  }
  else if (valueTwo < valueOne && valueTwo < valueThree) {
    myServo.write(60);
  }
  else if (valueThree < valueOne && valueThree < valueTwo) {
    myServo.write(30);
  }
}

/*
Denne leser verien ifra sensoren dersom. denne har jeg lånt fra :
kilkde : https://www.instructables.com/How-to-Connect-the-Sparkfun-Soil-Moisture-Sensor-a/
*/
int readSoil() {
  digitalWrite(soil_power, HIGH);
  delay(10);
  val = analogRead(soil_pin);
  digitalWrite(soil_power, LOW);
  return val;
}

/*
Her sjekker vi hvis verdien fra fuktighets sensoren er innenfor grenseverdien (NEED_WATER), der som den er større -> ønsker vi at planten for vann
*/
void CheckMoistLevel(int value) {
  if(value <= NEED_WATER) {
    //Activate water pump
    digitalWrite(pumpPin, HIGH); // sett i gang
    delay(5000); // pumpe 5 sekunder
    digitalWrite(pumpPin, LOW); // stop
  }
}


