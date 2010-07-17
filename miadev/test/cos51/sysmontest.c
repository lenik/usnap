#include <8051.h>
#include <cos51/sunit_stdio.h>
#include <cos51/sleep.h>
#include <cos51/sysmon.h>
#include <cos51/dk/hc6800.h>
#define SFR_TH0 0x8c

void testCase() {
    byte b;

    TH0 = 0xcd;
    b = getsfr(SFR_TH0);
    assert(b == 0xcd);

    setsfr(SFR_TH0, 0xef);
    assert(TH0 == 0xef);

}
