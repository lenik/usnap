#include <stddef.h>

#include "slap.h"
#include "io/crc8.h"

#ifndef SLAP_MAXPORT
#define SLAP_MAXPORT 16
#endif

static RecvProc slapPorts[SLAP_MAXPORT];

void slapRegister(int port, RecvProc recvf) {
    slapPorts[port] = recvf;
}

void slapUnregister(int port) {
    slapPorts[port] = NULL;
}

#define HEAD        0
#define LENGTH      1
#define PAYLOAD     2
#define CHECKSUM    3

static BYTE slapState = HEAD;

extern __xdata BYTE slapPayloadBuffer[];
static __xdata BYTE *slapPtr = NULL;
static BYTE slapPort = 0;
static BYTE slapPayloadLen = 0;
static BYTE slapRemain = 0;
static BYTE slapCRC = 0;

__xdata int statSlapPackets = 0;
__xdata int statSlapDelivered = 0;
__xdata int statSlapCrcError = 0;
__xdata int statSlapSyncs = 0;

void slapRecv(BYTE b) {
    switch (slapState) {
    case HEAD:
        crc8Reset();
        crc8Update(b); // pre-update for opt.

        statSlapPackets++;

        slapPtr = slapPayloadBuffer;
        slapPort = b & 0x0f;

        b >>= 4;
        if (b == 0x0f) {
            slapState = LENGTH;
            return;
        } else {
            slapPayloadLen = b;
            slapRemain = b;
            slapState = b ? PAYLOAD : CHECKSUM;
        }
        return;
    case LENGTH:
        slapPayloadLen = b;
        slapRemain = b;
        slapState = b ? PAYLOAD : CHECKSUM;
        break;
    case PAYLOAD:
        *slapPtr++ = b;
        if (! --slapRemain)
            slapState = CHECKSUM;
        break;
    case CHECKSUM:
        if (b == slapCRC) {
            RecvProc recvf = slapPorts[slapPort];
            if (recvf) {
                recvf(slapPayloadBuffer, slapPayloadLen);
                statSlapDelivered++;
            }
        } else {
            statSlapCrcError++;
        }
        slapState = HEAD;
        break;
    }
    slapCRC = crc8Update(b);
}

void slapRecvBlock(BYTE *pblock, BYTE cb) {
    while (cb--)
        slapRecv(*pblock++);
}
