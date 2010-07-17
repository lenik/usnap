#include <8052.h>
#include <cos51/types.h>
#include <cos51/sleep.h>
#define COMM_BUFSIZE 10
#include <cos51/comm.h>
#include <cos51/sleep.h>
#include <cos51/sunit.h>
#include <cos51/dk/hc6800.h>

void testCase() {
    char c;

    setTimer1Baud(1200);
    SCON = 0x40; // 01.0.1.0010  SM=2, ¬REN
    ES = 1;
    EA = 1;
    REN = 1;

    while (1) {
        if (available()) {
            // send('[');
            while (available()) {
                c = recv();
                if (c == 'Q') {
                    flush();
                    return;
                }
                send(c);
            }
            // send(']');
        }
    }

}
