#define __Pmk__
#define getm(a,b) for(temp=0;temp<4;temp++) if ((b[temp] = farmalloc(getsize(a)))==NULL) {printf("Not enough memory.\n");exit(1);}get(a,b);
#define putm(a,b) get(a,b);for(temp=0;temp<4;temp++) farfree(b[temp]);
#define __FORPMKDRAWMARGUMENTS__
#include<pmk100.h>
unsigned char huge If,Of;int huge mx,my,gd,gm;void huge *scr1[4],*scr2[4];
rec2d far getput;long far temp,temp1,temp2;
int far song[30000];
mouseclass far pmkm;
void main()
{initsound();readsong("music",song);playsong(-1,song);
 register int temp;rec3d startpagerec;stick3d titlestick;
 sks key;
 char3d title;hz3d prognam;
 init();mx=getmaxx();my=getmaxy();setbkcolor(0);If=Fpmk;Of=Fc;
 startpagerec.x1=startpagerec.y1=5;startpagerec.x2=mx-5;startpagerec.y2=my-100;startpagerec.widtho=startpagerec.heighto=10;startpagerec.widthm=10;startpagerec.heightm=15;startpagerec.widthi=startpagerec.heighti=7;startpagerec.fl=SOLID_FILL;startpagerec.fd=SOLID_FILL;startpagerec.fb=SOLID_FILL;startpagerec.bc=4;startpagerec.db=1;startpagerec.draw();
 titlestick.x=startpagerec.x1+startpagerec.widtho+startpagerec.widthm+startpagerec.widthi+20;titlestick.y=startpagerec.y1+startpagerec.heighto+startpagerec.heightm+startpagerec.heighti+20;titlestick.wl=titlestick.hu=10;titlestick.wr=titlestick.hd=20;titlestick.wm=150;titlestick.hm=40;titlestick.fl=titlestick.fr=titlestick.fu=titlestick.fd=titlestick.fm=1;titlestick.cl=titlestick.cu=15;titlestick.cr=titlestick.cd=8;titlestick.cm=7;titlestick.bc=1;titlestick.db=1;titlestick.draw();
 title.x=titlestick.x+20;title.y=titlestick.y+10;title.horiz=LEFT_TEXT;title.vert=TOP_TEXT;title.fontname=SANS_SERIF_FONT;title.fontdir=HORIZ_DIR;title.fontsize=4;title.c=15;title.co=9;title.depth=5;title.skip=1;title.dir=0;title.st="Pmk100!";title.draw();
 titlestick.x=startpagerec.x2-startpagerec.widtho-startpagerec.widthm-startpagerec.widthi-20;titlestick.y=startpagerec.y1+startpagerec.heighto+startpagerec.heightm+startpagerec.heighti+20;titlestick.wl=-10;titlestick.hu=10;titlestick.wr=-20;titlestick.hd=20;titlestick.wm=-190;titlestick.hm=40;titlestick.fl=titlestick.fr=titlestick.fu=titlestick.fd=titlestick.fm=1;titlestick.cl=titlestick.cu=15;titlestick.cr=titlestick.cd=8;titlestick.cm=7;titlestick.bc=1;titlestick.db=1;titlestick.draw();
 title.x=titlestick.x+titlestick.wr+titlestick.wm+titlestick.wl+30;title.y=titlestick.y+10;title.horiz=LEFT_TEXT;title.vert=TOP_TEXT;title.fontname=SANS_SERIF_FONT;title.fontdir=HORIZ_DIR;title.fontsize=4;title.c=15;title.co=9;title.depth=5;title.skip=1;title.dir=0;title.st="Made:DanSei";title.draw();prognam.x=mx/2-174;prognam.y=titlestick.y+titlestick.hu+titlestick.hm+titlestick.hd+20;prognam.fontsize=48;prognam.string=rname;prognam.c=0;prognam.co=14;prognam.depth=15;prognam.draw();d24(lib24k,rmade,mx/2-70,my-90,9,5);snhz16(eng16[_mh-1],mx/2-12,my-90,9);d24(lib24k,rds,mx/2+12,my-90,9,5);d16(eng16,vern1eng,mx/2-176,my-60,14,0);d16(eng16,vern2eng,mx/2-48,my-60,14,0);d16(eng16,vern3eng,mx/2+48,my-60,14,0);
 pmkm.init();pmkm.maxx=mx;pmkm.maxy=my;pmkm.cursor(knife[0]);
 m3dm mm(5);mm.w.cb=1;mm.it[0].st="System";mm.it[1].st="File";mm.it[2].st="Edit";mm.it[3].st="Config";mm.it[4].st="Translate";mm.it[5].st="Store";mm.set1(set1fn,TRIPLEX_FONT);mm.set1(set1vt,2);mm.set1(set1skp,15);mm.set1(set1fs,3);mm.setxy();mm.set1(set1cy,-5);mm.set1(set1cb,~4);mm.set1(set1cc,~1);mm.draw();mm.run(temp);
 Getch(key);
 cmd3d cmd;cmd.c.st="Command3d";cmd.c.fontname=TRIPLEX_FONT;cmd.c.fontsize=2;cmd.c.depth=5;
 cmd.setxy(stomach);
 cmd.o.bc=14;
 cmd.draw(0);
 while(getch()!=13);
 cmd.draw(1);
 getch();
 stopsong();quitsound();
}
