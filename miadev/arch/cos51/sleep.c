#include <stddef.h>
#include <8051.h>

#include "sleep.h"

volatile __bit signal0;
volatile __bit signal1;
volatile __bit signal2;

__near TimerProc timerProc0 = NULL;
__near TimerProc timerProc1 = NULL;
__near TimerProc timerProc2 = NULL;

/**
 * TODO Enhance:
 *
 * The waitTest() is implemented in a hard test loop, which consumes lot of power.
 * And should be implemented in CPU-IDLE to reduce power.
 *
 * For *delay() methods:
 *      udelay(us) which gives accurate latency, never using CPU-IDLE,
 *      mdelay(ms) which is less accurate can let xtal slow down to reduce power,
 *      delay(sec) consider using external RTC interrupt to implement the sleep mode.
 */

#ifdef TIMER_HUB
#   define waitInit(t) timerProc##t = sleepTimerProc##t
#   define waitTest(t) (timerProc##t)
#else
#   define waitInit(t) signal##t = 0;
#   define waitTest(t) (! signal##t)
#endif

void usleep0(register unsigned int us) {
    if (us <= 1) return;
    us = ~us + 1;
    waitInit(0);
    TMOD = 0x01;
    TH0 = us >> 8;
    TL0 = us & 0xFF;
    EA = 1;
    ET0 = 1;
    TR0 = 1;
    while (waitTest(0))
        ;
}

void usleep1(register unsigned int us) {
    if (us <= 1) return;
    us = ~us + 1;
    ET1 = 0;
    waitInit(1);
    TMOD = 0x10;
    TH1 = us >> 8;
    TL1 = us & 0xFF;
    EA = 1;
    ET1 = 1;
    TR1 = 1;
    while (waitTest(1))
        ;
}

void usleep2(register unsigned int us) {
    if (us <= 1) return;
#ifdef REG8052_H
    us = ~us + 1;
    waitInit(2);
    // TMOD = 0x10;
    TH2 = us >> 8;
    TL2 = us & 0xFF;
    EA = 1;
    ET2 = 1;
    // not implemented
    TR2 = 1;
    while (waitTest(2)) ;
#else
    us;
#endif
}

/**
 * Currently, *delay() only does accurate for chips:
 *      XTAL = 12MHz
 *      12T mode
 *      DJNZ = 2 cycles
 */
#define _DJNZ_CYCLE     (XTAL / XMUL * 2)

void udelay8(register byte us) {
    us;
    __asm           // ..(CALL)
        subb a, #9  // .
        jc 2$       // ..
        // assert C=0
        rrc a       // . (us / _DJNZ_CYCLE))
        mov r2, a   // .
    1$: djnz r2, 1$
    2$:
    __endasm;       // ..(RET)
}

#define UDELAY_START_CYCLES 21

/**
 * Registers: A, R2, R3
 *
 * @param us Must be passed by DPTR register.
 */
void udelay(register unsigned int us) {
    us;
    __asm               // ..(CALL)
        mov a, dph      // .
        jz 3$           // ..
        mov a, dpl      // .
        subb a, #UDELAY_START_CYCLES // .
        jc 3$           // ..
        mov r2, a       // .
        mov a, dph      // .
        subb a, #-2     // . [ INC R3]
        clr c           // .
        rrc a           // . (us / _DJNZ_CYCLE)
        mov r3, a       // .
        mov a, r2       // .
        rrc a           // . (us / _DJNZ_CYCLE)
        inc a           // . [ INC R2]
        mov r2, a       // .
    2$: djnz r2, 2$
        mov r2, #(256 - 3) // [.]
        djnz r3, 2$     // [..] Should subtract [3] from 256.
    3$:
    __endasm;           // .. (RET)
}

void msleep0(unsigned int ms) { while (ms > 30) { usleep0(29991); ms -= 30; } usleep0(ms * 1000); }
void msleep1(unsigned int ms) { while (ms > 30) { usleep1(29991); ms -= 30; } usleep1(ms * 1000); }
void msleep2(unsigned int ms) { while (ms > 30) { usleep2(29991); ms -= 30; } usleep2(ms * 1000); }
void mdelay(unsigned int ms)  { while (ms > 30) { udelay(29991); ms -= 30; }  udelay(ms * 1000); }

void sleep0(byte sec) { byte t; while (sec--) for (t = 0; t < 33; t++) usleep0(30300); }
void sleep1(byte sec) { byte t; while (sec--) for (t = 0; t < 33; t++) usleep1(30300); }
void sleep2(byte sec) { byte t; while (sec--) for (t = 0; t < 33; t++) usleep2(30300); }
void delay(byte sec)  { byte t; while (sec--) for (t = 0; t < 33; t++) udelay(30300); }

//#ifdef TIMER_HUB
void sleepTimerProc0() { timerProc0 = NULL; }
void sleepTimerProc1() { timerProc1 = NULL; }
void sleepTimerProc2() { timerProc2 = NULL; }
//#endif
