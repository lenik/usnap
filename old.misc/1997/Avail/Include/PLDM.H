#include"pldm_h.h"
int pld::lookkey(int *k)
{union REGS regs;
 regs.h.ah=1;
 int86(0x16,&regs,&regs);
 *k=regs.x.ax;
 if(regs.x.flags&0x0040) return (0);
 else return(1);
}
char pld::getkey(int *k)
{union REGS regs;
 regs.h.ah=0;
 int86(0x16,&regs,&regs);
 *k=regs.x.ax;
 if(lo(*k)==3) exit(1);
 return regs.h.al;
}
char pld::getkeyc(void)
{char c;int k;
 for(;((c=getkey(&k))==0););
 return c;
}
void pld::beep(void)
{sound(750);delay(200);nosound();}
void pld::gotoxyabs(char x,char y)
{union REGS regs;
 regs.h.ah=2;
 regs.h.bh=0;
 regs.h.dh=y;regs.h.dl=x;
 int86(0x10,&regs,&regs);
}
void pld::setcursor(int ctop,int cbot)
{union REGS regs;
 if(cbot>13)cbot=13;
 if(ctop<0)ctop=0;
 if(ctop==0||cbot==0)
 regs.h.ch=0x20;
 else
 {regs.h.ch=ctop;regs.h.cl=cbot;}
 regs.h.ah=1;int86(0x10,&regs,&regs);
}
void pld::ldsavename()
{window(15,24,61,24);
 textcolor(15);textbackground(7);clrscr();
 setcolor(15);rectangle(106,410,490,435);setcolor(8);rectangle(109,411,489,434);
 gotoxy(1,1);
 cout<<"Save file name:";cin>>savename0;
 setcolor(1);rectangle(108,390,490,405);setfillstyle(1,7);bar(110,392,488,403);
 char msg0[80];moveto(115,394);settextstyle(0,0,0);setcolor(4);sprintf(msg0,"%s",savename0);
 outtext(msg0);ldsavefile0();}

void pld::ldsavefile0()
{window(15,24,61,24);textcolor(4);textbackground(7);clrscr();setcolor(15);rectangle(108,410,490,435);setcolor(8);rectangle(109,411,489,434);gotoxy(2,1);cout<<"Please wait."<<savename0;
 fp=fopen(savename0,"wb");for(xx=123;xx<499;xx++)
			   for(yy=113;yy<358;yy++)
			   {cc=getpixel(xx,yy);
			   if(cc!=0)fprintf(fp,"%d,%d,%d",xx,yy,cc);}
 fclose(fp);
 beep();
}
void pld::ldloadname()
{window(15,24,61,24);
 textcolor(15);textbackground(7);clrscr();setcolor(15);rectangle(106,410,490,435);setcolor(8);rectangle(109,411,489,434);gotoxy(1,1);cout<<"Load file name:";cin>>loadname0;
 setcolor(1);rectangle(108,390,490,405);setfillstyle(1,7);bar(110,392,488,403);
 char msg0[80];
 moveto(115,394);settextstyle(0,0,0);setcolor(4);sprintf(msg0,"%s",loadname0);
 outtext(msg0);
 ldloadfile0();
}
void pld::ldloadfile0()
{window(15,24,61,24);textcolor(4);textbackground(7);clrscr();
setcolor(15);rectangle(108,410,490,435);setcolor(8);rectangle(109,411,489,434);gotoxy(2,1);cout<<"Please wait,Loading:"<<loadname0;
fp=fopen(loadname0,"rb");
for(xx=123;xx<499;xx++)
 for(yy=113;yy<358;yy++)
 {fscanf(fp,"%d,%d,%d",&xx,&yy,&cc);
  putpixel(xx,yy,cc);}
fclose(fp);beep();
}
void pld::ldmenu()
{setfillstyle(1,7);
 bar(509,122,629,439);
 rectangle(508,121,630,440);
 char *ldch1[]={"Help","Save","Load","Line","Move","Color","Mous","Scrn","Osel","Menu","Pset","Cls","Box","Fill","Arc","Exit"};
 char *ldch1_1[]={"F1:","F2:","F3:","F4:","F5:","F6:","F7:","F8:","F9:","F10:","INS","END","PGUP","PGDN","Alt-x","Esc"};
 window(65,8,78,24);textcolor(0);textbackground(7);clrscr();
 for(i=0;i<16;i++)
 {gotoxy(5,1+i);
  printf("%s",ldch1[i]);
 }
 for(i=0;i<16;i++)
 {setcolor(4);settextstyle(2,0,4);outtextxy(512,130+18*i,ldch1_1[i]);setcolor(15);}
 ldbar();
}
void pld::ldhelp()
{setfillstyle(1,7);bar(508,121,630,440);window(65,8,78,24);textcolor(0);textbackground(7);clrscr();gotoxy(1,1);printf("Help...");
 gotoxy(1,2);printf("F1 Help(Havn't create)");
 gotoxy(1,4);printf("Alt-A : Up:)");
 //...

 setcolor(15);
 rectangle(4,53,99,449);
 setfillstyle(1,7);
 bar(5,55,97,446);
 char *ch[]={"0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15"};
 for(i=0;i<16;i++)
 {setfillstyle(1,i);
  bar(8,57+11*2*i+3+i,40,80+11*2*i+3+i);
  settextstyle(2,0,4);
  setcolor(i);
  outtextxy(70,57+11*2*i+3+i,ch[i]);}
 for(i=0;i<16;i++)
 {setcolor(15);
  rectangle(8,57+11*2*i+3+i,40,80+11*2*i+3+i);setcolor(i);
  rectangle(60,57+11*2*i+3+i,90,80+11*2*i+3+i);
 }
 setcolor(0);line(48,56,48,447);
 setcolor(15);line(49,56,49,447);
 setcolor(15);line(49,56,49,447);
 getch();
 getch();
 setfillstyle(1,9);bar(106,116,116,118);}
void pld::ldscreencolor()
{window(15,24,60,24);
 textcolor(15);textbackground(7);clrscr();setcolor(15);rectangle(108,410,490,435);setcolor(8);rectangle(109,411,489,434);
 gotoxy(1,1);cout<<"Screen bkc:";cin>>ldscrcolor;
 gotoxy(15,1);cout<<"Screen type:";cin>>ldscrclass;
 setfillstyle(ldscrclass,ldscrcolor);bar(124,114,497,356);}
void pld::ldscreen()
{int i;setfillstyle(1,7);bar(103,56,634,107);setcolor(15);rectangle(101,54,636,109);
 setfillstyle(1,7);bar(504,112,633,446);setcolor(15);rectangle(502,111,635,448);
 rectangle(508,121,630,440);setcolor(8);rectangle(509,122,629,439);
 char *ldch1[]={"Help","Save","Load","Line","Move","Color","Mous","Scrn","Osel","Menu","Tran","Cls","Box","Fill Box","Tag S","Exit"};
 char *ldch1_1[]={"F1:","F2:","F3:","F4:","F5:","F6:","F7:","F8:","F9:","F10:","Home","END","PGUP","PGDN","Ins","Esc"};
 window(65,8,78,24);textcolor(8);textbackground(7);clrscr();
 for(i=0;i<16;i++)
  {gotoxy(6,1+i);printf("%s\n",ldch1[i]);}
 for(i=0;i<16;i++)
  {setcolor(4);settextstyle(2,0,4);outtextxy(512,130+18*i,ldch1_1[i]);}
 setfillstyle(1,7);
 bar(102,384,498,445);setcolor(15);
 rectangle(100,382,500,447);setfillstyle(1,7);bar(101,111,120,359);bar(101,360,499,378);
 setcolor(15);rectangle(101,111,120,359);rectangle(101,360,500,378);setcolor(8);
 rectangle(102,112,119,358);rectangle(102,361,499,377);
 setfillstyle(1,9);bar(106,116,116,118);
}
void pld::ldbar()
{setfillstyle(1,0);bar(1,1,97,450);}
void pld::ldfang()
{for(i=0;i<30;i++)
 {setcolor(3);setfillstyle(1,3);bar3d(120+i,i,130+11*i,15*i-15,3,1);delay(10);
  setcolor(10);setfillstyle(1,0);bar3d(120+i,i,130+11*i,15*i-15,3,1);}
 setfillstyle(1,8);
 bar(160,40,460,435);
 setfillstyle(1,3);
 setcolor(12);
 settextstyle(1,0,4);
 setcolor(3);
 bar3d(150,30,450,420,3,1);bar3d(150,420,450,420,3,1);setfillstyle(1,8);
 bar(283,213,313,243);setfillstyle(1,13);bar(280,210,310,240);
 setfillstyle(1,7);bar(285,215,305,235);setfillstyle(1,14);bar(290,220,300,230);
 setfillstyle(1,8);bar(293,223,297,227);
 setcolor(0);settextstyle(1,0,1);outtextxy(160,34,"...");
 settextstyle(2,0,5);setcolor(8);outtextxy(263,263,"1995-05-20");
 settextstyle(2,0,5);setcolor(15);outtextxy(260,260,"1995-05-20");
 window(22,5,55,6);textcolor(14);textbackground(11);clrscr();gotoxy(1,1);printf(" ");
 gotoxy(1,1);printf("Graph base make method.");
 setcolor(8);line(154,35,446,35);line(446,35,446,416);line(154,416,446,416);
 window(22,20,55,20);textcolor(8);textbackground(1);clrscr();gotoxy(1,1);printf(" ");
 gotoxy(1,1);printf("JiangSu province 87092 part  Zhao Zhongqiang");
 settextstyle(0,0,1);setcolor(0);outtextxy(298,226,"PLDM");
 settextstyle(0,0,1);setcolor(15);outtextxy(297,225,"PLDM");
 delay(2000);clearviewport();
}
void pld::ldprintscreengraph()
{ldprintwait();
 for(xx=123;xx<499;xx++)
  for(yy=113;yy<358;yy++)
  {cc=getpixel(xx,yy);
   if(cc!=0)fprintf(stdprn,"%d%d%d",xx,yy,cc);}beep();}
void pld::ldprintwait()
{window(15,24,60,24);
 textcolor(15);textbackground(7);clrscr();setcolor(15);rectangle(108,410,490,435);setcolor(8);rectangle(109,411,489,434);
 gotoxy(1,1);cout<<"Printint...";
}
void pld::ldico()
{window(8,2,73,2);
 textcolor(11);
 textbackground(7);
 clrscr();
 setfillstyle(1,7);
 bar(53,8,584,49);
 setcolor(8);settextstyle(2,0,9);outtextxy(54,11,"PLDM 87092 pla-TXS-01");
 gotoxy(50,1);
 printf("PLD draw system");
 setcolor(15);
 rectangle(101,54,636,109);
 setcolor(15);
 rectangle(106,70,630,90);
 char s[MAXPATH];char drive[MAXDRIVE];char dir[MAXDIR];
 getcwd(s,MAXPATH);
 strcat(s,"\\");puts(s);}
void pld::lddir()
{setcolor(15);rectangle(101,54,636,109);setcolor(15);rectangle(106,70,630,90);setcolor(8);rectangle(107,71,629,89);char s[MAXPATH],drive[MAXDRIVE],dir[MAXDIR];getcwd(s,MAXPATH);strcat(s,"\\");puts(s);}
void pld::lddirclear()
{setfillstyle(1,7);
 bar(103,56,634,107);
 setcolor(15);
 rectangle(101,54,636,109);
}
void pld::fangkuang()
{setcolor(15);rectangle(21,51,639,459);
 setcolor(7);rectangle(23,53,637,457);setfillstyle(1,8);bar(25,55,635,455);}
void pld::ldcircle()
{setfillstyle(1,7);bar(107,410,490,435);setfillstyle(1,7);bar(107,410,490,435);
 window(15,24,60,24);textcolor(15);textbackground(7);clrscr();setcolor(15);rectangle(108,410,490,435);setcolor(8);rectangle(109,411,489,434);
 gotoxy(1,1);cout<<"Color:";cin>>ldcirclecolor;
 gotoxy(10,1);cout<<"FillType:";cin>>ldcircleclass;
 setfillstyle(ldcircleclass,ldcirclecolor);setcolor(ldcirclecolor);
}
void pld::ldchar()
{setfillstyle(1,7);bar(107,410,490,435);window(15,24,60,24);textcolor(15);textbackground(7);clrscr();setcolor(15);
 rectangle(108,410,490,435);setcolor(8);rectangle(109,411,489,434);gotoxy(1,1);cout<<"Square:";cin>>ldcharlarge;
 gotoxy(10,1);cout<<"Color:";cin>>ldcharcolor;gotoxy(20,1);cout<<"Type:";cin>>ldcharclass;settextstyle(ldcharclass,0,ldcharlarge);
}
void pld::ldbarrectangle()
{setfillstyle(1,7);bar(107,410,490,435);window(15,24,60,24);textcolor(15);textbackground(7);clrscr();setcolor(15);rectangle(108,410,490,435);
 setcolor(8);rectangle(109,411,489,434);gotoxy(1,1);cout<<"Color:";cin>>ldbarcolor;
 gotoxy(20,1);cout<<"Type:";cin>>ldbarf;setlinestyle(0,ldbarf,1);setcolor(ldbarcolor);setfillstyle(ldbarclass,ldbarcolor);}
void pld::ldscreentime()
{window(60,5,78,5);textcolor(0);textbackground(7);clrscr();_dos_getdate(&d);
 gotoxy(0,1);printf("%d\n",d.year);gotoxy(7,1);printf("%d\n",d.day);gotoxy(4,1);printf("%d\n",d.month);
 gettime(&t);
 gotoxy(12,1);printf("%2d\n",t.ti_hour);gotoxy(14,1);printf("%2d\n",t.ti_min);gotoxy(17,1);printf("%2d\n",t.ti_hund);}
void pld::ldsubmenu()
{setfillstyle(1,7);
 bar(107,410,490,435);
 char *ldch1[]={"Fcircle","Dcircle","Fellip","Dellip","WriteE","WriteC","Print"};
 char *ldch1_1[]={"Alt","Alt","Alt","Alt","Alt","Alt","Alt","Alt"};
 char *ldch1_2[]={"1","2","3","4","5","6","7","8"};
 window(15,24,60,24);textcolor(15);textbackground(7);clrscr();
 setfillstyle(1,7);bar(102,384,498,445);setcolor(15);rectangle(100,382,500,447);setcolor(15);rectangle(108,410,490,435);setcolor(8);rectangle(109,411,489,434);
 for(i=0;i<8;i++)
 {gotoxy(2+6*i,1);printf("%s\n",ldch1[i]);}
 for(i=0;i<8;i++)
 {setcolor(4);settextstyle(2,0,3);outtextxy(109+48*i,412,ldch1_1[i]);}
 for(i=0;i<8;i++)
 {setcolor(4);settextstyle(2,0,3);outtextxy(109+48*i,420,ldch1_2[i]);}
}
void pld::ldnewfile()
{setcolor(8);rectangle(108,390,490,405);setfillstyle(1,7);bar(110,392,488,403);settextstyle(0,0,0);
 setcolor(1);outtextxy(112,394,"Newfile:");setcolor(8);rectangle(108,390,490,405);setfillstyle(1,7);bar(110,392,488,402);char msg0[80];
 moveto(112,394);settextstyle(0,0,0);setcolor(1);sprintf(msg0,"Newfile:");outtext(msg0);}
void pld::ldf1()
{setfillstyle(1,7);bar(508,121,630,440);window(65,8,78,24);textcolor(0);textbackground(7);clrscr();
 gotoxy(1,1);printf("F1:");rectangle(508,121,630,440);}
void pld::ldf2()
{setfillstyle(1,7);bar(508,121,630,440);window(65,8,78,24);textcolor(0);textbackground(7);clrscr();
 gotoxy(1,1);printf("F2:");rectangle(508,121,630,440);gotoxy(1,7);printf("Save...");gotoxy(1,4);printf("Random.");rectangle(508,121,630,440);}
void pld::ldf3()
{setfillstyle(1,7);bar(508,121,630,440);window(65,8,78,24);textcolor(0);textbackground(7);clrscr();
 gotoxy(1,1);printf("Load...");rectangle(508,121,630,440);}
void pld::ldf4()
{setfillstyle(1,7);bar(508,121,630,440);window(65,8,78,24);textcolor(0);textbackground(7);clrscr();
 gotoxy(1,1);printf("Draw line");gotoxy(1,2);printf("Use insert");gotoxy(1,3);printf("To make start");gotoxy(1,4);printf("Use TIUIanswer item");rectangle(508,121,630,440);}
void pld::ldf5()
{setfillstyle(1,7);bar(508,121,630,440);window(65,8,78,24);textcolor(0);textbackground(7);clrscr();
 gotoxy(1,1);printf("Move cursor:");gotoxy(1,2);printf("Move cursor to ");gotoxy(1,3);printf("certain place.");rectangle(508,121,630,440);}
void pld::ldf6()
{setfillstyle(1,7);bar(508,121,630,440);window(65,8,78,24);textcolor(0);textbackground(7);clrscr();
 gotoxy(1,1);printf("Change cursor color");rectangle(508,121,630,440);}
void pld::ldf7()
{setfillstyle(1,7);bar(508,121,630,440);window(65,8,78,24);textcolor(0);textbackground(7);clrscr();
 gotoxy(1,1);printf("Install mouse.");rectangle(508,121,630,440);}
void pld::ldf8()
{setfillstyle(1,7);bar(508,121,630,440);window(65,8,78,24);textcolor(0);textbackground(7);clrscr();
 gotoxy(1,1);printf("Change color");rectangle(508,121,630,440);}
void pld::ldf9()
{setfillstyle(1,7);bar(508,121,630,440);window(65,8,78,24);textcolor(0);textbackground(7);clrscr();
 gotoxy(1,1);printf("Run DOS Command");rectangle(508,121,630,440);}
void pld::ldf10()
{setfillstyle(1,7);bar(508,121,630,440);window(65,8,78,24);textcolor(0);textbackground(7);clrscr();
 gotoxy(1,1);printf("Menu");rectangle(508,121,630,440);}
void pld::lda_a()
{setfillstyle(1,7);bar(508,121,630,440);window(65,8,78,24);textcolor(0);textbackground(7);clrscr();
 gotoxy(1,1);printf("Alt_A Up");rectangle(508,121,630,440);}
void pld::lda_b()
{setfillstyle(1,7);bar(508,121,630,440);window(65,8,78,24);textcolor(0);textbackground(7);clrscr();
 gotoxy(1,1);printf("Alt_B Down");rectangle(508,121,630,440);}
void pld::lda_c_c()
{setfillstyle(1,7);bar(508,121,630,440);window(65,8,78,24);textcolor(0);textbackground(7);clrscr();
 gotoxy(1,1);printf("Alt_C Left");rectangle(508,121,630,440);}
void pld::lda_d()
{setfillstyle(1,7);bar(508,121,630,440);window(65,8,78,24);textcolor(0);textbackground(7);clrscr();
 gotoxy(1,1);printf("Alt_D Right");rectangle(508,121,630,440);}
void pld::lda_1()
{setfillstyle(1,7);bar(508,121,630,440);window(65,8,78,24);textcolor(0);textbackground(7);clrscr();
 gotoxy(1,1);printf("Draw FCircle");rectangle(508,121,630,440);}
void pld::lda_2()
{setfillstyle(1,7);bar(508,121,630,440);window(65,8,78,24);textcolor(0);textbackground(7);clrscr();
 gotoxy(1,1);printf("1 2");rectangle(508,121,630,440);}
void pld::lda_3()
{setfillstyle(1,7);bar(508,121,630,440);window(65,8,78,24);textcolor(0);textbackground(7);clrscr();
 gotoxy(1,1);printf("1 3");rectangle(508,121,630,440);}
void pld::lda_4()
{setfillstyle(1,7);bar(508,121,630,440);window(65,8,78,24);textcolor(0);textbackground(7);clrscr();
 gotoxy(1,1);printf("1 4");rectangle(508,121,630,440);}
void pld::lda_5()
{setfillstyle(1,7);bar(508,121,630,440);window(65,8,78,24);textcolor(0);textbackground(7);clrscr();
 gotoxy(1,1);printf("1 5");rectangle(508,121,630,440);}
void pld::lda_6()
{setfillstyle(1,7);bar(508,121,630,440);window(65,8,78,24);textcolor(0);textbackground(7);clrscr();
 gotoxy(1,1);printf("1 6");rectangle(508,121,630,440);}
void pld::lda_7()
{setfillstyle(1,7);bar(508,121,630,440);window(65,8,78,24);textcolor(0);textbackground(7);clrscr();
 gotoxy(1,1);printf("1 7");rectangle(508,121,630,440);}
void pld::lda_8()
{setfillstyle(1,7);bar(508,121,630,440);window(65,8,78,24);textcolor(0);textbackground(7);clrscr();
 gotoxy(1,1);printf("1 8");rectangle(508,121,630,440);}
void pld::lda_9()
{setfillstyle(1,7);bar(508,121,630,440);window(65,8,78,24);textcolor(0);textbackground(7);clrscr();
 gotoxy(1,1);printf("1 9");rectangle(508,121,630,440);}
void pld::ldpgup()
{setfillstyle(1,7);bar(508,121,630,440);window(65,8,78,24);textcolor(0);textbackground(7);clrscr();
 gotoxy(1,1);printf("p u");rectangle(508,121,630,440);}
void pld::ldpgdn()
{setfillstyle(1,7);bar(508,121,630,440);window(65,8,78,24);textcolor(0);textbackground(7);clrscr();
 gotoxy(1,1);printf("p d");rectangle(508,121,630,440);}
void pld::ldhome()
{setfillstyle(1,7);bar(508,121,630,440);window(65,8,78,24);textcolor(0);textbackground(7);clrscr();
 gotoxy(1,1);printf("hom");rectangle(508,121,630,440);}
void pld::ldspace()
{setfillstyle(1,7);bar(508,121,630,440);window(65,8,78,24);textcolor(0);textbackground(7);clrscr();
 gotoxy(1,1);printf("kong");rectangle(508,121,630,440);}
void pld::ldins()
{setfillstyle(1,7);bar(508,121,630,440);window(65,8,78,24);textcolor(0);textbackground(7);clrscr();
 gotoxy(1,1);printf("ins");rectangle(508,121,630,440);}
void pld::ldc_q()
{setfillstyle(1,7);bar(508,121,630,440);window(65,8,78,24);textcolor(0);textbackground(7);clrscr();
 gotoxy(1,1);printf("printf");rectangle(508,121,630,440);}
void pld::ldend()
{setfillstyle(1,7);bar(508,121,630,440);window(65,8,78,24);textcolor(0);textbackground(7);clrscr();
 gotoxy(1,1);printf("clear");rectangle(508,121,630,440);}
void pld::ldc_end()
{}
