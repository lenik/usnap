#include <stdio.h>

template <class T> T min(T a, T b) { return a < b ? a : b; }

void main() {
	printf("%d\n", min(100, 6));
}
