#include <Arduino.h>
#include "tempSen.h"
#include "sdWrite.h"

#define sdPin 4
#define tempPin 15
#define tempInterval 10 //Interval to read temps put in seconds

String msg;
String file = "temps.txt";
unsigned long last_check = 0;


void setup() {
  Serial.begin(9600);
  Serial.println();

}

void loop() {
  if(millis() - last_check > (tempInterval - 1)*1000)
  {
    last_check = millis();
    sdWrite(sdPin, file, printAllData(tempPin));
    Serial.println("printed temps");
  }
}

