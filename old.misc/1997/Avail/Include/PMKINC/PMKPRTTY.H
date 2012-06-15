#ifndef __PMKPRETTY_H
 #define __PMKPRETTY_H

  void arcrectangle(int x1,int y1,int x2,int y2,int r)
  {
   line(x1+r,y1,x2-r,y1);ellipse(x1+r,y1+r,90,180,r,r);
   line(x2,y1+r,x2,y2-r);ellipse(x2-r,y1+r,0,90,r,r);
   line(x2-r,y2,x1+r,y2);ellipse(x2-r,y2-r,270,360,r,r);
   line(x1,y2-r,x1,y1+r);ellipse(x1+r,y2-r,180,270,r,r);}

  //lefttop>rightbottom:
  //    |                      |
  //   /------------------------\
  // -- +                      + --
  //    |                      |
  //    |                      |
  // -- |                      | --
  //   \------------------------/
  //    |                      |


#endif
