#include <stdio.h>
#include <dos.h>

char passwd[9];
char decode[9];

void main() {
	unsigned int data;
	int count = 0;
	unsigned char a, b;

	outportb(0x70, 29);
	a = inportb(0x71);
	outportb(0x70, 28);
	b = inportb(0x71);

	data = ((unsigned int)a << 8) + b;

	while (data > 0) {
		if (data < 0x80) {
			passwd[count] = data;
			break;
		} else {
			unsigned char temp = data & 0x3f;
			if (temp <= 0x20) temp |= 0x30;
			passwd[count++] = temp;
			data -= temp;
			data >>= 2;
		}
	}

	for (int i = 0; count >= 0; i++)
		decode[i] = passwd[count--];

	printf("The CMOS's password is \"%s\"\n", decode);

}