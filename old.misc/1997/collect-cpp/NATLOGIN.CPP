
#include <stdio.h>
#include <conio.h>
#include <io.h>
#include <string.h>

#define KEY_UP		0x48
#define KEY_DOWN	0x50
#define KEY_LEFT	0x4B
#define KEY_RIGHT	0x4D

#define KEY_SPACE	' '

#define KEY_ENTER	-1		// DISABLED

#define KEY_END		0x4F

#define INITEXT		"C:\\Low\\NatLogin.TXT"

#define PASSWORD	"go"

void ShowWelcome();

int main(int argc, char **argv) {
	int key;

	for (;;) {
		ShowWelcome();
		if (argc > 1) {
                        if (strcmp(argv[1], "!") == 0) return 120;
                }
		key = getch();

		switch (key) {
		case 0:
			key = getch();
			switch (key) {
			case KEY_RIGHT:		// East
				return 1;
			case KEY_DOWN:		// South
				return 2;
			case KEY_LEFT:		// West
				return 3;
			case KEY_UP:		// North
				return 4;
			case KEY_END:
				char keybuf[256];
				printf("Enter password: ");
				textattr(0);
				cscanf("%s", keybuf);
				textattr(7);
				if (strcmp(keybuf, PASSWORD) == 0)
					return 100;
				break;
			default:
				;
			}
			break;
		case KEY_SPACE:
			return 60;
		case KEY_ENTER:
			return 61;
		case 0x1B:
			return 0;
		}
	}
}

void ShowWelcome() {
	if (access(INITEXT, 0)) {
		printf("\
Welcome to use TC-Info Development Enviroment! \n\
Considering 4 security, this program need you select the way Windows start, \n\
Please select: \n\
				[ North ] 			\n\
				    4				\n\
		     [ West]  3 ÄÄÄÄÅÄÄÄÄ 1  [ East ]		\n\
				    2				\n\
				[ South ]			\n\
		\n");
	} else {
		FILE *f = fopen(INITEXT, "rt");
		while (!feof(f)) fputc(fgetc(f), stdout);
		fclose(f);
	}
	return;
}
