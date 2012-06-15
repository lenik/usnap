#include <stdio.h>
#include <stdlib.h>
#include <dir.h>
#include <string.h>

void tran(char *filename) {
	FILE *f = fopen(filename, "rb");
	char fn[64];
	char cmdline[1024];
	if (f == NULL) {
		perror("");
		exit(-1);
	}
	fseek(f, 0x24l, SEEK_SET);
	if (fread((void *)fn, 1, 64, f) != 64) {
		perror("");
		exit(-1);
	}
	fclose(f);

	fn[63] = '\0'; 		/* for security */
	/* copy */
	sprintf(cmdline, "copy %s .", fn);
	system(cmdline);
}

main(int argc, char **argv) {
	struct ffblk ff;
	int r;
	int c = 0;
	char *prog = argv[0];

	printf("PIF transferer   dansei@tc    :: /h for help\n\n");

	while (argc > 1) {
		if (stricmp(argv[1], "/?") == 0 ||
		    stricmp(argv[1], "/h") == 0 ||
		    stricmp(argv[1], "--help") == 0) {
			printf("%s <files list>...\n\tunlink pif files\n", prog);
		} else
			for (r = findfirst(argv[1], &ff, 0x1F); r == 0; r = findnext(&ff), c++) {
				printf(">%s\n", ff.ff_name);
				tran(ff.ff_name);
			}
		argc--;
		argv++;
	}
	printf("transfer finished, total %d files\n", c);
	return 0;
}
