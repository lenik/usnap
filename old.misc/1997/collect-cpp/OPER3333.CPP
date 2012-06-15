
#include <stdio.h>

typedef struct _age {
	int v;
} age;

void f(int) {}
void f(long) {}
void f(char *) {}
void f(int *) {}

template <class T>
void x(T *m) {
	T x = *m;
	printf("%ld, %lx\n", (long)m, (long)m);
	printf("[0]: %d, %x, '%c'\n", x, x, x);
}

template <class T>
void y(T xxx) {
	printf("the %d-bit version of template\n", sizeof(xxx));
}
template <class T>
void f1(T x) {
	printf("the %d-bit version of template\n", sizeof(x) * 8);
	}

void main() {
//	char *s = "HH";
//	x(s);
	y(3);
	f1<char>(3);
}