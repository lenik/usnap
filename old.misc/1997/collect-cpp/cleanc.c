#include <stdio.h>
#include <dir.h>
#include <dos.h>
#include <io.h>
#include <string.h>
#include <sys\stat.h>

typedef char *string;
string willbedeleted[] = {
	"scandisk.log",
	"nu.ini",
	"ndd.ini",
	"pdos.def",
	"detlog.txt",
	"cedit.las",
	"*.log",
	"window~1.bmk",
	"suhdlog.dat",
	"vidc.zfr",
	"*.dos",
	"setuplog.txt",
	"netlog.txt",
	"setuplog.old",
	"winboot.~!~"
};


main() {
	int i = sizeof(willbedeleted) / sizeof(string);
	int j;
	int total = 0, removed = 0;
	for (j = 0; j < i; j++) {
		char name[1024];
		struct ffblk f;
		int r = 0;
		strcpy(name, "c:\\");
		strcat(name, willbedeleted[j]);
		r = findfirst(name, &f, 0x1F);
		while (r == 0) {
			strcpy(name, "c:\\");
			strcat(name, f.ff_name);
			if (chmod(name, S_IWRITE) == 0) {
				if (unlink(name) == 0) {
					printf("%s removed\n", name);
					removed++;
					goto nextfile;
				}
			}
			printf("can't remove %s\n", name);
nextfile:
			total++;
			r = findnext(&f);
		}
	}
	printf("total %d files with %d files removed. \n", total, removed);
	return 0;
}
