
#if (1)
#	define _USEYAOBAI
#endif

#ifdef __cplusplus
#	define BGIPATH		"..\\bgi"
#else
#	define BGIPATH		"bgi"
#endif

#include <string.h>
#include <bios.h>
#include <dos.h>
#include <math.h>
#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415927

#ifdef __cplusplus
#	define PARAM	...
#else
#	define PARAM	void
#endif

char buf[100];
double hou,min,sec;
static int rhou=0,rmin=0,rsec=0;
struct time t2;

void  ring(void);
void  SetDate(void);
void  SetTime(void);
void  menu(void);
void  GetDate(void);
void  time1(void);
void  drawline(int j, int x4, int y4);

typedef void interrupt (*INTFUNC)(PARAM);
void interrupt yaobai(PARAM);
static INTFUNC	old1C = NULL;
void init1C(void);
void uninit1C(void);

void sdelay(double stime) {
	double	t;
	struct time wt;
	gettime(&wt);
	t	= wt.ti_sec * 100 + wt.ti_hund;
	for (;;) {
		gettime(&wt);
		if (abs(wt.ti_sec * 100 + wt.ti_hund - t) > stime / 10) {
			break;
		}
	}
}

void Pclock(void)
{
	int  j, x3, y3, x4, y4;

	settextstyle(0,0,1);
	setcolor(7);
	outtextxy(1,1,"-------------CLOCK PATTERN-------------");
	outtextxy(450,10, "M---Back main menu");
	outtextxy(450,40, "E---Exit program");

	setfillstyle(1,0);
	setcolor(5);

	arc(300,200,0,360,150);
	arc(300,200,0,360,190);


	/* set font form */
	settextstyle(TRIPLEX_FONT, HORIZ_DIR,5);

	/* draw line */
	j=60;x4=150;y4=145;
	drawline(j,x4,y4);
	setcolor(1);
	setlinestyle(0,3,3);
	j=12;x3=150;y3=140;
	drawline(j,x3,y3);

	/* darw nubmics */
	setcolor(1);
	outtextxy(105,176," 9");
	outtextxy(455,175,"3");
	outtextxy(280,8,"12");
	outtextxy(292,350,"6");

	time1();
	switch(getch()) {
	case 'm':
		cleardevice();
		menu();
		break;
	case 'e':
		exit(1);
	}
}

void GetDate(void)
{
	  char buf3[100];
	  int year, day, mon;
	  struct date d1;
	  getdate(&d1);
	  year=d1.da_year;
	  day=d1.da_day;
	  mon=d1.da_mon;
	  sprintf(buf3,"%d-%d-%d\n",year,mon,day);
	  settextstyle(SMALL_FONT,HORIZ_DIR,8);
	  setcolor(GREEN);
	  outtextxy(240,140,buf3);
}

/*void alarm()
{ */
/*
	int  j, k, x4, y4;
	char buf4[100];
	gettime(&t2);
	hou=t2.ti_hour;

	cleardevice();
	setcolor(7);    Pclock();   */
/*	arc(300,200,0,360,150);
	arc(300,200,0,360,190);*/

	/* set font form
	settextstyle(TRIPLEX_FONT, HORIZ_DIR,5);*/

	/* draw line
	j=60;x4=150;y4=145;drawline(j,x4,y4);
	setcolor(1);
	setlinestyle(0,3,3);
	j=12;x4=150;y4=140;drawline(j,x4,y4);*/


	/* darw numbers */
/*	setcolor(1);
	outtextxy(105,176," 9");
	outtextxy(455,175,"3");
	outtextxy(280,8,"12");
	outtextxy(292,350,"6");*/
/*}*/

void  drawline(int j,int x4,int y4)
{  	float t;
	int x3,y3,x5,y5,i;
	t = 6.28318/j;
	for(i=0;i<=60;i++){
	x3 = 300+x4*cos(i*t);
	y3 = 200+x4*sin(i*t);
	x5 = 300+y4*cos(i*t);
	y5 = 200+y4*sin(i*t);
	line(x3,y3,x5,y5);}
}



void time1(void)
  {  char buf4[100];
  int x = 300, y = 200;
     int i=0,j=0;
     double x1, y1, x2, y2, x3, y3;

/*	struct time *t0,t1;*/
     x1=x ;x2=x;x3=x;y1=y;y2=y;y3=y;
     while(!bioskey(1))
     {
	 if(i==360){
	       setfillstyle(0,0);
	       bar(50,400,800,500);i=0;}i++;
	 settextstyle(0,0,1);setcolor(GREEN);
	 outtextxy(230,300,"made by zhao zi fei");
	 setlinestyle(0,1,2);
	 /* clear  old pointer */
		sdelay(116.6);
		setcolor(0);
		setbkcolor(0);
		setcolor(0);
		line(x,y,x1,y1);
		line(x,y,x2,y2);
		line(x,y,x3,y3);

	 /* get system present time */
		gettime(&t2);
		sec=t2.ti_sec;
		min=t2.ti_min + sec  / 60.0;    /* jiu zeng wu ca */
		hou=t2.ti_hour + min /60.0;

	 /* ring clock */
		if (rhou!=0 ){
		   if(rhou==(int)hou && rmin==(int)min && rsec==(int)sec){
		      sprintf(buf,"%d:%d:%d",rhou,rmin,rsec);
		      sprintf(buf4,"%2d:%2d:%2d",rhou,rmin,rsec);

		      setcolor(WHITE);
		      settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
		      outtextxy(1,1, "Current BeiJing time:");
		      outtextxy(450,400,buf4);
		      outtextxy(10,400,buf);
		      sound(500);
		      rhou=0;rmin=0;rsec=0;}
		   }


	 /* comput second pointer */
		x1 = cos(sec*6/57.2957-PI/2)*130+x;
		y1 = sin(sec*6/57.2957-PI/2)*130+y;
		setlinestyle(0,1,1);
		setcolor(4);line(x,y,x1,y1);
		setcolor(7);arc(300,200,0,360,2);

	 /* comput minute pointer */
		x2 = cos(min/30.0*PI-PI/2)*90+x;
		y2 = sin(min/30.0*PI-PI/2)*90+y;
		setlinestyle(0,3,3);
		setcolor(5);line(x,y,x2,y2);

	 /* comput hour pointer */
		x3 = cos(hou/6.0*PI-PI/2)*70+x;
		y3 = sin(hou/6.0*PI-PI/2)*70+y;
		setlinestyle(0,5,5);
		setcolor(6);line(x,y,x3,y3);

	 /* alarm clock */

		if(  (int)min==0 && (int)sec==0){
		      sprintf(buf4, "%02d:00" ,(int)hou);
		      settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		      outtextxy(10,20, "Current BeiJing time:");
		      outtextxy(450,400,buf4);sound(500);

		      if (hou<=12){
				outtextxy(570,400,"AM");}
		      else     {outtextxy(570,400,"PM");}
		  }

	  /* send sound program */
		{    static int seclast;
			if ( sec != seclast) {
				sound(100);sdelay(50);
				sound(50); sdelay(50);
				nosound();
				seclast = sec;
			 }
		 }

		GetDate();
     }  	/* while's } */
}

void ring(void)
{  char t[100],*p;
   static int ti[3],tin=0;

   system(" cls");
   printf("Input what time to ring");
   scanf("%s",t);
   p=t;
   for(;(p-t)<strlen(t) && tin<3;p++){
      switch(*p){
	 case ' ':
		    continue;
	 case ':':
		    tin++;continue;
	 case '\0':
		    tin++;continue;
	 case '\n':
		    tin++;continue;
	 }
	 ti[tin]=ti[tin]*10+(*p-'0');
     }
    rhou=ti[0]; rmin=ti[1]; rsec=ti[2];
   printf("%d:%d:%d",rhou,rmin,rsec);
   outtextxy(200,200," Goto colck picture(y/n)?");
   switch(getch()) {
	    case 'y':
		     system("cls");Pclock();break;
	    case 'n':
	    default:
		     system("cls");menu();break;
   }
}

void Dclock(void)
{
	 char buf2[100];
	 outtextxy(50,400,"---------------DATE CLOCK---------------");
	 settextstyle(2,0,6);
	 outtextxy(220,370,"Press 'm' back  main menu");
	 outtextxy(220,340,"Press 'q' exit  program");
          outtextxy(220,310,"Press 'c' display clock pattern");
	 do{
	 gettime(&t2);
	 hou=t2.ti_hour;
	 min=t2.ti_min;
	 sec=t2.ti_sec;

	 sprintf(buf2, "%02d:%02d:%02d",(int)hou,(int)min,(int)sec);
	 settextstyle(0,HORIZ_DIR,3);
	 outtextxy(220,100,buf2);
	 setcolor(4);
	 setbkcolor(0);setcolor(4);
	 sdelay(116);
	 bar(210,90,415,130);
			    }while(!bioskey(1) );

	 switch(getch()){
	     case 'm':
		      system("cls");menu();break;
	     case 'c':
		      system("cls");Pclock();break;
	     case 'q':
			exit(1);
		    }

}

void menu(void)
 {
   setcolor(WHITE);
   settextstyle(1,0,2);
   outtextxy(1,1,"  ------------------The Main Menu--------------------");
   outtextxy(1,70, "           C--------------------CLOCK PARTTEN");
   outtextxy(1,100,"           D--------------------DATA CLOCK");
   outtextxy(1,130,"           S--------------------SET TIME");
   outtextxy(1,160,"           Y--------------------SET DATE");
   outtextxy(1,190,"           R--------------------RING");
   switch(getch())
   {
      case 'c':
		cleardevice();
#ifdef _USEYAOBAI
		init1C();
#endif
		Pclock();
#ifdef _USEYAOBAI
		uninit1C();
#endif
		break;
      case 'd':
		cleardevice();
		Dclock();
		break;
      case 's':
		cleardevice();
		SetTime();
		break;
      case 'y':
		cleardevice();
		SetDate();
		break;
      case 'r':
		system("cls");
		ring();
		break;
      case 'q':
		exit(-1);
   }
}
void SetDate(void)
{
   system("date");
   outtextxy(200,250,"Enter clock partten?(Y/N)");
   switch(getch()){
	   case 'y':
				cleardevice();Pclock();break;
	   case 'n':
				cleardevice();menu();break;
	   default :
				cleardevice();menu();break;
			   }


}

void SetTime(void)
{        system("time");
/*
	char t[100],*p;
	int ti[3],tin=0;
	printf("please input you want set time:");
	scanf("s%",t);
	p=t;
	for(;(p-t)<strlen(t)&&tin<3;p++){
		switch(*p){
		case ' ':
			continue;
		case ':':
			tin++;
			break;
		case '\0':
			tin++;
			break;
		case '\n':
			tin++;
			break;
		}
		if( *p >= '0' && *p <= '9') {
			ti[tin] = ti[tin] * 10 + (*p - '0');
		}
	}

	t2.ti_hour = (char)ti[0];
	t2.ti_min  = (char)ti[1];
	t2.ti_sec  = (char)ti[2];
	settime(&t2) ;
	printf("%c:%c:%c",t2.ti_hour,t2.ti_min,t2.ti_sec);*/
	outtextxy(200,250,"Enter clock partten?(Y/N)");

	switch(getch()){
	   case 'y':
				cleardevice();Pclock();break;
	   case 'n':
				cleardevice();menu();break;
	   default :
				cleardevice();menu();break;
			   }
	cleardevice();

}

void init1C(void) {
	disable();
	old1C	= getvect(0x1C);
	setvect(0x1C, yaobai);
	enable();
}

void uninit1C(void) {
	disable();
	if (old1C != NULL) {
		setvect(0x1C, old1C);
	}
	enable();
}

void main(void)
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm, BGIPATH);

	menu();

	getch();
	closegraph();
}

#define L	70

void interrupt yaobai(PARAM) {
	static int		h;
	static double		lastal;
	static double		stepal;
	static double		sa;
	static struct time 	t;
	static double		dx, dy;
	static double		rot2;
	static int 		oldcolor;

	gettime(&t);
	h	= t.ti_hund;

	if (h < 50) {
		sa	= PI * 5 / 3.0;
		stepal	= -PI / 150.0;
	} else {
		sa	= PI * 4 / 3.0;
		stepal	= PI / 150.0;
	}
	rot2	= (double)(h % 50) / 50.0;
	rot2	= pow(rot2, 2.5);
	rot2	= rot2 * 50;
	sa	+= stepal * rot2;

	oldcolor= getcolor();
	setcolor(BLACK);
	dx	= L * cos(lastal);
	dy	= -L * sin(lastal);
	line(300, 390, 300 + dx, 390 + dy);
	circle(300 + dx, 392 + dy, 5);

	setcolor(BROWN);
	dx	= L * cos(sa);
	dy	= -L * sin(sa);
	line(300, 390, 300 + dx, 390 + dy);
	circle(300 + dx, 392 + dy, 5);

	lastal	= sa;

	setcolor(oldcolor);

	if (old1C != NULL) {
		(*old1C)();
	}
}
