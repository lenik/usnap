#ifndef __TTIME_H
#define __TTIME_H

#include "TopType.h"

Byte ToBCD_Byte(Byte Bin);
Byte ToBin_Byte(Byte BCD);

struct RTCTime{
  Byte Hour;
  Byte Minute;
  Byte Second;
  Byte DST;		//	Daylight saving time
};

struct RTCDate{
  Byte Century;
  Byte Year;
  Byte Month;
  Byte Day;
};

struct SDate{
  Word Year;
  Byte Month;
  Byte Day;
  Byte Week;
};
struct STime{
  Byte Hour;
  Byte Minute;
  Byte Second;
  Byte Second100;
};

struct RTCTime _RTCTime;
struct RTCDate _RTCDate;
struct SDate _SDate;
struct STime _STime;

float TimerConstant=18.206;
DWord _MaxClockCount=0x001800B0;

DWord GetClockCount(void);
void SetClockCount(DWord CC);
Word GetDayCount(void);
void SetDayCount(Word DC);
Byte ReadRTCTime(void);
Byte SetRTCTime(RTCTime __RTCTime);
Byte ReadRTCDate(void);
Byte SetRTCDate(RTCDate __RTCDate);
Byte SetRTCAlarm(RTCTime __RTCAlarmTime, void (*AlarmFunc)());
void DisableRTCAlarm(void);
Byte ReadRTCAlarm(void);
Byte SetRTCActivatePowerUp(RTCTime __RTCTime);
SDate GetDate(void);
Byte SetDate(SDate __SDate);
STime GetTime(void);
Byte SetTime(STime __STime);

#endif	//TTIME_H
