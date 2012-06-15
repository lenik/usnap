
// Put Default Keys to Key-Buffer
// TopCroak Software  DanSei/2000.3.4

#include <dos.h>
#include <string.h>
#include <malloc.h>

#include <stdio.h>

#define BIOSDATA_SEG		0x40
#define BIOSDATA_KEYHEAD	0x1A
#define BIOSDATA_KEYTAIL	0x1C
#define BIOSDATA_KEYBUFFER	0x1E

#define KEYBUFFER_SIZE		(0x20 / 2)

typedef unsigned char BYTE;
typedef unsigned int WORD;

void PutKey(char *);

int main(int argc, char **argv) {
	char ArgsBuf[1024];

	strcpy(ArgsBuf, "");
	for (int i = 1; i < argc; i++) {
		strcat(ArgsBuf, argv[i]);
		strcat(ArgsBuf, " ");
	}
	ArgsBuf[strlen(ArgsBuf) - 1] = '\0';

	PutKey(ArgsBuf);

	return 0;
}

#define Head	(*(KeyHead - BIOSDATA_KEYBUFFER) / 2)
#define Tail	(*(KeyTail - BIOSDATA_KEYBUFFER) / 2)

void PutKey(char *Keys) {
	volatile WORD far *KeyHead, far *KeyTail;
	volatile WORD far *KeyBuffer;
	WORD KeysLen;

	KeysLen = strlen(Keys);
	if (KeysLen >= KEYBUFFER_SIZE) KeysLen = KEYBUFFER_SIZE - 1;

	KeyHead = (WORD far *)MK_FP(0x40, BIOSDATA_KEYHEAD);
	KeyTail = (WORD far *)MK_FP(0x40, BIOSDATA_KEYTAIL);
	KeyBuffer = (WORD far *)MK_FP(0x40, BIOSDATA_KEYBUFFER);

	disable();
	*KeyHead = BIOSDATA_KEYBUFFER;
	*KeyTail = BIOSDATA_KEYBUFFER + KeysLen * 2;

	for (int i = 0; i < KeysLen; i++)
		KeyBuffer[i] = Keys[i]; //* 0x100;
	enable();

	return;
}
