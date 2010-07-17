#define HEAP_SIZE 200
#include <_heap.h>

#define DEBUG
#include <cos51/message.h>
#include <cos51/sunit_stdio.h>

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
    // TODO...
    vmstop();

    TRACE("initmq");

    INITMQ(pollTables, handlers, 100);

    TMOD = 0x01; // 0.0.10 xxxx, Timer 1: timer, mode 2 (TH ⇒ TL)
    TH0 = 0x03; // US2TCC(100, byte);
    TL0 = 0x03;
    TR0 = 1;
    ET0 = 1;

    TRACE("dequeue-loop");

    while (val < 'h') {
        puts("dequeue");
        dequeue();
    }
}

void pollTimer()
__interrupt(1) __using(1) {
    puts("pollTimer");
    TH1 = 3;
    TL1 = 3;

    pollEvents();
}
