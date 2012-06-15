
#include <stdio.h>

int f(int x, int a[], int n) {
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x > a[mid]) high = mid - 1;
		else if (x < a[mid]) low = mid + 1;
		else return mid;
	}
	return -1;
}

main() {
	static int a[] = { 4, 3, 2, 1, 0 };
	printf("%d\n", f(3, a, 5));
}
