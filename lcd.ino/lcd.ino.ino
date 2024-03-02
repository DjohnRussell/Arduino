#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup() {
  // 16, 2 refers to the columns and rows in the display!
  lcd.begin(16, 2);

  lcd.print("Starting.....");

}

void loop() {
  

}
