#include <cos51/types.h>

#define RECVBUF_SIZE 128
#include <cos51/sunit.h>

void testCase() {
    byte buf[100];
    int i;
    char c;

    //    TMOD |= 0x20;
    //    //PCON |= 0x80; // SMOD
    //    TH1 = 0xff; //2400 bps
    //    TR1 = 1;
    //    ES = 1;
    //    EA = 1;

    for (i = 0; i < 3; i++) {
        printf("[%d] Please input: \n", i);
        c = getchar();
        printf("You enterred %c! \n", c);
        gets(buf);
        printf("You enterred %s!\n", buf);
    }

}
