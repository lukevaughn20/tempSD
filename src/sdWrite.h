#ifndef _SD
#define _SD
#include <arduino.h>


void sdWrite(int pin, String file, String msg);
void sdRead(int pin, String file);

#endif