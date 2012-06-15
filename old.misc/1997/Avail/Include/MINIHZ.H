/* Warning:
    BESURE The string[] used in dnn functions, the elements of string[]
    must more 1 then the index of element of wlib[][]
*/
#ifndef __MINIHZ_H
void snhz16(unsigned char far a[32],int xx,int yy,unsigned char cc)
{register unsigned char dr;
 setcolor(cc);
 for(dr=0;dr<=15;dr++)
  {setlinestyle(4,a[dr*2],1);line(xx+15,yy+dr,xx,yy+dr);
   setlinestyle(4,a[dr*2+1],1);line(xx+23,yy+dr,xx+8,yy+dr);}
}
void d16(unsigned char far wlib[][32],char far string[],int xx,int yy,int cc,int skip)
{register int p;
 for(p=0;p<strlen(string);p++)snhz16(wlib[string[p]-1],xx+(16+skip)*p,yy,cc);
}
#endif
