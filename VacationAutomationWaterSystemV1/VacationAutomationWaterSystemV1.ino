#include <Servo.h>

const int soilPin = A0;

Servo servo;

// Holder styr på om jorda er våt
bool jordErVat = false;

void setup() {
  Serial.begin(9600);

  // Servo er koblet til pin 9
  servo.attach(9);

  // Startposisjon
  servo.write(0);
}

void loop() {

  // Leser råverdien fra fuktighetssensoren
  int verdi = analogRead(soilPin);

  // Gjør om råverdien til prosent
  // 0 = tørr
  // 900 = våt
  int fuktighet = map(verdi, 0, 900, 0, 100);

  // Sørger for at verdien ikke går under 0 eller over 100
  fuktighet = constrain(fuktighet, 0, 100);

  Serial.print("Råverdi: ");
  Serial.print(verdi);
  Serial.print("  Fuktighet: ");
  Serial.print(fuktighet);
  Serial.println("%");


  // Hvis jorda er tørr
  if (fuktighet < 45 && jordErVat == true) {

    Serial.println("Jorda er tørr!");

    // Servo går til 180 grader
    servo.write(180);

    // Lagre at jorda nå er tørr
    jordErVat = false;
  }


  // Hvis jorda er våt
  else if (fuktighet > 55 && jordErVat == false) {

    Serial.println("Jorda er våt!");

    // Servo går til 0 grader
    servo.write(0);

    // Lagre at jorda nå er våt
    jordErVat = true;
  } 
  

  delay(1000);
}
