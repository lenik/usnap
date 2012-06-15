#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#define OFFSET				0x4E
#define MAXSIZE				38

main(int argc, char **argv) {
	char *buf = malloc(2000);		/* save info.. */
	char oriText[MAXSIZE]; 			/* original text in file */
	FILE *exefile;

	int i;

	if (argc < 2) {
		printf("%s <exe file> [<infomations...>]\n", argv[0]);
		return -1;
	}

	if ((exefile = fopen(argv[1], "rb")) == NULL) {
		perror("open file error");
		return -2;
	}

	if (fseek(exefile, OFFSET, SEEK_SET) != 0) {
		perror("seek file error");
		fclose(exefile);
		return -3;
	}

	if (fread(oriText, 1, MAXSIZE, exefile) != MAXSIZE) {
		perror("read file error or file too small");
		fclose(exefile);
		return -4;
	}
	oriText[MAXSIZE] = '\0';

	printf("origin text is \n\"%s\". \n", oriText);

	if (argc >= 3) {
		fclose(exefile);
		if ((exefile = fopen(argv[1], "rb+")) == NULL) {
			perror("open file error");
			return -2;
		}
		if (strnicmp(oriText, "This progr", 10) != 0) {
			printf("this executable file seems not be able to add information, may be it's DOS program, continue? (y/N)\n");
			if (tolower(getch()) != 'y') {
				printf("program breaked. \n");
				fclose(exefile);
				return 0;
			}
		}
		strcpy(buf, argv[2]);
		for (i = 3; i < argc; i++) {
			strcat(buf, " ");
			strcat(buf, argv[i]);
		}
		if (strlen(buf) >= MAXSIZE) {
			printf("string %s is too long!\n");
			fclose(exefile);
			return -5;
		}
		if (fseek(exefile, OFFSET, SEEK_SET) != 0) {
			perror("seek error");
			fclose(exefile);
			return -6;
		}
		if (fwrite(buf, 1, strlen(buf) + 1, exefile) != strlen(buf) + 1) {
			perror("write file error");
			fclose(exefile);
			return -7;
		}
		printf("information has been converted to \"%s\". \n", buf);
	}

	fclose(exefile);
	return 0;
}
