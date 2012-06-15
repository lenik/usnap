// ref_1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#include <stdio.h>

class xint {
public:
	int _i;
	operator ++() { _i++; show(); }
	operator --() { _i--; show(); }
	operator int() { return _i; }
	void show() {
		printf("%d\n", _i);
	}
};

class C {
public:
	int m_i;
	static xint m_count;
public:
	C() {
		++m_count;
	}
	~C() {
		--m_count;
	}
};

xint C::m_count;

int f1() {
	int i1;
	C c1;
	C& c2 = c1;
	return 0;
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	return 0;
}
