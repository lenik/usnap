#include<string.h>
#include<ctype.h>
#include<Math.h>
  void   far linksc(char   far*des,char far src)
    {*(des+_fstrlen(des))=src;
     *(des+_fstrlen(des)+1)='\x0';}
  char   far *radix(char   far*s,unsigned char far sn,unsigned char far dn)
    {char *tran="0123456789abcdefghijklmnopqrstuvwxyz!@#$%^&*()";
     char *point=s,dv[100]="";
     long pointn,count,count1,sv=0;
     for(count=0;count<_fstrlen(s);count++)
       {for(count1=0;count1<_fstrlen(tran);count1++)
	 if(*(tran+count1)==tolower(*(point+count)))
	   pointn=count1;
	sv=sv+pointn*pow(sn,_fstrlen(s)-1-count);}
     for(count=sv;count!=0;(linksc(dv,*(tran+count%dn)),count=count/dn));
     strrev(dv);
     return dv;}
  long   far  radix(char   far*s,unsigned char far sn)
    {char *tran="0123456789abcdefghijklmnopqrstuvwxyz!@#$%^&*()";
     char *point=s;
     long pointn,count,count1,sv=0;
     for(count=0;count<_fstrlen(s);count++)
       {for(count1=0;count1<_fstrlen(tran);count1++)
	 if(*(tran+count1)==tolower(*(point+count)))
	   pointn=count1;
	sv=sv+pointn*pow(sn,_fstrlen(s)-1-count);}
     return sv;}
  double far middle(double far a,double far b)
    {return ((a+b)/2);}
  double far   baby(double far a,double far b)
    {return (a>b)?a-b+1:b-a+1;}
