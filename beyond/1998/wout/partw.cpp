
#include <stdio.h>
#include <stdlib.h>

#include <windows.h>
#pragma comment(lib, "user32.lib")

#define PARAM_SRC		1
#define PARAM_DEST		3
#define PARAM_OSRC		2
#define PARAM_ODEST		4
#define PARAM_LEN		5

#define UNIT			16384

int main(int argc, char **argv) {
	FILE *src, *dest;
	long offSrc = 0, offDest = 0;
	long length = 0;
	long p;
	char buf[UNIT];

	if (argc < 6) {
		printf("PART <SRC.FILE> <OFFSET> <DEST.FILE> <OFFSET> <LENGTH>\n");
		return 1;
	}

	src = fopen(argv[PARAM_SRC], "rb");
	if (!src) {
		perror("Error");
		return 2;
	}

	dest = fopen(argv[PARAM_DEST], "w+b");

	if (!dest) {
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

	BYTE keys[256];
	for (p = 0; p < 256; p++) keys[p] = 0;

	for (p = 0; p < length; p += UNIT) {
		long readSize = (p + UNIT <= length) ? UNIT : length - p;
		fseek(src, offSrc + p, SEEK_SET);
		fread(buf, 1, readSize, src);
		fseek(dest, offDest + p, SEEK_SET);
		fwrite(buf, 1, readSize, dest);

		bool shows = false;
		SHORT s;
		if ((s = ::GetAsyncKeyState(VK_SPACE)) & 0x8000) {
			shows = true;
		}
		if ((s = ::GetAsyncKeyState('I')) & 0x8000) {
			shows = true;
			p += UNIT;		// 16k
		}
		if ((s = ::GetAsyncKeyState('J')) & 0x8000) {
			shows = true;
			p += 4 * UNIT;		// 64k
		}
		if ((s = ::GetAsyncKeyState('K')) & 0x8000) {
			shows = true;
			p += 16 * UNIT;		// 256k
		}
		if ((s = ::GetAsyncKeyState('L')) & 0x8000) {
			shows = true;
			p += 64 * UNIT;		// 1m
		}
		if ((s = ::GetAsyncKeyState('M')) & 0x8000) {
			shows = true;
			p += 256 * UNIT;	// 4m
		}
		if ((s = ::GetAsyncKeyState('N')) & 0x8000) {
			shows = true;
			p += 1024 * UNIT;	// 16m
		}
		if (shows) {
			printf("%ld / %ld (%3.2f)\n", p, length, 100.0 * p / length);
		}
	}

	fclose(dest);
	fclose(src);

	return 0;
}
