/***********************************************************
 char far *LoadDriver(char *szDrvName)
 ***********************************************************/

#include <string.h>
#include <dos.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>

char far *LoadDriver(char *szDrvName){
  char far *lpDrvPtr=0;
  char far *lpPtr;
  char szDrvFile[100];
  char *pPtr;
  int Handle=1;
  unsigned wTemp, wDrvSize;
  struct find_t stFile;

  if (pPtr=getenv("SOUND")){
    strcat(strcpy(szDrvFile, pPtr), "\\DRV\\");
    strcat(szDrvFile, szDrvName);
    Handle=_dos_findfirst(szDrvFile, _A_NORMAL, &stFile);
  }
  if (Handle){
    strcpy(szDrvFile, szDrvName);
    Handle=_dos_findfirst(szDrvFile, _A_NORMAL, &stFile);
  }
  if (Handle){
    printf("Driver file does not exist.\n");
  }else{
    if(_dos_open(szDrvFile, O_RDONLY, &Handle))
      printf("Open %s error. \n", szDrvFile);
    else{
      wDrvSize=(unsigned) filelength(Handle);
      if(!_dos_allocmem(((wDrvSize+15)>>4), &wTemp)){
	FP_SEG(lpDrvPtr)=wTemp;
	FP_OFF(lpDrvPtr)=0;
	lpPtr=lpDrvPtr;
	if(_dos_read(Handle, lpPtr, wDrvSize, &wTemp)){
	  _dos_freemem(FP_SEG(lpDrvPtr));
	  lpDrvPtr=0;
	}
      }
      else
	printf("Memory alloction error\n");

      _dos_close(Handle);
    }
  }
  return (lpDrvPtr);
}