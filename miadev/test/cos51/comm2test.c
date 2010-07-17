#include <8052.h>
#include <cos51/types.h>
#include <cos51/comm.h>
#include <cos51/sleep.h>
#include <cos51/sunit.h>

#include <cos51/dk/hc6800.h>

__xdata byte recvbuf[100];
volatile byte sendp = 0;
volatile byte recvp = 0;
__bit sending = 0;
__bit quit = 0;

void slsend(byte c) {
    while (sending)
        ;
    SBUF = c;
    sending = 1;
}

void slrecv()
__interrupt(4) {
    if (RI) {
        if (SBUF == (byte) 'Q') {
            quit = 1;
            REN = 0;
        } else if (!quit) {
            recvbuf[recvp++] = SBUF;
            recvp %= sizeof(recvbuf);
        }
        RI = 0;
    }
    if (TI) {
        sending = 0;
        TI = 0;
    }
}

void testCase() {
    byte b;

    setTimer2Baud(1200);
    SCON = 0x40; // 01.0.1.0010  SM=2, ¬REN
    ES = 1;
    EA = 1;
    REN = 1;

    while (1) {
        if (recvp != sendp) {
            slsend('[');
            while (recvp != sendp) {
                b = recvbuf[sendp++];
                slsend(b);
                sendp %= sizeof(recvbuf);
            }
            slsend(']');
        }
        if (quit)
            break;
    }
    while (sending)
        ;
    vmstop();
}
