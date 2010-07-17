#include <stdio.h>
#include <8051.h>
#include <cos51/types.h>
#include <cos51/const.h>
#include <cos51/1602.h>
#include <cos51/dk/hc6800.h>

//#define REFRESH HZ2C(1)
#define TUNIT   10000
#define UPS         (1000000L / TUNIT)
#define REFRESH 3
#define RC          (UPS / REFRESH)

register volatile unsigned count = 0;
register volatile unsigned dispcount = 0;

byte phist[17];
register byte ph = 0;

byte refresh = 0;

void main() {
    register byte p;

    lcd1602Init();
    lcd1602At(0, 0);
    lcd1602Puts("KbdVibrate/Lenik");

    // 10ms
    TMOD = 0x10;
    TH1 = (US2C(TUNIT)) >> 8;
    TL1 = (US2C(TUNIT)) & 0xff;

    ET1 = 1;
    TR1 = 1;
    EA = 1;
    P2 = 0xff;

    p = P2;
    while (1) {
        if (p != P2) {
            p = P2;
            if (ph == sizeof(phist) - 1)
                ph = 0;
            count++;
        }
        // Test result: 40us * 1..10 = [0, 400us] pulse duration.
        if (ph < sizeof(phist) - 1) {
            phist[ph] = (P2 & 7) + '0';
            phist[++ph] = 0;
        }
    }
}

void disp()
__interrupt(3) __using(1) {
    TH1 = (US2C(TUNIT)) >> 8;
    TL1 = (US2C(TUNIT)) & 0xff;

    if (++refresh != RC)
        return;
    refresh = 0;

    dispcount++;
    P1_0^=1;
    lcd1602At(0, 0);
    printf_small("P=%x C=%d S=%d", P2, count, count/2);
    lcd1602At(1, 0);
    lcd1602Puts(phist);
}

void putchar(char c) {
    lcd1602Putchar(c);
}
