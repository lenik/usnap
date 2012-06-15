
/*
 *	A utility used for translate windows Link file
 *		into the true file, support Batch files
 *		processing.
 *	Author by DanSei, TopCroak Software
 *	2000.10
 */

/*
	#ifdef WIN32
	#	error This program could not be able to run under Windows
	#endif
*/

#include <stdio.h>
#include <stdlib.h>
#include <dir.h>
#include <string.h>
#include <conio.h>

#define LNKFILE_FILENAME_OFFSET		1024
#define TAKELENGTH			64

void tranLnk(char *filename) {
	FILE *f = fopen(filename, "rb");
	char buf[TAKELENGTH];
	char cmdline[TAKELENGTH + 30];
	static int bYesAll;

	if (f == NULL) {
		fprintf(stderr, "open file %s error", filename);
		perror("");
		exit(-1);
	}

	fseek(f, LNKFILE_FILENAME_OFFSET, SEEK_SET);

	if (fread(buf, 1, TAKELENGTH, f) != TAKELENGTH) {
		fprintf(stderr, "read file %s data error", filename);
		perror("");
		exit(-1);
	}

	fclose(f);

	buf[TAKELENGTH - 1] = '\0'; 		/* for security factor */

	sprintf(cmdline, "copy %s .", buf);
	if (system(cmdline) == 0) {
		int bAccept = 0;
		if (bYesAll == 0) {
			int bPressed = 0;
			printf("delete origin link file? ");
			for (; !bPressed; ) {
				switch (getch()) {
				case 0:
					getch();
					break;
				case 'Y':
				case 'y':
					bAccept = 1;
					bPressed = 1;
					break;
				case 'N':
				case 'n':
					bAccept = 0;
					bPressed = 1;
					break;
				case 'A':
				case 'a':
					bAccept = 1;
					bYesAll = 1;
					bPressed = 1;
					break;
				default:
					;
				}
			}
		} /* not bYesAll */
		else
		{
			bAccept = 1;
		}

		if (bAccept) {
			sprintf(cmdline, "del %s", filename);
			system(cmdline);
		}
	} /* last operation success */

	return;
}

void main(int argc, char **argv) {
	struct ffblk ff;
	int r;
	int c = 0;

	char *progname = argv[0];

	printf("Windows LNK file localize translator program     --help for help\n\n");

	while (argc > 1) {
		if (stricmp(argv[1], "/?") == 0 ||
		    stricmp(argv[1], "/h") == 0 ||
		    stricmp(argv[1], "--help") == 0) {
			printf("author by dansei, topcroak software	copyright\n\tsyntax: ");
			printf("%s <transfiles>...\n", progname);
		} else {
			for (r = findfirst(argv[1], &ff, 0x1F); r == 0; r = findnext(&ff), c++) {
				/* process for each file found */
				printf("> %s\n", ff.ff_name);
				tranLnk(ff.ff_name);
			}
		}
		argc--;
		argv++;
	}

	printf("translation finished, total %d files\n", c);

	return;
}
