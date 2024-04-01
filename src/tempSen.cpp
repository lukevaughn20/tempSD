#include <Arduino.h>
#include <DS18B20.h>

//starting index for temp sensors
int start = 0;

//returns devices on the temp sensor line
uint8_t  numOfDevices(int pin)
{
    DS18B20 ds(pin);
    return + ds.getNumberOfDevices();
}
//returns the data from each sensor to a single string
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