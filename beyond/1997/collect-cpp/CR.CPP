#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

#define epsilon		0.5

typedef double (*F1_Call)(double a, double b);

double f1(double a, double b) { return a + b; }
double f2(double a, double b) { return a - b; }
double f3(double a, double b) { return a * b; }
double f4(double a, double b) { return a / b; }
double f5(double a, double b) { return (long)a % (long)b; }
double f6(double a, double b) { if (abs(b) > 3) b = 3; return pow(a, b); }

void main() {
	double rNums[5][12] = {
		{ 4550.0f, 4550.0f, -1.0f, -1.0f, 9550.0f, 1590.0f, 9571.0f, 1611.0f, 2.10f, 0.35f, 0.206f, 0.206f, },
		{ 4550.0f, 9100.0f, -1.0f, -1.0f, 50000.0f, 4040.0f, 50113.0f, 4153.0f, 5.51f, 0.46f, 0.907f, 1.125f, },
		{ 4550.0f, 13650.0f, 4000.0f, 4000.0f, 50000.0f, 2965.0f, 54324.0f, 7289.0f, 3.98f, 0.53f, 2.048f, 3.240f, },
		{ 4550.0f, 27300.0f, 4000.0f, 8000.0f, 50000.0f, 8355.0f, 59521.0f, 17876.0f, 2.18f, 0.65f, 5.004f, 15.212f, },
		{ 4550.0f, 40950.0f, 4000.0f, 12000.0f, 50000.0f, 14485.0f, 65712.0f, 30197.0f, 1.60f, 0.74f, 7.427f, 3.7116f, }
	};

	int i1, i2, ir;

	F1_Call opCallbacks[] = {
		f1, f2, f3, f4, f5, f6
	};

	int p;
	for (i1 = 0; i1 < 5; i1++) {
		for (i2 = 0; i2 < 11; i2++) {
			int ii1, ii2;
			for (ii1 = i1; ii1 < i1+1; ii1++) {
				for (ii2 = 0; ii2 < 5; ii2++) {
					for (ir = 0; ir < sizeof(opCallbacks) / sizeof(F1_Call); ir++) {
						if (ir != 0) continue;
						double result;
						result = (*opCallbacks[ir])(rNums[i1][i2], rNums[ii1][ii2]);
						if (abs(result - rNums[i1][8]) < epsilon) {
							printf("an approx value: i1 = %d, i2 = %d, i^ = %d, i_ = %d, ir = %d, app->%f\n",
								i1, i2, ii1, ii2, ir, result - rNums[i1][8]);
							p++;
							if (p % 20 == 0) {
								printf(".....");
								getch();
							}
						}
					}
				}
			}
		}
	}

}
