  int    huge GetVideoMode(void)
    {union REGS regs;
     regs.h.ah=0x0f;
     int86(0x10,&regs,&regs);
     return regs.h.al;}
  int    huge IsTextGraphics(void)
    {int ch=getvideomode();
     if(ch==0||ch==1||ch==2||ch==3||ch==7||ch==82||ch==83)
       return 0;
     return 1;}
