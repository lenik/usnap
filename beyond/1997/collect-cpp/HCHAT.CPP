/* Heaven Chat Station */

#include "hchat.h"
#include "hchati.cpp"
#include "TKey_MKC.h"

/*
void interrupt (*OldKeyInt)(...);
void interrupt NewKeyInt(...){
  unsigned char KeyScan;
  asm {
    push ax
    in al, 0x60
    mov KeyScan, al
    pop ax
  }
  // if (KeyScan==MKC_SPACE(MKC_MAKE)) ChatTimer();
  (*OldKeyInt)();
  return;
}
*/

void main(){
  char TalksBackup[300];
  if (!InitEnv()) return;
  CW[Title].Clear();
    if (Ucdos) {
      gotoxy(10, 1); PutCString("天 堂 聊 天 站    核 心 测 试 版 C             制 作 / 谢 继 雷");
      gotoxy(20, 2); PutCString("天 堂 有 路 千 万 条 要 走 哪 条 随 你 挑");
    } else {
      gotoxy(10, 1); PutCString("Heaven Chat Station   Kernel Testing Version C    Author DanSei");
      gotoxy(20, 2); PutCString("Each way go to heaven is available for you");
    }
  CW[Title].Save();

  LoginFrame();

  //SetTimer();
  //OldKeyInt=getvect(0x09);
  //setvect(0x09, NewKeyInt);

  while (1){
    if (GetSent()[0]=='~') break;
    CWBegin(Talking);
    textattr(CW[Talking].Attr);
      MakeTalk(Talks);
      strcat(Talks, CurTime());
      PutCString(Talks);
    CWEnd(Talking);

    memcpy(TalksBackup, Talks, 300);
    ChatTimer();
    memcpy(Talks, TalksBackup, 300);
    Getting=fopen(GettingFile, "wb");
    if (!Getting)
      NoVS();
    else {
      VSOK();
      Tem[0]=random(0x80); Tem[1]=random(0x80); Tem[2]=random(0x80); Tem[3]=random(0x80);
      fwrite(Tem, 4, 1, Getting);
      fwrite(Talks, 300, 1, Getting);
      fclose(Getting);
      //LastID=(DWord)(Tem[0]<<24)+(DWord)(Tem[1]<<16)+(DWord)(Tem[2]<<8)+(DWord)(Tem[3]);
      LastID=Tem[3];
    }
    Records=fopen(RecordsFile, "ab");
    if (!Records) {
      NoVS();
    } else {
      VSOK();
      fseek(Records, 0, SEEK_END);
      fwrite(Talks, 300, 1, Records);
      fclose(Records);
    }
  }

  LogoutFrame();

  //RestoreTimer();
  //setvect(0x09, OldKeyInt);

  //CW[Screen].Restore();
}
