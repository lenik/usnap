#ifndef __PMKDEFS_H
  #include<PmkInc\PmkDefs.h>
#endif

#ifndef __PMKDRAWSHELL_S
  #include<PmkInc\PmkDraw.S>
#endif

#ifndef __DOS_H
  #include<dos.h>
#endif

#ifndef __GRAPHICS_H
  #include<graphics.h>
#endif

#ifndef __ALLOC_H
  #include<alloc.h>
#endif

	class    huge rgbcolor
	  {public:
	     rgbcolor(void);
	     BYTE cr,cg,cb;
	     void setrgbcolor(void);
	     void init(void);
	  };
	  rgbcolor::rgbcolor(void) {this->init();}
void      rgbcolor::setrgbcolor(void)
  {outportb(0x3c8,62);
   outportb(0x3c9,cr);
   outportb(0x3c9,cg);
   outportb(0x3c9,cb);}
void      rgbcolor::init(void)
  {cr=cg=cb=0;}

int  huge switchdir(int dir)
  {return ((4+dir)%8);}

	class    huge char3d
	  {public:
	     char3d(void);
	     int x,y;
	     BYTE fontname,fontsize,fontdir;
	     BYTE horiz,vert,dir,depth;
	     BYTE skip;
	     BYTE c,co;
	     char *st;
	     int getsize(int mode);
	     void draw(void);
	     void init(void);
	  };
	  char3d::char3d(void) {this->init();}
void      char3d::init(void)
  {x=y=fontdir=dir=depth=fontname=horiz=0;
   fontsize=skip=vert=1;
   c=7;co=15;st="";}
int       char3d::getsize(int mode)
  {int tempw,temph;
   textsettingstype textinfo;
   gettextsettings(&textinfo);
   settextstyle(fontname,fontdir,fontsize);
   tempw=textwidth(st);
   temph=textheight(st);
   settextstyle(textinfo.font,textinfo.direction,textinfo.charsize);
   return (mode!=1)?tempw:temph;}
void      char3d::draw(void)
  {int tmp;
   settextjustify(horiz,vert);
   settextstyle(fontname,fontdir,fontsize);
   setcolor(c);
   for(tmp=depth;tmp>=0;tmp-=skip)
     switch(dir)
       {case 0:outtextxy(x-tmp,y-tmp,st);
	       break;
	case 1:outtextxy(x,y-tmp,st);
	       break;
	case 2:outtextxy(x+tmp,y-tmp,st);
	       break;
	case 3:outtextxy(x+tmp,y,st);
	       break;
	case 4:outtextxy(x+tmp,y+tmp,st);
	       break;
	case 5:outtextxy(x,y+tmp,st);
	       break;
	case 6:outtextxy(x-tmp,y+tmp,st);
	       break;
	case 7:outtextxy(x-tmp,y,st);
	       break;
	default:;
       }
     setcolor(co);
     outtextxy(x,y,st);
  }

	class    huge rec2d
	  {public:
	     rec2d(void);
	     int x1,y1,x2,y2,putx,puty;
	     unsigned char bc,c,puttype,thick,putonce:1,f:1;
	     unsigned lt;
	     void init(void);
	     void draw(void);
	  };
	  rec2d::rec2d(void) {this->init();}
void 	  rec2d::init(void)
  {lt=0xffff;
   x1=y1=f=puttype=0;
   x2=y2=32;
   putonce=thick=1;
   putx=puty=33;
   bc=15;
   c=7;}
void      rec2d::draw(void)
  {setlinestyle(4,lt,thick);
   setcolor(bc);
   rectangle(x1,y1,x2,y2);
   if(f)
     {setfillstyle(f,c);
      bar(x1+1,y1+1,x2-1,y2-1);}
  }

void huge get(rec2d far ww,void huge *buf[4])
  {int t1,t2=ww.y1;
   for(t1=0;t1<3;t1++)
     {getimage(ww.x1,t2,ww.x2,t2+(ww.y2-ww.y1)*1/4,buf[t1]);
      t2+=(ww.y2-ww.y1)*1/4+1;}
   getimage(ww.x1,t2,ww.x2,ww.y2,buf[3]);}
void huge put(rec2d far ww,void huge *buf[4])
  {int t1,t2=ww.y1;
   for(t1=0;t1<4;t1++)
     {putimage(ww.putx,(ww.puty-ww.y1)+t2,buf[t1],ww.puttype);
      t2+=(ww.y2-ww.y1)*1/4+1;
      if(ww.putonce)
	farfree(buf[t1]);
     }
  }
unsigned huge getsize(rec2d far ww)
  {return imagesize(ww.x1,ww.y1,ww.x2,ww.y1+(int)(ww.y2-ww.y1)/4+4);}

	class    far  iorec
	  {public:
	     iorec(void);
	     int x1,y1,x2,y2,width,height;
	     unsigned char bc,cl,cd,cb,fl,fd,fb,dir,paint:1,db:1;
	     void init(void);
	     void draw(void);
	     unsigned char get3dcolor(unsigned int place,unsigned char opt);
	  };
	  iorec::iorec(void){this->init();}
void      iorec::init(void)
  {x1=y1=bc=dir=db=paint=0;
   x2=y2=80;
   width=height=5;
   fl=fd=fb=1;
   cl=15;
   cb=7;
   cd=8;}

void      iorec::draw(void)
  {setlinestyle(0,0,1);
   int poly[8],temp;
   if(db)setcolor(bc);
   if(x1>x2)swap(x1,x2,temp);
   if(y1>y2)swap(y1,y2,temp);
   if(!db)setcolor(get3dcolor(getto,getrc));
   setfillstyle(get3dcolor(getto,getrf),get3dcolor(getto,getrc));
   poly[0]=x1;
   poly[1]=poly[3]=y1;
   poly[2]=x2;
   poly[4]=x2-width+1;
   poly[5]=poly[7]=y1+height-1;
   poly[6]=x1+width-1;
   fillpoly(4,poly);
   if(!db)setcolor(get3dcolor(getlo,getrc));
   setfillstyle(get3dcolor(getlo,getrf),get3dcolor(getlo,getrc));
   poly[2]=poly[0];
   poly[3]=y2;
   poly[4]=poly[6]=x1+width-1;
   poly[5]=y2-height+1;
   poly[7]=y1+height-1;
   fillpoly(4,poly);
   if(!db)setcolor(get3dcolor(getbo,getrc));
   setfillstyle(get3dcolor(getbo,getrf),get3dcolor(getbo,getrc));
   poly[0]=x2;
   poly[1]=y2;
   poly[6]=x2-width+1;
   poly[7]=y2-height+1;
   fillpoly(4,poly);
   if(!db)setcolor(get3dcolor(getro,getrc));
   setfillstyle(get3dcolor(getro,getrf),get3dcolor(getro,getrc));
   poly[2]=x2;
   poly[3]=y1;
   poly[4]=x2-width+1;
   poly[5]=y1+height-1;
   fillpoly(4,poly);
   if(paint){setfillstyle(fb,cb);
	     bar(x1+width,y1+height,x2-width,y2-height);
   }
  }
unsigned char iorec::get3dcolor(unsigned int place,unsigned char opt)
  {unsigned char sc1,sc2;
   switch (dir)
    {
     case 0:
       switch(place)
	 {case getlo:
	  case getto:
	  case getri:
	  case getbi:
	    sc1=cl;
	    sc2=fl;
	    break;
	  case getli:
	  case getti:
	  case getro:
	  case getbo:
	    sc1=cd;
	    sc2=fd;
	    break;
	  default:;
	 }
       break;
     case 1:
       switch(place)
	 {case getto:
	  case getbi:
	    sc1=cl;
	    sc2=fl;
	    break;
	  case getti:
	  case getbo:
	    sc1=cd;
	    sc2=fd;
	    break;
	  default:;
	 }
       break;
     case 2:
       switch(place)
	 {case getli:
	  case getto:
	  case getro:
	  case getbi:
	    sc1=cl;
	    sc2=fl;
	    break;
	  case getlo:
	  case getti:
	  case getri:
	  case getbo:
	    sc1=cd;
	    sc2=fd;
	    break;
	  default:;
	 }
       break;
     case 3:
       switch(place)
	 {case getro:
	  case getli:
	    sc1=cl;
	    sc2=fl;
	    break;
	  case getlo:
	  case getri:
	    sc1=cd;
	    sc2=fd;
	    break;
	  default:;
	 }
       break;
     case 4:
       switch(place)
	 {case getli:
	  case getti:
	  case getro:
	  case getbo:
	    sc1=cl;
	    sc2=fl;
	    break;
	  case getlo:
	  case getto:
	  case getri:
	  case getbi:
	    sc1=cd;
	    sc2=fd;
	    break;
	  default:;
	 }
       break;
     case 5:
       switch(place)
	 {case getti:
	  case getbo:
	    sc1=cl;
	    sc2=fl;
	    break;
	  case getto:
	  case getbi:
	    sc1=cd;
	    sc2=fd;
	    break;
	  default:;
	 }
       break;
     case 6:
       switch(place)
	 {case getlo:
	  case getbo:
	  case getti:
	  case getri:
	    sc1=cl;
	    sc2=fl;
	    break;
	  case getli:
	  case getbi:
	  case getto:
	  case getro:
	    sc1=cd;
	    sc2=fd;
	    break;
	  default:;
	 }
       break;
     case 7:
       switch(place)
	 {case getlo:
	  case getri:
	    sc1=cl;
	    sc2=fl;
	    break;
	  case getli:
	  case getro:
	    sc1=cd;
	    sc2=fd;
	    break;
	  default:;
	 }
       default:;
    }
   return (opt==0?sc1:sc2);
  }

	class    far  flatrec
	  {public:
	     flatrec(void);
	     int x1,y1,x2,y2,width,height;
	     unsigned char fb,cb,bc,c,f,paint:1,db:1;
	     void init(void);
	     void draw(void);
	  };
	  flatrec::flatrec(void){this->init();}
void      flatrec::init(void)
  {x1=y1=0;
   x2=y2=80;
   width=height=5;
   fb=f=db=paint=1;
   cb=8;
   c=7;
   bc=15;
  }
void      flatrec::draw(void)
  {if(f)
     {setcolor(c);
      setfillstyle(f,c);
      bar(x1,y1,x2,y1+height);
      bar(x2-width,y1,x2,y2);
      bar(x2,y2-height,x1,y2);
      bar(x1,y2,x1+width,y1);
     }
   if(db)
     {setcolor(bc);
      rectangle(x1,y1,x2,y2);
      rectangle(x1+width-1,y1+height-1,x2-width+1,y2-height+1);
     }
   if(paint)
     {setfillstyle(fb,cb);
      bar(x1+width,y1+height,x2-width,y2-height);
     }
  }

	class    far  rec3d
	  {public:
	     rec3d(void);
	     iorec o,i;
	     flatrec n;
	     unsigned int dir,paint:1,db:1;
	     void init();
	     void draw();
	     void set1(int num,int val);
	  };
	  rec3d::rec3d(void){this->init();}
void      rec3d::init(void)
  {set1(recx1,0);
   set1(recy1,0);
   set1(recx2,o.x2);
   set1(recy2,o.y2);
   n.db=n.paint=0;
   i.dir=switchdir(i.dir);
  }
void      rec3d::draw(void)
  {if(db) n.db=o.db=i.db=1;
   if(paint)
     {o.paint=n.paint=0;
      i.paint=1;}
   o.draw();
   n.draw();
   i.draw();}
void      rec3d::set1(int num,int val)
  {switch(num)
     {case recx1:
	o.x1=val;
	n.x1=o.x1+o.width;
	i.x1=n.x1+n.width;
	break;
      case recy1:
	o.y1=val;
	n.y1=o.y1+o.height;
	i.y1=n.y1+n.height;
	break;
      case recx2:
	o.x2=val;
	n.x2=o.x2-o.width;
	i.x2=n.x2-n.width;
	break;
      case recy2:
	o.y2=val;
	n.y2=o.y2-o.height;
	i.y2=n.y2-n.height;
	break;
      case recwh:
	o.width=n.width=i.width=val;
	break;
      case recht:
	o.height=n.height=i.height=val;
	break;
      case reccl:
	o.cl=i.cl=val;
	break;
      case reccn:
	n.c=val;
	break;
      case reccd:
	o.cd=i.cd=val;
	break;
      case recbc:
	o.bc=i.bc=n.bc=val;
	break;
      case recfl:
	o.fl=i.fl=val;
	break;
      case recfn:
	n.f=val;
	break;
      case recfd:
	o.fd=i.fd=val;
	break;
      case reccx:
	o.x1+=val;
	o.x2+=val;
	n.x1+=val;
	n.x2+=val;
	i.x1+=val;
	i.x2+=val;
	break;
      case reccy:
	o.y1+=val;
	o.y2+=val;
	n.y1+=val;
	n.y2+=val;
	i.y1+=val;
	i.y2+=val;
	break;
      case recdir:
	o.dir=val;
	i.dir=switchdir(val);
	break;
      default:;
     }
  }