// his.cpp : Defines the entry point for the application.
//

#ifdef MSC

#include "stdafx.h"

HMODULE hmDaemon	= NULL;
HMODULE hmInput		= NULL;
HMODULE hmOutput	= NULL;
HMODULE hmPlat1		= NULL;

void run_script(LPSTR scriptfile) {
	FILE *f = fopen(scriptfile, "r");
	if (f == NULL) return;
	//
	fclose(f);
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.

	/*
	while (*lpCmdLine) {
		switch (*lpCmdLine) {
		case 's':
		case 'S':
			run_script(lpCmdLine + 2);
			while (*lpCmdLine && (*lpCmdLine != ' ')) ++lpCmdLine;
			break;
		}
		++lpCmdLine;
	}
	*/
	if (*lpCmdLine) run_script(lpCmdLine);

	char dirbuf[1000];
	GetCurrentDirectory(1000, dirbuf);

	MessageBox(NULL, "working", NULL, 0);
	return 0;
}
