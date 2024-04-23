#include <LiquidCrystal.h>
const int rs= 12, en= 11, d4= 5, d5= 4, d6= 3, d7= 2;
const int RED_LED = 9;
const int GREEN_LED =8 ;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {

  //Deode
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  // 16, 2 refers to the columns and rows in the display!
  //LCD
  lcd.begin(16, 2);
  lcd.print("Starting.....");
  delay(1500);
  lcd.clear();
}

void lightUp() {
  digitalWrite(RED_LED, HIGH);
  lcd.print("Red light");
  delay(2000);
  lcd.clear();
  digitalWrite(RED_LED, LOW);
  delay(2000);
  digitalWrite(GREEN_LED, HIGH);
  lcd.print("Green light");
  delay(2000);
  lcd.clear();
  digitalWrite(GREEN_LED, LOW);
  delay(2000);
  

}

void loop() {
  lightUp();
  //lcd.setCursor(1,0);
  lcd.print("This is a Test!");
  //lcd.setCursor(0, 1);
  //lcd.print(" Also a Test");

  
}
