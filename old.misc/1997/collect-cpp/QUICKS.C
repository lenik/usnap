#include <stdio.h>

#define N	9

void quicksort(int r[], int p, int q) {
	int i, j, x;
	int b = 0;

	for (i = p, j = q, x = r[i]; i < j;) {
		if (r[j--] < x && !b) { b = 1; r[i++] = r[++j]; } else continue;
		(r[i++] > x && b ) && ( b = 0, r[j--] = r[--i] );
	}
	r[i] = x;
	if (i > p + 1) quicksort(r, p, i - 1);
	if (j < q - 1) quicksort(r, j + 1, q);
}

main() {
	int a[N] = { 3, 7, 10, 4, 100, 25, 33, 1, 67 };
	int i;
	for (i = 0; i < N; i++) printf("%5d", a[i]);
	printf("\n");
	quicksort(a, 0, N - 1);
	for (i = 0; i < N; i++) printf("%5d", a[i]);
	printf("\n");
}
