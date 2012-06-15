#include<stdio.h>
#include<CLInc\CVar.h>

void main()
{CVAR *myc=new CVAR("Hello",100);
 CVAR ex;

 AddVarName(myc,"World");
 ex.VarType='C';strncpy(ex.VarVC,"DanSei",7);
 SetVarVal (myc,ex);

 strncpy(ex.CName,"Hello",6);
 GetVarVal(myc,ex);
 printf("%lf\n",ex.VarVN);

 strncpy(ex.CName,"World",6);
 GetVarVal(myc,ex);
 printf("%s\n",ex.VarVC);
}