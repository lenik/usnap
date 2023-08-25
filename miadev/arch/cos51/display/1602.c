#include "1602.h"
#include "sleep.h"
#include "util.h"

//#define LCD1602_BACK
//#define S51_DEBUG
#define SLOWDOWN() ((void)0)
//#define SLOWDOWN() mdelay(100)

#ifndef LCD1602_SELECT
#   define LCD1602_SELECT(rs, rw) \
            LCD1602_RS = rs; \
            LCD1602_RW = rw;
#endif

static BYTE displayFlags = LCD1602CMD_DISPLAY(1, 1, 1);

#ifdef LCD1602_BACK

static BYTE gaddr = 0;
static __xdata BYTE backbuf[LCD1602_MEMSIZE];

#   define CURROW \
        (gaddr >> LCD1602_HDEPTH)

#   define GET(addr, b) \
        b = backbuf[addr]

#   define SET(addr, b) \
        lcd1602WriteCommand(LCD1602CMD_DDRAM(addr)); \
        lcd1602WriteData(b); \
        backbuf[addr] = b

#   define AT(addr) \
        lcd1602WriteCommand(LCD1602CMD_DDRAM(addr)); \
        gaddr = addr

#   define PUT(b) \
        lcd1602WriteData(b); \
        backbuf[gaddr++] = b; \
        gaddr %= LCD1602_MEMSIZE

#   define PUT_AT(addr, b) \
        lcd1602WriteCommand(LCD1602CMD_DDRAM(addr)); \
        lcd1602WriteData(b); \
        backbuf[addr] = b; \
        gaddr = (addr + 1) % LCD1602_MEMSIZE

#   define CLEAR() \
        lcd1602WriteCommand(LCD1602CMD_CLEAR); \
        gaddr = 0

#else

#   define CURROW \
        ((lcd1602ReadStatus() & 0x7f) >> LCD1602_HDEPTH)

#   define GET(addr, b) \
        lcd1602WriteCommand(LCD1602CMD_DDRAM(addr)); \
        b = lcd1602ReadData()

#   define SET(addr, b) \
        lcd1602WriteCommand(LCD1602CMD_DDRAM(addr)); \
        lcd1602WriteData(b)

#   define AT(addr) \
        lcd1602WriteCommand(LCD1602CMD_DDRAM(addr))

#   define PUT(b) \
        lcd1602WriteData(b)

#   define PUT_AT(addr, b) \
        lcd1602WriteCommand(LCD1602CMD_DDRAM(addr)); \
        lcd1602WriteData(b)

#   define CLEAR() \
        lcd1602WriteCommand(LCD1602CMD_CLEAR)

#endif

void lcd1602Init() {
    BYTE mode = LCD1602CMD_MODE_827;
    BYTE times = 3;
    mdelay(15);
    while (times--) {
        lcd1602WriteCommand(mode);
        mdelay(5);
    }
    lcd1602WriteCommand(displayFlags);
    lcd1602WriteCommand(LCD1602CMD_DIR(1, 0));
    lcd1602WriteCommand(LCD1602CMD_CLEAR);
}

void lcd1602DisplayFlags(BYTE flags) {
    displayFlags = flags;
    lcd1602WriteCommand(displayFlags);
}

void lcd1602PowerOn() {
    lcd1602WriteCommand(displayFlags);
}

void lcd1602PowerOff() {
    lcd1602WriteCommand(LCD1602CMD_OFF);
}

BYTE lcd1602ReadStatus() {
    LCD1602_SELECT(0, 1);
    LCD1602_EN = 1;
    udelay_4();
    return LCD1602_D;
}

void lcd1602Wait() {
#ifndef S51_DEBUG
    while (lcd1602ReadStatus() & 0x80)
        ;
#endif
}

BYTE lcd1602GetRow() {
    BYTE addr = lcd1602ReadStatus() & 0x7f;
    return addr >> LCD1602_HDEPTH;
}

BYTE lcd1602GetColumn() {
    BYTE addr = lcd1602ReadStatus(); // & 0x7f
    return addr & LCD1602_HMASK;
}

BYTE lcd1602ReadData() {
    BYTE data;
    lcd1602Wait();
    LCD1602_SELECT(1, 1);
    // Tas(140): init address
    LCD1602_EN = 1;
    // Ter(25-): EN raise
    // Tddr(320-): data latency
    data = LCD1602_D;
    LCD1602_EN = 0;
    // Tef(25-), Tah(10+), Tdhr(10+): address/data hold
    return data;
}

void lcd1602WriteCommand(BYTE command) {
    lcd1602Wait();
    LCD1602_SELECT(0, 0);
    // Tas(140+): init address...
    LCD1602_EN = 1;
    // Ter(25-): EN raise
    LCD1602_D = command;
    // Tdsw(195): init data...
    // Tef(25-): EN fall
    LCD1602_EN = 0;
    // Tah(10+), Th(10+): address/data hold

//    P1 = (P1 & 0xF0) | (~command >> 4);
//    P1_5=0;
    SLOWDOWN();
//    P1 = (P1 & 0xF0) | 0x0F;
//    P1_5=1;
}

void lcd1602WriteData(BYTE data) {
    lcd1602Wait();
    LCD1602_SELECT(1, 0);
    LCD1602_EN = 1;
    LCD1602_D = data;
    LCD1602_EN = 0;

    SLOWDOWN();
}

void lcd1602Clear() {
    CLEAR();
}

void lcd1602Scroll(int8 n) {
    while (n < 0) {
        lcd1602WriteCommand(LCD1603CMD_SCROLL_L);
        n++;
    }
    while (n > 0) {
        lcd1602WriteCommand(LCD1603CMD_SCROLL_R);
        n--;
    }
}

void lcd1602ScrollUp() {
    char x, y;
    BYTE src = LCD1602_OFFSET(1, 0);
    BYTE dst = LCD1602_OFFSET(0, 0);
    BYTE ch;
    for (y = 1; y < LCD1602_HEIGHT; y++) {
        for (x = 0; x < LCD1602_WIDTH; x++) {
            GET(src, ch);
            SET(dst, ch);
            src++;
            dst++;
        }
        src += LCD1602_PITCH - LCD1602_WIDTH;
        dst += LCD1602_PITCH - LCD1602_WIDTH;
    }
    dst = LCD1602_OFFSET(LCD1602_HEIGHT - 1, 0);
    for (x = 0; x < LCD1602_WIDTH; x++) {
        SET(dst, ' ');
        dst++;
    }
}

void lcd1602ScrollDown() {
    char x, y;
    BYTE src = LCD1602_OFFSET(LCD1602_HEIGHT - 1, 0);
    BYTE dst = LCD1602_OFFSET(LCD1602_HEIGHT, 0);
    BYTE ch;
    for (y = 1; y < LCD1602_HEIGHT; y++) {
        src -= LCD1602_PITCH - LCD1602_WIDTH;
        dst -= LCD1602_PITCH - LCD1602_WIDTH;
        for (x = 0; x < LCD1602_WIDTH; x++) {
            src--;
            dst--;
            GET(src, ch);
            SET(dst, ch);
        }
    }
    dst = LCD1602_OFFSET(0, 0);
    for (x = 0; x < LCD1602_WIDTH; x++) {
        SET(dst, ' ');
        dst++;
    }
}

void lcd1602At(BYTE row, BYTE col) {
    AT(LCD1602CMD_DDRAM_AT(row, col));
}

void lcd1602PutcharAt(BYTE row, BYTE col, char c) {
    BYTE addr = row * LCD1602_PITCH + col;
    PUT_AT(addr, c);
}

void lcd1602Putchar(char c) {
    if (c == '\n') {
        // can't read the cursor address (unless set explicitly)
        // require LCD1602_BACK to work.
        BYTE row = CURROW; // lcd1602GetRow();
        if (row == LCD1602_HEIGHT - 1)
            lcd1602ScrollUp();
        else
            row++;
        AT(LCD1602_OFFSET(row, 0));
    } else {
        PUT(c);
    }
}

void lcd1602Puts(const char *p) {
    char c;
    while (c = *p++)
        lcd1602Putchar(c);
}

void lcd1602PutsAt(BYTE row, BYTE col, const char *p) {
    lcd1602At(row, col);
    lcd1602Puts(p);
}
