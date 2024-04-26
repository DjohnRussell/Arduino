# Arduino
# Arduino Starter Kit README

Welcome to the Arduino Starter Kit! This README file provides basic explanations for the connections of all the included parts of the kit.

## Components Included:

1. Arduino Uno R3
2. LED (Light Emitting Diode)
3. Piezo Buzzer
4. DC Motor
5. LCD (Liquid Crystal Display)
6. Resistors
7. Jumper Wires

## Connections:

### LED (Light Emitting Diode):

Connect the LED to the Arduino as follows:
- Connect the longer leg (anode) of the LED to a digital pin on the Arduino (e.g., pin 4).
- Connect the shorter leg (cathode) of the LED to a current-limiting resistor (e.g., 220 Ohm).
- Connect the other end of the resistor to the ground (GND) pin on the Arduino.

### Piezo Buzzer:

Connect the Piezo Buzzer to the Arduino as follows:
- Connect one pin of the Piezo Buzzer to a digital pin on the Arduino (e.g., pin 8).
- Connect the other pin of the Piezo Buzzer to the ground (GND) pin on the Arduino.

### DC Motor:

Connect the DC Motor to the Arduino as follows:
- Connect one terminal of the DC Motor to a digital pin on the Arduino (e.g., pin 9).
- Connect the other terminal of the DC Motor to the ground (GND) pin on the Arduino.

### LCD (Liquid Crystal Display):

Connect the LCD to the Arduino as follows:
- Connect the VSS pin of the LCD to the ground (GND) pin on the Arduino.
- Connect the VDD pin of the LCD to the 5V pin on the Arduino.
- Connect the Vo pin of the LCD to a 10k Ohm potentiometer.
- Connect the RS, RW, and E pins of the LCD to digital pins on the Arduino.
- Connect the D4-D7 pins of the LCD to digital pins on the Arduino.

### Resistors and Jumper Wires:

Resistors are used to limit the current flowing through components like LEDs. Connect resistors in series with LEDs as explained above. Jumper wires are used to create connections between various components and the Arduino. They are plugged into the pins of the components and the Arduino's headers to establish electrical connections.

## Example Code:

Example code for using the LED, Piezo Buzzer, DC Motor, and LCD with the Arduino can be found in the respective sections of this README.

### Quick For Loop Example:

Here's a quick example of using a for loop to blink an LED 5 times:

```cpp
const int ledPin = 4; // Define the pin for the LED

void setup() {
  pinMode(ledPin, OUTPUT); // Set the LED pin as an output
}

void loop() {
  for (int i = 0; i < 5; i++) { // Loop 5 times
    digitalWrite(ledPin, HIGH); // Turn the LED on
    delay(500); // Wait for 500 milliseconds
    digitalWrite(ledPin, LOW); // Turn the LED off
    delay(500); // Wait for 500 milliseconds
  }
}
