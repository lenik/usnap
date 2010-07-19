#include <8051.h>
#include <cos51/display/1602.h>
#include <cos51/dk/skbd8.h>

void main() {

    while (1) {
        skbd8Refresh();

        // P1 = (P1 & 0xf0) | (KBD & 0x0f);
        P1_0 = K0;
        P1_1 = K1;
        P1_2 = K2;
        P1_3 = K3;
    }

}
