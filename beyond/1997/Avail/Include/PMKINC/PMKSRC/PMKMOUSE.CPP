  class  huge MouseClass
    {protected:
	     REGS  m_Regs;
	     SREGS m_SRegs;

     public:
       char  m_Button,m_Flag;
       int   m_MouseX,m_MouseY;
       int   m_MouseMinX,m_MouseMinY,m_MouseMaxX,m_MouseMaxY;
       char  m_MouseMovAbsX,m_MouseMovAbsY;

       int  Test(void);
       int  Status(void);

       void Scr(void);

	    MouseClass(void);

       void Init(void);

       void Show(void);
       void Hide(void);

       void Move(int mx,int my);
       void Move(void);

       int  MovAbs(char mx,char my);
       void MovAbs(void);

       void Limit(int minx,int miny,int maxx,int maxy);
       void Limit(void);

       int  Press(int button,int &pcount);
       int  Release(int button,int &rcount);
       int  GetKey(void);
       int  GetKey(long second);

       void Speed(int numx,int numy);

       void Cursor(mc cur);
       void Cursorstr(mcstr cur);
    };

	    MouseClass::MouseClass(void)
	      {this->init();}

  void      MouseClass::Init(void)
    {m_Button=Test();
     m_MouseX=m_MouseY=0;
     m_MouseMinX=m_MouseMinY=m_MouseMaxX=m_MouseMaxY=0;
     this->Scr();
     this->Status();
     this->Show();
     return;}

  void      MouseClass::Show(void)
    {m_Regs.x.ax=1;
     int86(0x33,&m_Regs,&m_Regs);
    }

  void 	    MouseClass::Hide(void)
    {m_Regs.x.ax=2;
     int86(0x33,&m_Regs,&m_Regs);}

  void 	    MouseClass::Move(int mx,int my)
    {m_Regs.x.dx=4;
     m_Regs.x.cx=mx;
     m_Regs.x.dx=my;
     int86(0x33,&m_Regs,&m_Regs);}

  void 	    MouseClass::Move(void)
    {m_Regs.x.dx=4;
     m_Regs.x.cx=x;
     m_Regs.x.dx=m_MouseY;
     int86(0x33,&m_Regs,&m_Regs);}

  int  	    MouseClass::Movabs(char xy)
  {m_Regs.x.ax=0xb;
   int86(0x33,&m_Regs,&m_Regs);
   m_MouseMovAbsX=m_Regs.x.cx;
   m_MouseMovAbsY=m_Regs.x.dx;
   return (((xy=='x')||(xy=='X'))?m_MouseMovAbsX:m_MouseMovAbsY);}

  void 	    MouseClass::Movabs(void)
    {m_Regs.x.ax=0xb;
     int86(0x33,&m_Regs,&m_Regs);
     m_MouseMovAbsX=m_Regs.x.cx;
     m_MouseMovAbsY=m_Regs.x.dx;}

  void      MouseClass::Limit(void)
    {m_Regs.x.ax=7;
     m_Regs.x.cx=m_MouseMinX;
     m_Regs.x.dx=m_MouseMaxX;
     int86(0x33,&m_Regs,&m_Regs);
     m_Regs.x.ax=8;
     m_Regs.x.cx=m_MouseMinY;
     m_Regs.x.dx=m_MouseMaxY;
     int86(0x33,&m_Regs,&m_Regs);}

  void      MouseClass::Limit(int xmin,int ymin,int xmax,int ymax)
    {m_Regs.x.ax=7;
     m_Regs.x.cx=xmin;
     m_Regs.x.dx=xmax;
     int86(0x33,&m_Regs,&m_Regs);
     m_Regs.x.ax=8;
     m_Regs.x.cx=ymin;
     m_Regs.x.dx=ymax;
     int86(0x33,&m_Regs,&m_Regs);}

  int  	    MouseClass::Press(int button,int &pcount)
    {m_Regs.x.ax=5;
     m_Regs.x.bx=button;
     int86(0x33,&m_Regs,&m_Regs);
     pcount=m_Regs.x.bx;
     return m_Regs.x.ax;}

  int  	    MouseClass::Release(int button,int &rcount)
    {m_Regs.x.ax=6;
     m_Regs.x.bx=button;
     int86(0x33,&m_Regs,&m_Regs);
     rcount=m_Regs.x.bx;
     return m_Regs.x.ax;}

  int  	    MouseClass::Getkey(void)
    {int ch;
     while(!kbhit())
      {ch=status();
       if(ch)
	{while(status())
	  ;
	 return ch;}
      }
     return bioskey(0);
    }

  int  	    MouseClass::Getkey(long second)
    {if(second==0L)
      return getkey();
     time_t stime;
     long DIFFTIME;
     stime=time(0);
     int ch=0;
     while(1)
       {if(kbhit())
	 {ch=bioskey(0);
	  break;}
	ch=status();
	if(ch)
	  {while(status())
	    ;
	   break;}
	DIFFTIME=(long)(difftime(time(0),stime));
	if(DIFFTIME>=second)
	  break;
       }
     return ch;
    }

  void 	    MouseClass::Speed(int numx,int numy)
    {m_Regs.x.ax=0xf;
     m_Regs.x.cx=numx;
     m_Regs.x.dx=numy;
     int86(0x33,&m_Regs,&m_Regs);}

  void 	    MouseClass::Cursor(mc cur)
    {m_Regs.x.ax=9;
     m_Regs.x.bx=cur.cx;
     m_Regs.x.cx=cur.cy;
     m_Regs.x.dx=FP_OFF(cur.img);
     m_SRegs.es=FP_SEG(cur.img);
     int86x(0x33,&m_Regs,&m_Regs,&m_SRegs);}

  void 	    MouseClass::Cursorstr(mcstr cur)
    {char *tmp;
     int image[32],temp;
     for(temp=0;temp<32;temp++)
       image[temp]=strtol(cur.img[temp],&tmp,2);
     m_Regs.x.ax=9;
     m_Regs.x.bx=cur.cx;
     m_Regs.x.cx=cur.cy;
     m_Regs.x.dx=FP_OFF(image);
     m_SRegs.es=FP_SEG(image);
     int86x(0x33,&m_Regs,&m_Regs,&m_SRegs);}

//protected:
  int       MouseClass::Test(void)
    {m_Regs.x.ax=0;
     int86(0x33,&m_Regs,&m_Regs);
     if(m_Regs.x.ax==0) return 0;
     Flag=m_Regs.x.bx;
     return m_Regs.x.bx;}

  int       MouseClass::Status(void)
    {m_Regs.x.ax=3;
     int86(0x33,&m_Regs,&m_Regs);
     switch(getvideomode())
       {case 0:
	case 1:
	  m_Regs.x.dx=m_Regs.x.dx/16+1;
	  m_Regs.x.cx=m_Regs.x.cx/8+1;
	  break;
	case 2:
	case 3:
	case 7:
	case 0x82:
	case 0x83:
	  m_Regs.x.dx=m_Regs.x.dx/8+1;
	  m_Regs.x.cx=m_Regs.x.cx/8+1;
	  break;
     }
     m_MouseY=m_Regs.x.dx;
     m_MouseX=m_Regs.x.cx;
     m_Button=m_Regs.x.bx;
     return m_Button;}

  void      MouseClass::Scr(void)
    {switch(getvideomode())
     {case 0:
      case 1:
      case 2:
      case 3:
      case 7:
      case 0x82:
      case 0x83:
	limit(0,0,632,192);
	break;
      case 4:
      case 5:
      case 0x0d:
      case 0x13:
	limit(0,0,319,199);
	break;
      case 6:
      case 0x0a:
      case 0x0e:
      case 0x41:
      case 0x86:
	limit(0,0,639,199);
	break;
      case 0x0f:
      case 0x10:
      case 0x15:
      case 0x1a:
      case 0x2d:
	limit(0,0,639,349);
	break;
      case 0x14:
      case 0x1b:
      case 0x40:
      case 0x42:
      case 0x48:
      case 0x66:
      case 0x78:
      case 0xc0:
      case 0xd0:
	limit(0,0,639,399);
	break;
      case 0x11:
      case 0x12:
      case 0x17:
      case 0x18:
      case 0x1c:
      case 0x25:
      case 0x26:
      case 0x2e:
      case 0x49:
      case 0x50:
      case 0x51:
      case 0x5c:
      case 0x5d:
      case 0x67:
      case 0x73:
      case 0x79:
	limit(0,0,639,479);
	break;
      default:limit(0,0,getmaxx(),getmaxy());
     }
    }