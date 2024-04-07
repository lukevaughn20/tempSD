#include <Arduino.h>
#include <SPI.h>
#include <SdFat.h>

SdExFat SD;

#define SPI_SPEED SD_SCK_MHZ(4)

ExFatFile myFile;

//Returns if no file is able to open
// Rights message to sd card if does not fail
void sdWrite(int pin, String file, String msg)
{
    if(!SD.begin(4, SPI_SPEED))
    {
        Serial.println("init failed!");
        return;
    }

    myFile = SD.open(file.c_str(), FILE_WRITE);

    if(myFile)
    {
        myFile.write(msg.c_str());
        myFile.close();
    }
}

//Reads contents from file then prints to Serial 
void sdRead(int pin, String file)
{
    myFile.open(file.c_str());
    if(myFile)
    {
        while(myFile.available())
        {
            Serial.write(myFile.read());
        }
        myFile.close();
    }
}
