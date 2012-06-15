#ifndef __PMKSOUNDDEVICE_H
 #define __PMKSOUNDDEVICE_H
 #ifdef __cplusplus
 extern "C" {
 #endif
// int     far       init262(void);
			  //If can't init return -1
// int     far    initmpu401(void);
			  //If can't init return -1
// void    far	    off262(void);
// void    far     offmpu401(void);
 void    far     initsound(void);
   /* ! *  void    far       midiout(char *filename,int *dims); */
 int     far      readsong(char *filename,int *dims);
			  //if ok return 0  else return -1
 void    far      playsong(int far stat,int far *dims);
   /* ! *  int     far      readplay(char *filename,int *dims); */
 int     far    readvolume();
			  //Return volume
 int     far     setvolume(int far volumevalue);
			  //Return volumevalue
 void    far      stopsong(void);
 void    far     quitsound(void);

   /* ! *  int     far     readtempo(int *dims); */
// int     far     readticks(void);
// int     far     readtimer(int timer);
   /* ! *  int     far      settempo(void); */
 int     far      shiftkey(unsigned char key);
			  //Change base voice.(base freq) Return key

 #ifdef __cplusplus
 }
 #endif
#endif
