//893-
#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<alloc.h>
#include<malloc.h>
#include<sys\stat.h>
#include<string.h>
#include<fcntl.h>
#include<io.h>
#include<conio.h>
#include<time.h>
#include<bios.h>
#include<process.h>
#include<mem.h>
#include<iostream.h>
#include<ctype.h>
#include<dir.h>
#include<float.h>
#include<math.h>
#define enter 0x1c0d
#define spbar 0x3920
#define bksp 0x0e08
#define rarrow 0x4d00
#define larrow 0x4b00
#define uarrow 0x4800
#define darrow 0x5000
#define pgup 0x4900
#define pgdn 0x5100
#define home 0x4700
#define end 0x4f00
#define esc 0x011B
#define ret 0x1c0d
#define ins 0x5200
#define f1 0x3b00
#define f2 0x3c00
#define f3 0x3d00
#define f4 0x3e00
#define f5 0x3f00
#define f6 0x4000
#define f7 0x4100
#define f8 0x4200
#define f9 0x4300
#define f10 0x4400
#define a_x 0x2d00
#define a_s 0x1f00
#define a_h 0x2300
#define a_p 0x1900
#define a_a 0x1e00
#define a_b 0x3000
#define a_c 0x2e00
#define a_d 0x2000
#define a_1 0x7800
#define a_2 0x7900
#define a_3 0x7a00
#define a_4 0x7b00
#define a_5 0x7c00
#define a_6 0x7d00
#define a_7 0x7e00
#define a_8 0x7f00
#define a_9 0x8000
#define a_0 0x8100
#define alt 0x04
#define delkey 339
#define c_end 0x7500
#define c_p 0x0010
#define c_j 0x000a
#define a_w 001100
#define a_e 001200
#define ldmax 100
#define ldarrmax 10
#define lo(f) ((f)&0xff)
#define hi(f) (lo(f>>8))
class pld{
 protected:
 FILE *fp;
 struct dosdate_t d;
 struct time t;
 struct _dos_getdiskfree;
 long avail;
 unsigned size;
 void far *ptr[4];
 int x,y,X,Y,i,R,x2,xx,yy,cc,maxx,maxy,cursormovex,cursormovey,ldlinexend,ldlineyend,ldlinecolor,ldline1,ldline2,ldlineclass,ldcircler,ldcirclecolor,ldcircleclass,ldrectanglexend,ldrectangleyend,ldrectangleclass,ldrectanglecolor,ldcharcolor,ldcharlarge,
     j,select,selection,memorysize,handle,ldscrcolor,ldscrclass,ldcursormovex,ldcursormovey,ldleft,ldtop,ldright,ldbottom,ldcolor,ldcursorcolor,ldbarxend,ldbaryend,ldbarcolor,ldbarclass,ldcharclass,ldbarf,ldscores[ldarrmax],ldchinacolor,xstart,ystart,xend,yend;
 char buffer[25000],s[MAXPATH],drive[MAXDRIVE],dir[MAXDIR],rest,savename0[30],loadname0[30],ldprintname[30],alT[30],ldcharchar[30],ldchina[20];
 public:
  int lookkey(int *k);
  int fontselect(void);
  char getkey(int *k);
  char getkeyc(void);
  void beep(void);
  void gotoxyabs(char x,char y);
  void setcursor(int ctop,int cbot);
  void fonterror(int errcode);
  void fontsize(int fstyle);
  void sele();
  void ldscreen();
  void ldsavename();
  void ldsavefile0();
  void ldsavefile1();
  void ldloadname();
  void ldloadfile0();
  void ldloadfile1();
  void ldmenu();
  void ldhelp();
  void ldscreencolor();
  void ldselectionmenu();
  void ldline();
  void ldscreentime();
  void ldsubmenu();
  void ldbar();             //1064
  void ldfang();
  void ldico();
  void lddir();
  void ldf1();
  void ldf2();
  void ldf3();
  void ldf4();
  void ldf5();
  void ldf6();
  void ldf7();
  void ldf8();
  void ldf9();
  void ldf10();
  void lda_a();
  void lda_b();
  void lda_c_c();
  void lda_d();
  void lda_1();
  void lda_2();
  void lda_3();
  void lda_4();
  void lda_5();
  void lda_6();
  void lda_7();
  void lda_8();
  void lda_9();
  void ldhome();
  void ldins();
  void ldend();
  void ldpgup();
  void ldpgdn();
  void ldc_q();
  void lddirclear();
  void ldc_end();
  void ldcircle();
  void ldbarrectangle();
  void ldchar();
  void ldnewfile();
  void fangkuang();
  void ldspace();
  void ldprintscreengraph();
  void ldprintwait();
};
