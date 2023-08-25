#ifndef COS51_SLEEP_H
#define COS51_SLEEP_H

#include "types.h"

#define TIMER_HUB

#ifdef TIMER_HUB

    typedef void (*TimerProc)();

    extern __near TimerProc timerProc0;
    extern __near TimerProc timerProc1;
    extern __near TimerProc timerProc2;

    void sleepTimerProc0();
    void sleepTimerProc1();
    void sleepTimerProc2();

#   define T0_IMPL void timer0Hub() __interrupt(INT_TIMER0) { if (timerProc0) timerProc0(); }
#   define T1_IMPL void timer1Hub() __interrupt(INT_TIMER1) { if (timerProc1) timerProc1(); }
#   define T2_IMPL void timer2Hub() __interrupt(INT_TIMER2) { if (timerProc2) timerProc2(); }

#else

    extern volatile __bit signal0;
    extern volatile __bit signal1;
    extern volatile __bit signal2;

#define T0_IMPL void sleepTimer0() __interrupt(INT_TIMER0) { signal0 = 1; }
#define T1_IMPL void sleepTimer1() __interrupt(INT_TIMER1) { signal1 = 1; }
#define T2_IMPL void sleepTimer2() __interrupt(INT_TIMER2) { signal2 = 1; }

#endif

void usleep0(register unsigned int us);
void usleep1(register unsigned int us);
void usleep2(register unsigned int us);

void msleep0(unsigned int ms);
void msleep1(unsigned int ms);
void msleep2(unsigned int ms);

void sleep0(BYTE sec);
void sleep1(BYTE sec);
void sleep2(BYTE sec);

#ifndef SLEEPTIEMR
#define SLEEPTIMER 1
#endif

#if SLEEPTIMER == 0

#   define usleep   usleep0
#   define msleep   msleep0
#   define sleep    sleep0
#   define T_IMPL   T0_IMPL

#elif SLEEPTIMER == 1

#   define usleep   usleep1
#   define msleep   msleep1
#   define sleep    sleep1
#   define T_IMPL   T1_IMPL

#elif SLEEPTIMER == 2

#   define usleep   usleep2
#   define msleep   msleep2
#   define sleep    sleep2
#   define T_IMPL   T2_IMPL

#endif


#define __nop1 \
        nop
#define __nop2 \
        nop; \
        nop
#define __nop5 \
         __nop2; \
         __nop2; \
         __nop1

#define udelay_1()  __asm __nop1 __endasm
#define udelay_2()  __asm __nop2 __endasm
#define udelay_3()  __asm __nop2; __nop1 __endasm
#define udelay_4()  __asm __nop2; __nop2 __endasm
#define udelay_5()  __asm __nop5 __endasm
#define udelay_6()  __asm __nop5; __nop1 __endasm
#define udelay_7()  __asm __nop5; __nop2 __endasm
#define udelay_8()  __asm __nop5; __nop2; __nop1 __endasm
#define udelay_9()  __asm __nop5; __nop2; __nop2 __endasm
#define udelay_10() __asm __nop5; __nop5 __endasm

void udelayTiny(register BYTE us);
void udelay(register unsigned int us);
void mdelay(unsigned int ms);
void delay(BYTE sec);

#endif
