#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "yumath.h"

#define NULL	0
#define numnodelen	sizeof(struct numnode)
#define oprnodelen	sizeof(struct oprnode)
#define STRLEN	500

struct numnode {
  char ndat[NUM_MAX_LEN];
  struct numnode *next;
} *numstack;
struct oprnode {
  char opdat;
  struct oprnode *next;
} *oprstack;
char inputstr[STRLEN], opbuf[NUM_MAX_LEN], prelist[7][7];
int strp;

void initstack() {
  numstack = (struct numnode *)malloc(numnodelen);
  oprstack = (struct oprnode *)malloc(oprnodelen);
  oprstack->opdat = '%';
  numstack->next = NULL;
  oprstack->next = NULL;
}

void pushnum(char *str) {
  struct numnode *p;
  int i = 0;
  char *c = str;
  p = (struct numnode *)malloc(numnodelen);
  while((*c) != '\0') {
    p->ndat[i++] = *c++;
  } p->ndat[i] = '\0';
  p->next = numstack;
  numstack = p;
}

void popnum(char *str) {
  struct numnode *p;
  int i = 0;
  char *c = str;
  p = numstack;
  if (p->next == NULL) {
    printf("\n Syntax error!\n");
    exit (0);
  }
  while (p->ndat[i] != '\0') {
    *c = p->ndat[i];
    i++;
    c++;
  }
  *c = '\0';
  numstack = numstack->next;
  free(p);
}

void pushopr(char ch) {
  struct oprnode *p;
  p = (struct oprnode *)malloc(oprnodelen);
  p->opdat = ch;
  p->next = oprstack;
  oprstack = p;
}

void popopr(char *ch) {
  struct oprnode *p = oprstack;
  if (p->next == NULL) {
    printf("\nSyntax error!\n");
    exit(0);
  }
  *ch = p->opdat;
  oprstack = p->next;
  free(p);
}

int order(char ch) {
  switch (ch) {
    case '+':
      return 0;
    case '-':
      return 1;
    case '*':
      return 2;
    case '/':
      return 3;
    case '(':
      return 4;
    case ')':
      return 5;
    case '%':
      return 6;
    default:
      printf("\nSyntax error!");
      exit(0);
  }
}

void inputstring() {
  int key;
  int i = 0;
  do {
    printf("%c", key = getch());
    if (key == 0x1b) exit(0);
    if ((key == 8) && (i >= 0)) i--;
    else {
      inputstr[i] = (char)key; i++;
    }
    if (i >= STRLEN) {
      printf("\nString is too long!"); exit (0);
    }
  } while (key != 0x0D);
  if (inputstr[0] == 0x0D) exit(0);
  i--;
  inputstr[i] = '%';
}

void checkinput() {
  int i = 0;
  char ch;
  while (inputstr[i] != '%') {
    ch = inputstr[i];
    if ((ch > 0x27) && (ch < 0x3A) && (ch != 0x2C)) i++;
    else {
      printf("\nSyntax error!\n");
      exit(0);
    }
  }
  if (inputstr[0] == '-')
    if (inputstr[1] < 0x30) {
       printf("\nSynstax error!\n");
       exit(0);
    }
}

void over(int i) {
  if (i >= NUM_LEN) {
    printf("\nNumber too long! \n");
    exit(0);
  }
}

void readstr() {
  char ch = inputstr[strp];
  int i = 0;
  if (ch < 0x30) {
    if ((ch == '-') && (inputstr[strp - 1] == '('))
      if (inputstr[strp + 1] < 0x30) {
	printf("\nSyntax error!");
	exit(0);
      } else {
	opbuf[0] = inputstr[strp];
	strp++;
	i = 1;
	while ((inputstr[strp] >= 0x30) || (inputstr[strp] == '.')) {
	  opbuf[i] = inputstr[strp]; strp++; i++;
	  over(i);
	}
	opbuf[i] = '\0';
      }
    else {
      while ((inputstr[strp] >= 0x30) || (inputstr[strp] == '.')) {
	opbuf[i] = inputstr[strp];
	strp++;
	i++;
	over(i);
      }
      opbuf[i] = '\0';
    }
  }
}

char *operate(char *an, char *bn, char ch) {
  char *res;
  switch (ch) {
    case '+':
      res = add(an, bn);
      break;
    case '-':
      res = sub(an, bn);
      break;
    case '*':
      res = mul(an, bn);
      break;
    case '/':
      res = div(an, bn);
      break;
    default:
      printf("\nSyntax error!\n");
      exit(0);
  }
  return res;
}

void mainctrl() {
  int i;
  char cp, ch[1], an[NUM_MAX_LEN], bn[NUM_MAX_LEN];
  initstack();
  do {
    i = 0;
    strp = 0;
    inputstring();
    while (inputstr[i] != '\0') i++;
    inputstr[i] = '%';
    i = 0;
    checkinput();
    if (inputstr[0] == '-') {
      opbuf[0] = '-'; strp++; i++;
    }
    while ((inputstr[strp] >= 0x30) || (inputstr[strp] == '.')) {
      opbuf[i] = inputstr[strp];
      strp++;
      i++;
      over(i);
    }
    opbuf[i] = '\0';
    if (inputstr[0] == '(') {
      opbuf[i] = '(';
      i++;
      strp++;
      opbuf[i] = '\0';
    }
    while (!((opbuf[0] == '%') && (oprstack->opdat == '%'))) {
      if (!((opbuf[0] < 0x30) && (opbuf[1] == '\0'))) {
	pushnum(opbuf);
	readstr();
      } else
	switch (prelist[order(oprstack->opdat)][order(opbuf[0])]) {
	  case '<':
	    pushopr(opbuf[0]); readstr(); break;
	  case '=':
	    popopr(ch); readstr(); break;
	  case '>':
	    popopr(ch); popnum(bn); popnum(an);
	    pushnum(operate(an, bn, ch[0])); break;
	  case '*':
	    printf("\nSyntax error!");
	    exit(0);
	}
    }
    printf("\n=%s\n", numstack->ndat);
  } while (1);
}

main(int argc, char *argv[]) {
  int i, j;
  FILE *fp;
  char con[] = "/?";
  if (argc > 1) if (!strcmp(argv[1], con)) {
    printf("BC function: Calcuate!\n");
    printf("Usage: type BC & return in DOS prompt! ESC-exit!\n");
    printf("For example : -12.02 + 22 * (-23.1 + (-1.00009)) / 5.100\n");
    exit(0);
  }
  else {
    printf("Error! have not parameter! Press/?\n");
    exit(0);
  }
  for (i = 0; i < 7; i++)
    for (j = 0; j < 7; j++)
      prelist[i][j] = fgetc(fp) - 0xBF;
  mainctrl();
}
