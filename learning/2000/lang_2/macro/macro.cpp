// macro.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#define NAME(x) "My name is " # x ". Nice to c u! "
//--> "My name is " "(x)" ". Nice to c u! "

#define M(x) MessageBox(NULL, NAME(x), NAME(x), 0);

#define XBEGIN	#ifdef MAKE_X
#define XEND	#endif

#define MAKE_X

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.

	//M(dansei);

	//XBEGIN
	//	M(X);
	//XEND

	return 0;
}
