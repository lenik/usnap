#ifndef COS51_BAUD_H
#define COS51_BAUD_H

#include "../const.h"
#include "../types.h"

void setTimer1Baud300(unsigned xtal_57600, byte k300);
#define setTimer1Baud(baud) \
        setTimer1Baud300( (unsigned) (XTAL / 57600), (baud) / 300 )

void setTimer2Baud300(unsigned xtal_9600, byte k300);
#define setTimer2Baud(baud) \
        setTimer2Baud300( (unsigned) (XTAL / 9600), (baud) / 300 )

#endif
