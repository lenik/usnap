#include "crc8.h"

#ifdef CRC8_FLY
static byte polynomial = 0;
#else
static __xdata byte crc8tab[0x100];
#endif

static byte crc;

void crc8Init(byte _polynomial) {
#ifdef CRC8_FLY
    polynomial = _polynomial;
#else
    byte val = 0;
    byte bitIndex;
    do {
        crc = val;
        for (bitIndex = 0; bitIndex < 8; ++bitIndex)
            if (crc & 0x80)
                crc = (crc << 1) ^ _polynomial;
            else
                crc <<= 1;
        crc8tab[val] = crc;
        val++;
    } while (val); // 256 times
#endif
    crc = 0;
}

void crc8Reset() {
    crc = 0;
}

byte crc8Update(byte b) {
#ifdef CRC8_FLY
    byte bitIndex;
    crc ^= b;
    for (bitIndex = 0; bitIndex < 8; bitIndex++)
        if (crc & 0x80)
            crc = (crc << 1) ^ polynomial;
        else
            crc <<= 1;
#else
    crc = crc8tab[crc ^ b];
#endif
    return crc;
}

byte crc8UpdateBlock(byte *pblock, byte n) {
    while (n--)
        crc8Update(*pblock++);
    return crc;
}
