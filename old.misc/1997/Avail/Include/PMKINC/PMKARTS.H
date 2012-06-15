#ifndef __PMKARTS_H
 #define __PMKARTS_H

 #ifndef __PMKTIME_H
  #include<pmktime.h>
 #endif

 extern "C" {void    _Cdecl srand(unsigned __seed);
	     int     _Cdecl rand(void);}

 #define lefttoright   1
 #define uptobottom    2
 #define rndcolor     -1
 void rainlines(unsigned char mode,int x1,int y1,int x2,int y2,int color) //rate means how long does rain ONE line took.
 {int c,t0,t1,t2,t3,e=0;int p[1500],s;srand((unsigned)time(NULL));
  t0=(mode==lefttoright)?y1:x1;t1=(mode==lefttoright)?y2:x2;t2=(mode==lefttoright)?x2:y2;t3=(mode==lefttoright)?x1:y1;
  if(color!=-1)setcolor(color);for(c=t0;c<=t1;c++)p[c]=0;
  while(e++<(t2-t3)/5) for(c=t0;c<=t1;c++){if(color==-1)setcolor(rand()%16);s=rand()%50+1;if(mode==lefttoright)line(p[c],c,p[c]+s,c);else line(c,p[c],c,p[c]+s);p[c]+=s;}
 }
 void scrolllines(unsigned char mode,int x1,int y1,int x2,int y2,int color,int width,int d)
 {int s1,s2,t1,t2;t1=(mode==lefttoright)?x1:y1;t2=(mode==lefttoright)?x2:y2;
  setcolor(color);for(s1=0;s1<=width;s1++){for(s2=t1+s1;s2<=t2;s2+=width)if(mode==lefttoright)line(s2,y1,s2,y2);else line(x1,s2,x2,s2);delay(d);}
 }
#endif