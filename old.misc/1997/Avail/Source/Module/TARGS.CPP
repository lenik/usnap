#include "TArgs.h"

#include <alloc.h>
#include <string.h>

/* i should add:
   DistilArgs
   PullArgs */
TArgs::TArgs(int _argc, char **_argv) {
  Sep[0]='/';
  Sep[1]='-';
  Sep[2]=0;
  Sep[3]=0;
  argc=0;
  argv=NULL;
  Init(_argc, _argv);
}

void TArgs::Destroy() {
  for (int n=0; n<argc; n++)
    if (argv[n]!=NULL) {
      delete argv[n];
      argv[n]=NULL;
    }
  if (argv!=NULL) {
    delete argv;
    argv=NULL;
  }
}

void TArgs::Init(int _argc, char **_argv) {
  if (_argc==0) return;
  argc=_argc;
  argv=new char*[_argc];
  for (int n=0, in=0; n<_argc; n++, in++) {
    argv[in]=new char[strlen(_argv[n])+1];
    strcpy(argv[in], _argv[n]);
    argv[in][strlen(_argv[n])]='\x0';
    for (int s=0; s<MAXSEPARATECHAR; s++) {
      while ((Sep[s])&&(strchr(argv[in]+1, Sep[s])!=NULL)) {
	int _1stLen=(int)(strchr(argv[in]+1, Sep[s])-argv[in++]);
	argv=(char **)realloc(argv, sizeof(char*)*(++argc));
	argv[in]=new char[strlen(argv[in-1])-_1stLen+1];
	strcpy(argv[in], argv[in-1]+_1stLen);
	argv[in-1]=(char *)realloc(argv[in-1], _1stLen+1);
	argv[in-1][_1stLen]='\x0';
	s=0;
      } // while strchr sep
    } // for separate
  } // for _argc
}
