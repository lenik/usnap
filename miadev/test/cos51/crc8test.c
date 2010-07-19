#include <cos51/sunit_stdio.h>
#include <cos51/io/crc8.h>

void testCase() {
    byte block[] = { 0x01, 0x01, 0x34 };
    byte hello[] = { 'h', 'e', 'l', 'l', 'o' };
    byte c;

    crc8Init(CRC8_CCITT);

    c = crc8Update(0x01);
    assert(c == 0x07);

    c = crc8Update(0x01);
    assert(c == 0x12);

    c = crc8Update(0x34);
    assert(c == 0xf2);

    crc8Reset();
    c = crc8UpdateBlock(block, sizeof(block));
    assert(c == 0xf2);

    crc8Reset();
    c = crc8UpdateBlock(hello, sizeof(hello));
    assert(c == 0x92);
}
