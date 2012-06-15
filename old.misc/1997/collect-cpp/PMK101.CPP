#include<stdio.h>
#include<conio.h>
#include<graphics.h>

//FILE *fpmk,*fbas,*fpas,*fc;
#define Fpmk 0
#define Fbas 1
#define Fpas 2
#define Fc   3
#define to 0
#define tm 1
#define ti 2
#define ro 3
#define rm 4
#define ri 5
#define bo 6
#define bm 7
#define bi 8
#define lo 9
#define lm 10
#define li 11
char If,Of;
int mx=getmaxx(),my=getmaxy();
struct rec3d{int x1,y1,x2,y2,widtho,widthm,widthi,heighto,heightm,heighti;unsigned char bc,cl,cn,cd,fl,fn,fd,dir;};
char *getfiletype(char filetype) {char *Fileextn[4]={".Pmk",".Bas",".Pas",".C"};return (Fileextn[filetype]);}
void drawrec3d(rec3d runr3);
unsigned char get3dcolor(rec3d runr3,const unsigned int place,unsigned char returncolor,unsigned char returnfill);
void init(void);

void main()
{rec3d startpage;
 If=Fpmk;
 Of=Fc;
 init();
 settextjustify(LEFT_TEXT,TOP_TEXT);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
 outtextxy(0,0,"Program Maker 1.00");

 startpage.x1=15;startpage.y1=50;
 startpage.x2=getmaxx()-20;startpage.y2=getmaxy()-20;
 startpage.widtho=startpage.heighto=10;startpage.widthm=startpage.heightm=15;startpage.widthi=startpage.heighti=7;
 startpage.cl=getmaxcolor();startpage.cd=0;startpage.cn=7;
 startpage.fl=SOLID_FILL;startpage.fn=INTERLEAVE_FILL;startpage.fd=CLOSE_DOT_FILL;startpage.bc=8;
 startpage.dir=0;
 drawrec3d(startpage);
 getch();
}

void init(void)
{int gd=DETECT,gm,errorcode;
 errorcode=registerbgidriver(ATT_driver_far);
 errorcode=registerbgidriver(CGA_driver_far);
 errorcode=registerbgidriver(Herc_driver_far);
 errorcode=registerbgidriver(EGAVGA_driver_far);
 errorcode=registerbgifont(sansserif_font_far);
 errorcode=registerbgifont(gothic_font_far);
 errorcode=registerbgifont(small_font_far);
 errorcode=registerbgifont(triplex_font_far);
 initgraph(&gd,&gm,"");
 errorcode = graphresult();
 if (errorcode != grOk)
 { printf("Graphics error: %s\n", grapherrormsg(errorcode)); printf("Press any key to return to command prompt:"); getch(); }
}

void drawrec3d(rec3d runr3)
{int poly[8];unsigned char retc,retf;
 setfillstyle(get3dcolor(runr3,to,111,retf),get3dcolor(runr3,to,retc,111));
 poly[0]=runr3.x1-runr3.widtho; poly[1]=poly[3]=runr3.y1-runr3.heighto;
 poly[2]=runr3.x2+runr3.widtho;
 poly[4]=runr3.x2;poly[5]=poly[7]=runr3.y1;
 poly[6]=runr3.x1;
 fillpoly(4,poly);

 setfillstyle(get3dcolor(runr3,lo,111,retf),get3dcolor(runr3,lo,retc,111));
 poly[2]=poly[0];poly[3]=runr3.y2+runr3.heighto;
 poly[4]=poly[6];poly[5]=runr3.y2;
 poly[6]=runr3.x1;poly[7]=runr3.y1;
 fillpoly(4,poly);

 setfillstyle(get3dcolor(runr3,bo,111,retf),get3dcolor(runr3,bo,retc,111));
 poly[0]=runr3.x2+runr3.widtho;poly[1]=runr3.y2+runr3.heighto;
 poly[6]=runr3.x2;poly[7]=runr3.y2;
 fillpoly(4,poly);

 setfillstyle(get3dcolor(runr3,ro,111,retf),get3dcolor(runr3,ro,retc,111));
 poly[2]=runr3.x2+runr3.widtho;poly[3]=runr3.y1-runr3.heighto;
 poly[4]=runr3.x2;poly[5]=runr3.y1;
 fillpoly(4,poly);

 setfillstyle(runr3.fn,runr3.cn);
 poly[0]=runr3.x1;poly[1]=poly[3]=runr3.y1;
 poly[2]=runr3.x2;
 poly[4]=runr3.x2-runr3.widthm;poly[5]=poly[7]=runr3.y1+runr3.heightm;
 poly[6]=runr3.x1+runr3.widthm;
 fillpoly(4,poly);
 poly[2]=poly[0];poly[3]=runr3.y2;
 poly[4]=runr3.x1+runr3.widthm;poly[5]=runr3.y2-runr3.heightm;
 fillpoly(4,poly);
 poly[0]=runr3.x2;poly[1]=runr3.y2;
 poly[6]=runr3.x2-runr3.widthm;poly[7]=runr3.y2-runr3.heightm;
 fillpoly(4,poly);
 poly[2]=runr3.x2;poly[3]=runr3.y1;
 poly[4]=runr3.x2-runr3.widthm;poly[5]=runr3.y1+runr3.heightm;
 fillpoly(4,poly);

 setfillstyle(get3dcolor(runr3,ti,111,retf),get3dcolor(runr3,ti,retc,111));
 setfillstyle(get3dcolor(runr3,li,111,retf),get3dcolor(runr3,li,retc,111));
 setfillstyle(get3dcolor(runr3,bi,111,retf),get3dcolor(runr3,bi,retc,111));
 setfillstyle(get3dcolor(runr3,ri,111,retf),get3dcolor(runr3,ri,retc,111));

}

unsigned char get3dcolor(rec3d runr3,const unsigned int place,unsigned char returncolor,unsigned char returnfill)
{unsigned char sc1,sc2,tp;
 switch (runr3.dir)
 {case 0: switch(place)
	  {case lo:
	   case to:
	   case ri:
	   case bi:sc1=runr3.cl;sc2=runr3.fl;break;
	   case li:
	   case ti:
	   case ro:
	   case bo:sc1=runr3.cd;sc2=runr3.fd;break;
	   default:sc1=runr3.cn;sc2=runr3.fn;}break;
  case 1: switch(place)
	  {case to:
	   case bi:sc1=runr3.cl;sc2=runr3.fl;break;
	   case ti:
	   case bo:sc1=runr3.cd;sc2=runr3.fd;break;
	   default:sc1=runr3.cn;sc2=runr3.fn;}break;
  case 2: switch(place)
	  {case li:
	   case to:
	   case ro:
	   case bi:sc1=runr3.cl;sc2=runr3.fl;break;
	   case lo:
	   case ti:
	   case ri:
	   case bo:sc1=runr3.cd;sc2=runr3.fd;break;
	   default:sc1=runr3.cn;sc2=runr3.fn;}break;
  case 3: switch(place)
	  {case ro:
	   case li:sc1=runr3.cl;sc2=runr3.fl;break;
	   case lo:
	   case ri:sc1=runr3.cd;sc2=runr3.fd;break;
	   default:sc1=runr3.cn;sc2=runr3.fn;}break;
  case 4: switch(place)
	  {case li:
	   case ti:
	   case ro:
	   case bo:sc1=runr3.cl;sc2=runr3.fl;break;
	   case lo:
	   case to:
	   case ri:
	   case bi:sc1=runr3.cd;sc2=runr3.fd;break;
	   default:sc1=runr3.cn;sc2=runr3.fn;}break;
  case 5: switch(place)
	  {case ti:
	   case bo:sc1=runr3.cl;sc2=runr3.fl;break;
	   case to:
	   case bi:sc1=runr3.cd;sc2=runr3.fd;break;
	   default:sc1=runr3.cn;sc2=runr3.fn;}break;
  case 6: switch(place)
	  {case lo:
	   case bo:
	   case ti:
	   case ri:sc1=runr3.cl;sc2=runr3.fl;break;
	   case li:
	   case bi:
	   case to:
	   case ro:sc1=runr3.cd;sc2=runr3.fd;break;
	   default:sc1=runr3.cn;sc2=runr3.fn;}break;
  case 7: switch(place)
	  {case lo:
	   case ri:sc1=runr3.cl;sc2=runr3.fl;break;
	   case li:
	   case ro:sc1=runr3.cd;sc2=runr3.fd;break;
	   default:sc1=runr3.cn;sc2=runr3.fn;}
  default:;}
 if (returncolor>=100) tp=sc1; else tp=sc2;
 returncolor=sc1;returnfill=sc2;
 return tp;
}
public name = '_ATT_driver_far', segment name = 'ATT_TEXT'.

BGI to OBJ Converter  Version 4.0 Copyright (c) 1987, 1992 Borland International

6332 bytes from 'CGA.BGI' converted into 'CGAF.OBJ',
public name = '_CGA_driver_far', segment name = 'CGA_TEXT'.

BGI to OBJ Converter  Version 4.0 Copyright (c) 1987, 1992 Borland International

5554 bytes from 'EGAVGA.BGI' converted into 'EGAVGAF.OBJ',
public name = '_EGAVGA_driver_far', segment name = 'EGAVGA_TEXT'.

BGI to OBJ Converter  Version 4.0 Copyright (c) 1987, 1992 Borland International

6204 bytes from 'HERC.BGI' converted into 'HERCF.OBJ',
public name = '_Herc_driver_far', segment name = 'HERC_TEXT'.

BGI to OBJ Converter  Version 4.0 Copyright (c) 1987, 1992 Borland International

6665 bytes from 'IBM8514.BGI' converted into 'IBM8514F.OBJ',
public name = '_IBM8514_driver_far', segment name = 'IBM8514_TEXT'.

BGI to OBJ Converter  Version 4.0 Copyright (c) 1987, 1992 Borland International

6012 bytes from 'PC3270.BGI' converted into 'PC3270F.OBJ',
public name = '_PC3270_driver_far', segment name = 'PC3270_TEXT'.

BGI to OBJ Converter  Version 4.0 Copyright (c) 1987, 1992 Borland International

18063 bytes from 'GOTH.CHR' converted into 'GOTHF.OBJ',
public name = '_gothic_font_far', segment name = 'GOTH_TEXT'.

BGI to OBJ Converter  Version 4.0 Copyright (c) 1987, 1992 Borland International

5131 bytes from 'LITT.CHR' converted into 'LITTF.OBJ',
public name = '_small_font_far', segment name = 'LITT_TEXT'.

BGI to OBJ Converter  Version 4.0 Copyright (c) 1987, 1992 Borland International

13596 bytes from 'SANS.CHR' converted into 'SANSF.OBJ',
public name = '_sansserif_font_far', segment name = 'SANS_TEXT'.

BGI to OBJ Converter  Version 4.0 Copyright (c) 1987, 1992 Borland International

16677 bytes from 'TRIP.CHR' converted into 'TRIPF.OBJ',
public name = '_triplex_font_far', segment name = 'TRIP_TEXT'.

BGI to OBJ Converter  Version 4.0 Copyright (c) 1987, 1992 Borland International

6332 bytes from 'ATT.BGI' converted into 'ATT.OBJ',
public name = '_ATT_driver'.

BGI to OBJ Converter  Version 4.0 Copyright (c) 1987, 1992 Borland International

6332 bytes from 'CGA.BGI' converted into 'CGA.OBJ',
public name = '_CGA_driver'.

BGI to OBJ Converter  Version 4.0 Copyright (c) 1987, 1992 Borland International

5554 bytes from 'EGAVGA.BGI' converted into 'EGAVGA.OBJ',
public name = '_EGAVGA_driver'.

BGI to OBJ Converter  Version 4.0 Copyright (c) 1987, 1992 Borland International

6204 bytes from 'HERC.BGI' converted into 'HERC.OBJ',
public name = '_Herc_driver'.

BGI to OBJ Converter  Version 4.0 Copyright (c) 1987, 1992 Borland International

6665 bytes from 'IBM8514.BGI' converted into 'IBM8514.OBJ',
public name = '_IBM8514_driver'.

BGI to OBJ Converter  Version 4.0 Copyright (c) 1987, 1992 Borland International

6012 bytes from 'PC3270.BGI' converted into 'PC3270.OBJ',
public name = '_PC3270_driver'.

BGI to OBJ Converter  Version 4.0 Copyright (c) 1987, 1992 Borland International

18063 bytes from 'GOTH.CHR' converted into 'GOTH.OBJ',
public name = '_gothic_font'.

BGI to OBJ Converter  Version 4.0 Copyright (c) 1987, 1992 Borland International

5131 bytes from 'LITT.CHR' converted into 'LITT.OBJ',
public name = '_small_font'.

BGI to OBJ Converter  Version 4.0 Copyright (c) 1987, 1992 Borland International

13596 bytes from 'SANS.CHR' converted into 'SANS.OBJ',
public name = '_sansserif_font'.

BGI to OBJ Converter  Version 4.0 Copyright (c) 1987, 1992 Borland International

16677 bytes from 'TRIP.CHR' converted into 'TRIP.OBJ',
public name = '_triplex_font'.
