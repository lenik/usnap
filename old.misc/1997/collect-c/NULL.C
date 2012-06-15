#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys\stat.h>
#include <io.h>

void main(int argc, char **argv) {
	unsigned long l;
	char *endptr;
	int handle;

	if (argc < 3) {
		printf("NULL <size> <file>");
		return;
	}
	l = strtoul(argv[1], &endptr, 0);
	handle = open(argv[2], O_CREAT | O_BINARY);
	if (handle != 0) {
		printf("stuffing...\n");
		chsize(handle, l);
		close(handle);
		_chmod(argv[2], 1, 0);
	}
	printf("ok!\n");
}