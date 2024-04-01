#include <Arduino.h>
#include <SPI.h>
#include <SdFat.h>

SdExFat SD;

#define SPI_SPEED SD_SCK_MHZ(4)

ExFatFile myFile;

//For writing to file
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

//For reading a file
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
