#include <stdio.h>
#include <stdlib.h>
#include <bios.h>
#include <conio.h>
#include <io.h>
#include <fcntl.h>
#include <sys\stat.h>

#define PARAM_SRC		1
#define PARAM_DEST		3
#define PARAM_OSRC		2
#define PARAM_ODEST		4
#define PARAM_LEN		5

#define UNIT			16384

int main(int argc, char **argv) {
	int src, dest;
	long offSrc = 0, offDest = 0;
	long length = 0;
	long p;
	char buf[UNIT];

	if (argc < 6) {
		printf("PART <SRC.FILE> <OFFSET> <DEST.FILE> <OFFSET> <LENGTH>\n");
		return 1;
	}

	src = open(argv[PARAM_SRC], O_RDONLY | O_BINARY);
	if (src == -1) {
		perror("Error");
		return 2;
	}

	if (access(argv[PARAM_DEST], 0)) // not exist
		dest = open(argv[PARAM_DEST],
				O_WRONLY | O_BINARY | O_CREAT,
				S_IREAD | S_IWRITE
		);
	else
		dest = open(argv[PARAM_DEST], O_WRONLY | O_BINARY);

	if (dest == -1) {
		perror("Error");
		return 2;
	}

	offSrc = strtol(argv[PARAM_OSRC], NULL, 0);
	offDest = strtol(argv[PARAM_ODEST], NULL, 0);
	length = strtol(argv[PARAM_LEN], NULL, 0);

	if (offSrc < 0 || offDest < 0 || length <= 0) {
		printf("none has to be done\n");
		return 3;
	}

	printf("parting [%ld, %ld] of %s to [%ld, %ld] of %s\n",
			offSrc,
			offSrc + length,
			argv[PARAM_SRC],
			offDest,
			offDest + length,
			argv[PARAM_DEST]
	);

	for (p = 0; p < length; p += UNIT) {
		long readSize = (p + UNIT <= length) ? UNIT : length - p;
		lseek(src, offSrc + p, SEEK_SET);
		read(src, buf, readSize);
		lseek(dest, offDest + p, SEEK_SET);
		write(dest, buf, readSize);
		if (bioskey(_KEYBRD_READY)) {
			int c = getch();
			printf("%ld / %ld\n", p, length);
			if (c == 'i') {
				p += UNIT;
			}
		}
	}

	close(dest);
	close(src);

	return 0;
}
