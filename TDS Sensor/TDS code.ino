#include <EEPROM.h>
#include "GravityTDS.h"

#define TdsSensorPin A0

GravityTDS gravityTds;

float temperature = 23, tdsValue = 0;

void setup()
{
  Serial.begin(115200);
  gravityTds.setPin(TdsSensorPin);
  gravityTds.setAref(4.1);  //Formatter
  gravityTds.setAdcRange(1024);  //1024 for 10bit ADC;4096 for 12bit ADC
  gravityTds.begin();  //initialization
}

void loop()
{
  //temperature = readTemperature();  //add your temperature sensor and read it
  gravityTds.setTemperature(temperature);  // set the temperature and execute temperature compensation
  gravityTds.update();  //sample and calculate
  tdsValue = gravityTds.getTdsValue();  // then get the value
  Serial.print(tdsValue, 0);
  Serial.println("ppm");
  delay(1000);
}
