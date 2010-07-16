#include <assert.h>
#include <malloc.h>
#include <string.h>

#include "message.h"

int pollCount = 0;
const PollEntry *pollTable = NULL;
static __xdata int *pollIndexes = NULL;

int handlerCount;
const MessageHandler *handlerTable;

mbuf_t mbuf = NULL;

static int size = 0;
static int start = 0;
static int end = 0;

__xdata int statMTotal = 0;
__xdata int statMDrops = 0;

void initMQ(
        int _pollCount, const PollEntry *_pollTable,
        int _handlerCount, const MessageHandler *_handlerTable,
        int mbufSize) {
    pollCount = _pollCount;
    pollTable = _pollTable;
    pollIndexes = (__xdata int *) malloc(sizeof(int) * pollCount);
    handlerCount = _handlerCount;
    handlerTable = _handlerTable;

    size = mbufSize;
    mbuf = (mbuf_t) malloc(size);
    start = 0;
    end = 0;
}

static bool compact(int requiredSize) {
    if (end >= start) {
        int free = size - end;
        if (free < requiredSize) {
            int freesum = free + (start - 1);
            if (freesum < requiredSize)
                return false;
            else {
                memcpy(mbuf, mbuf + start, end - start);
                end -= start;
                start = 0;
            }
        }
    } else {
        int free = (start - 1) - end;
        if (free < requiredSize)
            return false;
    }
    return true;
}

void enqueue_void(m_t message) {
    statMTotal++;
    if (compact(1)) {
        mbuf[end++] = message;
        end %= size;
    } else
        statMDrops++;
}

void enqueue_b(m_t message, byte param) {
    statMTotal++;
    if (compact(2)) {
        mbuf[end++] = message;
        mbuf[end++] = param;
        end %= size;
    } else
        statMDrops++;
}

void enqueue_bb(m_t message, byte param, byte byteData) {
    statMTotal++;
    if (compact(3)) {
        mbuf[end++] = message;
        mbuf[end++] = param;
        mbuf[end++] = byteData;
        end %= size;
    } else
        statMDrops++;

}
void enqueue_w(m_t message, word data) {
    statMTotal++;
    if (compact(3)) {
        mbuf[end++] = message;
        *(word *) &mbuf[end] = data;
        end += 2;
        end %= size;
    } else
        statMDrops++;
}

void enqueue_bw(m_t message, byte param, word data) {
    statMTotal++;
    if (compact(4)) {
        mbuf[end++] = message;
        mbuf[end++] = param;
        *(word *) &mbuf[end] = data;
        end += 2;
        end %= size;
    } else
        statMDrops++;
}

/**
 * @return false if the queue is empty.
 */
bool dequeue() {
    if (end == start)
        return false;

    {
        // assert (op, param, data) in a linear space.
        m_t message = mbuf[start++];
        // FORCE-LINEAR   start %= size;

        char payloadFormat = message >> 5;
        char payloadSize = payloadFormat >> 1;
        // assert (end - start > payloadSize);

        byte param;
        word data;

        switch (payloadFormat) {
        case 0: // 00.0
        case 1: // 00.1
            param = 0;
            data = 0;
            break;
        case 2: // 01.0
        case 3: // 01.1
            param = mbuf[start++];
            data = 0;
            break;

        case 4: // 10.0
            param = mbuf[start++];
            data = mbuf[start++];
            break;

        case 5: // 10.1
            param = 0;
            data = *(word *) &mbuf[start];
            start += 2;
            break;

        case 6: // 11.0
        case 7: // 11.1
            param = mbuf[start++];
            data = *(word *) &mbuf[start];
            start += 2;
            break;

        default:
            assert(false);
            param = data = 0;
        }
        start %= size;
    }

    {
        int i;
        for (i = 0; i < handlerCount; i++) {
            MessageHandler handler = handlerTable[i];
            if ((*handler)(message, param, data))
                break;
        }
    }
    return true;
}

static bool pollingEvents = false;
void pollEvents() { // Don't have to be reentrant.

    const PollEntry *pEntry;
    __xdata int *pIndex;
    int i;

    if (pollingEvents)
        return;

    pollingEvents = 1;

    pEntry = pollTable;
    pIndex = pollIndexes;

    for (i = 0; i < pollCount; i++) {
        int interval = pEntry->pollInterval;
        int index = *pIndex;
        if (index++ == 0)
            // if (pEntry->poll()) mqDirty = true;
            pEntry->poll();
        if (index > interval)
            index = 0;
        *pIndex++ = index;
        pEntry++;
    }

    pollingEvents = 0;
}
