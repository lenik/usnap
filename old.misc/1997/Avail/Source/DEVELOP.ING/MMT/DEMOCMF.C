/***********************************************************
 TITLE DEMOCMF.C

 This program demostrates how to use the SBFM high level
 functions to playback the music file FFARES.CMF. The user
 is allowed to control the music output from the keyboard.

 Note that the BLASTER environment has to be set and SBFMDRV.COM
 has to be installed before executing this program.
 **********************************************************/

#include <io.h>
#include <dos.h>
#include <stdio.h>
#include <bios.h>
#include <fcntl.h>
#include <sbcmusic.h>
#include <sbc.h>

char far *lpMusicBuf=0;
char cTranspose=0;

main(int argc, char *argv[]){
  unsigned wVersion;
  if(sbfm_init()){
    wVersion=sbfm_version();
    printf("Driver version %d.%02d\n", wVersion>>8, wVersion&255);
    PlayCmfFile("FFARES.CMF");
    sbfm_terminate();
  }else
    printf("SBFMDRV not installed or FM Driver initialization error.\n ");
}

PlayCmfFile (char *szFilename){
  if(LoadFile(szFilename)){
    StartMusic();
    WaitMusicEnd();
  }
}

LoadFile(char *szFilename){
  char far *lpTmpPtr;
  int Handle;
  unsigned wByteRead, RetVal=0;
  long lFileSize;

  if(!_dos_open(szFilename, O_RDONLY, &Handle)){
    lFileSize=filelength(Handle);
    if(!_dos_alocmem((unsigned)((lFileSize+15)>>4), &wByteRead)){
      FP_SEG(lpMusicBuf)=wByteRead;
      FP_OFF(lpMuscBuf)=0;
      lpTmpPtr=lpMusicBuf;
      RetVal=1;
      do{
	if(!_dos_read(Handle, lpTmpPtr, 0x8000, &wByteRead)){
	  if(!(FP_OFF(lpTmpPtr)+=wByteRead))
	    FP_SEG(lpTmpPtr)+=0x1000;
	}else{
	  printf("Load file error.\n");
	  wByteRead=0;
	  RetVal=0;
	  _dos_freemem(FP_SEG(lpMusicBuf));
	}
      }while (wByteRead==0x8000);
    }
    else
      printf("Memory allocation error.\n");
    _dos_close(Handle);
  }else
    printf("Open %s fails.\n", szFilename);
  return(RetVal);
}
StartMusic(void){
  char far *lpInstPtr;
  char far *lpMusicPtr;
  int Timer0Freq;

  lpInstPtr= lpMusicBuf+*(int far *)(lpMusicBuf+6);
  lpMusicPtr=lpMusicBuf+*(int far *)(lpMusicBuf+8);

  sbfm_reset();

  Timer0Freq=(int)(1193180L/(*(int far*)(lpMusicBuf+12)));
  sbfm_song_speed(Timer0Freq);
  if(FP_OFF(lpInstPtr))
    sbfm_instrument(lpInstPtr, *(lpMusicBuf+0x24));
  sbfm_play_music(lpMusicPtr);
}

#pragma loop_opt(off)
WaitMusicEnd(void){
  unsigned wKey, wStatus;
  while(uStatus=sbfm_read_status()){
    if(wStatus!=255)
      printf("Status: %c-%d\n", wStatus, wStatus);
    if(_bios_keybrd(_KEYBRD_READY)){
      wKey=toupper(wKey&255);
      switch(Key){
	case 0x1b:	sbfm_stop_music();
			break;
	case 0x4b00:	sbfm_transpose(--cTranspose);
			printf("Transpose: %d\n", cTranspose);
			break;
	case 0x4d00:	sbfm_transpose(++cTranspose);
			printf("Transpose: %d\n", cTranspose);
			break;
	case 'P':	sbfm_pause_music();
			break;
	case 'C':	sbfm_resume_music();
			break;
      }
    }
  }
}
#pragma loop_opt()
