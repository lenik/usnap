
#include <dos.h>
#include <stdlib.h>
#include <stdio.h>

#define WORD	unsigned short int
#define BYTE	unsigned char

#define NUMPERLINE		4

void main(int argc, char **argv) {

	WORD	ioportw = 0, ioportr = 0;
	WORD	ndxStart = 0, ndxEnd = 255;
	WORD	i, ctab = 0;
	BYTE	b;

	if (argc < 2) {
		printf("IO dumpping: \n\tdumpio.exe <IOW-port> [<IOR-port> [<start index>[ <end index>]]] \n\t(IOR-port = IOW-port + 1 by default) \n");
		return;
	}

	ioportw = (WORD)strtoul(argv[1], NULL, 0);
	ioportr = ioportw + 1;

	if (argc > 2) {
		ioportr = (WORD)strtoul(argv[2], NULL, 0);
	}

	if (argc > 3) {
		ndxStart = (BYTE)strtoul(argv[3], NULL, 0);
		if (argc > 4) {
			ndxEnd = (BYTE)strtoul(argv[4], NULL, 0);
		}
	}

	printf("Port %d'%04x --> %d'%04x\n", ioportw, ioportw, ioportr, ioportr);
	printf("-------\n");

	for (i = ndxStart; i <= ndxEnd; i++) {
		printf("[%02x] ", i);
		outportb(ioportw, (BYTE)i);
		/* delay */
			1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10;
		b = inportb(ioportr);
		printf("%3d'%02x\t", (int)b, (int)b);
		ctab++;
		if (ctab % NUMPERLINE == 0) printf("\n");
	}

	printf("-------\n");

	return;
}
