#ifndef __TARGS_H

#define __TARGS_H

#define MAXSEPARATECHAR		4
class TArgs{
public:
  int argc;
  char **argv;
public:
  TArgs(int _argc, char **_argv);
  void Destroy();
public:
  char Sep[MAXSEPARATECHAR];
  void Init(int _argc, char **_argv);
  char *GetVal(char _Command);
  char *GetVal(char *_Command);
};

#endif
