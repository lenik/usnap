#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<CLInc\CL.h>
#include<TCF\Video.C>
#include<TCF\TextFont.C>
#include<CLDat\CLFont.Dat>

const InfoHeight=8;

char far*CLFile;

void CLVerFontInit();
void CLVersion();

int main(int argc,char**argv)
{
 if (argc!=2) {CLVersion();return 2;}
 CL *CLFile=new CL;
 CLFile->m_pszFileName=argv[1];
 switch (CLFile->Do())
  {case  0: printf("Normal exit.");break;
   case  1: printf("File Open Error: %s\n",CLFile->GetErrMsg());break;
   case 26: printf("File end before finish command.\n");
	    break;
   default: printf("Error!");
  }

 return (CLFile->GetErrNo());

}

void CLVerFontInit(void)
{TextFont16(C_Han4,0x80);
 TextFont16(C_Yan2,0x82);
 TextFont16(C_Yi_1,0x84);
 TextFont16(C_Dai4,0x86);
 TextFont16(C_Zhi4,0xf8);
 TextFont16(C_Zuo4,0xfa);
 TextFont16(C_Dan1,0xfc);
 TextFont16(C_Sai4,0xfe);
 return;
}

void CLVersion()
{text_info FirstScreen,TempScreen;
 gettextinfo(&FirstScreen);
 CLVerFontInit();
 printf("\n\x80\x81\x82\x83\x84\x85\x86\x87\t\t\xf8\xf9\xfa\xfb:\xfc\xfd\xfe\xff\n\t\t\tCopyright 1998\tTopCroakSoftware. All rights reserved.\n\n\n\tUsage:\n\t\tCL <CL File>\n");
 gettextinfo(&TempScreen);
 getch();
 gotoxy(1,(FirstScreen.winbottom-FirstScreen.cury<=InfoHeight)?FirstScreen.winbottom-InfoHeight+2:FirstScreen.cury+1);
 printf("Chinese Language I\tMade/DanSei\n");
 gotoxy(1,TempScreen.cury);
 OldCharMap();
}