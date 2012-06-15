#include <stdio.h>

#define pf(n)	printf("m%d = %d\n", n, m##n)

struct a {
	int m1;
	virtual void f1() {
		pf(1);
	}
};
struct b : public a {
	int m2;
	virtual void f1() {
		pf(2);
	}
};
struct c : public b {
	int m3;
	virtual void f1() {
		a::f1();
		b::f1();
		pf(3);
	}
	c::c(struct a ia) { m1 = m2 = m3 = 1000; }
};
struct w {
	int m4;
	void f1() {
		pf(4);
	}
};
struct v : public a {
	int m5;
	void f1() {
		pf(5);
	}
};

void ff(struct c ia) {ia.f1(); }

main() {
	class a i1;
	printf("HELLO -\n");
	i1.m1 = 111;
	i1.f1();
	printf("----- b\n");
	ff(i1);

}
