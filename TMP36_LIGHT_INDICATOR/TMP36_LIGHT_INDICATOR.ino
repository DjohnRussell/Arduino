// tmp36
//Flat side out : 1 pin -> 5v, 2 pin -> AO, 3 -> GND

const int tempSensorPin = A0;
const float TO_HIGH = 25.00;
const int red = 3;
const int green = 4;


void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(tempSensorPin);
  float millivolts = (sensorValue / 1024.0) * 5000; // Convert the analog reading to millivolts
  float temperatureC = (millivolts - 500) / 10; // Convert millivolts to Celsius

 

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println("°C");

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
