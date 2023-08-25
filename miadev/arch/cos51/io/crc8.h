#ifndef COS51_CRC8_H
#define COS51_CRC8_H

#include "../types.h"

/**
 * 11010101 CRC8 = 0xd5,
 * 00000111 CRC8_CCITT = 0x07,
 * 00110001 CRC8_DALLAS_MAXIM = 0x31,
 * 00011101 CRC8_SAE_J1850 = 0x1D,
 * 10011011 CRC_8_WCDMA = 0x9b,
 */
#define CRC7            0x09    // MMC, SD
#define CRC8_X          0xd5
#define CRC8_CCITT      0x07    // ATM, ISDN
#define CRC8_DAXIM      0x31    // 1-wire bus
#define CRC8_SAE_J1850  0x1d    //
#define CRC8_WCDMA      0d9b

void crc8Init(BYTE polynomial);

void crc8Reset();
BYTE crc8Update(BYTE b);

/**
 * @param pblock non-null pointer to the block buffer
 * @param size 0..255
 */
BYTE crc8UpdateBlock(BYTE *pblock, BYTE size);

#endif
