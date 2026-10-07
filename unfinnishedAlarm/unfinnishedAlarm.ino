#include <TimeLib.h>
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const int buzzer = 9;
const int potPin = A0;
const int setAlarmButtonPin = 7;        // Knapp for å stille alarmen
const int activateAlarmButtonPin = 8;   // Knapp for å aktivere/deaktivere alarmen

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int alarmHour = 0;
int alarmMinute = 0;
bool alarmActive = false;

void setup() {
  lcd.begin(16, 2);
  lcd.print("My alarm");
  delay(1000);
  lcd.clear();
  
  pinMode(setAlarmButtonPin, INPUT_PULLUP);
  pinMode(activateAlarmButtonPin, INPUT_PULLUP);

  // Still inn tiden her (eventuelt kan dette være NTP synkronisering)
  setTime(8, 29, 0, 1, 1, 2020); // Timer, Minutter, Sekunder, Dag, Måned, År
}

void loop() {
  displayClock();
  
  if (alarmActive && hour() == alarmHour && minute() == alarmMinute) {
    activateAlarm();
  }

  checkAlarmButton();
  checkSetAlarmButton();
}

void displayClock() {
  lcd.setCursor(0, 0);
  lcd.print("Time: ");
  printTime(hour(), minute());

  lcd.setCursor(0, 1);
  lcd.print("Alarm: ");
  if (alarmActive) {
    lcd.print("On ");
    printTime(alarmHour, alarmMinute);
  } else {
    lcd.print("Off");
  }
}

void printTime(int hours, int minutes) {
  if (hours < 10) lcd.print('0');
  lcd.print(hours);
  lcd.print(':');
  if (minutes < 10) lcd.print('0');
  lcd.print(minutes);
}

void activateAlarm() {
  lcd.clear();
  lcd.print("Alarm!");
  tone(buzzer, 1000);
  delay(1000);
  noTone(buzzer);
  delay(1000);
  lcd.clear();
}

void checkAlarmButton() {
  if (digitalRead(activateAlarmButtonPin) == LOW) {
    delay(200);
    while (digitalRead(activateAlarmButtonPin) == LOW);
    delay(200);
    alarmActive = !alarmActive;
    lcd.clear();
    displayClock();
    delay(1000);
  }
}

void checkSetAlarmButton() {
  if (digitalRead(setAlarmButtonPin) == LOW) {
    delay(200);
    while (digitalRead(setAlarmButtonPin) == LOW);
    delay(200);
    alarmHour = map(analogRead(potPin), 0, 1023, 0, 23);
    alarmMinute = map(analogRead(potPin), 0, 1023, 0, 59);
    lcd.clear();
    displayClock();
  }
}


