
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

#define ESC	0x1b

void Initialize() {
	int GraphDriver;
	int GraphMode;
	int ErrorCode;
	GraphDriver = DETECT;
	initgraph(&GraphDriver, &GraphMode, "");
	ErrorCode = graphresult();
	if (ErrorCode != grOk) {
		printf("Graphics System Error: %s\n", grapherrormsg(ErrorCode));
		exit(1);
	}
}
