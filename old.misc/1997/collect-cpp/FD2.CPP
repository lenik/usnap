#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <dir.h>

#define MAXFND	16
struct diritem{
  char *name;
  struct diritem *p, *n;
  diritem(int length);
  diritem(char *inits);
  ~diritem();
};

char *pszEvery = "*.*";
int pnum = 5;

int csub(char a, char b);
void strc(char *s, char c);
int cdir(diritem *d);
void add(diritem *o, diritem *s);
diritem *del(diritem *o);
void clrall(diritem **t);
void swapdiritem(diritem **a, diritem **b);
int cmpdiritem(diritem *a, diritem *b);
void sortdir(diritem **t);
diritem *cpoint(diritem *s, char *ref);
diritem *getdir(diritem **t, char *sname = pszEvery);
int chdirx(char *path);
void usage();
void outd(diritem *d);

int main(int argc, char **argv) {
  char *sname;
  diritem *d = NULL;
  char fnd[MAXFND + 1], buf[MAXPATH + 1];
  int k;
  char *keytbl = "qwertyuiop....asdfghjkl.....zxcvbnm";	// from 0x10

  if (argc >= 2 && strcmp(argv[1], "/?") == 0) {
    usage();
    return 0;
  }

  if (argc < 2) { sname = "*.*"; } else { sname = argv[1]; }
  fnd [0] = '\0';

  getdir(&d, sname);
  if (d == NULL) {
    getdir(&d);
    if (d == NULL) { return 1; }
    strcpy(fnd, sname);
  }

  if (cdir(d) == 1) {
    chdirx(sname);
    clrall(&d);
    return 0;
  }

  for (;;) {
    d = cpoint(d, fnd);
    outd(d);
    k = getch();
    switch (k) {
      case 0:
	int c = pnum;
	k =  getch();
	switch (k) {
	  case 'H': if (d->p != NULL) { d = d->p; } break;	// left
	  case 'P': if (d->n != NULL) { d = d->n; } break;  	// right
	  case 'K':	// up
	  case 'M':	// down
	    chdirx(k == 'K' ? ".." : d->name);
	    clrall(&d);
	    getdir(&d); if (d == NULL) { return 1; }
	    break;
	  case 'G': while (d->p != NULL) { d = d->p; } break;	// home
	  case 'O': while (d->n != NULL) { d = d->n; } break;	// end
	  case 'I':	// pgup
	    while (d->p != NULL && c-- > 0) { d = d->p; }
	    break;
	  case 'Q':	// pgdn
	    while (d->n != NULL && c-- > 0) { d = d->n; }
	    break;
	  case 'R':	// insert
	    printf("create: ");
	    if (mkdir(gets(buf)) == 0) { add(d, new diritem(buf)); }
	    break;
	  case 'S':	// delete
	    if (rmdir(d->name) == 0) {
	      if ((d = del(d)) == NULL) {
		chdirx("..");
		clrall(&d);
		getdir(&d); if (d == NULL) { return 1; }
	      }
	    }
	    break;
	  default:
	    if (k >= 0x10 && k <= 0x32) {
	      setdisk(keytbl[k - 0x10] - 'a');
	      clrall(&d);
	      getdir(&d); if (d == NULL) { return 1; }
	    }
	}
	fnd[0] = '\0';
	break;
      case '\r':
      case '\n':
	chdirx(d->name);
      case '':
	clrall(&d);
	return 0;
      default:
	strc(fnd, k);
    }
  }
}

diritem::diritem(int length = 12) {
  p = n = NULL;
  name = new char[length + 1];
}
diritem::diritem(char *inits) {
  p = n = NULL;
  if ((name = new char[strlen(inits) + 1]) != NULL) {
    strcpy(name, inits);
  }
}
diritem::~diritem(){
  if (name != NULL) { delete name; }
}

int csub(char a, char b) {
  a = tolower(a);
  b = tolower(b);
  return a > b ? a - b : b - a;
}

void strc(char *s, char c) {
  int l = strlen(s);
  if (l > 0 && c == '') {
    s[l - 1] = '\0';
  } else if (l < MAXFND) {
    s[l] = c;
    s[l + 1] = '\0';
  }
}

int cdir(diritem *d) {
  int count = 0;
  if (d == NULL) { return 0; }
  while (d->p != NULL) { d = d->p; }
  while (d != NULL) {
    if (d->name[0] != '.') { count++; }
    d = d->n;
  }
  return count;
}

void add(diritem *o, diritem *s) {
  if ((s == NULL) || (o == NULL)) { return; }
  if (o->n != NULL) {
    o->n->p = s;
    s->n = o->n;
  }
  o->n = s;
  s->p = o;
}
diritem *del(diritem *o) {
  diritem *_o;
  if (o == NULL) { return NULL; }
  if (o->n != NULL) { _o = o->n; }
  else { _o = o->p; }
  if (o->p != NULL) { o->p->n = o->n; }
  if (o->n != NULL) { o->n->p = o->p; }
  delete o;
  return _o;
}

void clrall(diritem **t) {
  if (*t == NULL) { return; }
  while ((*t)->p->p != NULL) { *t = (*t)->p; }
  while ((*t)->n != NULL) {
    delete (*t)->p;
    *t = (*t)->n;
  }
  delete *t;
  *t = NULL;
}

void swapdiritem(diritem **a, diritem **b) {
  char *x = (*a)->name;
  (*a)->name = (*b)->name;
  (*b)->name = x;
}

int cmpdiritem(diritem *a, diritem *b) {
  return strcmp(a->name, b->name);
}

void sortdir(diritem **t) {
  int ok = 0;
  if (*t == NULL) { return; }
  while (ok == 0)  {
    ok = 1;
    while ((*t)->p != NULL) { *t = (*t)->p; }
    while ((*t)->n != NULL) {
      if (cmpdiritem(*t, (*t)->n) > 0) {
	swapdiritem(t, &(*t)->n);
	ok = 0;
      }
      *t = (*t)->n;
    }
  }
}

diritem *cpoint(diritem *s, char *ref) {
  int diff, x;
  int p, l = strlen(ref);
  diritem *b, *e = NULL, *e2 = NULL;
  if (s == NULL || ref[0] == '\0') { return s; }
  while (s->p != NULL) { s = s->p; }
  b = s;
  for (p = 0; p < l; p++) {
    if (ref[p] == '?') { continue; }
    s = b;
    diff = csub(ref[p], s->name[p]);
    while (s->n != NULL && s != e) {
      s = s->n;
      x = csub(ref[p], s->name[p]);
      if (x <= diff) {
	e2 = s;
	if (x < diff) {
	  diff = x;
	  b = s;
	}
      }
    }
    e = e2;
  }
  return b == NULL ? s : b;
}

diritem *getdir(diritem **t, char *sname) {
  int disk0, disk;
  ffblk f;
  diritem *d = NULL;
  char curdir[MAXPATH + 1];
  char *ddesc = "X:";
  if (getcurdir(0, curdir) != 0) { return NULL; }
  if (curdir[0] == '\0') {
    disk0 = getdisk();
    for (disk = 0;disk < 26;++disk) {
      setdisk(disk);
      if (disk == getdisk()) {
	ddesc[1] = 'A' + disk;
	if (d == NULL) {
	  d = new diritem(ddesc);
	} else {
	  add(d, new diritem(ddesc));
	  if (d->n != NULL) { d = d->n; }
	}
      }
    }
    setdisk(disk0);
  }
  if (findfirst(sname, &f, FA_HIDDEN | FA_DIREC) == 0) {
    if ((f.ff_attrib & FA_DIREC) != 0) {
      if (d == NULL) {
	d = new diritem(f.ff_name);
      } else {
	add(d, new diritem(f.ff_name));
	if (d->n != NULL) { d = d->n; }
      }
    }
    while (findnext(&f) == 0) {
      if ((f.ff_attrib & FA_DIREC) == 0) { continue; }
      if (d == NULL) {
	d = new diritem(f.ff_name);
      } else {
	add(d, new diritem(f.ff_name));
	if (d->n != NULL) { d = d->n; }
      }
    }
    sortdir(&d);
    while (d->p != NULL && d->p->name[0] != '.') { d = d->p; }
    (*t) = d;
    return d;
  }
  return NULL;
}

int chdirx(char *path) {
  char *x;
  if (path[0] == '') { path++; }
  if ((x = strchr(path, ':')) != NULL) {
    setdisk(x[-1] - 'A');
    path = x + 1;
  }
  return chdir(path);
}

void outd(diritem *d) {
  diritem *c = d;
  int ct = 0;
  char buf[256];
  if (d == NULL) return;
  clrscr();
  while(d->p != NULL && ct++ < pnum) d=d->p;
  ct = 0;
  putchar('\n');
  while(d != NULL && ct++ < pnum + pnum) {
    printf("%s %c\n", d->name, d==c?'û':' ');
    d=d->n;
  }
  printf("\n%s\n", getcwd(buf, 200));
}

void usage() {
  printf("\
fast directory	version 2.00\n\
topcroak software	author: dansei	1999.4.5\n\
>> FD [<dirname>]  (may contain *,?)\n\
>>   function key:\n\
>>	up/down/home/end:	move cursor\n\
>>	left/right/enter:	make current path\n\
>>	alt-key:		change current disk\n\
>>	ascii char:		name reference\n\
>>	escape:			keep current path\n\
>>	insert/delete:		quick dir create/remove\n");
}