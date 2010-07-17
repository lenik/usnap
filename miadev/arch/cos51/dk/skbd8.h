#ifndef __SKBD8_H
#define __SKBD8_H

/**
 * Serial Keyboard by 74LS165 PISO
 */

#include "../types.h"

#include "hc6800.h"
#include "../74xx/165.h"

__data __at(0x2f) byte KBD;
__bit __at(0x78) K0;
__bit __at(0x79) K1;
__bit __at(0x7a) K2;
__bit __at(0x7b) K3;
__bit __at(0x7c) K4;
__bit __at(0x7d) K5;
__bit __at(0x7e) K6;
__bit __at(0x7f) K7;

void skbd8Refresh() {

    X165_READ_BYTE(KBD, X165_SH_LD, X165_CLK, X165_IN);

}

#endif
