// Automatic water pump with lcd desply
#include <LiquidCrystal.h>

//Initialize the lib by providing pin numbers of the interface
LiquidCrystal lcd(12,11,5,4,3,2);

// Pin definitions
const int moistureSensorPin = A0;  // Analog pin for soil moisture sensor
const int pumpPin = 2;              // Digital pin for water pump control

// Moisture threshold for watering (adjust as needed)
const int moistureThreshold = 500;  // Example threshold, adjust according to your sensor readings

void setup() {
  
  pinMode(moistureSensorPin, INPUT);
  pinMode(pumpPin, OUTPUT);
  Serial.begin(9600);
  //setting up lcds number of columns and rows
  lcd.begin(16,2);
}

void loop() {
  // Read soil moisture level
  int moistureLevel = analogRead(moistureSensorPin);
  
  // Print moisture level (for debugging)
  Serial.print("Moisture Level: ");
  Serial.println(moistureLevel);
  // Using lcd to desplay message
  lcd.print("Moisture Level: ");
  lcd.println(moistureLevel);
  
  // Check if soil is dry enough to water
  if (moistureLevel < moistureThreshold) {
    // Soil is dry, activate water pump
    digitalWrite(pumpPin, HIGH); // Turn on the pump
    delay(5000); // Run the pump for 5 seconds (adjust as needed)
    digitalWrite(pumpPin, LOW); // Turn off the pump
    
    Serial.println("Watering...");
    // using the lcd display to also desplay message
    lcd.print("Watering...");
  }
  
  // Wait before taking the next moisture reading
  delay(1000); // Adjust delay time as needed
}
