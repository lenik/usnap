// WPS typer

#include <stdio.h>

typedef unsigned char	BYTE;
typedef unsigned int	WORD;
typedef unsigned long	DWORD;

struct WpsFile {
  int wpsfile;
  int crypted;
  int keepsofts, keepsoftn;
  char pw[9];
  FILE *f;
};

int WpsSeek(struct WpsFile wf, long offset) {
  return fseek(wf.f, offset + (wf.wpsfile == 1 ? 0x400 : 0), SEEK_SET);
}

int OpenWpsFile(struct WpsFile *wf, const char *fn, const char *mode) {
  FILE *f;
  int i, j = 0;
  wf->f = NULL;
  if ((f = fopen(fn, mode)) == NULL) { return 1; }
  wf->f = f;
  wf->wpsfile = 0;
  wf->keepsofts = 0;
  wf->keepsoftn = 1;

  if (fgetc(f) <= 0x04 && fgetc(f) == 0xFF) {
    fseek(f, 0x2DD, SEEK_SET);
	  wf->crypted = 0;
	  if ((i = fgetc(f)) != 0) { /* has password */
	    wf->crypted = 1;
	    do {
	      i = (BYTE)~i;
	      wf->pw[j++] = (i & 0xF) << 4 | i >> 4;
	      i = fgetc(f);
	    } while (j < 8 && i != 0);
	    wf->pw[j] = '\0';
	  }
    wf->wpsfile = 1;
  }
  WpsSeek(*wf, 0);
  return 0;
}

int CloseWpsFile(struct WpsFile *wf) {
  int r = fclose(wf->f);
  wf->f = NULL;
  return r;
}

int WpsGetc(struct WpsFile wf, WORD *r) {
  int i, j;
  WORD w;
  if ((i = fgetc(wf.f)) == EOF) { return EOF; }
  w = (BYTE)i;
  switch (i) {
    case 0x0C: w = 0; break;		/* New Page */
    case 0x8D:			/* Soft LF */
    case 0x8A:
      w &= wf.keepsoftn == 1 ? 0xF : 0; break;
    case 0x7F:			/* Soft space */
      w = wf.keepsofts == 1 ? ' ': 0; break;
    default:
      if (i >= 0xA1) {			/* HZ */
	if ((j = fgetc(wf.f)) == EOF) { return EOF; }
	w |= j << 8;
	if (i == 0xA1 && j == 0xA1) {	/* HZ space */
	  w = 0x2020;
	}
      }
  }
  *r = w;
  return 0;
}

int ConvertToText(struct WpsFile wf, FILE *tf) {
  WORD r;
  while (WpsGetc(wf, &r) != EOF) {
    if (r == 0) { continue; }
    if (fputc(r & 0xFF, tf) == EOF) { return 1; }
    if (r >= 0x100) {
      if (fputc(r >> 8, tf) == EOF) { return 1; }
    }
  }
  return 0;
}