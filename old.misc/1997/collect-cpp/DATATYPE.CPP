#include <conio.h>
#include <stdio.h>
#include <bios.h>
#include <dos.h>

#ifndef Byte
#define Byte unsigned char
#endif
#ifndef Word
#define Word unsigned int
#endif
#ifndef DWord
#define DWord unsigned long
#endif

#define ToBCD_Byte(Bin) ((Bin)/10*0x10+(Bin)%10)
#define ToBin_Byte(BCD) (((BCD)>>4)*10+((BCD)&0xf))

struct __Data{
  Word Year:12;		//	4096s
  Byte Month:4;		//	16s
  Byte Day:5;		//	32s
} __sData;
struct __Time{
  Byte Hour:5;		//	32s
  Byte Minute:6;	//	64s
  Byte Second:6;	//	64s
  Byte Second100:7;	//	128s
} __sTime;


struct TimeStruct{
  __Data Data;
  __Time Time;
} _SysTime;

struct RTCTime{
  Byte Hour;
  Byte Minute;
  Byte Second;
  Byte DST;		//	Daylight saving time
} _RTCTime;
struct RTCDate{
  Byte Century;
  Byte Year;
  Byte Month;
  Byte Day;
} _RTCDate;

float TimerConstant=18.206;
DWord _MaxClockCount=0x001800B0;

DWord GetClockCount(void){
  DWord Ret=0;
  asm {
    push ax
    push bx
    push cx
    push dx
    pushf
    xor ah,ah
    int 0x1a
  } Ret=(DWord)_CX<<16;
    Ret+=_DX;
  asm {
    popf
    pop dx
    pop cx
    pop bx
    pop ax
  }
  return Ret;
}

void SetClockCount(DWord CC){
  CC%=_MaxClockCount;
  asm {
    push ax
    push bx
    push cx
    push dx
    pushf
  } _CX=CC>>16;
    _DX=CC&0xffff;
  asm {
    mov ah,1
    int 0x1a
    popf
    pop dx
    pop cx
    pop bx
    pop ax
  }
}

__Time TransCountToTime(DWord CC){
  __Time RetTime;
  RetTime.Hour=(int)(CC/3600/TimerConstant);
  CC=CC-(DWord)(CC/3600/TimerConstant)*(3600*TimerConstant);
  RetTime.Minute=CC/60/TimerConstant;
  CC=CC-(DWord)(CC/60/TimerConstant)*(60*TimerConstant);
  RetTime.Second=CC/TimerConstant;
  CC=CC-(DWord)(CC/TimerConstant)*TimerConstant;
  RetTime.Second100=(CC/TimerConstant)*100;
  return RetTime;
}
DWord TransTimeToCount(__Time ___Time){
  DWord CC;
  CC=(___Time.Hour*3600+___Time.Minute*60+___Time.Second)*TimerConstant+___Time.Second100*TimerConstant/100;
  return CC;
}

Byte ReadRTCTime(void){
  asm {
    pushf
    push ax
    push bx
    push cx
    push dx
    mov ah,2
    int 0x1a
    jc ReadRTCTimeError
  } _RTCTime.DST=_DL;
    _RTCTime.Hour=ToBin_Byte(_CH);
    _RTCTime.Minute=ToBin_Byte(_CL);
    _RTCTime.Second=ToBin_Byte(_DH);
  asm {
    pop dx
    pop cx
    pop bx
    pop ax
    popf
  }
  return 1;
ReadRTCTimeError:
  asm {
    pop dx
    pop cx
    pop bx
    pop ax
    popf
  }
  return 0;
}

Byte SetRTCTime(RTCTime __RTCTime){
  asm {
    pushf
    push ax
    push bx
    push cx
    push dx
  } _CH=ToBCD_Byte(__RTCTime.Hour);
    _CL=ToBCD_Byte(__RTCTime.Minute);
    _DH=ToBCD_Byte(__RTCTime.Second);
    _DL=__RTCTime.DST;
  asm {
    mov ah,3
    int 0x1a
    jc SetRTCTimeError
    pop dx
    pop cx
    pop bx
    pop ax
    popf
  }
  return 1;
SetRTCTimeError:
  asm {
    pop dx
    pop cx
    pop bx
    pop ax
    popf
  }
  return 0;
}

void main(){
  clrscr();
  goto l1;
l1:
  _RTCTime.Hour=23;
  _RTCTime.Minute=40;
  _RTCTime.Second=30;
  _RTCTime.DST=0;
  SetRTCTime(_RTCTime);
//  SetClockCount(0x1000af);
l2:
  do {
    gotoxy(1,10);
    printf("%6.lX\n", GetClockCount());
    __sTime=TransCountToTime(GetClockCount());
    printf("%d:%d:%d.%d\n", __sTime.Hour, __sTime.Minute, __sTime.Second, __sTime.Second100);

    if (ReadRTCTime())
      printf("%d:%d:%d   DST=%d\n", _RTCTime.Hour, _RTCTime.Minute, _RTCTime.Second, _RTCTime.DST);
    else
      printf("ReadRTCTime error.\n");
  } while (!bioskey(1));
  return;
}

/*
	~INT 1A,4~   Read real time clock date (AT,PS/2)
	~INT 1A,5~   Set real time clock date (AT,PS/2)
	~INT 1A,6~   Set real time clock alarm (AT,PS/2)
	~INT 1A,7~   Reset real time clock alarm (PS/2)
	~INT 1A,8~   Set RTC activated power on mode (convertible,PS/2)
	~INT 1A,9~   Read RTC alarm time and status (convertible,PS/2)
	~INT 1A,A~   Read system day counter (PS/2)
	~INT 1A,B~   Set system day counter (PS/2)
	~INT 1A,80~  Set up sound multiplexer (PCjr only)

	- function is specified in register AH
	- see	~RTC~

:int 1a,4
^INT 1A,4 - Read Real Time Clock Date  (XT 286,AT,PS/2)


	AH = 04


	on return:
	CH = century in BCD (decimal 19 or 20)
	CL = year in BCD
	DH = month in BCD
	DL = day in BCD
	CF = 0 if successful
	   = 1 if error or clock not operating

	- calling this interrupt will update the DOS maintained date and
	  reset the ~BIOS Data Area~ date rollover flag at 40:70
	- see	~RTC~
:int 1a,5
^INT 1A,5 - Set Real Time Clock Date  (XT 286,AT,PS/2)


	AH = 05
	CH = century in BCD (decimal 19 or 20)
	CL = year in BCD
	DH = month in BCD
	DL = day in BCD


	returns nothing


	- all values must be in BCD
	- see	~RTC~
:int 1a,6
^INT 1A,6 - Set Real Time Clock Alarm  (XT 286,AT,PS/2)


	AH = 06
	CH = hours in BCD
	CL = minutes in BCD
	DH = seconds in BCD


	on return:
	CF = 1 if alarm already set or clock inoperable


	- alarm setting is not relative like some sources claim, but the
	  actually clock time the interrupt should occur
	- settings values must be in BCD
	- when the alarm time is reached ~INT 4A~ is executed
	- INT 4A vector should be replaced with address of the alarm
	  handling interrupt routine before setting the alarm
	- ~INT 1A,7~ should be called to disable the ~RTC~ alarm
:int 1a,7
^INT 1A,7 - Disable Real Time Clock Alarm  (XT,AT,PS/2)


	AH = 07


	returns nothing


	- should be called previous to setting or resetting the
	  ~RTC~ alarm with ~INT 1A,6~
:int 1a,8
^INT 1A,8 - Set RTC Activated Power On Mode (convertible)


	AH = 08
	CH = hours in BCD
	CL = minutes in BCD
	DH = seconds in BCD


	- see	~RTC~
:int 1a,9
^INT 1A,9 - Read RTC Alarm Time and Status (convertible,PS/2)


	AH = 09


	on return:
	CH = hours in BCD
	CL = minutes in BCD
	DH = seconds in BCD
	DL = alarm status:
	   = 00 if alarm not enabled (AIE=0)
	   = 01 if alarm enabled but will not power up system (AIE=1)
	   = 02 if alarm will power up system (AIE=1)


	- see	~RTC~
:int 1a,a
^INT 1A,A - Read System Day Counter (PS/2)


	AH = 0Ah


	on return:
	CX = count of days since 1-1-1980

:int 1a,b
^INT 1A,B - Set System Day Counter (PS/2)


	AH = 0Bh
	CX = count of days since 1-1-1980

:int 1a,80
^INT 1A,80 - Setup Sound Multiplexer  (PCjr only)


	AL = 00 - source is ~8253~ channel 2
	   = 01 - source is cassette input
	   = 02 - source is I/O channel "AUDIO IN"
	   = 03 - source is sound generator chip

*/
