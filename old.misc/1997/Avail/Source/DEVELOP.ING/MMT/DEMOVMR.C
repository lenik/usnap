/***********************************************************
 TITLE DEMOVMR.C

 This program demostrates how to perform voice recording using
 the CT-VOICE.DRV driver. The voice recording is using the
 Conventional memory method.  The recording can be terminated
 by pressing ESC.

 The Program checks BLASTER environment for the Card settings.
 It also performs test base onBLASTER environment settings to
 ensure they are tally with the hardware settings on the Card.

 Note that the program included the module LOADDRV.C to load
 the loadable CT-VOICE.DRV into memory.
 **********************************************************/

#include <io.h>
#include <stdlib.h>
#include <dos.h>
#include <bios.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sbc.h>
#include <sbcvoice.h>

#include "loaddrv.c"

SaveVoiceFile(char *, char far*);
RecordVoice(char *szFilename);

main(){
  extern char far * near voice_drv;
  if(!GetEnvSetting()){
    if(sbc_check_card()&4){
      if(sbc_test_int()){
	if(sbc_test_dma()>=0){
	  if(voice_drv=LoadDriver("CT-Voice.DRV")){
	    if(!ctvm_init()){
	      ctvm_speaker(0);
	      RecordVoice("TEMP.VOC");
	      ctvm_terminate();
	    }
	  }
	}
	else
	  printf("Error on DMA channel.\n");
      }
      else
	printf("Error on interrup.\n");
    }
    else
      printf("Sound Blaster Card not found or wrong I/O settings.\n");
  }
  else
    printf("BLASTER environment not set or incomplete or invalid.\n");
}

RecordVoice(char *szFilename){
  unsigned wSeg;
  char far *lpVoiceBuf;
  long lBufSize=0x20000L;
  if (!_dos_allocmem((unsigned)((lBufSize+15)>>4), &wSeg)){
    FP_SEG(lpVoiceBuf)=wSeg;
    FP_OFF(lpVoiceBuf)=0;
    if(Recording(lpVoiceBuf, lBufSize))
      SaveVoiceFile(szFilename, lpVoiceBuf);
    _dos_freemem(FP_SEG(lpVoiceBuf));
  }
  else
    printf("Memory allocation error.\n");
}

#pragma loop_opt(off)
Recording(char far *lpBuf, long lBufSize){
  int RetVal=0;
  ctvm_speaker(0);
  if(ctvm_input(lpBuf, lBufSize, 8000)==NO_ERROR){
    RetVal=0;
    printf("\nStart recording, press ESC key to terminate...");
    while(ct_voice_status){
      if(_bios_keybrd(_KEYBRD_READY)){
	if(_bios_keybrd(_KEYBRD_READY)==0x11b)
	  ctvm_stop();
      }
    }
    printf("\nRecording end.");
  }
  return(RetVal);
}

#pragma loop_opt()
SaveVoiceFile(char *szFilename, char far *lpBuf){
  int Handle;
  long lVoiceSize;
  VOCHDR stHeader;

  strcpy(stHeader.id, "Creative Voice File\x01A");
  stHeader.voice_offset=sizeof(VOCHDR);
  stHeader.version=0x10a;
  stHeader.check_code=~stHeader.version+0x1234;
  if(_dos_creat(szFilename, _A_NORMAL, &Handle))
    printf("Create %s error. \n", szFilename);
  else{
    if(WriteToFile(Handle, (char far*)&stHeader, (long)sizeof(VOCHDR))){
      lVoiceSize=*(lpBuf+3);
      lVoiceSize<<=16;
      lVoiceSize+=*(unsigned far *)(lpBuf+1);
      lVoiceSize+=5;
      WriteToFile(Handle, lpBuf, lVoiceSize);
    }
    _dos_close(Handle);
  }
}

WriteToFile(int Handle, char far*lpBuf, long lSize){
  int RetVal=1;
  unsigned wByteToWrite, wByteWritten;
  while(lSize){
    wByteToWrite=0x8000;
    if(lSize<0x8000)
      wByteToWrite=(int)lSize;
    if(_dos_write(Handle, lpBuf, wByteToWrite, &wByteWritten)){
      printf("Write file error. \n");
      RetVal=0;
      break;
    }
    else{
      if(wByteWritten!=wByteToWrite){
	printf("Disk full.\n");
	RetVal=0;
	break;
      }
      else{
	if(FP_OFF(lpBuf)<0x8000)
	  FP_OFF(lpBuf)+=wByteWritten;
	else{
	  FP_OFF(lpBuf)+=wByteWritten;
	  FP_SEG(lpBuf)+=0x1000;
	}
	lSize-=wByteWritten;
      }
    }
  }
  return(RetVal);
}
