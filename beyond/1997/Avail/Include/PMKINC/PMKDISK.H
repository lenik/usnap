#ifndef __AUTODETECTDISK_H
#define __AUTODETECTDISK_H
#if !defined(__DOS_H)
#include<dos.h>
#endif
#if !defined(__CTYPE_H)
#include<ctype.h>
#endif
#ifndef dhard
#define dhard  0
#endif
#ifndef d360k
#define d360k  1
#endif
#ifndef d1200k
#define d1200k 2
#endif
#ifndef d720k
#define d720k  3
#endif
#ifndef d1400k
#define d1400k 4
#endif
struct        far disktype{unsigned char hdnum,heads;unsigned int dx,cx;int cylinders,sectors;};
disktype      far nultype={0,0,0,0,0,0};
unsigned char far retdiskc(disktype ret){switch (ret.cx){case 0x2709:return 1;case 0x4f0f:return 2;case 0x4f09:return 3;case 0x4f12:return 4;default:;}return 0;}
char     *    far retdisks(disktype ret){switch (ret.cx){case 0x2709:return "360k";case 0x4f0f:return "1.2M";case 0x4f09:return "720k";case 0x4f12:return "1.44M";default:;}return "Hard disk.";}
disktype      far autodetectdisk(char disk){union REGS in,out;disktype detdisk;disk=tolower(disk);if (disk=='a')in.h.dl=0x00; else if(disk=='b')in.h.dl=0x01;else if((disk>='c')&&(disk<='z'))in.h.dl=0x80+(int)disk-(int)'c';else {detdisk=nultype;return detdisk;}in.x.ax=0x0800;in.x.cx=0;int86(0x13,&in,&out);detdisk.dx=out.x.dx;detdisk.cx=out.x.cx;detdisk.hdnum=out.h.dl;detdisk.heads=++out.h.dh;out.h.bh=(out.h.cl&0xc0)>>6;out.h.bl=out.h.ch;detdisk.cylinders=out.x.bx+1;detdisk.sectors=out.h.cl&0x3f;return detdisk;}
#endif