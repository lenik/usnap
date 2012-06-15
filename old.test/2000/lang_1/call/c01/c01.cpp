// c01.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#define M(x) MessageBox(NULL, x, x, 0);

char b[100];

struct st {
	int i;
	long l;
};

void _cdecl f1() {
	M("f1");
}

void _cdecl f2(int x) {
	b[0] = x;
	b[1] = 0;
	M(b);
}

void pascal f3(char *x) {
	M(x);
}
void _stdcall f4(char *x) {
	M(x);
}

st _cdecl g1(st p) {
	p.i++;
	p.l++;
	sprintf(b, "i:%d, l:%d", p.i, p.l);
	M(b);
	return p;
}
st pascal g2(st p) {
	p.i;
	p.l;
	sprintf(b, "i:%d, l:%d", p.i, p.l);
	M(b);
	return p;
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.

	char *s = "Hello, world!";

	_asm {
		call f1;
		push 'A';
		call f2;
		add esp, 4;
		push s;
		call f3;
		push s;
		call f4;
		push 1;		// st.i
		push 2;		// st.l
		call g1;
		add esp, 8;
		push 3;
		push 4;
		call g2;
	}

	return 0;
}
