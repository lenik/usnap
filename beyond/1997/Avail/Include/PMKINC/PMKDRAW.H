#ifndef __PMKDRAW_H
	#define __PMKDRAW_H

	#ifdef  __FORPMKDRAWMARGUMENTS__
	 extern int huge mx,my,gd,gm;extern long huge temp,temp1,temp2;
	#else
	 int huge mx,my,gd,gm;long huge temp,temp1,temp2;
	#endif

	#if !defined(__STDLIB_H)
	  #include<stdlib.h>
	#endif

	#if !defined(__GRAPHICS_H)
	  #include<graphics.h>
	#endif

	#if !defined(__STRING_H)
	  #include<string.h>
	#endif

	#if !defined(__CONIO_H)
	  #include<conio.h>
	#endif

	#if !defined(__STDIO_H)
	  #include<stdio.h>
	#endif

	#if !defined(__ALLOC_H)
	  #include<malloc.h>
	#endif

	#if !defined(__PMKINITIALIZES_H)
	  #include<PmkInc\PmkInit.h>
	#endif

	#if !defined(__PMKDRAW_SHELL)
	  #include<PmkInc\PmkDraw.s>
	#endif

	class    huge rgbcolor
	  {public:
	     rgbcolor(void);
	     BYTE cr,cg,cb;
	     void setrgbcolor(void);
	     void init(void);
	  };

	int      huge switchdir(int dir);

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

	class    huge rec2d
	  {public:
	     rec2d(void);
	     int x1,y1,x2,y2,putx,puty;
	     unsigned char bc,c,puttype,thick,putonce:1,f:1;
	     unsigned lt;
	     void init(void);
	     void draw(void);
	  };

	void     huge get(rec2d far ww,void huge *buf[4]);
	void     huge put(rec2d far ww,void huge *buf[4]);

	unsigned huge getsize(rec2d far ww);

	class    far  iorec
	  {public:
	     iorec(void);
	     int x1,y1,x2,y2,width,height;
	     unsigned char bc,cl,cd,cb,fl,fd,fb,dir,paint:1,db:1;
	     void init(void);
	     void draw(void);
	     unsigned char get3dcolor(unsigned int place,unsigned char opt);
	  };

	class    far  flatrec
	  {public:
	     flatrec(void);
	     int x1,y1,x2,y2,width,height;
	     unsigned char fb,cb,bc,c,f,paint:1,db:1;
	     void init(void);
	     void draw(void);
	  };

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

	/*
	class    huge cmd3d{
	  public:cmd3d(void){init();};
		 int x,y,pre,fol,pcx,pcy,run(int &ret);
		 rec3d b;char3d c;rec2d o;
		 void init(void),setxy(int mode),draw(int mode);};
	void          cmd3d::init(void){pre=fol=10;o.bc=15;o.f=0;b.x1=b.y1=pcx=pcy=1;
				     setxy(0);}
	void          cmd3d::setxy(int mode){if(mode){b.x2=b.x1+b.widtho*2+b.widthm*2+b.widthi*2+pre+c.getsize(0)+fol;b.y2=b.y1+b.heighto*2+b.heightm*2+b.heighti*2+pre+c.getsize(1)+fol;}
					      else{b.x2=b.x1+b.widtho*2+pre+c.getsize(0)+fol;b.y2=b.y1+b.heighto*2+pre+c.getsize(1)+fol;b.widthi=b.heighti=b.widthm=b.heightm=0;b.paint=1;b.cb=b.cn;}o.x1=b.x1-1;o.y1=b.y1-1;o.x2=b.x2+1;o.y2=b.y2+1;c.x=b.x1+pre;c.y=b.y1+pre;}
	void          cmd3d::draw(int mode){
	if(mode){b.dir=(b.dir+4)%8;
		 b.x1+=pcx;
		 b.y1+=pcy;
		 b.x2+=pcx;
		 b.y2+=pcy;}
		 o.draw();b.draw();
		 c.draw();
	if(mode){b.dir=(b.dir+4)%8;b.x1-=pcx;b.y1-=pcy;b.x2-=pcx;b.y2-=pcy;}
	}
	*/

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

	class    huge m3dm
	  {public:
	     m3dm(int num);
	     int pre,fol,*skip,on,n;
	     int run(int &ret);
	     rec3d w;
	     char3d *it;
	     rec2d *cur;
	     void init(void);
	     void setxy(void);
	     void set1(int num,int val);
	     void draw(void);
	  };
	void	      m3dm::m3dm(int num=5)
	  {n=num;
	   init();};
	void          m3dm::init(void)
	  {int temp;
	   pre=fol=2;
	   on=0;
	   w.o.width=w.n.width=w.i.width=w.o.height=w.n.height=w.i.height=1;
	   w.set1(recx1,0);
	   w.set1(recx2,50);
	   w.set1(recy1,0);
	   w.set1(recy2,50);
	   for(temp=0;temp<=n;temp++)
	     {cur[temp].f=1;
	      it[temp].init();
	      skip[temp]=10;}
	  }
	void          m3dm::setxy(void)
	  {int temp,size,ts=0,h=pre;
	   for(temp=0;temp<=n;temp++)
	     {it[temp].y=w.o.y1+w.o.height+w.n.height+w.i.height+pre;
	      it[temp].x=w.o.x1+w.o.width+w.n.width+w.i.width+h;
	      h+=it[temp].getsize(0)+skip[temp];
	      size=it[temp].getsize(1);
	      ts=(ts<size)?size:ts;
	      cur[temp].x1=cur[temp].putx=it[temp].x;
	      cur[temp].y1=cur[temp].puty=it[temp].y;
	      cur[temp].x2=it[temp].x+it[temp].getsize(0);
	      cur[temp].y2=it[temp].y+it[temp].getsize(1);
	     }
	   w.set1(recy2,w.o.y1+w.o.height*2+w.n.height*2+w.i.height*2+ts+fol);
	   w.set1(recx2,it[n].x+it[n].getsize(0)+fol+w.i.width+w.n.width+w.o.width);
	  }

	void          m3dm::set1(int num,int val)
	  {int temp;
	   for(temp=0;temp<=n;temp++)
	     switch(num)
	       {case m3d1cx :it[temp].x+=val;break;
		case m3d1cy :it[temp].y+=val;break;
		case m3d1fn :it[temp].fontname=val;break;
		case m3d1fs :it[temp].fontsize=val;break;
		case m3d1dir:it[temp].dir=val;break;
		case m3d1dep:it[temp].depth=val;break;
		case m3d1skp:it[temp].skip=val;break;
		case m3d1c  :it[temp].c=val;break;
		case m3d1hz :it[temp].co=val;break;
		case m3d1x1 :it[temp].horiz=val;break;
		case m3d1vt :it[temp].vert=val;break;
		case m3d1x1 :cur[temp].x1+=val;break;
		case m3d1y1 :cur[temp].y1+=val;break;
		case m3d1x2 :cur[temp].x2+=val;break;
		case m3d1y2 :cur[temp].y2+=val;break;
		case m3d1px :cur[temp].putx+=val;break;
		case m3d1py :cur[temp].puty+=val;break;
		case m3d1cc :cur[temp].c=val;break;
		case m3d1cb :cur[temp].bc=val;break;
		case m3d1cf :cur[temp].f=val;
		default:;
	       }
	  }

	void          m3dm::draw(void)
	  {int temp;
	   w.draw();
	   for(temp=0;temp<=n;temp++)
	     it[temp].draw();
	  }

	int           m3dm::run(int &ret)
	  {int key;
	   void huge *ct1[4],huge *ct2[4];
	   getm(cur[on],ct1);
	   cur[on].draw();
	   getm(cur[on],ct2);
	   cur[on].puttype=COPY_PUT;
	   cur[on].putonce=1;
	   put(cur[on],ct1);
	   cur[on].puttype=XOR_PUT;
	   cur[on].putonce=0;
	   put(cur[on],ct2);
	   key=getch();
	   while(key!=13)
	     {cur[on].putonce=1;
	      put(cur[on],ct2);
	      switch (key)
		{case 0:key=getch();
			switch(key)
			  {case 72:
			   case 75:
				   on=(on>0)?on-1:0;
				   break;
			   case 77:
			   case 80:
				   on=(on<n)?on+1:n;
				   default:;
			  }
			break;
		 case '8':
		 case '4':
			on=(on>0)?on-1:0;
			break;
		 case '6':
		 case '2':
			on=(on<n)?on+1:n;
			default:;
		}
	      getm(cur[on],ct1);
	      cur[on].draw();
	      getm(cur[on],ct2);
	      cur[on].puttype=COPY_PUT;
	      put(cur[on],ct1);
	      cur[on].puttype=XOR_PUT;
	      cur[on].putonce=0;
	      put(cur[on],ct2);
	      key=getch();
	     }
	   ret=on;
	   return on;
	  }

	/*
	class    huge m3dr{public:m3dr(int num=5){n=num;init();};int pre,fol,skip[100],on,n,run(int &ret);rec3d w;char3d it[100];rec2d cur[100];void init(void),setxy(void),set1(int num,int val),draw(void);};
	void          m3dr::init(void){int temp;pre=fol=2;on=0;w.o.width=w.n.width=w.i.width=w.o.height=w.n.height=w.i.height=1;w.set1(recx1,0);w.set1(recx2,50);w.set1(recy1,0);w.set1(recy2,50);for(temp=0;temp<=n;temp++){cur[temp].f=1;it[temp].init();skip[temp]=5;}}
	void          m3dr::setxy(void){int temp,size,ts=0,h=pre;for(temp=0;temp<=n;temp++){it[temp].x=w.o.x1+w.o.width+w.n.width+w.i.width+pre;it[temp].y=w.o.y1+w.o.height+w.n.height+w.i.height+h;h+=it[temp].getsize(1)+skip[temp];size=it[temp].getsize(0);ts=(ts<size)?size:ts;cur[temp].x1=cur[temp].putx=it[temp].x;cur[temp].y1=cur[temp].puty=it[temp].y;cur[temp].x2=it[temp].x+it[temp].getsize(0);cur[temp].y2=it[temp].y+it[temp].getsize(1);}w.set1(recx2,w.o.x1+w.o.width*2+w.n.width*2+w.i.width*2+ts+fol);w.set1(recy2,it[n].y+it[n].getsize(1)+skip[n]+fol+w.i.height+w.n.height+w.o.height);}
	void          m3dr::set1(int num,int val){int temp;for(temp=0;temp<=n;temp++)switch(num){case 0:it[temp].x+=val;break;case 1:it[temp].y+=val;break;case 2:it[temp].fontname=val;break;case 3:it[temp].fontsize=val;break;case 4:it[temp].dir=val;break;case 5:it[temp].depth=val;break;case 6:it[temp].skip=val;break;case 7:it[temp].c=val;break;case 8:it[temp].co=val;break;case 9:it[temp].horiz=val;break;case 10:it[temp].vert=val;break;case 11:cur[temp].x1+=val;break;case 12:cur[temp].y1+=val;break;case 13:cur[temp].x2+=val;break;case 14:cur[temp].y2+=val;break;case 15:cur[temp].putx+=val;break;case 16:cur[temp].puty+=val;break;case 17:cur[temp].c=val;break;case 18:cur[temp].bc=val;break;case 19:cur[temp].f=val;default:;}}
	void          m3dr::draw(void){int temp;w.draw();for(temp=0;temp<=n;temp++)it[temp].draw();}
	int           m3dr::run(int &ret){int key;void huge *ct1[4],huge *ct2[4];getm(cur[on],ct1);cur[on].draw();getm(cur[on],ct2);cur[on].puttype=COPY_PUT;cur[on].putonce=1;put(cur[on],ct1);cur[on].puttype=XOR_PUT;cur[on].putonce=0;put(cur[on],ct2);key=getch();while(key!=13){cur[on].putonce=1;put(cur[on],ct2);switch (key){case 0:key=getch();switch(key){case 72:case 75:on=(on>0)?on-1:0;break;case 77:case 80:on=(on<n)?on+1:n;default:;}break;case '8':case '4':on=(on>0)?on-1:0;break;case '6':case '2':on=(on<n)?on+1:n;default:;}getm(cur[on],ct1);cur[on].draw();getm(cur[on],ct2);cur[on].puttype=COPY_PUT;put(cur[on],ct1);cur[on].puttype=XOR_PUT;cur[on].putonce=0;put(cur[on],ct2);key=getch();}ret=on;return on;}
	*/

#endif
