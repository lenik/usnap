// imp01.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

class I1 {
public:
	int	var1;
	virtual void vf1()
		// = 0;
	{
		int a;
		a=3;
		a++;
	}

	virtual void f1() {
		int a, b, c;
		c=3; a=b=c; a+=c;
	}
	virtual void cc(I1 obj) {
		vf1();
		obj.vf1();
	}
};

class S1 : public I1 {
public:
	virtual void vf1() {
		f1();
	}
	virtual void f1() {
		int d, e, f;
		d=4; e=f=d; d+=f;
	}
};

S1	s;

class I2 {
public:
	char c;
	virtual int operator ==(I2& o) const {
		return this->c == o.c;
	}
	virtual void compare(I2& o) {
		if (*this == o) {
			int a = 4; a++;
		}
	}
};

struct S2 : public I2 {
public:
	virtual int operator ==(I2& o) const {
		return this->c == o.c;
	}
};

class Base {
public:
	static int i;
	virtual void f() {}
};
class B1 : public Base {
public:
	static int i;
	virtual void f() {}
};
class B2 : public Base {
public:
	static int j;
	virtual void f() {}
};

int Base::i = 1;
int B1::i = 2;
int B2::j = 3;

int f(Base& bb) {
	return bb.i;
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.
	//S1 s2; 	s.cc(s2);
	/*
	S2	a, b;
	a.c	= 3;
	b.c	= 4;
	a.compare(b);
	*/

	Base b;
	B1 b1;
	B2 b2;

	b2.i = 4;
	int x;
	x=f(b);
	x = f(b1);
	x = f(b2);

	return 0;
}