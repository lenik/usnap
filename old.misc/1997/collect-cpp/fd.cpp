#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<dir.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
#include<alloc.h>
#include<TCF\textfont.c>

struct diritem{
  char *name;
  struct diritem *p, *n;
  diritem(int length = 256);
  diritem(char *inits);
  ~diritem();
};
diritem::diritem(int length = 256) {
  name = new char[length + 1];
}
diritem(char *inits) {
  if ((name = newchar[strlen(inits) + 1]) != NULL) {
    strcpy(name, inits);
  }
}

StringNod::StringNod(int StringLen=256){
  if (!(String=new char[StringLen])) errno=(int)'M';
  if ((unsigned char)errno!='M') String[0]=0;
}
StringNod::~StringNod(){
  delete String;
}

char *        MakeFixed(char *Src, int Len=20){
  int nc;
  char *Ret;
  if(!(Ret=new char[((strlen(Src)>Len)?strlen(Src):Len)+1])){
    return "Memory Out!!";
  }
  strcpy(Ret, Src);
  for (nc=0; nc<Len; nc++){
    if (!Ret[nc]){
      for (; nc<Len; nc++) Ret[nc]=' ';
      Ret[Len]=0;
      break;
    }
  }
  delete Ret;
  return Ret;
}

unsigned char CompareString(char *StringA, char *StringB){
  int pc=0;
  while (pc<((strlen(StringA)>strlen(StringB))?strlen(StringB):strlen(StringA))){
    if (StringA[pc]>StringB[pc]) return '>';
    else if (StringA[pc]<StringB[pc]) return '<';
    pc++;
  }
  if (strlen(StringA)>strlen(StringB)) return '>';
  else if (strlen(StringA)<strlen(StringB)) return '<';
  else return '=';
}

void Combine(StringNod **ComString){
  StringNod *TakeNod;
  if((*ComString)==NULL) return;
  while(((*ComString)->Prev!=NULL)) (*ComString)=(*ComString)->Prev;
  while(((*ComString)->Next!=NULL)){
    if (!(*ComString)->String[0])
      if((*ComString)->Prev!=NULL)
	if((*ComString)->Next!=NULL){
	  TakeNod=(*ComString)->Next;
	  (*ComString)->Prev->Next=(*ComString)->Next;
	  (*ComString)->Next->Prev=(*ComString)->Prev;
	  delete (*ComString);
	  (*ComString)=TakeNod;
	}
	else{
	  (*ComString)->Prev->Next=NULL;
	  TakeNod=(*ComString)->Prev;
	  delete (*ComString);
	  (*ComString)=TakeNod;
	  while(((*ComString)!=NULL)&&((*ComString)->Prev!=NULL)) (*ComString)=(*ComString)->Prev;
	  return;
	}
      else
	if((*ComString)->Next!=NULL){
	  (*ComString)=(*ComString)->Next;
	  delete (*ComString)->Prev;
	  (*ComString)->Prev=NULL;
	}
	else{
	  delete (*ComString);
	  (*ComString)=NULL;
	  return;
	}
    else
      (*ComString)=(*ComString)->Next;
  }
//---- !! Last String !! ----//
    if (!(*ComString)->String[0])
      if((*ComString)->Prev!=NULL){
	(*ComString)->Prev->Next=NULL;
	TakeNod=(*ComString)->Prev;
	delete (*ComString);
	(*ComString)=TakeNod;
	while(((*ComString)!=NULL)&&((*ComString)->Prev!=NULL)) (*ComString)=(*ComString)->Prev;
	return;
      }
      else{
	delete (*ComString);
	(*ComString)=NULL;
	return;
      }
//---- !! Last String !! ----//
  while(((*ComString)->Prev!=NULL)) (*ComString)=(*ComString)->Prev;
  return;
}

void SwapString(char **SA, char **SB){
  char *Swap;
  Swap=(*SA);
  (*SA)=(*SB);
  (*SB)=Swap;
  Swap=NULL;
}

void SwapPointer(StringNod **pA, StringNod **pB){
  StringNod *Swap;
  Swap=(*pA);
  (*pA)=(*pB);
  (*pB)=Swap;
  Swap=NULL;
}

void Swap(StringNod **SwapA, StringNod **SwapB){
/*
  StringNod *_SwapA, *_SwapPrevNextA, *_SwapB, *_SwapPrevNextB;
  _SwapA=new StringNod;
  _SwapPrevNextA=new StringNod;
  _SwapB=new StringNod;
  _SwapPrevNextB=new StringNod;

  _SwapA->Prev=SwapA->Prev;
  _SwapA->Next=SwapA->Next;
  _SwapPrevNextA->Next=SwapA->Prev->Next;
  _SwapPrevNextA->Prev=SwapA->Next->Prev;

  _SwapB->Prev=SwapB->Prev;
  _SwapB->Next=SwapB->Next;
  _SwapPrevNextB->Next=SwapB->Prev->Next;
  _SwapPrevNextB->Prev=SwapB->Next->Prev;


  SwapA->Prev->Next=SwapB->Prev->Next;
  SwapA->Next->Prev=SwapB->Next->Prev;
  SwapA->Prev=SwapB->Prev;
  SwapA->Next=SwapB->Next;


  SwapA->Prev=_SwapB->Prev;
  SwapA->Next=_SwapB->Next;
  SwapA->Prev->Next=_SwapPrevNextB->Next;
  SwapA->Next->Prev=_SwapPrevNextB->Prev;

  SwapB->Prev=_SwapA->Prev;
  SwapB->Next=_SwapA->Next;
  SwapB->Prev->Next=_SwapPrevNextA->Next;
  SwapB->Next->Prev=_SwapPrevNextA->Prev;

  delete _SwapA;
  delete _SwapB;
  delete _SwapPrevNextA;
  delete _SwapPrevNextB;
*/
/*
  SwapPointer(&((*SwapA)->Prev),&((*SwapB)->Prev));
  SwapPointer(&((*SwapA)->Next),&((*SwapB)->Next));
  SwapPointer(&((*SwapA)->Prev->Next),&((*SwapB)->Prev->Next));
  SwapPointer(&((*SwapA)->Next->Prev),&((*SwapB)->Next->Prev));
*/
}

void Sort(StringNod **SortString){
  int AllPass=0;
//  Swap((*SortString), (*SortString)->Next);
  while (((*SortString)!=NULL)&&((*SortString)->Prev!=NULL)) (*SortString)=(*SortString)->Prev;
  while (!AllPass){
    AllPass=1;
    while (((*SortString)!=NULL)&&((*SortString)->Prev!=NULL)) (*SortString)=(*SortString)->Prev;
    while (((*SortString)!=NULL)&&((*SortString)->Next!=NULL)){
      if (CompareString((*SortString)->String, (*SortString)->Next->String)=='>') {
	SwapString(&(*SortString)->String, &(*SortString)->Next->String);
	/*
	{
	 SwapPointer(&(*SortString), &((*SortString)->Next));
	 SwapPointer(&(*SortString)->Prev, &((*SortString)->Next->Prev));
	 SwapPointer(&(*SortString)->Next, &((*SortString)->Next->Next));
	 SwapPointer(&(*SortString)->Prev->Next, &((*SortString)->Next->Prev->Next));
	 SwapPointer(&(*SortString)->Next->Prev, &((*SortString)->Next->Next->Prev));
	}
	*/
	AllPass=0;
      }
      (*SortString)=(*SortString)->Next;

    }//New Loop
  }//Finished Sorting
  while (((*SortString)!=NULL)&&((*SortString)->Prev!=NULL)) (*SortString)=(*SortString)->Prev;
  return;
}

unsigned char FindFiles(char *Wild, StringNod **FileStore){
  ffblk FileDesc;
  StringNod *Head=NULL,*Last=NULL;
  int Done;
  Done=findfirst(Wild, &FileDesc, FA_HIDDEN|FA_DIREC);
  if(!((*FileStore)=new StringNod)) return 'M';
  if(Done){
    delete (*FileStore);
    (*FileStore)->Prev=(*FileStore)->Next=NULL;
    return 'N';
  }
  Head=(*FileStore);
  (*FileStore)->Prev=NULL;
  strcpy((*FileStore)->String,FileDesc.ff_name);
  Last=(*FileStore);
  while(!Done){
    Done=findnext(&FileDesc);
    if(Done) break;
    if(!((*FileStore)=new StringNod)) return 'M';
    (*FileStore)->Prev=Last;
    Last->Next=(*FileStore);
    strcpy((*FileStore)->String,FileDesc.ff_name);
    Last=(*FileStore);
  }
  (*FileStore)->Next=NULL;
  (*FileStore)=Head;
  return 0;
}

unsigned char main(int argc, char**argv){
  int argi, key;
  int OriX, OriY;
  StringNod *Outs, *Pass, *EndNod;
  text_info ScrInfo;
  void *TextBuf=NULL;
  OriX=wherex(); OriY=wherey();

  if (argc==2){
    int ret;
    if((strchr(argv[1], '?')==NULL)&&(strchr(argv[1], '*')==NULL))
      ret=chdir (argv[1]);
    if (!ret) return 'I';
  }

  if(!(TextBuf=new char[80*25*2])) return 'M';

  gettextinfo(&ScrInfo);
  gettext(ScrInfo.winleft, ScrInfo.wintop, ScrInfo.winright, ScrInfo.winbottom, TextBuf);
  OriY=(ScrInfo.screenheight-OriY)<5?1:OriY;

  if (
      (!strcmp(argv[1], "/?"))||
      (!strcmp(argv[1], "/Help"))||
      (!strcmp(argv[1], "/H"))||
      (!strcmp(argv[1], "/h"))
  ){
    printf("Usage: %s [/?|H|h|Help] [Directory wild names...]\n", argv[0]);
    return '?';
  }

begin:
  if(!(Outs=new StringNod)) return 'M';
  Outs->Prev=Outs->Next=NULL;

  if (argc==1) {argc=2;argv[1]="*.";}
  for(argi=1; argi<=argc-1; argi++){
    FindFiles(argv[argi], &Pass);
    EndNod=Outs;
    while(EndNod->Next!=NULL){
      EndNod=EndNod->Next;
    }
    EndNod->Next=Pass;
    Pass->Prev=EndNod;
    Pass=new StringNod;
  }

  delete Pass;
  Outs=Outs->Next;
  delete Outs->Prev;
  Outs->Prev=NULL;
  Combine(&Outs);

	Outs=Outs->Next;
	Sort(&Outs);

  key=' ';

  while (key!=13){

    if (!key) {
      key=getch();
      /* Up   */ if ((key==72)&&(Outs!=NULL)&&(Outs->Prev!=NULL)) Outs=Outs->Prev;
      /* Down */ if ((key==80)&&(Outs!=NULL)&&(Outs->Next!=NULL)) Outs=Outs->Next;
      /* PgUp */ if ((key==73)&&(Outs!=NULL)) for (int GoDown=0; GoDown<5; GoDown++) if (Outs->Prev!=NULL) Outs=Outs->Prev;
      /* PgDn */ if ((key==81)&&(Outs!=NULL)) for (int GoDown=0; GoDown<5; GoDown++) if (Outs->Next!=NULL) Outs=Outs->Next;
      /* Home */ if ((key==71)&&(Outs!=NULL)) while (Outs->Prev!=NULL) Outs=Outs->Prev;
      /* End  */ if ((key==79)&&(Outs!=NULL)) while (Outs->Next!=NULL) Outs=Outs->Next;

      /* Left */ if (key==75){
		   chdir("..");
		   while((Outs!=NULL)&&(Outs->Prev!=NULL)) Outs=Outs->Prev;
		   while((Outs!=NULL)&&(Outs->Next!=NULL)){
		     Outs=Outs->Next;
		     delete Outs->Prev;
		     Outs->Prev=NULL;
		   }
		   if (Outs!=NULL) {delete Outs;
		   Outs=NULL;
		   }
		   //OriX=(OriX+80-15)%80+1;
		   argc=1;
		   goto begin;
		 }

      /* Right*/ if (key==77) {
		   chdir (Outs->String);
		   while((Outs!=NULL)&&(Outs->Prev!=NULL)) Outs=Outs->Prev;
		   while((Outs!=NULL)&&(Outs->Next!=NULL)){
		     Outs=Outs->Next;
		     delete Outs->Prev;
		     Outs->Prev=NULL;
		   }
		   if (Outs!=NULL) {
		     delete Outs;
		     Outs=NULL;
		   }
		   goto begin;
		 }

      /* ~A-Z */ if (((16<=key)&&(key<=25))||((30<=key)&&(key<=38))||((44<=key)&&(key<=50))){
		   char DiskIndex[35]={'Q','W','E','R','T','Y','U','I','O','P',
				       0,0,0,0,
				       'A','S','D','F','G','H','J','K','L',
				       0,0,0,0,0,
				       'Z','X','C,','V','B','N','M'};
		   if (DiskIndex[key-16])
		     setdisk((int)DiskIndex[key-16]-65);
		   while((Outs!=NULL)&&(Outs->Prev!=NULL)) Outs=Outs->Prev;
		   while((Outs!=NULL)&&(Outs->Next!=NULL)){
		     Outs=Outs->Next;
		     delete Outs->Prev;
		     Outs->Prev=NULL;
		   }
		   if (Outs!=NULL) {
		     delete Outs;
		     Outs=NULL;
		   }
		   goto begin;
		 }

      /* F1   */ if (key==59){
		   void *TextBuf1=NULL;
		   unsigned char
		     WaveMap[16]={0,0,0,0,56,68,68,130,130,1,1,0,0,0,0,0},
		     HorMap[32]={0,0,0,0,0,0,63,0,0,252,0,0,0,0,0,0,0,0,0,0,0,0,252,0,0,63,0,0,0,0,0,0},
		     _FangXiangMap[64]={4,0,3,0,1,0,0,4,255,254,4,0,4,16,7,248,4,16,4,16,4,16,8,16,8,16,16,16,32,160,64,64,2,0,4,0,8,4,127,254,64,4,64,36,79,244,72,36,72,36,72,36,72,36,79,228,72,36,64,4,64,20,64,8},
		     _FanYeMap[64]={14,4,241,222,84,68,56,68,254,68,17,84,84,204,146,68,124,68,84,204,85,84,124,68,84,68,84,68,125,84,68,136,0,4,255,254,2,0,4,16,31,248,16,16,17,16,17,16,17,16,17,16,17,16,17,16,18,144,4,96,8,24,48,8},
		     _ZuoYouMap[64]={2,0,2,0,2,8,255,252,4,0,4,0,4,0,8,16,15,248,16,128,16,128,32,128,64,128,128,132,127,254,0,0,2,0,2,0,2,4,255,254,4,0,4,0,8,0,8,8,31,252,40,8,72,8,136,8,8,8,8,8,15,248,8,8},
		     _JianMap[32]={32,16,39,16,57,124,65,20,130,254,122,20,36,124,39,16,249,124,33,16,37,20,34,254,42,16,53,16,40,150,0,124};

		   if(!(TextBuf1=new char[80*25*2])) return 'M';
		   gettext(ScrInfo.winleft, ScrInfo.wintop, ScrInfo.winright, ScrInfo.winbottom, TextBuf1);
		   clrscr();
		   SetCharMap(1,1,WaveMap);
		   SetCharMap(2,2,HorMap);
		   TextFont16( _FangXiangMap,    0xc0);
		   TextFont16(&_FangXiangMap[32],0xc2);
		   TextFont16( _FanYeMap,        0xc4);
		   TextFont16(&_FanYeMap[32],    0xc6);
		   TextFont16( _ZuoYouMap,       0xc8);
		   TextFont16(&_ZuoYouMap[32],   0xca);
		   TextFont16( _JianMap,         0xcc);
		   printf(" Fast Directory \n");
		   printf(" Help \n");
		   printf("\tÀÁÂÃÌÍ\n");
		   printf("\tÄÅÆÇÌÍ\n");
		   printf("\tÈÉÊËÌÍ\n");
		   printf("\tAlt-A~Z Change Disk");
		   if(!getch()) getch();
		   OldCharMap();
		   puttext(ScrInfo.winleft, ScrInfo.wintop, ScrInfo.winright, ScrInfo.winbottom, TextBuf1);
		   delete TextBuf1;
		 }
    } //key=0

    if (key==27) break;

    gotoxy(OriX, OriY);
    textattr(7); cprintf(" %s ",((Outs!=NULL)&&(Outs->Prev!=NULL)&&(Outs->Prev->Prev!=NULL))?MakeFixed(Outs->Prev->Prev->String,12):"           ");
    gotoxy(OriX, OriY+1);
    textattr(7); cprintf("É%s»",((Outs!=NULL)&&(Outs->Prev!=NULL))?MakeFixed(Outs->Prev->String,12):"ÍÍÏÍÍÍÍÍÍÍÍÍ");
    gotoxy(OriX, OriY+2);
    textattr(112);cprintf("Ì%s¹",(Outs!=NULL)?MakeFixed(Outs->String,12):"ÍÍÍÍÍÍÍÍÍÍÍÍ");
    gotoxy(OriX, OriY+3);
    textattr(7); cprintf("È%s¼",((Outs!=NULL)&&(Outs->Next!=NULL))?MakeFixed(Outs->Next->String,12):"ÍÍÍÍÍÍÍÍÍÑÍÍ");
    gotoxy(OriX, OriY+4);
    textattr(7); cprintf(" %s ",((Outs!=NULL)&&(Outs->Next!=NULL)&&(Outs->Next->Next!=NULL))?MakeFixed(Outs->Next->Next->String,12):"           ");

    key=getch();
  }

  puttext(ScrInfo.winleft, ScrInfo.wintop, ScrInfo.winright, ScrInfo.winbottom, TextBuf);
  gotoxy(ScrInfo.curx, ScrInfo.cury);
//  }

  if (key==27) return 'Q';

  chdir (Outs->String);
  while((Outs!=NULL)&&(Outs->Prev!=NULL)) Outs=Outs->Prev;
  while((Outs!=NULL)&&(Outs->Next!=NULL)){
    Outs=Outs->Next;
    delete Outs->Prev;
    Outs->Prev=NULL;
  }
  if (Outs!=NULL) {delete Outs;
  Outs=NULL;
  }

  delete TextBuf;
  TextBuf=NULL;
  return 0;
}
