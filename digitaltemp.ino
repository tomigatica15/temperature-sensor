#include <LiquidCrystal.h>

const int lm35 = A1;
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  int lm35Value = analogRead(lm35);

  float temp = (lm35Value * 5.0 / 1023.0) * 100.0;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temperatura:");
  lcd.setCursor(0, 1);
  lcd.print(temp, 1);
  lcd.print(" C");

  /*Serial.print("Temperatura: ");
  Serial.print(temp, 1);
  Serial.println(" °C");*/

  if (temp > 60) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Peligro!!!!!!!");
    lcd.setCursor(0, 1);
    lcd.print(temp, 1);
    lcd.print(" C de temp");
  }

  delay(1000);
}
