/* which - C version of the unix/csh 'which' command
 * vix 23jul86 [written]
 * vix 24jul86 [don't use dynamic memory]
 * dansei 27jan00 [moved to MS-DOS]
 * dansei 28apr00 [added debug function]
 * dansei 10jun00 [advanced output format]
 * dansei 03jun01 [modify some bugs]
 */

#define MSDOS

#include <stdio.h>

#ifdef MSDOS
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <fcntl.h>
#define access(filename, mode) access_exe(filename)
#define DELI	';'
#define PARSER	'\\'
#else
#define DELI	':'
#define PARSER	'/'
#endif

static	char	*myname;

int access_exe(const char *filename);
static which(char *);
int outputs(const char *s);
#define puts outputs

int bInDebug = 0;

static char buf[1024];

typedef char *PSTR;

#define MAXPATHS		100
PSTR paths[MAXPATHS];
int npaths;

main(argc, argv)
int	argc;
char	*argv[];
{
	PSTR path = getenv("PATH");

	for (npaths = 0; npaths <= MAXPATHS; npaths++) {
		if (path == NULL || path[0] == '\0') break;
		while (path[0] == ' ') path++;
		paths[npaths] = path;
		path = strchr(path, ';');
		if (path != NULL) {
			path[0] = '\0';
			path++;
		}
	}

	myname = argv[0];
        for (argc--, argv++;  argc;  argc--, argv++) {
		if (strcmp(*argv, "-d") == 0) {
                        bInDebug = 1;
                        continue;
		}
		if (strcmp(*argv, "-D") == 0) {
			bInDebug = 0;
			continue;
		}
		if (strcmp(*argv, "-?") == 0 || stricmp(*argv, "-h") == 0) {
			printf("which: find command\nsyntax: %s [-dD] commands...\n\t-dD enable or disable debug info\n", myname);
			continue;
		}
		which(*argv);
	}
	return 0;
}

static which(name)
char	*name;
{
	char	test[1000];
	int	i, len, found, hassolution = 0;

	for (i = 0; i < npaths; i++) {
		strcpy(test, paths[i]);
		len = strlen(test);
		if (len < 0) continue;
		if (len > 0) {
			if (test[len - 1] != ':' && test[len - 1] != '\\') {
				test[len++] = '\\';
				test[len] = '\0';
			}
		}
		strcat(test, name);

                found = (0 == access(test, 01));        /* executable */
		if (found) {
			hassolution = 1;
			puts(buf);
		}
	}
	if (hassolution == 0)
	{
		printf("%s: no %s found in path\n", myname, name);
		return 1;
	}
	return 0;
}

#ifdef MSDOS
#undef access
int access_exe(filename)
const char *filename;
{
        if (bInDebug)
                printf("Searching: %s\n", filename);

	strcpy(buf, filename);
	if (access(buf, 0) == 0) return 0;

	strcpy(buf, filename);
	strcat(buf, ".com");
	if (access(buf, 0) == 0) return 0;

	strcpy(buf, filename);
	strcat(buf, ".exe");
	if (access(buf, 0) == 0) return 0;

	strcpy(buf, filename);
	strcat(buf, ".bat");
	if (access(buf, 0) == 0) return 0;

	return -1;
}
#endif

#ifdef MSDOS
#undef puts
int outputs(s)
const char *s;
{
	int	h;
	long	size;
	h = open(s, O_RDONLY);
	if (h != -1) {
		size = filelength(h);
		close(h);
		printf("%s size/%ld\n", s, size);
		return 0;
	} else {
		puts(s);
		return 1;
	}
}
#endif
