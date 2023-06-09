#include "LiquidCrystal.h"
LiquidCrystal lcd(8,7,6,5,4,3);
int sensorPin = 0;
 
void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
}
 
void loop()
{
 
 int reading = analogRead(sensorPin);

 // measure the 5v with a meter for an accurate value
 //In particular if your Arduino is USB powered

 float voltage = reading * 4.68;
 voltage /= 1024.0;
 
 // now print out the temperature

 float temperatureC = (voltage - 0.5) * 100;
 Serial.print(temperatureC);
 Serial.println(" degrees C");
 float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
 Serial.print(temperatureF); Serial.println(" degrees F");
   lcd.setCursor(2,0);
   lcd.print("Dad Eats Ass");
   lcd.setCursor(6,1);
   lcd.print(temperatureF);
   lcd.setCursor(11,1);
   lcd.print("F");
 delay(500);
}
