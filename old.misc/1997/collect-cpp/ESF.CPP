#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <dir.h>
#include <dos.h>
#include <stdlib.h>
#include "WT.cpp"

struct _Config {
  char YourPath[256], MyPath[256];
  int HeadSize;
  char Class1[256], Class2[256];
} Config;

int findfirst1(const char *pathname, struct ffblk *ffblk, int attrib);
int finddir(const char *pathname);
int mkldir(char *dir), Chdir();
void mdir(int s, char *dn), process(char *fn), rprocess(char *fn);

void Title(), End(), Menu(), HelpScreen();

void main(int argc, char **argv) {
  int k;
  struct ffblk f;
  char TiMu[256], ZoVe[256];

  if (argc < 3) {
    printf("\
��ʽ: ESFI <��ѧ���ݴ�Ŀ¼> <��ѧվ�ݴ�Ŀ¼> \n\
���綫�����ļ����ڸ�Ŀ¼��dh2Ŀ¼, ת�����ļ�ת�浱ǰĿ¼��esdoc\whĿ¼��: \n\
	>>>  ESFI \\DH2 ESDOC\\WH \n");
    return;
  }

  mdir(1, argv[1]);
  mdir(2, argv[2]);

  for (;;) {
    Menu();
    k = getche();
    switch (k) {
      case 0:
	k = getch();
	switch (k) {
	  case 0x3B: HelpScreen(); break;		// F1
	  case 0x3C:					// F2 F3
	  case 0x3D:
	    if (findfirst1(Config.YourPath, &f, FA_ARCH) == 0) {

	      k == 0x3C ? process(f.ff_name) : rprocess(f.ff_name);
	      while (findnext(&f) == 0) {
		process(f.ff_name);
	      }
	    } else {
	      printf("û���ҵ��ļ�");
	    } break;
	  case 0x3E: break;				// F4
	  case 0x3F:					// F5
	    printf("�����³���: "); scanf("%d", &Config.HeadSize);
	    break;
	  case 0x41:					// F7 F8
	  case 0x42:
	    printf(k == 0x41 ? "����ԴĿ¼: " : "����Ŀ��Ŀ¼: ");
	    scanf("%s", k == 0x41 ? Config.YourPath : Config.MyPath);
	    mdir (k == 0x41 ? 1 : 2,  k == 0x41 ? Config.YourPath : Config.MyPath);
            break;
	  case 0x43:					// F9
	    printf("��Ҫ����һ��? (y/n) ");
	    if ((getche() | 0x20) == 'y') {
	      printf("\n�������һ: "); scanf("%s", Config.Class1);
	    } else {
	      Config.Class1[0] = '\0';
	    } break;
	  case 0x44:					// F10
	    printf("��Ҫ�������? (y/n) ");
	    if ((getche() | 0x20) == 'y') {
	      printf("\n��������: "); scanf("%s", Config.Class2);
	    } else {
	      Config.Class2[0] = '\0';
	    } break;
	}
	break;
      case 'x':
      case 'X':
	End();
	return;
    } // switch
  } // for
}

int findfirst1(const char *pathname, struct ffblk *ffblk, int attrib) {
  char buf[512];
  strcpy(buf, pathname);
  strcat(buf, "*.*");
  return findfirst(buf, ffblk, attrib);
}

int finddir(const char *pathname) {
  struct ffblk f;
  char buf[512];
  strcpy(buf, pathname);
  if (buf[strlen(buf) - 1] == '\\') {
    buf[strlen(buf) - 1] = '\0';
  }
  return findfirst(buf, &f, FA_DIREC);
}

int mkldir(char *dir) {
  struct ffblk f;
  int i, r;
  for (i = 0;; i++) {
    if (dir[i] == '\0') {
      if (dir[i - 1] != '\\') {
	if (findfirst(dir, &f, FA_DIREC) != 0) { return mkdir(dir); }
      } else {
	return 0;
      }
    }
    if (dir[i] == '\\') {
      if (dir[i - 1] == ':') { continue; }
      dir[i] = '\0';
      if (findfirst(dir, &f, FA_DIREC) == 0) { continue; }
      r = mkdir(dir);
      dir[i] = '\\';
      if (r == 0) { continue; }
      else return 1;
    }
    continue;
  }
  return 1;
}

void mdir(int s, char *dn) {
  char buf[512];
  strcpy(buf, dn);

  for (;;) {
    if (buf[strlen(buf) - 1] != '\\' && buf[strlen(buf) - 2] != ':') {
      strcpy(buf + strlen(buf), "\\");
    }
    if (finddir(buf) == 0) { break; }
    else {
      printf("Ŀ¼������, �Ƿ񴴽�? ");
      if ((getche() | 0x20) == 'y') {
	if (mkldir(buf) == 0) { break; }
	else { printf("���ܴ���Ŀ¼, ����������. \n"); }
      }
      printf("\n����Ŀ¼: "); scanf("%s", buf);
    }
  }
  strcpy(s == 1 ? Config.YourPath : Config.MyPath, buf);
}

void Title() {
  printf("\
\n������ѧ��<=>������ѧվ	�ĵ��ӿ�	[�ڲ�ʹ��]\n\
*TopCroak Software* �ҿ����� 	����/л����	1999.4.29\n");
}

void End() {
  printf("�����˳�.\n");
}

void Menu() {
  Title();
  printf("\n\
//////////////// �� �� �� ///////////////// \n\
//  F2 - ��ѧ�� -> ��ѧվ \n\
//  F3 - ��ѧվ -> ��ѧ�� \n\
//  X  - �˳� \n\
////////////////  ѡ  ��  ///////////////// \n\
//  F5 - ��ʾ�ļ�ͷ��С:  %04d \n\
//  F7 - ԴĿ¼:     %s \n\
//  F8 - Ŀ��Ŀ¼:   %s \n\
//-- \n\
//  F9  - ����һ: %s \n\
//  F10 - �����: %s \n\
//// EAST DOCUMENTS INTERFACE ///////////// \n\
/////////////////// TOPCROAK SOFTWARE ///// \n",
Config.HeadSize,
Config.YourPath, Config.MyPath,
Config.Class1, Config.Class2);
}

void HelpScreen() {
  printf("[�ҿ�]�ް�����Ϣ\n");
}

void process(char *fn) {
  char you[512], me[512];
  char buf[512];
  FILE *f;
  struct WpsFile f2;
  int t, i;
  WORD w;

  strcpy(you, Config.YourPath);
  strcat(you, fn);
  strcpy(me, Config.MyPath);
  strcat(me, fn);
  printf("\n�ļ�: [%s] ", you);
  if ((f = fopen(you, "rb")) == NULL) {
    printf("���ܴ򿪸��ļ�.\n");
    return;
  }
  if (OpenWpsFile(&f2, me, "wb") != 0) {
    printf("���ܴ�Ŀ���ļ�.\n");
    fclose(f);
    return;
  }
  /* Header */
  printf("(");
  for (t = 0; t < Config.HeadSize; t++) {
    if (WpsGetc(f2, &w) == EOF) { break; }
    if (w != 0) { putch(w & 0xFF); }
    if (w >= 0x100) { putch(w >> 8); }
  }
  printf("...) \n");

  if ((getche() | 0x20) == 'y') {
    WpsSeek(f2, 0);
    if (Config.Class1[0] != '\0') { fputs("{bc}", f2.f); fputs(Config.Class1, f2.f); fputs("{/bc}", f2.f); }
    if (Config.Class2[0] != '\0') { fputs("{sc}", f2.f); fputs(Config.Class2, f2.f); fputs("{/sc}", f2.f); }
    printf("������Ŀ: "); scanf("%s", buf);
      fputs("{��Ŀ}", f2.f); fputs(buf, f2.f); fputs("{/��Ŀ}", f2.f);
    printf("��������: "); scanf("%s", buf);
      fputs("{����}", f2.f); fputs(buf, f2.f); fputs("{/����}", f2.f);
    while (WpsGetc(f2, &w) != EOF) {
      if (w == 0) { continue; }
      if (fputc(w & 0xFF, f2.f) == EOF) { perror("д����!"); break; }
      if (w >= 0x100) {
	if (fputc(w >> 8, f2.f) == EOF) { perror("д����!"); break; }
      }
    }
    puts("ok!");
  }
  CloseWpsFile(&f2);
  fclose(f);
}

void rprocess(char *fn) {
  char you[512], me[512], t[512];
  char buf[512];
  FILE *f;

  strcpy(you, Config.YourPath);
  strcat(you, fn);
  strcpy(me, Config.MyPath);
  strcat(me, fn);
  strcpy(t, Config.MyPath);
  strcat(t, "ESINTERF.ACE");

  if ((f = fopen(t, "wt")) == NULL) {
    printf("����ʱ�ļ�����");
    return;
  }
  if (fputs("\
	  {bt}  --{au}\n\
{w}", f) == EOF) {
    printf("д��ʱ�ļ�����! ");
    fclose(f);
    return;
  }
  fclose(f);
  sprintf(buf, "est %s %s >%s", t, me, you);
  if (system(buf) != 0) { printf("���ö��ͷ���ģ��ʱ����, �������ڴ治����EST.EXE��ʧ. "); }
  return;
}