#ifndef __PMKMOUSECLASSM_H
 #define __PMKMOUSECLASSM_H

  #if !defined(__TIME_H)
    #include<time.h>
  #endif

  #if !defined(__DOS_H)
    #include<dos.h>
  #endif

  #if !defined(__STDLIB_H)
    #include<stdlib.h>
  #endif

  #if !defined(__BIOS_H)
    #include<bios.h>
  #endif

  #if !defined(__CONIO_H)
    #include<conio.h>
  #endif

  struct far  mc;
  struct far  mcstr;
  class  huge MouseClass;

  struct far  mc
    {unsigned img[32];
     int cx,cy;};

  struct far  mcstr
    {char *img[32];
     int cx,cy;};

  class  huge MouseClass
    {protected:
	     REGS  m_Regs;
	     SREGS m_SRegs;

     public:
       char  m_Button,m_Flag;
       int   m_MouseX,m_MouseY;
       int   m_MouseMinX,m_MouseMinY,m_MouseMaxX,m_MouseMaxY;
       char  m_MouseMovAbsX,m_MouseMovAbsY;

       int  Test(void);
       int  Status(void);

       void Scr(void);

	    MouseClass(void);

       void Init(void);

       void Show(void);
       void Hide(void);

       void Move(int mx,int my);
       void Move(void);

       int  MovAbs(char mx,char my);
       void MovAbs(void);

       void Limit(int minx,int miny,int maxx,int maxy);
       void Limit(void);

       int  Press(int button,int &pcount);
       int  Release(int button,int &rcount);
       int  GetKey(void);
       int  GetKey(long second);

       void Speed(int numx,int numy);

       void Cursor(mc cur);
       void Cursorstr(mcstr cur);
    };

#endif