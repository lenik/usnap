#include<string.h>
#include<stdlib.h>

main(int argc,char**args)
{char *p="";int pp;
 char *c;char *s;
 if (argc<3) {printf("\nUsage:\n    %s FileName {FindString} Argument (/?) \ne.g.:\n    %s README.TXT {Version}\n",args[0],args[0]);return 1;}
 for(pp=3;pp<=argc;pp++)
  {strcat(p,args[pp]);
   strcat(p," ");
  }
 s=args[2];
 if((s[0]!='{')||(s[strlen(s)-1]!='}')){printf ("The FindString hasn't '{' and '}'.\n");return 1;}
 s[0]='"';s[strlen(s)-1]='"';
 sprintf(c,"find %s %s %s",p,s,args[1]);
 system(c);
 return errno;
}