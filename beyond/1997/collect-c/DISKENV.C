#include <stdio.h>
#include <dir.h>
#include <errno.h>

int main (int argc, char **argv) {
  char c;
  char dirbuf[1024];
  int n;
  FILE *f;

  if (argc < 3) {
    printf("%s s|r filename\n", argv[0]);
    return -1;
  }

  switch (argv[1][0]) {
    case 's':
    case 'S':
	if (getcurdir (0, dirbuf) == -1) return errno;
	if ((f = fopen (argv[2], "w")) == NULL) return errno;
	fprintf (f, "%c:\\%s\n", (char) getdisk() + 'A', dirbuf);
	fclose (f);
	break;

    case 'r':
    case 'R':
	if ((f = fopen (argv[2], "r")) == NULL) return errno;
	if ((c = getc (f)) == EOF) return errno;
	setdisk (c - 'A');

	do {
	  if ((c = getc(f)) == EOF) return errno;
	} while ((c != '\\') && (c != '.') && (c));
	if (!c) return 0;
	dirbuf[0] = c;
	n = fscanf (f, "%s", dirbuf + 1);
	if ((n == -1) || (n == 0)) dirbuf[1] = 0;

	fclose (f);
	if (chdir (dirbuf) == -1) return errno;
	break;

    default:
	return -1;
  }
  return 0;
}