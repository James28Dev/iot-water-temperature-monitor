#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2 //กำหนดขาที่จะเชื่อมต่อ Sensor
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
 
void setup(void) {
Serial.begin(9600);
sensors.begin();
lcd.begin();
lcd.backlight();
lcd.setCursor(2, 0);
lcd.print("Requesting..");
lcd.setCursor(0, 1);
lcd.print("Tem is: ");
}
 
void loop() {
sensors.requestTemperatures(); //อ่านข้อมูลจาก library
lcd.setCursor(8, 1);
lcd.print(sensors.getTempCByIndex(0)); // แสดงค่า อูณหภูมิ 
lcd.print(" *C");
lcd.setCursor(14, 1);
delay(1000);

//Serial.print("Temperature is: ");
//Serial.print(sensors.getTempCByIndex(0)); // แสดงค่า อุณหภูมิ 
//Serial.println(" *C");

}
