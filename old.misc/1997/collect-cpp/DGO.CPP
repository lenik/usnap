/*
 *	DGO - Delay GOing	Version 1.00
 *	DanSei / TopCroak Software.01Feb2000
 */

#include <string.h>
#include <bios.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "PLoader.c"

#define PROGNAME	"C:\\WINDOWS\\X.COM"
#define DELAYTIME	5

int main(int argc, char **argv) {
	time_t TimeBegin, TimeDelay;
	double DelayTime = DELAYTIME;
	int Pressed = 0;
	char ProgName[256], ProgParam[256];

	strcpy(ProgName, PROGNAME);
	strcpy(ProgParam, "");

	if (argc >= 2) {
		if (strcmp(argv[1], "/?") == 0) {
			printf("Syntax: \n\t%s [/? | [delay] name [param...] ]\nExecute the specific program if no key pressed in the delay time. \n", argv[0]);
			return 0;
		}
		DelayTime = (double)atol(argv[1]);
		if (argc >= 3) {
			strcpy(ProgName, argv[2]);
			if (argc > 3) {
				strcpy(ProgParam, argv[3]);
				for (int i = 4; i < argc; i++) {
					strcat(ProgParam, " ");
					strcat(ProgParam, argv[i]);
				}
			}
		}
	}

	ExternalProgram win(ProgName, ProgParam);
	time(&TimeBegin);
	do {
		time(&TimeDelay);
		if (bioskey(_KEYBRD_READY) != 0) {
			Pressed = 1;
			break;
		}
	} while (difftime(TimeDelay, TimeBegin) < DelayTime);
	if (!Pressed) win.LoadAndExecute();
	return 0;
}
