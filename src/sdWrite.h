#ifndef _SD
#define _SD
#include <arduino.h>


//Calls setup fuctions for writing to sd(EXFAT ONLY)
void sdWrite(int pin, String file, String msg);
//Calls setup functions for reading to sd(ANY FAT formatting)
void sdRead(int pin, String file);

#endif