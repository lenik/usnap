#include <stdio.h>
#include <iostream.h>

class c {
	char *name;
public:
	c(char *n) { name = n ; cout << "\t" << name << "\tConstructed\n"; }
	~c() { cout << "\t" << name << "\tDestructed! \n"; }
};

#define outaddr(a, n) do { cout << a; printf("\t%lX\n", (c far *)&n); } while (0)

void f01(c i01) {
	outaddr("f01", i01);
}

void f02(c &i02) {
	outaddr("f02", i02);
}

void f03(c *i03) {
	outaddr("f02", *i03);
}

void main() {
	cout << "begin.....................\n";
	c inst01("inst01");
	c inst02("inst02");
	c inst03("inst03");
	outaddr("inst01", inst01);
	f01(inst01);
	outaddr("inst02", inst02);
	f02(inst02);
	outaddr("inst03", inst03);
	f03(&inst03);
	cout << "well done!\n";
}
