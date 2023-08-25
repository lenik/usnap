#ifndef COS51_MESSAGE_H
#define COS51_MESSAGE_H

#include <stdbool.h>

#include "types.h"

typedef unsigned char m_t;

#define _M_VOID(x)      (0x00 | (x))
#define _M_B(x)         (0x40 | (x))
#define _M_W(x)         (0x80 | (x))
#define _M_BB(x)        (0xA0 | (x))
#define _M_BW(x)        (0xC0 | (x))

#define M_DEV_ATTACH    _M_B(1)
#define M_DEV_DETACH    _M_B(2)
#define M_POWER _M_B(3)

#define M_KEYDOWN       _M_B(10)
#define M_KEYUP         _M_B(11)
#define M_KEY           _M_B(12)
#define M_MOUSEDOWN     _M_B(13)
#define M_MOUSEUP       _M_B(14)
#define M_CLICK         _M_B(15)
#define M_DBLCLICK      _M_B(16)

#define M_RECV          _M_BB(1)
#define M_RECVL         _M_BW(1)
#define M_SENT          _M_BB(1)

//SDCC doesn't expand the macro until it's used.
//#undef _M_VOID
//#undef _M_B
//#undef _M_W
//#undef _M_BB
//#undef _M_BW

typedef struct _PollEntry {

    /**
     * @return non-zero if there has event been enqueued.
     */
    BYTE (*poll)();

    int pollInterval;

} PollEntry;

extern int pollCount;
extern const PollEntry *pollTable;

/**
 * @return non-zero if the message is handled.
 */
typedef BYTE (*MessageHandler)(m_t message, BYTE param, WORD ndata) __reentrant;

// extern int handlerCount;
// SDCC-BUGFIX: declare/define type mismatches: (in large-mode only)
// extern const MessageHandler *handlerTable;

#define INITMQ(PTAB, HTAB, MS) \
    initMQ(sizeof(PTAB) / sizeof(__code void *), (PTAB), \
            sizeof(HTAB) / sizeof(__code void *), (HTAB), \
            (MS))

void initMQ(
        int pollCount, const PollEntry *pollTable,
        int handlerCount, const MessageHandler *handlerTable,
        int mbufSize
);

typedef __xdata BYTE *mbuf_t;

extern mbuf_t mbuf;
extern __xdata int statMTotal;
extern __xdata int statMDrops;

void enqueue_void(m_t message);
void enqueue_b(m_t message, BYTE param);
void enqueue_bb(m_t message, BYTE param, BYTE byteData);
void enqueue_w(m_t message, WORD data);
void enqueue_bw(m_t message, BYTE param, WORD data);

/**
 * @return false if the queue is empty.
 */
bool dequeue();

/**
 * The main function should as follow:
 *
 * void timer() interrupt 1 { pollEvents(); }
 * void main() { INITMQ(...); while (1) dequeue(); }
 */
void pollEvents();

#endif
