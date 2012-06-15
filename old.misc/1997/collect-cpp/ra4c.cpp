
#include <stdio.h>
#include <string.h>
#include <dir.h>
#include <dos.h>
#include <process.h>

//#define RA4_CONT        0xDF
long RA4_CONT = 0;
#define RA4_TAGS        (RA4_CONT + 11)

struct ra4info {
	char title[100];
	char artist[100];
	char copy[100];
};


void replace(char *name, char *path);
void outinfo(ra4info *);
long findCont(FILE *);

void main(int argc, char **argv) {
	static char base1[64];
	static char base2[64];
	static char full[128];
	ffblk ff;

	if (argc < 2) {
		printf("ra4c <file> ...\n");
		return;
	}

	while (argc > 1) {
		fnsplit(argv[1], base2, base1, NULL, NULL);
		strcat(base2, base1);
		if (findfirst(argv[1], &ff, FA_RDONLY | FA_ARCH | FA_HIDDEN) != 0) {
			printf("no file find. \n");
			return;
		}

		do {
			strcpy(full, base2);
			strcat(full, ff.ff_name);
			printf("--> %s \n", full);
			replace(full, base2);
		} while (findnext(&ff) == 0);
		argc--;
		argv++;
	}
	return;
}

void replace(char *name, char *path) {
	FILE *ra4f;
	ra4info r4i;
	static char dest[256], cmd[256], temp[256], *t;
	int readsize;

	if ((ra4f = fopen(name, "rb")) == NULL) {
		printf("error opening file %s", name);
		perror("");
		return;
	}

	if ((RA4_CONT = findCont(ra4f)) < 0) {
		printf("\tnot a valid ra4 file!\n");
		fclose(ra4f);
		return;
	}

	fseek(ra4f, RA4_TAGS, SEEK_SET);

	readsize = fread(temp, 1, sizeof(temp), ra4f);

	fclose(ra4f);

	memset(&r4i, 0, sizeof(r4i));

	t = temp + 1;
	strcpy(r4i.title, t);
	t += strlen(t) + 1 + 1;         // one is NULL, one is a byte of len
	if (t - temp < readsize) {
		strcpy(r4i.artist, t);
		t += strlen(t) + 2;
		if (t - temp < readsize)
			strcpy(r4i.copy, t);
	}

	sprintf(dest, "%s-%s.rm", r4i.artist, r4i.title);
	sprintf(cmd, "ren %s %s", name, dest);
	printf("\trename %s -> %s\n", name, dest);
	system(cmd);

	return;
}

void outinfo(ra4info *v) {
	printf("\
title 	= %s\n\
artist 	= %s\n\
copy 	= %s\n",
		v->title,
		v->artist,
		v->copy);
	return;
}

long findCont(FILE *f) {
	char c, tagc[5];

	fseek(f, 0, SEEK_SET);
	memset(tagc, 0, sizeof(tagc));

	while ((c = fgetc(f)) != EOF) {
		tagc[0] = tagc[1];
		tagc[1] = tagc[2];
		tagc[2] = tagc[3];
		tagc[3] = c;
		if (strcmp(tagc, "CONT") == 0) {
			return ftell(f) - 4;
		}
	}
	return -1;
}
