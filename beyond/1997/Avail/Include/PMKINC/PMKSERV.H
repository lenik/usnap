#ifndef __PMKSERVICESM_H
#define __PMKSERVICESM_H
#if !defined(__BIOS_H)
#include <bios.h>
#endif
struct huge ksw{int sw:2,cw:2,aw:2;};struct huge ksb {int sr:1,sl:1,cr:1,cl:1,ar:1,al:1;};union  huge ksu {ksw w;ksb r;};struct huge kss {int scr:1,num:1,cap:1,ins:1,pscr:1,pnum:1,pcap:1,psys:1;};struct huge sks {ksu  u;kss s;unsigned key;};
void   huge getchkeystatus(sks far &ret){int key;key=_bios_keybrd(_NKEYBRD_SHIFTSTATUS);ret.u.r.sr=(key&0x1);ret.u.r.sl=(key&0x2)>>1;ret.s.scr=(key&0x10)>>4;ret.s.num=(key&0x20)>>5;ret.s.cap=(key&0x40)>>6;ret.s.ins=(key&0x80)>>7;ret.u.r.cl=(key&0x100)>>8;ret.u.r.al=(key&0x200)>>9;ret.u.r.cr=(key&0x400)>>10;ret.u.r.ar=(key&0x800)>>11;ret.s.pscr=(key&0x1000)>>12;ret.s.pnum=(key&0x2000)>>13;ret.s.pcap=(key&0x4000)>>14;ret.s.psys=(key&0x8000)>>15;return;}
void   huge Getch(sks far &ret){getchkeystatus(ret);ret.key=bioskey(1)?bioskey(0):0;while((!ret.u.r.sr)&&(!ret.u.w.cw)&&(!ret.u.w.aw)&&(!ret.s.pscr)&&(!ret.s.pnum)&&(!ret.s.pcap)&&(!ret.key)){getchkeystatus(ret);ret.key=bioskey(1)?bioskey(0):0;}}
#if !defined(__PMKSOUNDDEVICE_H)
#include<PmkInc\PmkSound.h>
#endif

#endif