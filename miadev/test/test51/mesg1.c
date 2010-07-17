#include <8051.h>

#define HEAP_SIZE 200
#include <_heap.h>

#include <cos51/message.h>

#include <cos51/crazykbd.h>
#define CRAZYKBD_MAXKEY 10
#define CRAZYKBD_TRANSTAB
#include <cos51/crazykbd_buf.h>

keyscan_t kbd_scan(byte *kbuf) {
    kbuf[0] = P1 << 4;
    return 4;
}

int lockdown = 0;

byte myHandler(m_t message, byte param, word data) __reentrant {
    byte handled = 0;
    byte LED = 0;
    switch (message) {
    case M_KEYDOWN:
        LED |= 8;
        handled = 1;
        break;
    case M_KEYUP:
        handled = 1;
        break;
    }
    LED |= param;

    data;

    if (handled) {
        P1 = (P1 & 0xF0) | LED;
    }
        lockdown = 10000;
    return handled;
}

__code PollEntry pollTables[] = { { crazykbd_poll, 1 }, };

__code MessageHandler handlers[] = { myHandler, };

#define OSCFREQ_KHZ         11954
#define TSCALE              OSCFREQ_KHZ / 12000

#define US2TC(us)           ((us) * TSCALE)
#define MS2TC(ms)           US2TC((ms) * 1000)

#define US2TCC(us, type)    ((~(type) US2TC(us)) + 1)
#define MS2TCC(ms, type)    ((~(type) MS2TC(ms)) + 1)

void main() {
    TR1 = 0;
    TMOD = 0x20; // 0.0.10 xxxx, Timer 1: timer, mode 2 (TH ⇒ TL)
    TH1 = 0x9D; // US2TCC(100, byte);

    EA = 1;
    ET1 = 1;
    TR1 = 1;

    INITMQ(pollTables, handlers, 100);
    while (1)
        dequeue();
}

static byte xx = 0;
void pollTimer()
__interrupt 3 __using 1 {
    if (lockdown) {
        lockdown--;
    } else {
        xx++;
        P1 = (P1 & 0xF0) | (xx >> 4);
    }
    pollEvents();
}
