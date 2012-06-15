// _S1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.

	static BYTE Bytes[10000] = { 1, 2, 3, 4, };
	static BYTE Bytes2[10] = { 5, 6, 7 ,8, };
	Bytes[0] = Bytes[0];
	Bytes2[0] = Bytes2[0];
	return 0;
}
