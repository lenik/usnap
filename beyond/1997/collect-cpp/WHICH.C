/* which - C version of the unix/csh 'which' command
 * vix 23jul86 [written]
 * vix 24jul86 [don't use dynamic memory]
 * dansei 27jan00 [moved to MS-DOS]
 * dansei 28apr00 [added debug function]
 * dansei 10jun00 [advanced output format]
 */

#define MSDOS

#include <stdio.h>

#ifdef MSDOS
#include <stdlib.h>
#include <string.h>
#include <io.h>
#define access(filename, mode) access_exe(filename)
#define DELI	';'
#define PARSER	'\\'
#else
#define DELI	':'
#define PARSER	'/'
#endif

static	char	*myname;

#ifdef MSDOS
int access_exe(const char *filename);
static which(char *, char *);
#include <dir.h>
#include <dos.h>
int outputs(const char *s);
#define puts outputs
#endif

int bInDebug = 0;

static char buf[1024];

main(argc, argv)
int	argc;
char	*argv[];
{
	char	*path = getenv("PATH");

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
		if (0 != which(*argv, path))
			exit(1);
        }
	return 0;
}

static which(name, path)
char	*name, *path;
{
	char	test[1000], *pc, save;
	int	len, found;

	pc = path;
	found = 0;
	while (*pc != '\0' && found == 0)
	{
		len = 0;
		while (*pc != DELI && *pc != '\0')
		{
			len++;
			pc++;
		}

		if (*(pc - 1) == PARSER) *(pc - 1) = '\0';
		save = *pc;
		*pc = '\0';
		sprintf(test, "%s%c%s", pc - len, PARSER, name);
		*pc = save;
		if (*pc)
			pc++;

                found = (0 == access(test, 01));        /* executable */
		if (found)
			puts(buf);
	}
	if (found == 0)
	{
		printf("%s: no %s found in path (%s)\n", myname, name, path);
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

	if (access(filename, 0)) {
		strcpy(buf, filename);
		strcat(buf, ".com");
		if (access(buf, 0)) {
			strcpy(buf, filename);
			strcat(buf, ".exe");
			if (access(buf, 0)) {
				strcpy(buf, filename);
				strcat(buf, ".bat");
				if (access(buf, 0)) {
					return (-1);
				}
			}
		}
	}
	return 0;
}
#endif

#ifdef MSDOS
#undef puts
int outputs(s)
const char *s;
{
	struct ffblk ff;
	if (findfirst(s, &ff, FA_ARCH | FA_HIDDEN | FA_RDONLY) == 0) {
		printf("%s size/%ld\n", s, ff.ff_fsize);
		return 0;
	} else {
		return puts(s);
	}
}
#endif