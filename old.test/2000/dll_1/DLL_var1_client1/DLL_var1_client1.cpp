// DLL_var1_client1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#include "tchar.h"

typedef int (_stdcall *geti_func)();
typedef void (_stdcall *seti_func)(int);

geti_func	geti1, geti2;
seti_func	seti1, seti2;

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.

	HMODULE	h1, h2;
	int	i;

	h1	= LoadLibrary(_T("DLL_var1.dll"));
	h2	= LoadLibrary(_T("DLL_var1_2.dll"));

	if (h1 == NULL || h2 == NULL) {
		if (h1 != NULL) FreeLibrary(h1);
		if (h2 != NULL) FreeLibrary(h2);
		return 0;
	}

	geti1	= (geti_func)GetProcAddress(h1, "geti");
	seti1	= (seti_func)GetProcAddress(h1, "seti");
	geti2	= (geti_func)GetProcAddress(h2, "geti");
	seti2	= (seti_func)GetProcAddress(h2, "seti");

	seti1('1');
	seti2('2');
	i	= geti1();
	MessageBox(NULL, (LPCTSTR)&i, NULL, 0);
	i	= geti2();
	MessageBox(NULL, (LPCTSTR)&i, NULL, 0);

	FreeLibrary(h1);
	FreeLibrary(h2);

	return 0;
}
