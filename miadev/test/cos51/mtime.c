#include <8051.h>

#include <cos51/types.h>

#define SLEEPTIMER 1
#include <cos51/sleep.h>
T_IMPL

volatile __bit ret = 0;
void reTimer1() {
    P1_0 = 0;
    P1_1 = 1;
    P1_2 ^= 1;
    P1_3 ^= 1;
    ret = 1;
}

void main() {
    int n;
    byte val = 0;
    P1_0 = 0;
    for (n = 0; n < 60; n++) {
        delay(1);
        val++;
        P1 = (P1 & 0xF0) | (val & 0x0F);
    }
}
