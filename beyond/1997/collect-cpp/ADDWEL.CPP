
#include <stdio.h>
#include <dos.h>

#define BYTE	unsigned char
#define WORD	unsigned
#define DWORD	unsigned long

void addexe(FILE *);

void main(int argc, char **argv) {
	BYTE begin[3];
	DWORD fsize;

	FILE *exefile;

	if (argc < 2) {
		printf("%s <execfile>\n", argv[0]);
		return;
	}

	if ((exefile = fopen(argv[1], "rb+")) == NULL) {
		perror("couldn't open file for update");
		return;
	}

	fread(begin, 1, 3, exefile);
	fseek(exefile, 0, SEEK_END);
	fsize = ftell(exefile);
	fseek(exefile, 0, SEEK_SET);

	if (begin[0] == 'M' && begin[1] == 'Z') {
		addexe(exefile);
	} else {
		WORD relaaddr = fsize - 3;
		WORD returnaddr = -relaaddr - 46;
		WORD ipbegin, ipend;
		BYTE callcode[] = { 0xE9, relaaddr & 0xFF, relaaddr >> 8 };
		BYTE returncode[] = { 0xE9, returnaddr & 0xFF, returnaddr >> 8 };
		DWORD *asmcode;
		WORD begin12 = ((WORD *)begin)[0];
		BYTE begin3 = begin[2];

		fwrite(callcode, 1, 3, exefile);
		fseek(exefile, 0, SEEK_END);
		asm {
			db 0E8h, 0, 0
			pop ipbegin
			jmp asmcodeend

			pusha
			push ds
			push cs
			pop ds

		////////////////////////////////////////////// Execute part
			db 0E8h, 0, 0
			jmp display
			db 'Welcome!', 0dh, 0ah, '$'
		}
		display:
		asm {
			mov ah, 9
			pop dx
			add dx, 2
			int 21h
		////////////////////////////////////////////// Execute part
		}
		asmcodeend: asm {
			db 0E8h, 0, 0
			pop ipend
		}
		ipbegin += 5;
		ipend -= 3;

		asmcode = (DWORD *)MK_FP(_CS, ipbegin);

		fwrite(asmcode, 1, ipend - ipbegin, exefile);

		BYTE mov123[] = {
			0xBF, 0, 1,
			0xB8, begin12 & 0xFF, begin12 >> 8,
			0xAB,
			0xB0, begin3,
			0xAA,
			0x1F,
			0x61
		};

		fwrite(mov123, 1, 12, exefile);
		fwrite(returncode, 1, 3, exefile);

	} // if 'MZ'

	fclose(exefile);
	printf("written\n");
}

void addexe(FILE *exefile) {
	exefile = exefile;
	return;
}