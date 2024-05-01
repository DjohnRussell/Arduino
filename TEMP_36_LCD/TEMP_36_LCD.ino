#include <LiquidCrystal.h>
//tmp36
//Flat side out : 1 pin -> 5v, 2 pin -> AO, 3 -> GND

const int tempSensorPin = A0;
const float TO_HIGH = 25.00;
const int red = 8;
const int green = 9;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  //LCD
  lcd.begin(16, 2);
  lcd.print("  Thermometer");
  delay(1500);
  lcd.clear();

  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(tempSensorPin);
  float millivolts = (sensorValue / 1024.0) * 5000; // Convert the analog reading to millivolts
  float temperatureC = (millivolts - 500) / 10; // Convert millivolts to Celsius

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println("°C");

  lcd.print("Temperature: ");
  lcd.setCursor(0, 1);
  lcd.print(temperatureC);
  lcd.print(" C");
  delay(500);
  lcd.clear();

  delay(1000); 
  if(temperatureC >= TO_HIGH) {
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    
  }
  else {
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
  }
}