// Expression
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <alloc.h>
#include "stringa.cpp"
#include "numstr.cpp"

enum _CalcExpError{
  CalcOK=0,
  DivideZero,
  Over,
  ParanthesesLeftGreat,
  ParanthesesRightGreat,
  UndefinedVar,
  UndefinedFunc
}CalcExpError;

char* CalcExp(char **ExpSrc){
  CalcExpError=CalcOK;
  char *Exp, *SwapExp, *LastExp;
  Exp=new char[strlen(*ExpSrc)+50];
  strcpy(Exp, (*ExpSrc));
  // calc (exp)
  if (strchrn(Exp, '(')!=strchrn(Exp, ')')) {
    if (strchrn(Exp, '(')>strchrn(Exp, ')')) CalcExpError=ParanthesesLeftGreat;
    else CalcExpError=ParanthesesRightGreat;
    return NULL;
  }
  if (strchrn(Exp, '('))
  for (unsigned int pp=0; pp<strlen(Exp); pp++){
    if (Exp[pp]=='('){
      int matchcount=-1;
      for (unsigned int subp=pp+1; subp<strlen(Exp); subp++){
	if (Exp[subp]=='(') matchcount--;
	else if (Exp[subp]==')') matchcount++;
	if (!matchcount) {
	  char *SubExp=new char[subp-pp];
	  for (unsigned int pmatchcopy=pp+1; pmatchcopy<=subp-1; pmatchcopy++)
	    SubExp[pmatchcopy-(pp+1)]=Exp[pmatchcopy];
	  SubExp[subp-pp-1]=0;
	  delete SubExp;
	  CalcExp(&SubExp);
	  if (!SubExp) return NULL; //Return CalcExpError
	  strchg(&Exp, pp, subp-pp+1, SubExp);
	  delete SubExp;
	  pp+=strlen(SubExp)-1;
	  break;
	}//!matchcount
      }//Replace a subexp
      continue;
    }//'('

    // char *SimpleCalc (char *exp){
    //if strstr (Exp, "*")

    // }

  }//Scan exp
  (*ExpSrc)=Exp;
  return Exp;
}

void main(){
  char *kkk;
  long aa;
  kkk=new char[300];
  aa=coreleft();
  kkk="1.2(4(*33-)3(    ) )56";
  CalcExp(&kkk);
  aa=coreleft();
  aa=coreleft();
  printf("%s\n", kkk);
  if(!getch()) getch();
}