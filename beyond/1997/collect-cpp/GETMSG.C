#include <stdio.h>
#include <string.h>

void main(int argc, char **argv) {
  FILE *fi;
  char buf1[1000], buf2[1000];
  char *p, *p1;
  int prespace;

  if (argc < 2) {
    puts("getmsg filename");
    return;
  }

  if ((fi = fopen(argv[1], "rt")) == NULL) {
    perror("");
    return;
  }

  memcpy(_streams, fi, sizeof(FILE));

  /*
  _streams[0].level = fi.level;
  _streams[0].flags = fi.flags;
  _streams[0].fd = fi.fd;
  _streams[0].hold = fi.bsize;
   buffer curp istemp token
  */

  while (!feof(stdin)) {
    gets(buf1);
    if (buf1[strlen(buf1) - 1] == ';') continue;
    if (buf1[strlen(buf1) - 2] == ';') continue;
    if (buf1[0] != '#') continue;
    if ((p = strchr(buf1, '_')) != NULL) {
      prespace = 0;
      while (*p != '#') {
	if (*p == ' ') { prespace = 1; break; }
	p--;
      }
      if (prespace == 0) continue;
      /*if ((p = strchr(buf2, ' ')) == NULL) continue;*/
      p++;
      p1 = buf2;
      while (*p && *p != ' ') {
	*p1++ = *p++;
      }
      *p1 = '\0';
    }
    printf("\
	case %s:\n\
		Buf = \"%s\"; break;\n", buf2, buf2);
  }

  fclose(fi);
}