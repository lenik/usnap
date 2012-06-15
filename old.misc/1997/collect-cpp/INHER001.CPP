
#include <iostream.h>

class a {
public:
	virtual void f1() {
		cout << "a::f1" << endl;
	}
	void xf2() { cout << "a::xf2" << endl; }
};

class b : public a {
public:
	virtual void f1() { cout << "b::f1" << endl; a::f1(); }
	void xf2() { cout << "b::xf2" << endl; a::xf2(); }
};

void mf(a &a1) {
	a1.f1();
}
void mxf(a *a1) {
	a1->vtbl[0].xf2();
	a1->xf2();
}

main() {
	b xxx;
	cout << ">>>>>>>>" << endl;
	mf(xxx);
	mxf(&xxx);

	return 0;
}
