#include "stdio.h"
#include "stdlib.h"
#define SUCCESS 1
#define FAILED -1
#define INIT_SIZE 5
#define ADDNODE 1
#include "math.h"

typedef struct element_st{
    int data;
   }ELEMENT;

typedef struct slist_st{
    ELEMENT *element;
    int size;
    int length;
   }SLIST;
SLIST *list=NULL;

typedef long (*lookupproc)(ELEMENT *);

/*   (1)   */

int InitSList(SLIST *list)
  {
  /* if((list->element=(ELEMENT *)calloc(INIT_SIZE , sizeof(ELEMENT))==NULL))*/
   list->element=(ELEMENT *)calloc(INIT_SIZE, sizeof(ELEMENT));
   if(list->element==NULL)
     return FAILED;
   else
     {
     /* list=(SLIST*)list->element;*/
      list->size=INIT_SIZE;
      list->length=0;
      return SUCCESS;
     }
  }

/*   (2)   */

int FreeSList(SLIST *list)
  {
   if(list!=NULL && list->element!=NULL)
     {
      free(list->element);
      list->length=0;
      list->size=0;
      return SUCCESS;
     }
   else
     return FAILED;
  }

/*  (3)   */

int GetSListLength(SLIST *list)
  {
   if(list!=NULL)
     return list->length;
   else
     return FAILED;
  }


int Equal(ELEMENT, ELEMENT );
/*   (4)   */

int FindElement(SLIST *list,ELEMENT elem)
  {int i;
   for(i=0;i<list->length;i++)
     if(Equal(list->element[i],elem)==SUCCESS)
       return i++;
   return FAILED;
 }

/*   (5)    */

int InsertElement(SLIST *list,int position,ELEMENT elem)
  {ELEMENT *tmplist;int i;
   if(position<1||position>list->length+1)
     return FAILED;
   if(list->length==list->size)
     {
      tmplist=(ELEMENT *)realloc(list->element,(list->size+ADDNODE) * sizeof(ELEMENT));
      if(tmplist==NULL)
	return FAILED;
      list->element=tmplist;
      list->size=list->size+ADDNODE;
     }
   list->length++;
   for(i=list->length-1;i>=position-1;i--)
     list->element[i+1]=list->element[i];
   list->element[position-1]=elem;
   return SUCCESS;
 }

/*   (6)   */

int DeleteElement(SLIST *list,int position,ELEMENT *elem)
  {int i;
   if(position<1||position>list->length)
     return FAILED;
   list->length--;
   *elem=list->element[position-1];
   for(i=position;i<list->length;i++)
     list->element[i-1]=list->element[i];
   return SUCCESS;
  }

/*   (7)   */

int GetElement(SLIST *list,int position,ELEMENT *elem)
  {
   if(position<1||position>list->length)
     return FAILED;
   *elem=list->element[position-1];
   return SUCCESS;
  }

/*   (8)   */

int GetPriorElement(SLIST *list, ELEMENT elem,ELEMENT *prior)
  {int pos;
   pos=FindElement(list,elem);
   if(pos==FAILED)
     return FAILED;
   if(pos==1)
     return FAILED;
   *prior=list->element[pos-2];
   return SUCCESS;
 }

 /*   (9)   */

int GetNextElement(SLIST *list,ELEMENT elem,ELEMENT *next)
  {int pos;
   pos=FindElement(list,elem);
   if(pos==FAILED)
     return FAILED;
   if(pos==list->length)
     return FAILED;
   *next=list->element[pos];
   return SUCCESS;
 }

/*   (10)   */

int TraverseSList(SLIST *list,lookupproc lookup)
  {int i;
   if(list==NULL)
     return FAILED;
   for(i=0;i<list->length;i++)
    {
     lookup(list->element);
     (list->element)++;
    }
   return SUCCESS;
  }

/*	(11)	*/

long out(ELEMENT *list)
{  if(list==NULL)
	return FAILED;
  // @2-1 : drop while{}
  // @2-2 : %ld--> long
  //	    %d --> int
printf("%d ",list->data);
}

/*   (12)    	*/

int Equal(ELEMENT elem2,ELEMENT elem)
{}
/*	main	*/


main()
{ int i,j,k,position;
  lookupproc lookup;
  void *p;
  p = (void *)(void (*)())(lookupproc)lookup;

  ELEMENT elem, * element1=NULL, * element2=NULL;
  SLIST *list1=NULL,*tmplist=NULL;

  // @1:
  list = (SLIST *)calloc(1, sizeof(SLIST));
  if(InitSList(list)) {
	for(i=0;i<INIT_SIZE;i++){
		scanf("%d",&elem.data);
/*		scanf("%d",&elem.date);*/
		InsertElement(list,i+1,elem);
	}
/*   for(i=0;i<INIT_SIZE;i++)
    {
     printf("%d",list->element->data);
     (list->element)++;
    }
*/

    lookup=out;
    TraverseSList(list,lookup);
 }
}

// CALLBACK
/*

	int f1() {
		printf("Hello\n");
	}
	int f2() {
		printf("World\n");
	}
	typedef int (*FPROC)();			-----
	main() {                                main() {
		FPROC f;                                int (*f)();
		f = f1;                                 f = &f1;
		f();                                    (*f)();
		f = f2;                                 f = &f2;
		f();                                    (*f)();
	}                                       }
*/

//						int (*)();
