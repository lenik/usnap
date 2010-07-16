#include <8052.h>
#include "types.h"

/**
 * F' = T1-overflow-freq.
 * x=SMOD ? 1 : 2
 * baud = F' / 32x   (/16x in  6T mode)
 *
 * F' = baud * 32x
 * = k300 * 300 * 32x
 *
 * F' = (XTAL/12) / ~count      (1M ... 3906)
 * ~count = XTAL / 12F'
 * = XTAL / (12 * k300 * 300 * 32x)
 * = XTAL_57600 / (2 * k300 * x)
 */
void setTimer1Baud300(unsigned xtal_57600, byte k300) {
    unsigned c;

    if (! (PCON & SMOD)) k300 <<= 1;

    //    RCAP2H, RCAP2L
#ifdef MODE_6T
    c = xtal_57600 / k300;
#else
    c = xtal_57600 / 2 / k300;
#endif

    // if(c > 0x100) error;
    if (c > 0x100)
        c = 0;
    else
        c = ~c + 1;

    TMOD = (TMOD & 0x0f) | 0x20; // Timer 1 mode 2
    ET1 = 0;
    TH1 = c;
    TR1 = 1;

#ifdef REG8052_H
    RCLK = TCLK = 0;
#endif
}

#ifdef REG8052_H

/**
 * F'' = T2-overflow-freq.
 * x=SMOD ? 1 : 2
 * baud = F'' / 32x   (/16x in  6T mode)
 *
 * F'' = baud * 32x
 * = k300 * 300 * 32x
 *
 * F'' = (XTAL/2) / ~count    (XTAL/1 in 6T mode)
 * ~count = XTAL/2F''
 * = XTAL / (2 * k300 * 300 * 32x)
 * = XTAL_9600 / (2 * k300 * x)
 */
void setTimer2Baud300(unsigned xtal_9600, unsigned k300) {
    unsigned c;

    if (! (PCON & SMOD)) k300 <<= 1;

    //    RCAP2H, RCAP2L
#ifdef MODE_6T
    c = xtal_9600 / (1 * k300);
#else
    c = xtal_9600 / (2 * k300);
#endif

    c = ~c + 1;

    TH2 = RCAP2H = c >> 8;
    TL2 = RCAP2L = (byte) c;

    ET2 = 0;
    TR2 = 1;
    RCLK = TCLK = 1;
}

#endif
