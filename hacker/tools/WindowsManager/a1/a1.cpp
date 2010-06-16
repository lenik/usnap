// a1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include <stdio.h>

#define B2

#ifdef B1
void _stdcall f1();
#elif defined(B2)
typedef void (_stdcall *f1proc)();
f1proc f1x;
#endif


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.

	// load a library and get a proc address
	/*
#ifdef B1
	f1();
#elif defined(B2)
	HMODULE hmdll;
	hmdll = LoadLibrary("d1.dll");
	char buf[1000];
	sprintf(buf, "app: hmdll=%x",hmdll);
	MessageBox(NULL, buf, NULL, 0);
	f1x=(f1proc)GetProcAddress(hmdll, "f1");
	f1x();
#endif
	*/


	return 0;
}
