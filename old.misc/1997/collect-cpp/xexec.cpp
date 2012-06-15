
#include <stdio.h>
#include <string.h>

extern "C" int _stdcall WinExec(char *, int);

void dump(FILE *f) {
	int c;
	while (!feof(f)) {
		c = fgetc(f);
		if (c == EOF) break;
		fputc(c, stdout);
	}
}

int main(int argc, char **argv) {
	FILE *lead, *tail;
	int i;
	char cmdbuf[16384];

	if ((lead = fopen("echolead.txt", "rt")) != NULL) {
		dump(lead);
		fclose(lead);
	}

	cmdbuf[0] = 0;
	i = 1;
	if (argv[0][0] == 'x') i++;
	for (; i < argc; i++) {
		strcat(cmdbuf, argv[i]);
		if (i != argc - 1) strcat(cmdbuf, " ");
	}
	printf("will execute: [%s]\n", cmdbuf);
	WinExec(cmdbuf, 0);

	if ((tail = fopen("echotail.txt", "rt")) != NULL) {
		dump(tail);
		fclose(tail);
	}

	return 0;
}
