#include <dos.h>
#include <_Null.h>

#include "TopType.h"
#include "TTime.h"

Byte ToBCD_Byte(Byte Bin) {
  return ((Bin)/10*0x10+(Bin)%10);
}

Byte ToBin_Byte(Byte BCD) {
  return (((BCD)>>4)*10+((BCD)&0xf));
}

DWord GetClockCount(void){
  REGS _r;
  _r.h.ah=0;
  int86(0x1a, &_r, &_r);
  return (DWord)_r.x.cx<<16+_r.x.dx;
}

void SetClockCount(DWord CC){
  REGS _r;
  CC%=_MaxClockCount;
  _r.x.cx=CC>>16;
  _r.x.dx=CC&0xffff;
  _r.h.ah=1;
  int86(0x1a, &_r, &_r);
}

Word GetDayCount(void){
  REGS _r;
  _r.h.ah=0xa;
  int86(0x1a, &_r, &_r);
  return _r.x.cx;
}

void SetDayCount(Word DC){
  REGS _r;
  _r.x.cx=DC;
  _r.h.ah=0xb;
  int86(0x1a, &_r, &_r);
}

Byte ReadRTCTime(void){
  REGS _r;
  _r.h.ah=2;
  int86(0x1a, &_r, &_r);
  if (_r.x.flags&1) return 0;
  _RTCTime.DST=ToBin_Byte(_r.h.dl);
  _RTCTime.Hour=ToBin_Byte(_r.h.ch);
  _RTCTime.Minute=ToBin_Byte(_r.h.cl);
  _RTCTime.Second=ToBin_Byte(_r.h.dh);
  return 1;
}

Byte SetRTCTime(RTCTime __RTCTime){
  REGS _r;
  _r.h.dl=__RTCTime.DST;
  _r.h.ch=ToBCD_Byte(__RTCTime.Hour);
  _r.h.cl=ToBCD_Byte(__RTCTime.Minute);
  _r.h.dh=ToBCD_Byte(__RTCTime.Second);
  _r.h.ah=3;
  int86(0x1a, &_r, &_r);
  if (_r.x.flags&1) return 0;
  return 1;
}

Byte ReadRTCDate(void){
  REGS _r;
  _r.h.ah=4;
  int86(0x1a, &_r, &_r);
  if (_r.x.flags&1) return 0;
  _RTCDate.Century=ToBin_Byte(_r.h.ch);
  _RTCDate.Year=ToBin_Byte(_r.h.cl);
  _RTCDate.Month=ToBin_Byte(_r.h.dh);
  _RTCDate.Day=ToBin_Byte(_r.h.dl);
  return 1;
}

Byte SetRTCDate(RTCDate __RTCDate){
  REGS _r;
  _r.h.ch=ToBCD_Byte(__RTCDate.Century);
  _r.h.cl=ToBCD_Byte(__RTCDate.Year);
  _r.h.dh=ToBCD_Byte(__RTCDate.Month);
  _r.h.dl=ToBCD_Byte(__RTCDate.Day);
  _r.h.ah=5;
  int86(0x1a, &_r, &_r);
  if (_r.x.flags&1) return 0;
  return 1;
}

void interrupt (*OldAlarmVect)(...);
void (*__ExternFunc)()=NULL;
void interrupt __AlarmFunc(...) {
  (*__ExternFunc)();
}

Byte SetRTCAlarm(RTCTime __RTCAlarmTime, void (*AlarmFunc)()) {
  REGS _r;
  disable();
  OldAlarmVect=getvect(0x4a);
  __ExternFunc=AlarmFunc;
  setvect(0x4a, __AlarmFunc);
  _r.h.ch=ToBCD_Byte(__RTCAlarmTime.Hour);
  _r.h.cl=ToBCD_Byte(__RTCAlarmTime.Minute);
  _r.h.dh=ToBCD_Byte(__RTCAlarmTime.Second);
  _r.h.ah=6;
  int86(0x1a, &_r, &_r);
  if (_r.x.flags&1) {
    setvect(0x4a, OldAlarmVect);
    enable();
    return 0;
  } else {
    enable();
    return 1;
  }
}

void DisableRTCAlarm(void){
  REGS _r;
  disable();
  _r.h.ah=7;
  int86(0x1a, &_r, &_r);
  setvect(0x4a, OldAlarmVect);
  enable();
}

Byte ReadRTCAlarm(void){
  REGS _r;
  _r.h.ah=9;
  int86(0x1a, &_r, &_r);
  _RTCTime.Hour=ToBin_Byte(_r.h.ch);
  _RTCTime.Minute=ToBin_Byte(_r.h.cl);
  _RTCTime.Second=ToBin_Byte(_r.h.dh);
  return _r.h.dl;
}

Byte SetRTCActivatePowerUp(RTCTime __RTCTime){
  REGS _r;
  _r.h.ch=ToBCD_Byte(__RTCTime.Hour);
  _r.h.cl=ToBCD_Byte(__RTCTime.Minute);
  _r.h.dh=ToBCD_Byte(__RTCTime.Second);
  _r.h.ah=8;
  int86(0x1a, &_r, &_r);
  if (_r.x.flags&1) return 0;
  return 1;
}

SDate GetDate(void) {
  REGS _r;
  _r.h.ah=0x2a;
  int86(0x21, &_r, &_r);
  _SDate.Year=_r.x.cx;
  _SDate.Month=_r.h.dh;
  _SDate.Day=_r.h.dl;
  _SDate.Week=_r.h.al;
  return _SDate;
}

Byte SetDate(SDate __SDate) {
  REGS _r;
  _r.x.cx=__SDate.Year;
  _r.h.dh=__SDate.Month;
  _r.h.dl=__SDate.Day;
  _r.h.ah=0x2b;
  int86(0x21, &_r, &_r);
  if (_r.h.al) return 0;
  return 1;
}

STime GetTime(void) {
  REGS _r;
  _r.h.ah=0x2c;
  int86(0x21, &_r, &_r);
  _STime.Hour=_r.h.ch;
  _STime.Minute=_r.h.cl;
  _STime.Second=_r.h.dh;
  _STime.Second100=_r.h.dl;
  return _STime;
}

Byte SetTime(STime __STime){
  REGS _r;
  _r.h.ch=__STime.Hour;
  _r.h.cl=__STime.Minute;
  _r.h.dh=__STime.Second;
  _r.h.dl=__STime.Second100;
  _r.h.ah=0x2d;
  int86(0x21, &_r, &_r);
  if (_r.h.al) return 0;
  return 1;
}
