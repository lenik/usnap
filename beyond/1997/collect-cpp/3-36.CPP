#include <graphics.h>
#include <math.h>
#include <conio.h>
void main(){
  int gd=VGA, gm=VGAMED;
  int x,y;
  float pi=3.14159265358979324;
  float al, l, a;
  initgraph(&gd, &gm, "..\\bgi");
  for (int py=20; py<=190; py+=3){
    al=2*pi*(py-20)/360;
    l=pi*sin(al);
    for (a=0; a<=6*pi; a+=pi/7){
      x=600/(6*pi)*a+20;
      y=py+30*sin(al)*sin(a+sin(a)*pi-l);
      if (a==0) moveto(x, y);
      lineto(x, y);
      moveto(x, y);
    }
  }
  getch();
//  closegraph();
}