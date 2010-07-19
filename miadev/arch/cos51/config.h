#ifndef COS51_CONFIG_H
#define COS51_CONFIG_H

#define INT_X0          0
#define INT_TIMER0      1
#define INT_X1          2
#define INT_TIMER1      3
#define INT_UART        4
#define INT_TIMER2      5
#define INT_X2          6
#define INT_X3          7

#define RBANK_USER      1
#define RBANK_COS51     3

#define RBANK_SUNIT     RBANK_COS51

#ifndef XTAL
#   define XTAL 12000000.0
#endif

#ifndef XMUL
#   define XMUL 12
#endif

#include "const.h"

#endif
