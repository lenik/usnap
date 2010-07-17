#include <cos51/types.h>
#include <cos51/sunit_stdio.h>

void testCase() {
    byte buf[100];
    int i;
    char c;

    puts("0123456789abcdefghijklmnopqrstuvwxyz\n");
    puts("sunit self-test program\n");

    //    TMOD |= 0x20;
    //    //PCON |= 0x80; // SMOD
    //    TH1 = 0xff; //2400 bps
    //    TR1 = 1;
    //    ES = 1;
    //    EA = 1;

    for (i = 0; i < 3; i++) {
        printf_small("[%d] char: ", i);
        c = getchar();
        printf_small("[%d] You enterred %c!\n", i, c);

        printf_small("[%d] string: ", i);
        gets(buf);
        printf_small("[%d] You enterred %s!\n\n", i, buf);
    }
}
