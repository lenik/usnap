
#include <complex.h>
#include <math.h>
#include <stdio.h>

void main() {

	double	w, h;
	double	L;
	double	al;
	double	angle_z;
	double	angle_m;
	int	t1 = 0, t2 = 0;
	complex	z;

	for (al = 0; al < 6.28; al += .01, t1++) {
		w	= cos(al) * 100;
		h	= sin(al) * 100;
		L	= sqrt(w * w + h * h);

		z	= complex(w, h);
		angle_z	= arg(z);

		angle_m	= atan2(h, w);

		printf("[%2.3lf] < %2.4lf   %2.4lf > ",
			al, angle_z, angle_m
		);

		if (abs(angle_z - angle_m) > 0.001) {
			printf(" <<<");
			t2++;
		}

		printf("\n");
	}
	printf("------\n");
	printf("diff at: %d/%d\n", t2, t1);
}
