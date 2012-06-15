#define lo(f) ((f)&0xff)
#define hi(f) (lo(f>>8))
int lookkey(int *k);char getkey(int *k);char getkeyc(void);
void beep(void);
void gotoxyabs(char x,char y);
void setcursor(int ctop,int cbot);
int lookkey(int *k)
{union REGS regs;
 regs.h.ah=1;
 int86(0x16,&regs,&regs);
 *k=regs.x.ax;
 if(regs.x.flags&0x0040) return (0);
 else return(1);
}
char getkey(int *k)
{union REGS regs;
 regs.h.ah=0;
 int86(0x16,&regs,&regs);
 *k=regs.x.ax;
 if(lo(*k)==3) exit(1);
 return regs.h.al;
}
char getkeyc(void)
{char c;int k;
 for(;((c=getkey(&k))==0););
 return c;
}
void beep(void)
{sound(750);delay(200);nosound();}
void gotoxyabs(char x,char y)
{union REGS regs;
 regs.h.ah=2;
 regs.h.bh=0;
 regs.h.dh=y;regs.h.dl=x;
 int86(0x10,&regs,&regs);
}
void setcursor(int ctop,int cbot)
{union REGS regs;
 if(cbot>13)cbot=13;
 if(ctop<0)ctop=0;
 if(ctop==0||cbot==0)
 regs.h.ch=0x20;
 else
 {regs.h.ch=ctop;regs.h.cl=cbot;}
 regs.h.ah=1;int86(0x10,&regs,&regs);
}
