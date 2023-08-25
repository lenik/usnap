#ifndef COS51_1WIRE_H
#define COS51_1WIRE_H

#include "sleep.h"

/**
 * Timing, in μs unit.
 */
#define OWT_RSTL            960     // > 480, max if under parasite pwr
#define OWT_RSTH            480     // < 960, (for check PD)
#define OWT_PDHIGH          60      // > 15,  wait before check presence
#define OWT_PDLOW           60      // < 240, presence detect

#define OWT_SLOT            60      // (sampled at 15<30<60)
#define OWT_REC             1       // for recovery
#define OWT_LOW0            60      // < 120
#define OWT_LOW1            1       // < 15
#define OWT_RDV             15      // read data valid
#define OWT_READ            1       //

#define OWC_ROM_READ        0x33    // single slave only
#define OWC_ROM_MATCH       0x55    // unmatched slaves wait for reset
#define OWC_ROM_SKIP        0xcc    // single slave only, or collide in next
#define OWC_ROM_SEARCH      0xf0

#define OWC_ALARM_SEARCH    0xec

#define OWC_E2_SAVE         0x48    // copy scratchpad
#define OWC_RAM_WRITE       0x4e    // write scratchpad
#define OWC_E2_LOAD         0xb8    // recall E²
#define OWC_RAM_READ        0xbe    // read scratchpad

#define OWC_RESET(port)

#define onewireWait(port) while (port)

#define onewireReset(port, pd) \
    do { \
        onewireWait(port); \
        port = 0; \
        udelay(OWC_RSTL); \
        port = 1; \
        udelay(OWC_PDHIGH); \
        pd = port; \
    } while (0)

#define onewireWriteByte(port, b) \
    do { \
        BYTE __i = 8 + 1; \
        BYTE __b = b; \
        while (--__i) { \
            onewireWriteBit((port), __b); \
            __b >>= 1; \
        } \
    } while (0)

#define onewireWriteBit(port, b) \
    do { \
        port = 0; \
        udelay((b) ? OWCT_LOW1 : OWCT_LOW0); \
        port = 1; \
        udelay((b) ? OWCT_SLOT - OWCT_LOW1 : OWCT_SLOT - OWCT_LOW0); \
    } while (0)

#define onewireReadBit(port, b) \
    do { \
        port = 0; \
        udelay_1(); \
        port = 1; \
        udelay(10); /*OWCT_RDV*/ \
        b = port; \
        udelay(OWCT_SLOT - 15); \
    } while (0)

#define onewireReadByte(port, b) \
    do { \
        BYTE __i = 8 + 1; \
        while (--__i) { \
            onewireReadBit(port, CY); \
            __asm rlc

#endif
