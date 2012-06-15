/***********************************************************
 TITLE DEMOVDP.C

 This program demostrates how to perform voice out using the
 CTVDSK.DRV driver. The voice out is using the Disk Double
 Bufferng method.
 The program checks BLASTER environment for the card settings.
 It also performs test base on BLASTER enviroment settings to
 ensure they are tally with the hardware setings on the Card.

 Note that the program included the module LOADDRV.C to load
 the loadable CTVDSK.DRV into memory.
 **********************************************************/

#include <dos.h>
#include <bios.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sbc.h>
#include <sbcvoice.h>
#include "loaddrv.c"

main(){
  extern char far *near ctvdsk_drv;
  if(!GetEnvSetting()){
    if(sbc_check_card()&4){
      if(sbc_test_int()){
	if(sbc_test_dma()>=0){
	  if(voice_drv=LoadDriver("CTVDSK.DRV")){
	    if(!ctvm_init(16)){
	      OutputFile("DEMO.VOC");
	      ctvm_terminate();
	    }
	    else
	      ShowError();
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

OutputFile (char *szFilename){
  int Handle;
  if (!_dos_open(szFilename, O_RDONLY, &Handle)){
    ctvd_speaker(1);
    if(ctvd_output(Handle)==NO_ERROR){
      PlayVoiceInBkgnd();
      if(ctvd_drv_error())
	ShowError();
      else
	printf("Voice output ended.\n");
    }
    else
      ShowError();

    _dos_close(Handle);
  }
  else
    printf("Open %s file error\n", szFilename);
}

#pragma loopopt(off)
PlayVoiceInBkgnd(void){
  unsigned wKey;
  while(ct_voice_status){
    if(_bios_keybrd(_KEYBRD_READY)){
      switch((wKey=_bios_keybrd(_KEYBRD_READ)&0xff)){
	case 0x1b: ctvd_stop(); printf("Voice stopped.\n"); break;
	case ' ':  ctvd_pause(); printf("Pause...\nPressed any key to continue.\n"); _bios_keybrd(_KEYBRD_READ); ctvd_continue(); break;
	case 0x0d: ctvd_break_loop(1); printf("Break-out takes place immediately\n"); break;
	case 0x9:  ctvd_break_loop(0); printf("Break-ou ttakes place after the current loop finished\n"); break;
      }
    }
  }
}
#pragma loop_opt()

ShowError(void){
  int Err;
  Err=ctvd_drv_error();
  printf("Driver error=%2d\n", Err);
  Err=ctvdexterror();
  if(Err!=0)
    printf("DOS error=%2d\n", Err);
}
