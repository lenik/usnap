
// lines commander

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *strinsert(char *str, char *istr) {
	char *buf = new char[4096];
	int istr_len = strlen(istr);
	strcpy(buf, istr);
	strcat(buf, str);
	strcpy(str, buf);
	return str + istr_len;
}

void main(int argc, char **argv) {
	char cmdline[4096];
	char buf[8000];
	char line[4096]; 		// each item line
	char *p;
	char *itemname;
	int readstdin = 0;
	FILE *f;

	argc--;
	argv++;
	if (**argv == '-') {
		argc--;
		argv++;
		readstdin = 1;
	} else {
		itemname = *argv;
		argc--;
		argv++;
	}

	strcpy(cmdline, "");
	for (int i = 0; i < argc; i++) {
		strcat(cmdline, argv[i]);
		if (i < argc - 1) strcat(cmdline, " ");
	}

	if (readstdin) {
		f = stdin;
	} else {
		f = fopen(itemname, "r");
	}
	if (f == NULL) {
		perror("could not read list file");
		return;
	}
	do {
		// get new item
		if (fgets(line, 80, f) == NULL) break;
		if (line[strlen(line) - 1] == '\n') {
			line[strlen(line) - 1] = 0;
		}
		// translate and execute
		strcpy(buf, cmdline);
		p = buf;
		do {
			p = strchr(p, '&');
			if (p == NULL) break;
			strcpy(p, p + 1);
			p = strinsert(p, line);
		} while (1);

		//printf("%s\n", buf);
		if (strlen(buf) > 0) system(buf);
	} while (1);

	fclose(f);

}
