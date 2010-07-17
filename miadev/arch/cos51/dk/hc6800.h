#ifndef COS51_DK_HC6800_H
#define COS51_DK_HC6800_H

#include <8052.h>

#define XTAL            12000000.0

#define RELAY           P1_4    // J2
#define BEEP            P1_5    // J8
#define G_SCL           P2_0
#define G_SDA           P2_1
#define IRD             P3_2    // J1, P32=INT0, P33=INT1
#define DS18B20         P3_7    // 1-wire

#define LCD1602_D_PORT  0x80    // P0
#define LCD1602_RS_PORT 0xa6    // P2_6
#define LCD1602_RW_PORT 0xa5    // P2_5
#define LCD1602_EN_PORT 0xa7    // P2_7

#define DS1302_CE       P3_5
#define DS1302_DSIO     P3_4    // JP1302
#define DS1302_SCLK     P3_6

#define EEPROM_SCL      G_SCL
#define EEPROM_SDA      G_SDA
#define EEPROM_DB       P2      // 据说设备地址=0xA0

// DA/AD 4 channel
#define PCF8591T_ADDR   0       // I2C Address 000
#define PCF8591T_SCL    G_SCL
#define PCF8591T_SDA    G_SDA

#define STEPMOTOR_YA    P1_0    // red
#define STEPMOTOR_YB    P1_1    // white
#define STEPMOTOR_YC    P1_2    // yellow
#define STEPMOTOR_YD    P1_3    // green
#define STEPMOTER_MASK  0x0f
#define STEPMOTER_A     0x0e    // ～0001 = 1110
#define STEPMOTER_AB    0x0c    // ～0011 = 1100
#define STEPMOTER_B     0x0d    // ～0010 = 1101
#define STEPMOTER_BC    0x09    // ～0110 = 1001
#define STEPMOTER_C     0x0b    // ～0100 = 1011
#define STEPMOTER_CD    0x03    // ～1100 = 0011
#define STEPMOTER_D     0x07    // ～1000 = 0111
#define STEPMOTER_DA    0x06    // ～1001 = 0110

// 74H595
#define X595_SER        P3_4    // JP595
#define X595_RCLK       P3_5    // Excl. DS1302
#define X595_SRCLK      P3_6    // Excl. DS1302, Share 74LS165

// 74LS165, ABCDEFGH->JP6
#define X165_IN         P1_7    // JP165
#define X165_SH_LD      P1_6
#define X165_CLK        P3_6    // Excl. DS1302, Share 74H595

#include "../config.h"

#endif
