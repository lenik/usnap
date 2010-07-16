#ifndef COS51_SLAP_H
#define COS51_SLAP_H

#include "types.h"
#include "crc8.h"
#include "message.h"

/**
 * Serial Line A-network Packets
 *
 * (IP4: AAAA network)
 */

typedef void (*RecvProc)(__xdata byte *payload, byte cb) __reentrant;

void slapRegister(int port, RecvProc recvf);
void slapUnregister(int port);

extern __xdata int statSlapPackets;
extern __xdata int statSlapDelivered;
extern __xdata int statSlapCrcError;
extern __xdata int statSlapSyncs;

void slapRecv(byte b);
void slapRecvBlock(byte *buf, byte cb);

#ifdef SLAP_PAYLOAD
__xdata byte slapPayloadBuffer[SLAP_PAYLOAD];
#endif

#endif
