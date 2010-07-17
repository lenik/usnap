#include <stdio.h>
#include <8051.h>
#include <cos51/led8.h>
#include <cos51/dk/hc6800.h>
#include <cos51/const.h>

#define REFC MS2C(1)

byte off = 0;

void putchar(char c) {
    if (c == '\n')
        off = 0;
    else
        led8Draw(off++, c);
}

void led8Set(byte index, byte mask) {
    LED8_SETADDR(index);
    P0 = mask;
}

void main() {
    int i = 0;
    int v;

    TMOD = 0x01;
    TH0 = REFC >> 8;
    TL0 = REFC;
    TR0 = 1;
    ET0 = 1;
    EA = 1;

    while (1) {
        i++;
//        v = i;
//        putchar(0x20 + (v % 0x60)); // 20..7f
//        v /= 0x60;
//        putchar(0x20 + (v % 0x60)); // 20..7f
//        v /= 0x60;
//        putchar(0x20 + (v % 0x60)); // 20..7f
//        v /= 0x60;
//        putchar('\n');
        printf_small("HeloWrld\n");
    }

}

byte dd = 0;

void timer0()
__interrupt(1) {
    if (dd++ == 10) {
        dd = 0;
        P1_0 ^= 1;
        TH0 = REFC >> 8;
        TL0 = REFC;
        led8Refresh();
    }
}
