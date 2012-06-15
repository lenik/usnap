/***********************************************************
 TITLE DEMOVDR.C

 This program demostrates how to perform voice recording using
 the CTVDSK.DRV driver. The voice recording is using the Disk
 Double Bufferng method.
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
	      RecordFile("TEMP.VOC");
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

RecordFile(char *szFilename){
  int Handle;
  if(!_dos_creat(szFilename, _A_NORMAL, &Handle)){
    ctvd_speaker(0);
    if(ctvd_input(Handle, 8000)==NO_ERROR){
      RecordUntilStopped();
      if(ctvd_drv_error())
	ShowError();
      else
	printf("Voice record ended.\n");
    }
    else
      ShowError();

    _dos_close(Handle);
  }
  else
    printf("Create %s file error\n", szFilename);
}

#pragma loop_opt(off)
RecordUntilStopped(void){
  unsigned wKey;
  while (ct_voice_status){
    if(_bios_keybrd(_KEYBRD_READY)){
      if((wKey=_bios_keybrd(_KEYBRD_READ)&0xff)==0x1b)
	ctvd_stop();
    }
  }
  printf("Voice stopped.\n");
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
