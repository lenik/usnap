#include <stddef.h>
#include <8052.h>
#include "config.h"
#include "comm.h"

/**
 * Serial Communication Implementation
 */

extern __xdata BYTE sendbuf[];
extern __xdata BYTE recvbuf[];
extern BYTE sendbuf_size; // must <= 255
extern BYTE recvbuf_size; // must <= 255

static volatile BYTE sendp = 0;
static volatile BYTE buffp = 0;

static volatile BYTE readp = 0;
static volatile BYTE recvp = 0;

static volatile bool send_empty = 1;
static volatile bool send_full = 0;

static volatile bool recv_empty = 1;
static volatile bool recv_full = 0;
static volatile bool recv_timeout = 0;

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
            recvbuf[recvp] = SBUF;
            recvp++;
            recvp %= recvbuf_size;
            recv_empty = 0;
            if (recvp == readp)
                recv_full = 1;
        }
        RI = 0;
    }
    if (TI) {
        if (send_empty) {
            // unexpected
        } else {
            // send the next char
            sendp++;
            sendp %= sendbuf_size;
            send_full = 0;
            if (sendp == buffp)
                send_empty = 1;
            else
                SBUF = sendbuf[sendp];
        }
        TI = 0;
    }
}

bool send(BYTE ch) {
    while (send_full) {
        if (timeout_proc && timeout_proc())
            return 0;
    }

    sendbuf[buffp++] = ch;
    buffp %= sendbuf_size;

//    ES = 0;

    if (send_empty)
        SBUF = ch;
    send_empty = 0;

    if (buffp == sendp)
        send_full = 1;

//    ES = 1;
    return 1;
}

int recv() {
    unsigned char ch;
    if (recv_empty) {
        REN = 1;
        while (recv_empty) {
            if (timeout_proc && timeout_proc()) {
                recv_timeout = 1;
                return -1;
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
    return (int) ch;
}

WORD sendblob(char *p, WORD size) {
    WORD remain = size;
    while (remain) {
        if (!send(*p++))
            break;
        remain--;
    }
    return size - remain;
}

WORD recvblob(char *p, WORD size) {
    WORD remain = 0;
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

size_t available() {
    if (recv_empty)
        return 0;
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
