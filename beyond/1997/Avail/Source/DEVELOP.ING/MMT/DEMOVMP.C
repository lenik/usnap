/***********************************************************
 Source Documentation
 TITLE  DEMOVMP.C

 This program demostrates how to perform voice out using the
 CT-VOICE.DRV driver. The voice out is using the Conventional
 memory method.
 The program checks BLASTER environment for the Card settings.
 It also performs test base on BLASTER environment settings to
 ensure they are tally with the hardware settings on the Card.
 Note that the program included the module LOADDRV.C to load
 the loadable CT-VOICE.DRV into memory.
 **********************************************************/

#include <io.h>
#include <dos.h>
#include <bios.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sbc.h>
#include <sbcvoice.h>
#include "loaddrv.c"

char far *LoadFile(char *szFilename);

main(){
  extern char far *near voice_drv;
  char far *lpVoiceBuf;
  if(!GetEnvSetting()){
    if(sbc_check_card()&4){
      if(sbc_test_int()){
	if(sbc_test_dma()>=0){
	  if(voice_drv=LoadDriver("CT-Voice.DRV")){
	    if(!ctvm_init()){
	      ctvm_speaker(0);
	      if(lpVoiceBuf=LoadFile("DEMO.VOC")){
		OutputVoice(lpVoiceBuf);
		_dos_freemem(FP_SEG(lpVoiceBuf));
	      }
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

char far *LoadFile(char *szFilename){
  char far *lpFileBuf=0, far *lpTmpPtr;
  int Handle;
  unsigned wByteRead;
  long lFileSize;
  if(!_dos_open(szFilename, O_RDONLY, &Handle)){
    lFileSize=filelength(Handle);
    if(!_dos_allocmem((unsigned)((lFileSize+15)>>4), &wByteRead)){
      FP_SEG(lpFileBuf)=wByteRead;
      FP_OFF(lpFileBuf)=0;
      lpTmpPtr=lpFileBuf;
      do{
	if(!_dos_read(Handle, lpTmpPtr, 0x8000, &wByteRead)){
	  if(!(FP_OFF(lpTmpPtr)+=wByteRead))
	    FP_SEG(lpTmpPtr)+=0x1000;
	}
	else{
	  printf("Load file error. \n");
	  wByteRead=0;
	  lpFileBuf=0;
	  _dos_freemem(FP_SEG(lpFileBuf));
	}
      }while(wByteRead==0x8000);
    }
    else
      printf("Memory allocation error.\n");
    _dos_close(Handle);
  }
  else printf("Open %s fails.\n", szFilename);
  return (lpFileBuf);
}

#pragme loop_opt(off)
OutputVoice(char far *lpBuf){
  unsigned wKey;
  int done=0;
  lpBuf+=((VOCHDR far*)lpBuf)->voice_offset;
  ctvm_speaker(1);
  if(ctvm_output(lpBuf)==NO_ERROR){
    done=1;
    while (ct_voice_status){
      if(_bios_keybrd(_KEYBRD_READY)){
	if(wKey=_bios_keybrd(_KEYBRD_READ)){
	  switch(toupper(wKey&0xff)){
	    case 0x1b:
	    case 'S':
	      ctvm_stop();
	      break;
	    case 'P':
	      ctvm_pause();
	      break;
	    case 'C':
	      ctvm_continue();
	      break;
	    case 'B':
	      ctvm_break_loop(1);
	      break;
	  }
	}
      }
    }
  }
  ctvm_speaker(0);
  return(done);
}
#pragma loop_opt()
