#include <8052.h>
#include <cos51/types.h>
#include <cos51/comm.h>
#include <cos51/sleep.h>
#include <cos51/dk/hc6800.h>

#define SUNIT_NOCOMM
#include <cos51/sunit.h>

__xdata byte recvbuf[30];
register byte sendp = 0;
register byte recvp = 0;
__bit quit = 0;

void slsend(byte c) {
    while (!TI)
        ;
    // mdelay(100);
    SBUF = c;
    TI = 0;
}

void _slrecv()
__interrupt(4) {
    if (RI) {
        byte b = SBUF;
        recvbuf[recvp++] = b;
        if (b == (byte) 'Q') {
            quit = 1;
            REN = 0;
        }
        recvp %= sizeof(recvbuf);
        RI = 0;
    }
}

void testCase() {
    byte b;

    EA = 1;

    //    TMOD = 0x20;
    //    TH1 = 0;
    //    TR1 = 1;
    //    ET1 = 0;
    setTimer2Baud(9600);

    //    PCON &= 0x7f; // SMOD = 0;
    SCON = 0x52; // 01.0.1.0010  SM=2, REN, TI
    // TI = 1;
    ES = 1;

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
    slsend('q');
    slsend('u');
    slsend('i');
    slsend('t');
    while (!TI)
        ;
    vmstop();
}
