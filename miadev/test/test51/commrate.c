#include <stdio.h>
#include <8052.h>
#include <cos51/types.h>
#include <cos51/baud.h>
#include <cos51/1602.h>
#include <cos51/dk/hc6800.h>

void slsend(byte c) {
    while (!TI)
        ;
    SBUF = c;
    TI = 0;
}

void slrecv()
__interrupt(4) {
    if (RI) {
        // byte b = SBUF;
        P2_0 ^= 1;
        RI = 0;
    }
    // TI = 1;
}

unsigned sendCount = 0;

void main() {
    lcd1602Init();

    EA = 1;

    SCON = 0x52; // 010.1.0000, mod 2, REN, TI
    //    ES = 1;
    setTimer1Baud(1200);

    TMOD = 0x20;
    TH1 = 0x00;
    TL1 = 0x00;
    TR1 = 1;
    // ET1 = 1;

    while (1) {
        slsend('*');
        sendCount++;
    }
}

void putchar(char c) {
    lcd1602Putchar(c);
}
