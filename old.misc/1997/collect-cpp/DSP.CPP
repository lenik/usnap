#include <stdio.h>
#include <dos.h>

#define Byte unsigned char
#define Word unsigned int

class DSP{
  Word SBPort;
  enum DSP_Port{
    RESET=0x6,			//Out
    READ_DATA=0xa,		//In
    WRITE_COMMAND_DATA=0xc,	//Out
    WRITE_BUFFER_STATUS=0xc,	//In
    DATA_AVAILABLE_STATUS=0xe	//In
  };
public:
  Byte RetB;
  Word RetW;
public:
  DSP();
  DSP(Word);
  void ChangeSBPort(Word);
public:
  Byte TIME_CONSTANT;
  void CreateSample(unsigned long SampleRateSpeed);
public:
  Byte Reset();
  Byte CheckWriteBufferStatus();
  Byte CheckDataAvailableStatus();
};

DSP::DSP(){
  SBPort=0x220;
  TIME_CONSTANT=167;
}
DSP::DSP(Word _SBPort){
  SBPort=_SBPort;
  DSP();
}
void DSP::ChangeSBPort(Word _SBPort){
  SBPort=_SBPort;
}
void DSP::CreateSample(unsigned long SampleRateSpeed){
  TIME_CONSTANT=256-1000000/SampleRateSpeed;
}
Byte DSP::Reset(){
  outportb(SBPort+RESET, 1);
  delay(3);
  outportb(SBPort+RESET, 0);
  for (int LoopCount=0; LoopCount<100; LoopCount++){
    RetB=inportb(SBPort+READ_DATA);
    if (RetB==0xAA) return 1;
  } return 0;
}
Byte DSP::CheckWriteBufferStatus(){
  for (int LoopCount=0; LoopCount<100; LoopCount++){
    RetB=inportb(SBPort+WRITE_BUFFER_STATUS);
    if (!(RetB>>7)) return 1;
  } return 0;
}
Byte DSP::CheckDataAvailableStatus(){
  for (int LoopCount=0; LoopCount<100; LoopCount++){
    RetB=inportb(SBPort+DATA_AVAILABLE_STATUS);
    if (RetB>>7) return 1;
  } return 0;
}
void main(){
  int Ret=0;
  DSP dspt;
  Ret=dspt.Reset();
  Ret=dspt.CheckWriteBufferStatus();
  Ret=dspt.CheckDataAvailableStatus();

}