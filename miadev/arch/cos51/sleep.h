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

#   define T0_IMPL void timer0Hub() __interrupt 1 { if (timerProc0) timerProc0(); }
#   define T1_IMPL void timer1Hub() __interrupt 3 { if (timerProc1) timerProc1(); }
#   define T2_IMPL void timer2Hub() __interrupt 5 { if (timerProc2) timerProc2(); }

#else

    extern volatile __bit signal0;
    extern volatile __bit signal1;
    extern volatile __bit signal2;

#define T0_IMPL void sleepTimer0() __interrupt 1 { signal0 = 1; }
#define T1_IMPL void sleepTimer1() __interrupt 3 { signal1 = 1; }
#define T2_IMPL void sleepTimer2() __interrupt 5 { signal2 = 1; }

#endif

void usleep0(register unsigned int us);
void usleep1(register unsigned int us);
void usleep2(register unsigned int us);

void msleep0(unsigned int ms);
void msleep1(unsigned int ms);
void msleep2(unsigned int ms);

void sleep0(byte sec);
void sleep1(byte sec);
void sleep2(byte sec);

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

void udelay8(register byte us);
void udelay(register unsigned int us);
void mdelay(unsigned int ms);
void delay(byte sec);

#endif
