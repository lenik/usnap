#include <stdio.h>
#include <8051.h>
#include <cos51/display/led8.h>
#define COMM_BUFSIZE 32
#include <cos51/io/comm.h>
#include <cos51/dk/hc6800.h>

#define BAUD        9600
#define BYTERATE    (BAUD / 10)

word cap = 0;
byte bitbuf;
byte bitn = 0;

word irdints = 0;

void main() {
    int i = 0;

    IT0 = 1; // falling edge int.
    EX0 = 1; // enable ext-int 0

    setTimer1Baud(BAUD);
    ET1 = 1;

    setTimer2Baud(BAUD);
    SCON = 0x40; // 01.0.1.0010  SM=2, ¬REN
    ES = 1;
    EA = 1;
    REN = 1; // not necessary.

    IRD = 1; // for read

    //
    //    P1_0 = 0;
    //    P1_1 = 0;
    //    P1_2 = 0;
    //    P1_3 = 0;
}

void ird_int()
__interrupt( INT_X0) {
    cap = BYTERATE;

    irdints++;

    P1_0 ^= 1;

    printf("Ci=%d\n", cap);
}

void timer1()
__interrupt( INT_TIMER1) {

    P1_1 = cap ? 0 : 1;

    // don't capture at all.
    if (!cap) {
        return;
    }

    // the very beginning
    if (cap == BYTERATE && bitn == 0) {
        puts("<begin>");
    }

    bitbuf <<= 1;
    bitbuf |= IRD;

    if (bitn == 7) { // 0..7 bits are buffered.
        send(bitbuf);
        bitbuf = 0;
        bitn = 0;
        cap--;
    } else {
        bitn++;
    }
}
