
#include <stdio.h>
#include <string.h>
#include <dir.h>
#include <dos.h>
#include <process.h>

struct mp3info {
	char TAG[3];
	char title[30];
	char artist[30];
	char album[30];
	char year[4];
	char comment[29];
	char FF;
};

struct verbose {
	char title[128];
	char artist[128];
	char album[128];
	char comment[128];
};

void copy2(char s[], char d[], int maxlength) {
	int pd;
	int ps;
	// left trim to s+ps
	for (ps = 0; ps < maxlength; ps++) {
		if (s[ps] == ' ' || s[ps] == '\t') continue;
		break;
	}
	// copy
	for (pd = 0; ps < maxlength; ps++, pd++) {
		d[pd] = s[ps];
		if (s[ps] == '\0') break;
	}
	d[pd] = '\0';
	// rtrim to d+pd, where pd points to last char not space
	for (pd--; pd > 0; pd--) {
		if (d[pd] == ' ' || d[pd] == '\t') {
			d[pd] = '\0';
			continue;
		}
		break;
	}
	return;
}

void replace(char *name, char *path);

void main(int argc, char **argv) {
	static char base1[64];
	static char base2[64];
	static char full[128];
	ffblk ff;

	if (argc < 2) {
		printf("mp3c <file> ...\n");
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
	FILE *mp3f;
	mp3info m3i;
	verbose v;
	static char dest[256];
	static char cmd[256];

	if ((mp3f = fopen(name, "rb")) == NULL) {
		printf("error opening file %s", name);
		perror("");
		return;
	}

	fseek(mp3f, -128, SEEK_END);

	if (fread(&m3i, sizeof(mp3info), 1, mp3f) != 1) {
		perror("error reading");
		fclose(mp3f);
		return;
	}

	fclose(mp3f);

	if (strncmp(m3i.TAG, "TAG", 3) != 0) {
		printf("\tno info!\n");
		return;
	}

	copy2(m3i.title, v.title, sizeof(m3i.title));
	copy2(m3i.artist, v.artist, sizeof(m3i.artist));
	copy2(m3i.album, v.album, sizeof(m3i.album));
	copy2(m3i.comment, v.comment, sizeof(m3i.comment));

	sprintf(dest, "%s-%s.mp3", v.artist, v.title);
	sprintf(cmd, "ren \"%s\" \"%s\"", name, dest);
	printf("\trename %s -> %s\n", name, dest);
	system(cmd);
	// outinfo(&v);

	return;
}

void outinfo(verbose *v) {
	printf("\
title 	= %s\n\
artist 	= %s\n\
album 	= %s\n\
comment = %s\n",
		v->title,
		v->artist,
		v->album,
		v->comment);
	return;
}
