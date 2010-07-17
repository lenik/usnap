#ifndef __PS2KBD_H
#define __PS2KBD_H

#include "types.h"

#ifndef PS2_INT
#   define PS2_INT 1
#endif

static byte ps2Frame;
static byte ps2Bit = 0;

void ps2Recv(byte frame);

void ps2Handler()
// __interrupt(PS2_INT)
{
    // bb...b P S
    byte i = (n) + 2 + 1;
    switch (ps2Bit) {
    case 8: // parity
    case 9: // stop
        ps2Bit = 0;
        ps2Recv(ps2Frame);
        return;
    default:
        ps2Frame >>= 1;
        if ((in))
            ps2Frame |= 0x80;
    }
    ps2Bit++;
}

static byte ps2DeviceType = 0xff;
static byte ps2ScanCode;

void ps2Recv(byte frame) {
    if (ps2DeviceType == 0xff) {
        ps2DeviceType = frame;
        return;
    }
    ps2ScanCode = frame;
}

#endif
