
#pragma once


int issep(int c) {
	return c == ' ' || c == '\t' || c == '\n' || c == '\0';
}
char *mid(char *s, int i, int l = -1) {
	static char tmp[4000];
	if (i >= (int)strlen(s)) i = strlen(s);
	if (l < 0) strcpy(tmp, s + i);
	else strncpy(tmp, s + i, l);
	return tmp;
}
char right(char *s, int i) {
	if (i >= (int)strlen(s)) return 0;
	return s[strlen(s) - i - 1];
}

char t[5000];
char *readword(FILE *f) {
	static int c = 0;
	int i = 0;
	while (issep(c)) c = fgetc(f);
	if (c == EOF) return NULL;
	do {
		if (c == EOF) break;
		t[i++] = c;
		if (c == '\\') t[i++] = fgetc(f);
	} while (!issep(c = fgetc(f)));
	t[i] = '\0';
	return t;
}

void fout(FILE *f, int indent, const char *s) {
	int i;
	for (i = 0; i < indent; i++) {
		fprintf(f, "\t");
	}
	fprintf(f, s);
}
