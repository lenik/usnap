#include "crc8.h"

#ifdef CRC8_FLY
static BYTE polynomial = 0;
#else
static __xdata BYTE crc8tab[0x100];
#endif

static BYTE crc;

void crc8Init(BYTE _polynomial) {
#ifdef CRC8_FLY
    polynomial = _polynomial;
#else
    BYTE val = 0;
    BYTE bitIndex;
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

BYTE crc8Update(BYTE b) {
#ifdef CRC8_FLY
    BYTE bitIndex;
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

BYTE crc8UpdateBlock(BYTE *pblock, BYTE n) {
    while (n--)
        crc8Update(*pblock++);
    return crc;
}
