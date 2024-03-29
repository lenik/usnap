#ifndef COS51_SLAP_H
#define COS51_SLAP_H

#include "types.h"
#include "io/crc8.h"

/**
 * Serial Line A-network Packets
 *
 * (IP4: AAAA network)
 */

typedef void (*RecvProc)(__xdata BYTE *payload, BYTE cb) __reentrant;

void slapRegister(int port, RecvProc recvf);
void slapUnregister(int port);

extern __xdata int statSlapPackets;
extern __xdata int statSlapDelivered;
extern __xdata int statSlapCrcError;
extern __xdata int statSlapSyncs;

void slapRecv(BYTE b);
void slapRecvBlock(BYTE *buf, BYTE cb);

#ifdef SLAP_PAYLOAD
__xdata BYTE slapPayloadBuffer[SLAP_PAYLOAD];
#endif

#endif
