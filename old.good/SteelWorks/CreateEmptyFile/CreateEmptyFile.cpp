// CreateEmptyFile.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	char *each = NULL;

	if (argv[1][0] == ':') {
		each = argv[1] + 1;
		argv++;
		argc--;
	}

	for (int i = 1; i < argc; i++) {
		FILE *f = fopen(argv[i], "w");
		if (each != NULL) {
			FILE *e = fopen(each, "r");
			int c;
			if (e != NULL) {
				int s = 0;
				while ((c = fgetc(e)) != EOF) {
					if (s == 1) {
						switch (c) {
						case 'f':
							fprintf(f, "%s", argv[i]);
							break;
						default:
							fputc('%', f);
							fputc(c, f);
						}
						s = 0;
					} else {
						if (c == '%') s = 1;
						else fputc(c, f);
					}
				}
				fclose(e);
			}
		}
		fclose(f);
	}

	return 0;
}
