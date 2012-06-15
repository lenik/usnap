// DLL_throw_client1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#include "..\DLL_throw\DLL_throw.h"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.

	try {
		fnDLL_throw();
	} catch (CDLL_throw_exception *e) {
		e->msg();
	}

	return 0;
}
