#include <stdio.h>
#include <math.h>
#include "Quadratic_eduation.c"
//#define UNIT_TEST 1

int main() {
	#ifndef UNIT_TEST
	double a = NAN, b = NAN, c = NAN;
	double x1 = NAN, x2 = NAN;

	printf("Enter quadratic equation coefficients a b c:\n"
		   "Or text if you want to finish.\n");

	while (scanf("%lf %lf %lf", &a, &b, &c) && !isnan(a) && !isnan(b) && !isnan(c)) {
		int Number_of_Roots = Quadratic_equation(a, b, c, &x1, &x2);
		Output_Roots(Number_of_Roots, &x1, &x2);

		a = NAN, b = NAN, c = NAN;
	}

	#else
	Unit_tests();

	#endif
}
