#include <stddef.h>
#include <8052.h>
#include "config.h"
#include "comm.h"

/**
 * Serial Communication Implementation
 */

extern __xdata char *sendbuf;
extern __xdata char *recvbuf;
extern byte sendbuf_size;
extern byte recvbuf_size;

static volatile byte sendp = 0;
static volatile byte buffp = 0;

static volatile byte readp = 0;
static volatile byte recvp = 0;

static bool send_empty = 1;
static bool send_full = 0;
static bool sending = 0;

static bool recv_empty = 1;
static bool recv_full = 0;
static bool recv_timeout = 0;

TimeoutProc timeout_proc = NULL;

void commSerialProc()
__interrupt(4) __using(RBANK_COS51) {
    if (RI) {
        if (recv_full) {
            // unexpected
#ifdef COMM_DEBUG
            puts("recv_full but RI");
            putchar(REN ? '+' : '-');
            puts("REN\n");
#endif
            REN = 0;
        } else {
            recvbuf[recvp++] = SBUF;
            recvp %= recvbuf_size;
            recv_empty = 0;
            if (recvp == readp)
            recv_full = 1;
        }
        RI = 0;
    }
    if (TI) {
        if (send_empty) {
            // direct send
            sending = 0;
        } else {
            // send the next char
            SBUF = sendbuf[++sendp];
            sendp %= sendbuf_size;
            send_full = 0;
            if (sendp == buffp) {
                send_empty = 1;
                sending = 0;
            }
        }
        TI = 0;
    }
}

bool send(char ch) {
    if (send_empty) {
        if (!sending) {
            // critical:
            // what if TI==1 then SBUF=x and TI=0?
            SBUF = ch;
            sending = 1;
            return 1;
        } else {
            // sendp -> [0:sending-skip] [1:ch] [2] <-- buffp
            buffp = (buffp + 1) % sendbuf_size;
        }
    } else
        while (send_full) {
            if (timeout_proc && timeout_proc())
                return 0;
        }

    sendbuf[buffp++] = ch;
    buffp %= sendbuf_size;
    send_empty = 0;

    ES = 0;
    if (buffp == sendp)
        send_full = 1;
    ES = 1;

    return 1;
}

char recv() {
    char ch;
    if (recv_empty) {
        REN = 1;
        while (recv_empty) {
            if (timeout_proc && timeout_proc()) {
                recv_timeout = 1;
                return (char) -1;
            }
        }
    }

    ch = recvbuf[readp++];
    readp %= recvbuf_size;
    recv_full = 0;

    ES = 0;
    if (readp == recvp)
        recv_empty = 1;
    ES = 1;

    recv_timeout = 0;
    return ch;
}

word sendblob(char *p, word size) {
    word remain = size;
    while (remain) {
        if (!send(*p++))
            break;
        remain--;
    }
    return size - remain;
}

word recvblob(char *p, word size) {
    word remain = 0;
    char ch;
    while (remain) {
        ch = recv();
        if (recv_timeout)
            break;
        *p++ = ch;
        remain--;
    }
    return size - remain;
}

byte available() {
    if (recv_empty)
        return 0;
    if (recv_full)
        return 0xff;
    if (readp < recvp)
        return recvp - readp;
    else
        return (recvbuf_size - readp) + recvp;
}

void flush() {
    while (!send_empty) {
        if (timeout_proc && timeout_proc())
            break;
    }
}
