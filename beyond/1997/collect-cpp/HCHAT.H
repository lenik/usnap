/* Heaven Chat Station */

#include <stdio.h>
#include <conio.h>
#include <io.h>
#include <fcntl.h>
#include <sys\stat.h>
#include <dos.h>
#include <dir.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "toptype.cpp"
#include "tstring.cpp"

char UsersFile[] =	"F:\\User\\HChat\\ChatData\\Users.HC";
char RecordsFile[] =	"F:\\User\\HChat\\ChatData\\Records.HC";
char GettingFile[] =	"F:\\User\\HChat\\ChatData\\Getting.HC";

int InitVirtualServer(void);
int InitEnv(void);
int Ucdos=0;
int IsUcdosResident(void);

char* CurTime(void);

int GetCString(char *Dest);
int PutCString(char *Source);
char *MakeTalk(char *_Talk);
char *GetSent(void);

int StartInfo(void);
int InitUser(void);
void LoginFrame(void);
void LogoutFrame(void);

void VSOK(void);
void NoVS(void);

int Interval, IntervalConstant=100;
void SetTimer(void);
void RestoreTimer(void);
void interrupt (*OldTimer)(...);
void interrupt Timer(...);
void ChatTimer(void);

struct UserDesc{
  char Name[200];
  char sSex[100];
  char Like[200];
  char Leave[300];
} User;
char DefaultAction[100], DApre[20], DAadd[20];
char Talks[300];

FILE *Users, *Records, *Getting;
FILE *rGetting;

int ow, oh;
text_info Origin;
struct CWin{
  int x1, y1, x2, y2;
  int Attr;
  text_info Last;
  void Active(void);
  void Clear(void);
  void Save(void);
  void Restore(void);
} CW[10];
enum {
  Screen=0,
  Title,
  R1,
  Talking,
  Input,
  Station,
  Status
} LastCW=Screen, LastCWSwap;
tm *time_now;
time_t secs_now;
unsigned long LastID;
char Tem[300];
