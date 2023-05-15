//LCD
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

//Sensor
const int SensorPower = 2;
#define SensorSignal A0
int val;

void setup() {
lcd.begin();
pinMode(SensorPower, OUTPUT);
digitalWrite(SensorPower, LOW);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Analog Output:");
  lcd.setCursor(6, 1);
  lcd.print(value());
  delay(1000);
}
int value() {
digitalWrite(SensorPower, HIGH);
delay(10);
val = analogRead(SensorSignal);
digitalWrite(SensorPower, LOW);
return val;
}