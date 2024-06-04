#include <LiquidCrystal.h>
//tmp36
//Flat side out : 1 pin -> 5v, 2 pin -> AO, 3 -> GND

const int tempSensorPin = A0;
const float TO_HIGH = 23.00;
const int motor_pin = 9; 

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  pinMode(motor_pin, OUTPUT);
  //LCD
  lcd.begin(16, 2);
  lcd.print("  Thermometer");
  delay(1500);
  lcd.clear();

  Serial.begin(9600);
}

void motorGo(int pin){
  digitalWrite(motor_pin, HIGH);
}

void motorStop(int pin){
  digitalWrite(motor_pin, LOW);
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
    
    motorGo(motor_pin);
    
  }
  else {
   
   motorStop(motor_pin);
  }
}