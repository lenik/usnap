// memarray.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.

	short a1[4][3] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, },
	};

	struct short3 {
		short m[3];
	};

	int ss = sizeof(short3);

	short3 *b = (short3 *)a1;

	//((short [4][4])a1)[1][2]=3;
	short a2[4][3];
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 3; x++) {
			a2[y][x] = b[y].m[x];
		}
	}
	return 0;
}
