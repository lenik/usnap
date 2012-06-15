#include <math.h>

#define x	(double)0.5

void main() {
	double i = 1, t = x, s = t;

	while (fabs(t) > 0.00001) {
		i = i + 2;
		t = t * x * x * (i - 2) / i;
		s = s + t;
	}

	printf("%f\n", s);
	return;
}
