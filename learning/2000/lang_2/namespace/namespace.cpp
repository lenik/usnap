// namespace.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

namespace N1 {
	int x;
}
namespace N1 {
	int y;
}

namespace N2 {
	namespace N1 {
		int a;
	}
}
namespace N2 {
	namespace N1 {
		int b;
	}
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.

	N1::x = N1::y = 0;
	N2::N1::a = N2::N1::b = 0;

	int a = 3;
	int& b = a, c = a;
	b = 4;
	c = 5;

	return 0;
}
