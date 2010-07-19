#ifndef COS51_1602_H
#define COS51_1602_H

#include <8051.h>

#include "types.h"

#ifndef LCD1602_D_PORT
#define LCD1602_D_PORT 0x80 // P0
#endif

#ifndef LCD1602_RS_PORT
#define LCD1602_RS_PORT 0xa6 // P2_6
#endif

#ifndef LCD1602_RW_PORT
#define LCD1602_RW_PORT 0xa5 // P2_5
#endif

#ifndef LCD1602_EN_PORT
#define LCD1602_EN_PORT 0xa7 // P2_7
#endif

/**
 * Data/Command selector
 */
__sbit __at(LCD1602_RS_PORT) LCD1602_RS;

/**
 * Read/Write selector
 */
__sbit __at(LCD1602_RW_PORT) LCD1602_RW;

/**
 * Enable
 */
__sbit __at(LCD1602_EN_PORT) LCD1602_EN;

/**
 * D0..D7
 */
__sfr __at(LCD1602_D_PORT) LCD1602_D;

#define LCD1602_WIDTH       40 // 16 visible.
#define LCD1602_HEIGHT      2
#define LCD1602_PITCH       0x40
#define LCD1602_MEMSIZE     (LCD1602_HEIGHT * LCD1602_PITCH)
#define LCD1602_HDEPTH      6
#define LCD1602_HMASK       0x3f
#define LCD1602_OFFSET(row, col) \
        (((row) << LCD1602_HDEPTH) | (col))

#define LCD1602CMD_CLEAR    0x01
#define LCD1602CMD_HOME     0x02    // or 0x03

#define LCD1602CMD_DIR(direction, scroll) \
        (0x04 | ((direction)<<1) | (scroll))

#define LCD1602CMD_DISPLAY(display, cursor, blink) \
        (0x08 | ((display)<<2) | ((cursor)<<1) + (blink))

#define LCD1602CMD_ON \
        LCD1602CMD_DISPLAY(1, 1, 1)
#define LCD1602CMD_OFF \
        LCD1602CMD_DISPLAY(0, 0, 0)

#define LCD1603CMD_BACKWARD 0x10    // 0001 00 **
#define LCD1603CMD_FORWARD 0x14     // 0001 01 **
#define LCD1603CMD_SCROLL_L 0x18    // 0001 10 **
#define LCD1603CMD_SCROLL_R 0x1C    // 0001 11 **

// 4/8-bit, 1/2-Row, 7/10(A) font height
#define LCD1602CMD_MODE_417 0x20 // 001 000 **
#define LCD1602CMD_MODE_41A 0x24 // 001 001 **
#define LCD1602CMD_MODE_427 0x28 // 001 010 **
#define LCD1602CMD_MODE_42A 0x2C // 001 011 **
#define LCD1602CMD_MODE_817 0x30 // 001 100 **
#define LCD1602CMD_MODE_81A 0x34 // 001 101 **
#define LCD1602CMD_MODE_827 0x38 // 001 110 ** (1602)
#define LCD1602CMD_MODE_82A 0x3C // 001 111 **

#define LCD1602CMD_CGRAM(addr6) (0x40 | ((addr6) & 0x3f))
#define LCD1602CMD_DDRAM(addr7) (0x80 | ((addr7) & 0x7f))
#define LCD1602CMD_DDRAM_AT(row, col) \
        (0x80 | (LCD1602_OFFSET(row, col) & 0x7f))

void lcd1602Init();
void lcd1602DisplayFlags(byte flags);
void lcd1602PowerOn();
void lcd1602PowerOff();
byte lcd1602ReadStatus();
void lcd1602Wait();
byte lcd1602GetRow();
void lcd1602WriteCommand(byte command);
byte lcd1602ReadData();
void lcd1602WriteData(byte data);

void lcd1602Clear();
void lcd1602Scroll(char n);
void lcd1602ScrollUp();
void lcd1602ScrollDown();
void lcd1602At(byte row, byte col);
void lcd1602PutcharAt(byte row, byte col, char c);
void lcd1602Putchar(char c);
void lcd1602Puts(const char *p);
void lcd1602PutsAt(byte row, byte col, const char *p);

#endif
