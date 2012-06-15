/* Warning:
    BESURE The string[] used in dnn functions, the elements of string[]
    must more 1 then the index of element of wlib[][]
*/

#ifndef __PMKZK_H
    #define __PMKZK_H

/*	#if !defined(__PMKDRAW_H)
	#include<PmkInc\PmkDraw.h>
	#endif
*/
	#if !defined(__STRING_H)
	#include<string.h>
	#endif
	void   huge     snhz16(unsigned char huge a[32],      int  far xx,      int far yy,unsigned char far cc){register unsigned char dr;setcolor(cc);for(dr=0;dr<=15;dr++){setlinestyle(4,a[dr*2],1);line(xx+15,yy+dr,xx,yy+dr);setlinestyle(4,a[dr*2+1],1);line(xx+23,yy+dr,xx+8,yy+dr);}}
	void   huge     snhz24(unsigned char huge a[72],      int  far xx,      int far yy,unsigned char far cc){register unsigned char i,k;for(i=0;i<24;i++)for(k=0;k<8;k++){if((a[i*3]>>(7-k))&1)putpixel(xx+i,yy+k,cc);if((a[i*3+1]>>(7-k))&1)putpixel(xx+i,yy+8+k,cc);if((a[i*3+2]>>(7-k))&1)putpixel(xx+i,yy+16+k,cc);}}
	void   huge     snhz40(unsigned char huge a[200],     int  far xx,      int far yy,unsigned char far cc){register unsigned char dr1,dr2;setcolor(cc);for(dr1=0;dr1<=39;dr1++)for(dr2=1;dr2<=5;dr2++){setlinestyle(4,a[dr1*5+dr2-1],1);line(xx+(dr2+1)*8,yy+dr1,xx+(dr2-1)*8+1,yy+dr1);}}
	void   huge     snhz48(unsigned char huge a[288],     int  far xx,      int far yy,unsigned char far cc){register unsigned char dr1,dr2;setcolor(cc);for(dr1=0;dr1<=47;dr1++)for(dr2=1;dr2<=6;dr2++){setlinestyle(4,a[dr1*6+dr2-1],1);line(xx+(dr2+1)*8,yy+dr1,xx+(dr2-1)*8+1,yy+dr1);}}
	void   huge        d16(unsigned char huge wlib[][32], char far string[],int far xx,int far yy,int far cc,int far skip){register int p;for(p=0;p<_fstrlen(string);p++)snhz16(wlib[string[p]-1],xx+(16+skip)*p,yy,cc);}
	void   huge        d24(unsigned char huge wlib[][72], char far string[],int far xx,int far yy,int far cc,int far skip){register int p;for(p=0;p<_fstrlen(string);p++)snhz24(wlib[string[p]-1],xx+(24+skip)*p,yy,cc);}
	void   huge        d40(unsigned char huge wlib[][200],char far string[],int far xx,int far yy,int far cc,int far skip){register int p;for(p=0;p<_fstrlen(string);p++)snhz40(wlib[string[p]-1],xx+(40+skip)*p,yy,cc);}
	void   huge        d48(unsigned char huge wlib[][288],char far string[],int far xx,int far yy,int far cc,int far skip){register int p;for(p=0;p<_fstrlen(string);p++)snhz48(wlib[string[p]-1],xx+(48+skip)*p,yy,cc);}
	rec2d  huge   gethzwin(char          far  string[],   int  far howbig,  int far xx,int far yy,int far skip){rec2d retval;retval.x1=retval.putx=xx+8;retval.y1=retval.puty=yy;retval.x2=xx+howbig*_fstrlen(string)+skip*(_fstrlen(string)-1)+8;retval.y2=yy+howbig;return retval;}
	class  huge     hz3d{public:hz3d(void){init();}int x,y;unsigned char fontname,fontsize,dir,depth,skip,c,co;char *string;void draw(void);void init(void){x=y=dir=depth=fontname=0;fontsize=16;skip=1;c=7;co=15;}};
	void            hz3d::draw(void){int tmp,xx,yy,tc;unsigned char flag=0;for(tmp=depth;tmp>=0;tmp-=skip){xx=x;yy=y;switch (dir){case 0:xx=x-tmp;yy=y-tmp;break;case 1:yy=y-tmp;break;case 2:xx=x+tmp;yy=y-tmp;break;case 3:xx=x+tmp;break;case 4:xx=x+tmp;yy=y+tmp;break;case 5:yy=y+tmp;break;case 6:xx=x-tmp;yy=y+tmp;break;case 7:xx=x-tmp;default:;}
					 workout:switch(fontsize){case 16:switch(fontname){
					 #ifdef _eng16_
					 case E16: d16(eng16,string,xx,yy,c,skip);break;
					 #endif
					 #ifdef _lib16_
					 case L16: d16(lib16,string,xx,yy,c,skip);break;
					 #endif
					 default:;}break;case 24:switch(fontname){
					 #ifdef _lib24s_
					 case L24s:d24(lib24s,string,xx,yy,c,skip);break;
					 #endif
					 #ifdef _lib24f_
					 case L24f:d24(lib24f,string,xx,yy,c,skip);break;
					 #endif
					 #ifdef _lib24h_
					 case L24h:d24(lib24h,string,xx,yy,c,skip);break;
					 #endif
					 #ifdef _lib24k_
					 case L24k:d24(lib24k,string,xx,yy,c,skip);break;
					 #endif
					 default:;}break;
					 #ifdef _lib40_
					 case 40:d40(lib40,string,xx,yy,c,skip);break;
					 #endif
					 #ifdef _lib48_
					 case 48:d48(lib48,string,xx,yy,c,skip);break;
					 #endif
					 default:;}
				     }if (flag) goto cont;
	/*Not delete this info.*/        xx=x;yy=y;tc=c;c=co;flag=1;goto workout;
					 cont:c=tc;return;}
#endif