
// Article Test King 	Ver 1.00  // By DanSei  46K MEM
//1996

#include<stdio.h>
#include<io.h>
#include<fcntl.h>
#include<conio.h>
#include<stdlib.h>
#include<TDVideoA.cpp>
#include"TKFont.Dat"

int  far InfoHeight=7;

void CLVersion(int k);

struct CResult {
	/* engChr, engSym, chnChr, chnSym */
	unsigned rec, res, rcc, rcs; /* right */
	unsigned wec, wes, wcc, wcs; /* wrong */
	unsigned eec, ees, ecc, ecs; /* extra */
	unsigned lec, les, lcc, lcs; /* lost  */
};

struct CInfo {
	/* engChr, engSym, chnChr, chnSym, space, other */
	unsigned nec, nes, ncc, ncs, nsp, not;
};

int main(int argc,char**argv)
{unsigned char trans[10],t;
 int fin,fsrc;
 unsigned long fp;

 if ((argc<=1)||(argc>=4)) {CLVersion(0);return 2;}

 if (argc==3) if( (fsrc=open(argv[2],O_BINARY|O_RDONLY))==-1 )  {perror("Error in source file ");return 4;} else goto n;
 if ( (fsrc=open("TKSource.TXT",O_BINARY|O_RDONLY))==-1 ) {printf("You haven't type the Source filename and also no \x22TKSource.TXT\x22 file.\n"); return 5;}
n:
 if ( (fin =open(argv[1],O_BINARY|O_RDONLY))==-1 ) {perror("Error in test file ");return 10;}

 textattr(159);cprintf("W a i t i n g . . .");
 //fsrc
 for (fp=0L;fp<=filelength(fsrc);fp++)
  {if ( (read(fsrc, trans, 1)) == -1) {printf("Read Failed.\n"); exit(1); }
   t=trans[0];
   if (t<=31)		   {OTHER1[o1++]=t;continue;}
   if (t==32) 		   {space1++;continue;}
   if ((t>=33) && (t<=47)) {ES1[es1++]=t;continue;}
   if ((t>=58) && (t<=64)) {ES1[es1++]=t;continue;}
   if ((t>=91) && (t<=96)) {ES1[es1++]=t;continue;}
   if ((t>=123)&& (t<=126)){ES1[es1++]=t;continue;}
   if ((t>=48) && (t<=57)) {EE1[ee1++]=t;continue;}
   if ((t>=65) && (t<=90)) {EE1[ee1++]=t;continue;}
   if ((t>=97) && (t<=122)){EE1[ee1++]=t;continue;}
   if ((t>=128)&& (t<=254))
    if (isc)
      {if (((isc-160)>=0) &&((isc-160)<=15)) {CS1[cs1++]=isc*0x100+t;}
       if ((isc-160)>=16)		     {CC1[cc1++]=isc*0x100+t;}
       if ((isc<160)||(t<160)){OTHER1[o1++]=isc;OTHER1[o1++]=t;}
       isc=0;continue;}
    else {isc=t;continue;}
  }
 //fin
 isc=0;
 for (fp=0L;fp<=filelength(fin);fp++)
  {if ( (read(fin, trans, 1)) == -1) {printf("Read Failed.\n"); exit(1); }
   t=trans[0];
   if (t<=31)		   {OTHER2[o2++]=t;continue;}
   if (t==32) 		   {space2++;continue;}
   if ((t>=33) && (t<=47)) {ES2[es2++]=t;continue;}
   if ((t>=58) && (t<=64)) {ES2[es2++]=t;continue;}
   if ((t>=91) && (t<=96)) {ES2[es2++]=t;continue;}
   if ((t>=123)&& (t<=126)){ES2[es2++]=t;continue;}
   if ((t>=48) && (t<=57)) {EE2[ee2++]=t;continue;}
   if ((t>=65) && (t<=90)) {EE2[ee2++]=t;continue;}
   if ((t>=97) && (t<=122)){EE2[ee2++]=t;continue;}
   if ((t>=128)&& (t<=254))
    if (isc)
      {if (((isc-160)>=0) &&((isc-160)<=15)) {CS2[cs2++]=isc*0x100+t;}
       if ((isc-160)>=16)		     {CC2[cc2++]=isc*0x100+t;}
       if ((isc<160)||(t<160)){OTHER2[o2++]=isc;OTHER2[o2++]=t;}
       isc=0;continue;}
    else {isc=t;continue;}
  }
 close(fsrc);
 close(fin);
 // Calculation of Text Inputing.
 // English S

 p1=p2=p3=p4=0;
 for (p4=0;p4<es1;p4++)
   if (ES2[p2+p4]==ES1[p1+p4]) es3[0]++;
   else
    { if      (ES2[p2+p4]==ES1[p1+p4+1]) {es3[3]++;p2--;}
      else if (ES2[p2+p4]==ES1[p1+p4-1]) {es3[2]++;p2++;}
      else if (ES2[p2+p4]==ES1[p1+p4+2]) {es3[3]+=2;p2-=2;}
      else if (ES2[p2+p4]==ES1[p1+p4-2]) {es3[2]+=2;p2+=2;}
      else if (ES2[p2+p4]==ES1[p1+p4+3]) {es3[3]+=3;p2-=3;}
      else if (ES2[p2+p4]==ES1[p1+p4-3]) {es3[2]+=3;p2+=3;}
      else es3[1]++;
    }

 // English Char
 p1=p2=p3=p4=0;
 for (p4=0;p4<ee1;p4++)
   if (EE2[p2+p4]==EE1[p1+p4]) ee3[0]++;
   else
    { if      (EE2[p2+p4]==EE1[p1+p4+1]) {ee3[3]++;p2--;}
      else if (EE2[p2+p4]==EE1[p1+p4-1]) {ee3[2]++;p2++;}
      else if (EE2[p2+p4]==EE1[p1+p4+2]) {ee3[3]+=2;p2-=2;}
      else if (EE2[p2+p4]==EE1[p1+p4-2]) {ee3[2]+=2;p2+=2;}
      else if (EE2[p2+p4]==EE1[p1+p4+3]) {ee3[3]+=3;p2-=3;}
      else if (EE2[p2+p4]==EE1[p1+p4-3]) {ee3[2]+=3;p2+=3;}
      else ee3[1]++;
    }

 // Chinese S
 p1=p2=p3=p4=0;
 for (p4=0;p4<cs1;p4++)
   if (CS2[p2+p4]==CS1[p1+p4]) cs3[0]++;
   else
    { if      (CS2[p2+p4]==CS1[p1+p4+1]) {cs3[3]++;p2--;}
      else if (CS2[p2+p4]==CS1[p1+p4-1]) {cs3[2]++;p2++;}
      else if (CS2[p2+p4]==CS1[p1+p4+2]) {cs3[3]+=2;p2-=2;}
      else if (CS2[p2+p4]==CS1[p1+p4-2]) {cs3[2]+=2;p2+=2;}
      else if (CS2[p2+p4]==CS1[p1+p4+3]) {cs3[3]+=3;p2-=3;}
      else if (CS2[p2+p4]==CS1[p1+p4-3]) {cs3[2]+=3;p2+=3;}
      else cs3[1]++;
    }

 // Chinese Char
 p1=p2=p3=p4=0;
 for (p4=0;p4<cc1;p4++)
   if (CC2[p2+p4]==CC1[p1+p4]) cc3[0]++;
   else
    { if      (CC2[p2+p4]==CC1[p1+p4+1]) {cc3[3]++;p2--;}
      else if (CC2[p2+p4]==CC1[p1+p4-1]) {cc3[2]++;p2++;}
      else if (CC2[p2+p4]==CC1[p1+p4+2]) {cc3[3]+=2;p2-=2;}
      else if (CC2[p2+p4]==CC1[p1+p4-2]) {cc3[2]+=2;p2+=2;}
      else if (CC2[p2+p4]==CC1[p1+p4+3]) {cc3[3]+=3;p2-=3;}
      else if (CC2[p2+p4]==CC1[p1+p4-3]) {cc3[2]+=3;p2+=3;}
      else cc3[1]++;
    }

 // Space
 if (space2>=space1) {space3[0]=space1;space3[2]=space2-space1;}
 else 		     {space3[0]=space2;space3[3]=space1-space2;}

 // Other
 p1=p2=p3=p4=0;
 for (p4=0;p4<o1;p4++)
   if (OTHER2[p2+p4]==OTHER1[p1+p4]) o3[0]++;
   else
    { if      (OTHER2[p2+p4]==OTHER1[p1+p4+1]) {o3[3]++;p2--;}
      else if (OTHER2[p2+p4]==OTHER1[p1+p4-1]) {o3[2]++;p2++;}
      else if (OTHER2[p2+p4]==OTHER1[p1+p4+2]) {o3[3]+=2;p2-=2;}
      else if (OTHER2[p2+p4]==OTHER1[p1+p4-2]) {o3[2]+=2;p2+=2;}
      else if (OTHER2[p2+p4]==OTHER1[p1+p4+3]) {o3[3]+=3;p2-=3;}
      else if (OTHER2[p2+p4]==OTHER1[p1+p4-3]) {o3[2]+=3;p2+=3;}
      else o3[1]++;
    }

ss=(float)(es3[0]+ee3[0]+cs3[0]*2+cc3[0]*2)/(es1+ee1+cs1*2+cc1*2)*100
  -(float)(es3[1]+ee3[1]+cs3[1]*2+cc3[1]*2+es3[2]+ee3[2]+cs3[2]*2+cc3[2]*2+es3[3]+ee3[3]+cs3[3]*2+cc3[3]*2)
	 /(es1+ee1+cs1*2+cc1*2)*500;
 if(ss<0) ss=0;
 //Print Result...
 textattr(31);
 clrscr();
 TextFont16(C_Mb_2,0x80); TextFont16(C_Hu_2,0x82); TextFont16(C_Bi_3,0x84); TextFont16(C_Jc_4,0x86);
 TextFont16(C_Yi_1,0x88); TextFont16(C_Dai4,0x8a);
 TextFont16(C_Zuo4,0xe0); TextFont16(C_Zhe3,0xe2);
 TextFont16(C_Xie4,0xf0); TextFont16(C_Ji_4,0xf2); TextFont16(C_Lei2,0xf4);
 TextFont16(C_Yr_2,0x90); TextFont16(C_Ce_4,0x92); TextFont16(C_Shi4,0x94); TextFont16(C_Wen2,0x96); TextFont16(C_Jm_4,0x98);
 TextFont16(C_Ks_1,0xa0); TextFont16(C_Ge_2,0xa2); TextFont16(C_Zi_4,0xa4); TextFont16(C_Fu_3,0xa6); TextFont16(C_Hao4,0xa8);
 TextFont16(C_Vs_1,0xb0); TextFont16(C_Yy_1,0xb2);
 TextFont16(C_Vg_4,0xb4); TextFont16(C_Qt_4,0xb6); TextFont16(C_Cuo4,0xb8); TextFont16(C_Wu_4,0xba);
 TextFont16(C_Zg_1,0xc0); TextFont16(C_Lou4,0xc2);
 TextFont16(C_Qi_2,0xc4); TextFont16(C_Ta_1,0xc6); TextFont16(C_He_2,0xc8); TextFont16(C_Ji_d,0xca);
 TextFont16(C_Xc_3,0xcc); TextFont16(C_Py_2,0xce);
 TextFont16(C_Shi3,0xd0); TextFont16(C_Ys_4,0xd2);
 TextFont16(C_Bg_3,0xd4); TextFont16(C_Rr_3,0xd6);//Jm=0x98
 TextFont16(C_Bc_1,0xd8); TextFont16(C_Vun3,0xda); TextFont16(C_Fen1,0xdc);

 printf("\n\x80\x81\x82\x83\x84\x85\x86\x87\x88\x89\x8a\x8b\t\xe0\xe1\xe2\xe3 : \xf0\xf1\xf2\xf3\xf4\xf5\n");
 printf("\n\t\t\x90\x91\x96\x97\x98\x99:%12s\t\x92\x93\x94\x95\x96\x97\x98\x99:%12s\n\n",(argc==3)?argv[2]:"TKSource.TXT",argv[1]);
 printf("\xb2\xb3\x96\x97\xa6\xa7\xa8\xa9=\t%d\t\t\t%d\n",es1,es2);
 printf("\xb2\xb3\x96\x97\xa4\xa5\xa6\xa7=\t%d\t\t\t%d\n",ee1,ee2);
 printf("\xb0\xb1\x96\x97\xa6\xa7\xa8\xa9=\t%d*2\t\t\t%d*2\n",cs1,cs2);
 printf("\xb0\xb1\x96\x97\xa4\xa5\xa6\xa7=\t%d*2\t\t\t%d*2\n",cc1,cc2);
 printf("\xc8\xc9\xca\xcb\t=\t%d\t\t\t%d\n",es1+ee1+cs1*2+cc1*2,es2+ee2+cs2*2+cc2*2);
 printf("\n\xa0\xa1\xa2\xa3\t=\t%d\t\t\t%d\n",space1,space2);
 printf("\xc4\xc5\xc6\xc7\t=\t%d\t\t\t%d\n",o1,o2);

 printf("\n\t\t\xb4\xb5\xb6\xb7\t\xb8\xb9\xba\xbb\t\xba\xbb\xc0\xc1\t\xc2\xc3\xa4\xa5\t\t  \xcc\xcd  \xce\xcf\n");
 printf("\xb2\xb3\x96\x97\xa6\xa7\xa8\xa9=\t%d\t%d\t%d\t%d\t\t\xb4\xb5 \x4 %d\n",es3[0],es3[1],es3[2],es3[3],es3[0]+ee3[0]+cs3[0]*2+cc3[0]*2);
 printf("\xb2\xb3\x96\x97\xa4\xa5\xa6\xa7=\t%d\t%d\t%d\t%d\t\t\xba\xbb \x4 %d\n",ee3[0],ee3[1],ee3[2],ee3[3],es3[1]+ee3[1]+cs3[1]*2+cc3[1]*2);
 printf("\xb0\xb1\x96\x97\xa6\xa7\xa8\xa9=\t%d*2\t%d\t%d\t%d\t\t\xc0\xc1 \x4 %d\n",cs3[0],cs3[1],cs3[2],cs3[3],es3[2]+ee3[2]+cs3[2]*2+cc3[2]*2);
 printf("\xb0\xb1\x96\x97\xa4\xa5\xa6\xa7=\t%d*2\t%d\t%d\t%d\t\t\xc2\xc3 \x4 %d\n",cc3[0],cc3[1],cc3[2],cc3[3],es3[3]+ee3[3]+cs3[3]*2+cc3[3]*2);
 printf("\xc8\xc9\xca\xcb\t=\t%d\t%d\t%d\t%d\t\t  \xd8\xd9\xda\xdb\xdc\xdd\n\t\t\t\t\t\t\t%f\xdc\xdd\n",
	es3[0]+ee3[0]+cs3[0]*2+cc3[0]*2,
	es3[1]+ee3[1]+cs3[1]*2+cc3[1]*2,
	es3[2]+ee3[2]+cs3[2]*2+cc3[2]*2,
	es3[3]+ee3[3]+cs3[3]*2+cc3[3]*2,
	ss);
 printf("\n\xa0\xa1\xa2\xa3\t=\t%d\t%d\t%d\t%d\n",space3[0],space3[1],space3[2],space3[3]);
 printf("\xc4\xc5\xc6\xc7\t=\t%d\t%d\t%d\t%d\n",o3[0],o3[1],o3[2],o3[3]);

 printf("\n\xf0\xf1\xf0\xf1\xd0\xd1\xd2\xd3\xd4\xd5\xd6\xd7\x98\x99!!!\n");

 return 0;
}

void CLVersion(int k)
{text_info FirstScreen,TempScreen;
 gettextinfo(&FirstScreen);
 TextFont16(C_Mb_2,0x80); TextFont16(C_Hu_2,0x82); TextFont16(C_Bi_3,0x84); TextFont16(C_Jc_4,0x86);
 TextFont16(C_Yi_1,0x88); TextFont16(C_Dai4,0x8a);
 TextFont16(C_Ge_2,0x90); TextFont16(C_Shi4,0x92);
 TextFont16(C_Yr_2,0x94); TextFont16(C_Bei4,0x96); TextFont16(C_Wen2,0x98); TextFont16(C_Jm_4,0x9a);
 TextFont16(C_Zuo4,0xe0); TextFont16(C_Zhe3,0xe2);
 TextFont16(C_Xie4,0xf0); TextFont16(C_Ji_4,0xf2); TextFont16(C_Lei2,0xf4);
 printf("\n\x80\x81\x82\x83\x84\x85\x86\x87\x88\x89\x8a\x8b\t\xe0\xe1\xe2\xe3:\xf0\xf1\xf2\xf3\xf4\xf5\nCopyright 1996\tTopCroakSoftware. All rights reserved.\n");
 if (k==1) return;
 printf("\n\x90\x91\x92\x93:\n\t\tTKing <\x96\x97\x80\x81\x82\x83\x98\x99\x9a\x9b> [\x94\x95\x98\x99\x9a\x9b=\x22TKSource.TXT\x22]\n");
 gettextinfo(&TempScreen);
 getch();
 gotoxy(1,(FirstScreen.winbottom-FirstScreen.cury<=InfoHeight)?FirstScreen.winbottom-InfoHeight+2:FirstScreen.cury+1);
 printf("IT Test King I\tAuthor / DanSei, 1996\n");
 gotoxy(1,(FirstScreen.winbottom-FirstScreen.cury<=InfoHeight)?FirstScreen.winbottom-InfoHeight+5:FirstScreen.cury+4);
 printf("Usage:\n\t\tTKing <Test File> [Source File=\x22TKSource.TXT\x22]\n");
 gotoxy(1,TempScreen.cury);
 TResetCharMap();
}