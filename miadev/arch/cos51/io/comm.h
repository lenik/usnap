#ifndef COS51_COMM_H
#define COS51_COMM_H

#include "../types.h"
#include "baud.h"

#ifdef COMM_BUFSIZE
__xdata BYTE sendbuf[COMM_BUFSIZE];
__xdata BYTE recvbuf[COMM_BUFSIZE];
size_t sendbuf_size = COMM_BUFSIZE;
size_t recvbuf_size = COMM_BUFSIZE;
#endif

void commSerialProc() __interrupt(INT_UART);

typedef bool (*TimeoutProc)();

extern TimeoutProc timeout_proc;

bool send(BYTE ch);
int recv();

/**
 * @return the actual BYTEs sent if timeout.
 */
WORD sendblob(BYTE *buf, WORD size);

/**
 * @return the actual BYTEs received if timeout.
 */
WORD recvblob(BYTE *buf, WORD size);

size_t available();

void flush();

#endif
