#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int rx=0, ry=0, lx, ly;  //Relative&Last Relativ, Scale
enum _Status {Switching=1, Set, Clear} Status;

char Table[16][16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
void Help();
void Show();
void Save();
void Load();
void None();
void Fill();
void Invert();
void Outline();

void Brick(int rrx, int rry, int rc){
  setfillstyle(SOLID_FILL, rc);
  bar (240+rrx*10, 100+rry*10, 250+rrx*10, 110+rry*10);
  rectangle (240+rrx*10, 100+rry*10, 250+rrx*10, 110+rry*10);
}

void main(){
  registerbgidriver(EGAVGA_driver);
  registerbgifont(triplex_font);

  int gd=VGA, gm=VGAMED;
  char *Outs;
  Outs=new char[200];
  initgraph(&gd, &gm, "..\\bgi");
  cleardevice();

  setbkcolor(BLACK); setcolor(BLACK);
  settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
  settextjustify(LEFT_TEXT, TOP_TEXT);

  for (int nnx=0; nnx<16; nnx++)
    for (int nny=0; nny<16; nny++)
      Brick(nnx, nny, Table[nny][nnx]?WHITE:DARKGRAY);

  setcolor(WHITE);
  outtextxy(0, 310, "F1-Help F2-Show F3-Save F4-Load F5-None");
  outtextxy(0, 330, "F6-Fill F7-Invert F8-Outline");

  unsigned char key=getch();
  while(key!=27){
    lx=rx; ly=ry;
    switch(key){
      case 0: key=getch();
	      switch(key){
		case 72: ry=(ry+15)%16; break; //Up
		case 80: ry=(ry+17)%16; break; //Down
		case 75: rx=(rx+15)%16; break; //Left
		case 77: rx=(rx+17)%16; break; //Right
		case 59: Help(); break;	       //F1
		case 60: Show(); break;        //F2
		case 61: Save(); break;        //F3
		case 62: Load(); break;        //F4
		case 63: None(); break;	       //F5
		case 64: Fill(); break;        //F6
		case 65: Invert(); break;      //F7
		case 66: Outline(); break;     //F8
		default:;
	      }
	      break;
      case 9: Status=Status%3+1; break;
      case 32:Table[ry][rx]=1-Table[ry][rx]; break;
      case 27:break;
      default:;
    }//switch
    switch(Status){
      case Set:   Table[ry][rx]=1; break;
      case Clear: Table[ry][rx]=0; break;
      case Switching:
      default:;
    }
    setcolor(BLACK);
    for (int nnx=0; nnx<16; nnx++)
      for (int nny=0; nny<16; nny++)
	Brick(nnx, nny, Table[nny][nnx]?WHITE:DARKGRAY);
    setcolor(BLACK);
    Brick(lx, ly, Table[ly][lx]?WHITE:DARKGRAY);
    setcolor(LIGHTBLUE);
    Brick(rx, ry, Table[ry][rx]?WHITE:DARKGRAY); //Outline
    sprintf(Outs, "X=%d  Y=%d", rx, ry);
    setfillstyle(SOLID_FILL, BLACK); bar(30,270,200,300);
    setcolor(WHITE);
    outtextxy(30, 270, Outs);

    key=getch();

  }//while

  delete Outs;

    char x,y;
  unsigned char bytes[32]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  for (y=0; y<16; y++)
    for(x=0; x<=7; x++){
      bytes[y]   +=(unsigned char)Table[y][x]  <<(7-x);
      bytes[y+16]+=(unsigned char)Table[y][x+8]<<(7-x);
    }

  closegraph();
  Save();

  printf("mapgen.sav: {%u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u};", bytes[0], bytes[1], bytes[2], bytes[3], bytes[4], bytes[5], bytes[6], bytes[7], bytes[8], bytes[9], bytes[10], bytes[11], bytes[12], bytes[13], bytes[14], bytes[15], bytes[16], bytes[17], bytes[18], bytes[19], bytes[20], bytes[21], bytes[22], bytes[23], bytes[24], bytes[25], bytes[26], bytes[27], bytes[28], bytes[29], bytes[30], bytes[31]);
}

void Help(){
  outtextxy(30, 280, "out: mapgen.sav");
  getch();
}
void Show(){
}
void Save(){
  FILE *file;
  char x,y;
  unsigned char bytes[32]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  for (y=0; y<16; y++)
    for(x=0; x<=7; x++){
      bytes[y]   +=(unsigned char)Table[y][x]  <<(7-x);
      bytes[y+16]+=(unsigned char)Table[y][x+8]<<(7-x);
    }
  file=fopen("MapGen.sav", "w");
  if (file==NULL) return;
  fprintf(file, "%u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u", bytes[0], bytes[1], bytes[2], bytes[3], bytes[4], bytes[5], bytes[6], bytes[7], bytes[8], bytes[9], bytes[10], bytes[11], bytes[12], bytes[13], bytes[14], bytes[15], bytes[16], bytes[17], bytes[18], bytes[19], bytes[20], bytes[21], bytes[22], bytes[23], bytes[24], bytes[25], bytes[26], bytes[27], bytes[28], bytes[29], bytes[30], bytes[31]);
  fclose(file);
}

void Load(){
  FILE *file;
  char x,y;
  unsigned char bytes[32];
  file=fopen("MapGen.sav", "r");
  if (file==NULL) return;
  fscanf(file, "%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u", &bytes[0], &bytes[1], &bytes[2], &bytes[3], &bytes[4], &bytes[5], &bytes[6], &bytes[7], &bytes[8], &bytes[9], &bytes[10], &bytes[11], &bytes[12], &bytes[13], &bytes[14], &bytes[15], &bytes[16], &bytes[17], &bytes[18], &bytes[19], &bytes[20], &bytes[21], &bytes[22], &bytes[23], &bytes[24], &bytes[25], &bytes[26], &bytes[27], &bytes[28], &bytes[29], &bytes[30], &bytes[31]);
  fclose(file);
  for (y=0; y<16; y++)
    for(x=0; x<=7; x++){
      Table[y][x]  =(unsigned char)(bytes[y]   <<x)>>7;
      Table[y][x+8]=(unsigned char)(bytes[y+16]<<x)>>7;
    }
}

void None(){
  for (int nnx=0; nnx<16; nnx++)
    for (int nny=0; nny<16; nny++)
      Table[nny][nnx]=0;
}
void Fill(){
  for (int nnx=0; nnx<16; nnx++)
    for (int nny=0; nny<16; nny++)
      Table[nny][nnx]=1;
}
void Invert(){
  for (int nnx=0; nnx<16; nnx++)
    for (int nny=0; nny<16; nny++)
      Table[nny][nnx]=1-Table[nny][nnx];
}
void Outline(){
  for (int nnx=0; nnx<16; nnx++)
    Table[nnx][0] = Table[nnx][15] =
    Table[0][nnx] = Table[15][nnx] = 1;
}
