#include <Arduino.h>
#include <DS18B20.h>

//starting index for temp sensors
int start = 0;

//returns the data from each sensor on the line in a single string
String printAllData(int pin)
{
    DS18B20 ds(pin);
    String msg;
    int id = 0;
    while(ds.selectNext())
    {
        msg = ("Device ID: " + String(id) + " has Temp F: " + String(ds.getTempF()) + "\n");
        id += 1;
    }
    return msg;
}