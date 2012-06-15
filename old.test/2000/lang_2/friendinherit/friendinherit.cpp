// friendinherit.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

class quick_safe_helper;
	class extends_quick_safe_helper;


class safe_class {
private:
	int a, b, c;
protected:
	int d, e, f;
public:
	friend class quick_safe_helper;
};

class x_safe_class : public safe_class {
private:
	int g, h, i;
protected:
	int j, k, l;
public:
	friend class extends_quick_safe_helper;
};

class quick_safe_helper {
public:
	void f(safe_class o);
	void f2(x_safe_class o);

public:
	class quick_safe_helper_inner {
	public:
		void inner_f(safe_class o);
	} i;
};

class extends_quick_safe_helper : public quick_safe_helper {
public:
	void g(safe_class o);
	void g2(x_safe_class o);
};


void quick_safe_helper::f(safe_class o) {
	o.a = o.b = o.c = 10;
	o.d = o.e = o.f = 20;
}

void quick_safe_helper::f2(x_safe_class o) {
	o.d = o.e = o.f = 30;
	//o.g = o.h = o.i = 40;
	//o.j = o.k = o.l = 50;
}

void quick_safe_helper::quick_safe_helper_inner::inner_f(safe_class o) {
	//o.a = o.b = o.c = 10;
	//o.d = o.e = o.f = 20;
}

void extends_quick_safe_helper::g(safe_class o) {
	//o.a = o.b = o.c = 110;
	//o.d = o.e = o.f = 120;
}

void extends_quick_safe_helper::g2(x_safe_class o) {
	o.d = o.e = o.f = 130;
	o.g = o.h = o.i = 140;
	o.j = o.k = o.l = 150;
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.

	safe_class s1;
	x_safe_class xs2;

	quick_safe_helper qsh1;
	extends_quick_safe_helper xqsh2;

	qsh1.f(s1);
	qsh1.f2(xs2);
	qsh1.i.inner_f(s1);

	xqsh2.f(s1);
	xqsh2.f(xs2);
	xqsh2.g(s1);
	xqsh2.g2(xs2);

	return 0;
}
