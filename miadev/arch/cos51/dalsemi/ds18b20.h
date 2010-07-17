#ifndef __DS18B20_H
#define __DS18B20_H

#include "../1wire.h"

#define DS18B20_LSB         0
#define DS18B20_MSB         1
#define DS18B20_TH          2
#define DS18B20_TL          3
#define DS18B20_CONFIG      4
#define DS18B20_CRC         8

/**
 * Max conversion time:
 *
 * r=0 Res=9bit     Tconv/8 = 93.75 ms
 * r=1 Res=10bit    Tconv/4 = 187.5 ms
 * r=2 Res=11bit    Tconv/2 = 375 ms
 * r=3 Res=12bit    Tconv   = 750 ms
 */
#define DS18B20_RES(c)      ((c) >> 5)
#define DS18B20_RES(c, r)   ((r) << 5)
#define DS18B20_CONVTIME(r) \

#define DS18B20C_CONVERT_T  0x44
#define DS18B20T_CONVERT_T  750000
#define DS18B20T_Tconv(r) \
        ( DS18B20_CONVERT_T >> (3-(r)) )

#define DS18B20T_E2_SAVE    10000

#define DS18B20_ENCODE(f) \
    ((int) (f * 16))
#define DS18B20_MSB(f)  HIGH_BYTE(DS18B20_ENCODE(f))
#define DS18B20_LSB(f)   LOW_BYTE(DS18B20_ENCODE(f))

#define DS18B20_DECODE_INT(w) \
    ((char) ((unsigned char) (w)) >> 4))
#define DS18B20_DECODE_FRAC(w) \
    (((unsigned char) ((w) & 0x0f)) * 13 / 2)

#endif
