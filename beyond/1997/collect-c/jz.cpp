#include <stdio.h>
#include <stdlib.h>

void main(int argc,char **argv)
{long l;
 char s[1000];
 if(argc<4) {
	printf("Usage: JZ <OldNum> <OldJZ> <NewJZ>\n");return;
	}

	int oldjz, newjz;
	oldjz = strtol(argv[1], 0, 10);
	newjz = strtol(argv[2], 0, 10);

	while (argv[3]) {
		l=strtol(argv[3],0,oldjz);
		printf("%s ",ltoa(l,s, newjz));
		argv++;
	}
}
