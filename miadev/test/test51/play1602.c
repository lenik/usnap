#include <stdio.h>
#include <cos51/sleep.h>
#include <cos51/display/1602.h>

void putchar(char c) {
    lcd1602Putchar(c);
}

void main() {
    lcd1602Init();

    // lcd1602Puts("123456789a123456789b123456789c123456789d\n123456789a123456789b123456789c123456789d");
    // lcd1602Puts("hello, world! \nHi everyone! \nThis is a message from Lenik. ");
    printf("hello, my name is %s!\nI'm %d years old. ",
            "Lenik", 30);

    while (1) {
        mdelay(100);
        P1_1 ^= 1;
        lcd1602Scroll(-1);
    }
}
