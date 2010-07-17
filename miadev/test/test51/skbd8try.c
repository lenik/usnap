#include <8051.h>
#include <cos51/1602.h>
#include <cos51/dk/skbd8.h>

__idata __at(0x2f) byte KBD;
__bit __at(0xf8) K0;
__bit __at(0xf9) K1;
__bit __at(0xfa) K2;
__bit __at(0xfb) K3;
__bit __at(0xfc) K4;
__bit __at(0xfd) K5;
__bit __at(0xfe) K6;
__bit __at(0xff) K7;

void skbd8Refresh() {

    X165_READ_BYTE(KBD, X165_SH_LD, X165_CLK, X165_IN);

}

void main() {

    while (skbd8Refresh()) {
        P1_0 = K4;
        P1_1 = K5;
        P1_2 = K6;
        P1_3 = K7;
    }

}
