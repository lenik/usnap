#define __LED8_C
#include "led8.h"
#include "math/apn.h"

extern __xdata BYTE led8Cache[];
extern BYTE led8Count;

/**
 *
 *   0
 * -----
 *5| 6 |1
 * |---|
 *4|   |2
 * -----  ,7
 *   3
 */
static __code BYTE led8tab[] = {
//
        0x00, // 00000000 32  20  space
        0x82, // 10000010 33  21  !
        0x22, // 00100010 34  22  "
        0x49, // 01001001 35  23  #
        0xed, // 11101101 36  24  $
        0xd2, // 11010010 37  25  %
        0xdf, // 11011111 38  26  &
        0x20, // 00100000 39  27  '
        0x39, // 00111001 40  28  (
        0x0f, // 00001111 41  29  )
        0x5c, // 01011100 42  2A  *
        0x46, // 01000110 43  2B  +
        0x48, // 01001000 44  2C  ,
        0x40, // 01000000 45  2D  -
        0x80, // 10000000 46  2E  .
        0x52, // 01010010 47  2F  /
        0x3f, // 00111111 48  30  0
        0x06, // 00000110 49  31  1
        0x5b, // 01011011 50  32  2
        0x4f, // 01001111 51  33  3
        0x66, // 01100110 52  34  4
        0x6d, // 01101101 53  35  5
        0x7d, // 01111101 54  36  6
        0x07, // 00000111 55  37  7
        0x7f, // 01111111 56  38  8
        0x6f, // 01101111 57  39  9
        0x09, // 00001001 58  3A  :
        0x0d, // 00001101 59  3B  ;
        0x58, // 01011000 60  3C  <
        0x48, // 01001000 61  3D  =
        0x4c, // 01001100 62  3E  >
        0x53, // 01010011 63  3F  ?
        0x5f, // 01011111 64  40  @
        0x77, // 01110111 65  41  A
        0x7f, // 01111111 66  42  B
        0x39, // 00111001 67  43  C
        0x3f, // 00111111 68  44  D
        0x79, // 01111001 69  45  E
        0x71, // 01110001 70  46  F
        0x3d, // 00111101 71  47  G
        0x76, // 01110110 72  48  H
        0x06, // 00000110 73  49  I
        0x0f, // 00001111 74  4A  J
        0x76, // 01110110 75  4B  K
        0x38, // 00111000 76  4C  L
        0xb7, // 10110111 77  4D  M
        0x37, // 00110111 78  4E  N
        0x3f, // 00111111 79  4F  O
        0x73, // 01110011 80  50  P
        0xbf, // 10111111 81  51  Q
        0x77, // 01110111 82  52  R
        0x6d, // 01101101 83  53  S
        0x07, // 00000111 84  54  T
        0x3e, // 00111110 85  55  U
        0x3e, // 00111110 86  56  V
        0xbe, // 10111110 87  57  W
        0x76, // 01110110 88  58  X
        0x6e, // 01101110 89  59  Y
        0x1b, // 00011011 90  5A  Z
        0x39, // 00111001 91  5B  [
        0x24, // 00100100 92  5C  \ (bs)
        0x0f, // 00001111 93  5D  ]
        0x23, // 00100011 94  5E  ^
        0x08, // 00001000 95  5F  _
        0x02, // 00000010 96  60  `
        0x5f, // 01011111 97  61  a
        0x7c, // 01111100 98  62  b
        0x58, // 01011000 99  63  c
        0x5e, // 01011110 100 64  d
        0xc8, // 11001000 101 65  e // 7b
        0x71, // 01110001 102 66  f
        0x6f, // 01101111 103 67  g
        0x74, // 01110100 104 68  h
        0x05, // 00000101 105 69  i
        0x0d, // 00001101 106 6A  j
        0x70, // 01110000 107 6B  k
        0x06, // 00000110 108 6C  l
        0xd4, // 11010100 109 6D  m
        0x54, // 01010100 110 6E  n
        0x5c, // 01011100 111 6F  o
        0x73, // 01110011 112 70  p
        0x67, // 01100111 113 71  q
        0x50, // 01010000 114 72  r
        0x6d, // 01101101 115 73  s
        0x78, // 01111000 116 74  t
        0x1c, // 00011100 117 75  u
        0x1c, // 00011100 118 76  v
        0x9c, // 10011100 119 77  w
        0x24, // 00100100 120 78  x
        0x6e, // 01101110 121 79  y
        0x48, // 01001000 122 7A  z
        0x39, // 00111001 123 7B  {
        0x06, // 00000110 124 7C  |
        0x0f, // 00001111 125 7D  }
        0x01, // 00000001 126 7E  ~
        };

void led8Draw(BYTE index, char c) {
    BYTE mask = c;
    if (index >= led8Count)
        return;
    mask -= 0x20;
    if (mask >= sizeof(led8tab))
        mask = '?' - 0x20;
    mask = led8tab[mask];
    led8Cache[index] = mask;
    led8Set(index, mask);
}

void led8Refresh() {
    BYTE i, mask;
    for (i = 0; i < led8Count; i++) {
        mask = led8Cache[i];
        led8Set(i, mask);
    }
}

void led8Puts(const char *mesg) {
    BYTE index = 0;
    char c;
    while (c = *mesg++) {
        led8Draw(index++, c);
        if (index >= led8Count)
            break;
    }
    while (index++ < led8Count)
        led8Set(index, 0);
}

/**
 * @param apn arbitrary number.
 * @param cb BYTEs of apn
 * @param frac10 fractional width, [0, frac10^10)
 */
void led8PutNum(const BYTE *apn, BYTE cb, BYTE frac10)
__reentrant {
    BYTE pos = led8Count;
    BYTE buf[17]; // led8Count + 1, 16+1 is just fine.
    BYTE *p;

    // log(0x100, 10^16) ~ 6.64
    if (cb > 6)
        cb = 6;
    int cc = apnToString(buf, apn, cb, 10);

    p = buf + cc;
    while (cc-- && pos)
        led8Draw(--pos, *--p);
}
