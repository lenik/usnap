#include<_defs.h>
#include<_null.h>
//#include<stdio.h>
extern "C" {
	int cdecl scanf(const char _FAR *__format, ...);
	int cdecl printf(const char _FAR *__format, ...);
      }

struct n
  {int data;
   n *point;
  };

void main()
{n *p1,*p2,*p3;
 p2->point=NULL;
 do
 {p1=new n;
  p1->point=p2->point;
  scanf("%d",&p1->data);
  p2->point=p1;
 }while(p1->data!=-1);
// p3=p1;
 do
 {p1=p1->point;
  printf("\t%d\t\t%d\n",p3->data,p1->data);
  //p3=p3->point;
 }while(p1!=NULL);
}