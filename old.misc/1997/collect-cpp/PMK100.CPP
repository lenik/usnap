#define __Pmk__
#include<PmkInc\PmkLoad.h>

unsigned char huge If,Of;int huge mx,my,gd,gm;void huge *scr1[4],*scr2[4];
rec2d far getput;long far temp,temp1,temp2;

void main()
{
 buildbgi();buildchr();
 init();
 mx=getmaxx();my=getmaxy();setbkcolor(0);
 int temp;
 cleardevice();

 rec3d sp;

 sp.o.width=sp.o.height=10;
 sp.n.width=10;
 sp.n.height=15;
 sp.i.width=sp.i.height=7;
 sp.set1(recx1,5);
 sp.set1(recy1,5);
 sp.set1(recx2,mx-5);
 sp.set1(recy2,my-100);
 sp.i.bc=sp.o.bc=sp.n.bc=4;
 sp.i.db=sp.o.db=sp.n.db=0;
 sp.db=0;
 sp.draw();
 getch();
 rec3d startpagerec;iorec titlestick;
 sks key;
 char3d title;
 hz3d prognam;
 If=Fpmk;Of=Fc;

 startpagerec.o.width=startpagerec.o.height=10;startpagerec.n.width=10;startpagerec.n.height=15;startpagerec.i.width=startpagerec.i.height=7;startpagerec.set1(recfl,SOLID_FILL);startpagerec.set1(recfd,SOLID_FILL);startpagerec.i.fb=SOLID_FILL;startpagerec.o.bc=startpagerec.n.bc=startpagerec.i.bc=4;startpagerec.db=1;
 startpagerec.o.x1=startpagerec.o.y1=5;startpagerec.o.x2=mx-5;startpagerec.o.y2=my-100;
 startpagerec.draw();

 m3dm mm(1);mm.w.i.cb=1;
 mm.it[0].st="System";mm.it[1].st="File";
 mm.it[2].st="Edit";mm.it[3].st="Config";mm.it[4].st="Translate";mm.it[5].st="Store";
 mm.set1(m3d1fn,TRIPLEX_FONT);
 mm.set1(m3d1vt,2);
 mm.set1(m3d1skp,15);
 mm.set1(m3d1fs,3);
 mm.setxy();
 mm.set1(m3d1cy,-5);
 mm.set1(m3d1cb,~7);
 mm.set1(m3d1cc,~1);
 mm.draw();
 mm.run(temp);
 printf("Coreleft: %lu\n",(unsigned long)coreleft());
 getch();
}
