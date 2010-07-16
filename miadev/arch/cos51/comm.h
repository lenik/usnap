#ifndef COS51_COMM_H
#define COS51_COMM_H

#include "const.h"

void setTimer1Baud300(unsigned xtal_57600, unsigned k300);
#define setTimer1Baud(baud) \
        setTimer1Baud300( (unsigned) (XTAL / 57600), (baud) / 300 )

void setTimer2Baud300(unsigned xtal_9600, unsigned k300);
#define setTimer2Baud(baud) \
        setTimer2Baud300( (unsigned) (XTAL / 9600), (baud) / 300 )

#endif
