#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "ploader.c"

#include <math.h>
#include <alloc.h>
#include <bios.h>
#include <io.h>

#define DELAY1	500
#define POS	(24 * 160 + 0 * 2)

#define TCOUNT	(4 * 18)
#define SCOUNT	6

int ucdos = 0;
int quick = 0;

void Begin_Chinese(), Begin_English();
void End_OK_Chinese(), End_OK_English();
void Help_Chinese(), Help_English();
void End_Error_Chinese(), End_Error_English();

void interrupt (*old1c)(...);

void interrupt new1c(...) {
  static char *Ts, *T = quick == 1 ?
	"TOPCROAKCHKREFERCHKREFERCHKREFER桃壳软件检查引用检查引用检查引用" :
	"TOPCROAKCLRCOUNTADJTIMERWELLDONE桃壳软件清除计数调整时间保存状态";
  static int i, count, index = 0;
  static char far *s;
  s = (char far *)MK_FP(0xB800, POS);
  if (++count % TCOUNT == 0)
    Ts = T + (ucdos << 5) + 8 * (index++ % 4);
  if (count % SCOUNT == 0)
    for (i = 0; i < 8; i++) s[i + i] = Ts[i];
}

void main(int argc, char **argv) {
  WORD r;
  char cmdline[256];

  asm {
    push ax
    mov ax, 0xDB00
    int 0x2F
    pop ax
  }
  ucdos = _BX == 0x5450;

  if (strcmp(argv[1], "/?") == 0) {
    if (ucdos == 1)
      Help_Chinese();
    else
      Help_English();
    return;
  }

  if (strcmp(argv[1], "/!") == 0) {
    argv[1][0] = '\0';
    quick = 1;
  }

  strcpy(cmdline, *++argv);
  while (*argv && *++argv) {
    strcat(cmdline, " ");
    strcat(cmdline, *argv);
  }
  if (ucdos == 1) Begin_Chinese(); else Begin_English();
  old1c = getvect(0x1C);

  setvect(0x1C, new1c);
  ExternalProgram ep("basrun71.lib", cmdline);
  r = ep.LoadAndExecute();
  if (r == 0) if (ucdos == 1) End_OK_Chinese(); else End_OK_English();
  else if (ucdos == 1) End_Error_Chinese(); else End_Error_English();
  setvect(0x1C, old1c);
}

void Begin_Chinese() {
	textcolor(YELLOW); cprintf("Quick Basic 7.10        脱壳解密程序1.0    驻留内存\n\r");
	textcolor(LIGHTBLUE); cprintf("计算机软件安全协会      谢继雷/桃壳软件\n\r");
        textcolor(WHITE); cprintf("执行\"QB /!\"查看脱壳版QB7.1帮助\n\r");
        textcolor(LIGHTGREEN); cprintf("生成密钥......\n\r");
        if (!quick) delay(DELAY1);
	cprintf("装入程序......\n\r");
	textcolor(LIGHTGRAY);
	cprintf("\
\n\r");
}

void Begin_English() {
	textcolor(YELLOW); cprintf("Quick Basic 7.10        Unshell decryptor 1.00	Resident memory\n\r");
	textcolor(LIGHTBLUE); cprintf("cybersoft security association  DanSei/TopCroak Software\n\r");
        textcolor(WHITE); cprintf("Enter \"QB /?\" see help\n\r");
        textcolor(LIGHTGREEN); cprintf("Generating Key ......\n\r");
        if (!quick) delay(DELAY1);
	cprintf("Loading ......\n\r");
	textcolor(LIGHTGRAY);
	cprintf("\n\r");
}

void End_OK_Chinese() {
	textcolor(WHITE);
	cprintf("正常退出!\n\r");
	textcolor(LIGHTGRAY);
	cprintf("\n\r");
}

void End_OK_English() {
	textcolor(WHITE);
	cprintf("Normal Exit!\n\r");
	textcolor(LIGHTGRAY);
	cprintf("\n\r");
}

void Help_Chinese() {
        printf("\
脱壳解密Quick Basic 7.10用法帮助\n\r-\n\r\
  QB /? /! /AH /B /C:n {/Ea | /Es} /E:n /G /H /K:[file] /L [库名]\n\r\
     /MBF /NOF[RILLS] /NOHI [/RUN] BAS文件名 /CMD 字串\n\r\n\r\
  /? 查看本帮助\n\r\
  /! 快速启动 (不启动间接库引用, 可能会导致QB在引用库时弹出一大堆微软版权侵犯\n\r\
               窗口, 并陷入死循环. 如果不引用外接库不会出现此问题. )\n\r\
  其它选项参考标准QB资料. ");
}

void Help_English() {
        printf("\
Unshelled decrypted Quick Basic 7.10 Help\n\r-\n\r\
  QB /? /! /AH /B /C:n {/Ea | /Es} /E:n /G /H /K:[file] /L [lib]\n\r\
     /MBF /NOF[RILLS] /NOHI [/RUN] <BAS File> /CMD string\n\r\n\r\
  /? View this help\n\r\
  /! quick launch (No indirect ref. this may cause lots of Microsoft Software\n\r\
               Warning windows, and get into died. It's actually no problem\n\r\
               if you only do little programming without libs referring. )\n\r\
  See other standard QB commandline reference. ");
}

void End_Error_Chinese() {
	textcolor(WHITE);
	cprintf("程序运行出错!\n\r");
	textcolor(LIGHTGRAY);
	cprintf("\n\r");
}

void End_Error_English() {
	textcolor(WHITE);
	cprintf("Fail in running!\n\r");
	textcolor(LIGHTGRAY);
	cprintf("\n\r");
}
