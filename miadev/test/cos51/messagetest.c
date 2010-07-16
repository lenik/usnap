#define DEBUG
#include <cos51/sunit.h>
#include <cos51/message.h>

#define HEAP_SIZE 200
#include <_heap.h>

byte handler(m_t message, byte param, word data)
__reentrant {
    puts("Handler: ");
    printf("%d %d %d\n", message, param, data);
    return true;
}

static char val = 'a';
byte poll() {
    puts("poll!");
    if (val >= 'c')
        return 0;
    enqueue_bb(M_RECV, 7, val++);
    return 1;
}

__code PollEntry pollTables[] = { { poll, 1 }, };
__code MessageHandler handlers[] = { handler, };

void testCase() {
    TRACE("initmq");
    INITMQ(pollTables, handlers, 100);

    TR1 = 0;
    TMOD = 0x10; // 0.0.10 xxxx, Timer 1: timer, mode 2 (TH ⇒ TL)
    TH1 = 0x03; // US2TCC(100, byte);
    TL1 = 0x03;

    EA = 1;
    ET1 = 1;
    TR1 = 1;

    TRACE("dequeue-loop");
    while (val < 'h') {
        puts("dequeue");
        dequeue();
    }
}

void pollTimer()
__interrupt 3 __using 1 {
    puts("pollTimer");
    TH1 = 3;
    TL1 = 3;

    pollEvents();
}
