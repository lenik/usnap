// #define DEBUG
#include <cos51/sunit_stdio.h>

#define SLAP_PAYLOAD 100
#include <cos51/slap.h>

void recv1(__xdata byte *p, byte cb) __reentrant {
    printf("p1[%d]: \n", cb);
    while (cb--) {
        putchar(*p++);
    }
    putchar('\n');
}

void recv2(__xdata byte *p, byte cb) __reentrant {
    printf("p2[%d]: \n", cb);
    while (cb--) {
        putchar(*p++);
    }
    putchar('\n');
}

byte c_p1[] = { 0x51, 'h', 'e', 'l', 'l', 'o', };
byte m_p1[] = { 0x51, 'h', 'e', 'l', 'l', 'o', 0x53 };

byte c_p2[] = { 0xF2, 5, 'h', 'e', 'l', 'l', 'o', };
byte m_p2[] = { 0xF2, 5, 'h', 'e', 'l', 'l', 'o', 0x1b };

byte m_badcrc[] = { 0x31, 'x', 'x', 'x', 0 };

byte c_noaddr[] = { 0x33, 'x', 'x', 'x', };
byte m_noaddr[] = { 0x33, 'x', 'x', 'x', 0xc0 };

void testCase() {
    crc8Init(CRC8_CCITT);

    //    crc8Reset();
    //    printf("c-p1: %x\n", crc8UpdateBlock(c_p1, sizeof(c_p1)));
    //    crc8Reset();
    //    printf("c-p2: %x\n", crc8UpdateBlock(c_p2, sizeof(c_p2)));
    //    crc8Reset();
    //    printf("c-noaddr: %x\n", crc8UpdateBlock(c_noaddr, sizeof(c_noaddr)));

    TRACE("register...");
    slapRegister(1, recv1);
    slapRegister(2, recv2);

    TRACE("m-p1");
    slapRecvBlock(m_p1, sizeof(m_p1));
    TRACE("m-p2");
    slapRecvBlock(m_p2, sizeof(m_p2));
    TRACE("m-badcrc");
    slapRecvBlock(m_badcrc, sizeof(m_badcrc));
    TRACE("m-noaddr");
    slapRecvBlock(m_noaddr, sizeof(m_noaddr));

    TRACE("print stats");
    assert(statSlapPackets == 4);
    assert(statSlapDelivered == 2);
    assert(statSlapCrcError == 1);
}
