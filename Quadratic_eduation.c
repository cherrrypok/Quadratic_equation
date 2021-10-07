#include "Quadratic_eduation.h"


int Quadratic_equation(const double a, const double b, const double c, double *x1, double *x2) {
	if (Comparison_with_Zero(a))
    {
		return Linear_equation(b, c, x1);
    }

	else if (Comparison_with_Zero(c))
    {
		if (Linear_equation(a, b, x1) == One_real_root && !Comparison(*x1, 0))
        {
		      *x2 = 0;
              return Two_real_roots;
        }
        else
        {
            return One_real_root;
        }
	}

	else
	{
		double D = b * b - 4.0 * a * c;
		if (D < 0)
			return No_real_roots;
		if (Comparison_with_Zero(D))
		{
			*x1 = Checking_for_minus_zero(-b / (2 * a));
			return One_real_root;
		}
		if (D > 0)
		{
			double square_root_of_D = 0;
			square_root_of_D = sqrt(D);
			*x1 = Checking_for_minus_zero((-b + square_root_of_D) / (2 * a));
			*x2 = Checking_for_minus_zero((-b - square_root_of_D) / (2 * a));
			return Two_real_roots;
		}
	}
	return -1;
}

int Linear_equation(const double a, const double b, double* x1) {
	if (Comparison_with_Zero(a))
	{
		if (Comparison_with_Zero(b))
			return Infinite_number_of_roots;
		else
			return No_real_roots;
	}
	else
	{
		*x1 = Checking_for_minus_zero(-b / a);
		return One_real_root;
	}
}

void Output_Roots(const int Number_of_Roots, double* x1, double* x2) {
	switch (Number_of_Roots){
	case No_real_roots:
		printf("No real roots\n");
		break;
	case One_real_root:
		printf("One real root:\nx1 = %lf\n", *x1);
		break;
	case Two_real_roots:
		printf("Two real roots:\nx1 = %lf x2 = %lf\n", *x1, *x2);
		break;
	case Infinite_number_of_roots:
		printf("Infinite number of roots\n");
		break;
	default:
		printf("Unexpected number of roots. ERROR №%d\n", Number_of_Roots);
		break;
	}
}

int Comparison_with_Zero(const double Number) {
	double epsilon = 1e-6;
	if (fabs(Number) < epsilon) {
		return 1;
	}
	return 0;
}

int Comparison(const double a, const double b) {
	double epsilon = 1e-5;
	if (fabs(a - b) < epsilon) {
		return 1;
	}
	return 0;
}

double Checking_for_minus_zero(const double a){
    if (Comparison(a, -0))
        return 0;
    return a;
}

void Unit_tests(){
	int num = 1;
	double x1 = NAN, x2 = NAN;
	// Unit_test(num++, a, b, c, real_Roots, real_x1, real_x1, &x1, &x2);
	Unit_test(num++, 1, 2, 1, 1, -1, NAN, &x1, &x2);
	Unit_test(num++, 0, 0, 0, -1, NAN, NAN, &x1, &x2);
	Unit_test(num++, 0, 0, 100, 0, NAN, NAN, &x1, &x2);
	Unit_test(num++, 0, 100, 0, 1, 0, NAN, &x1, &x2);
	Unit_test(num++, 0, 100, -100, 1, 1, NAN, &x1, &x2);
	Unit_test(num++, 0, 50, 5, 1, -0.1, NAN, &x1, &x2);
	Unit_test(num++, 1, 2, -3, 2, -3, 1, &x1, &x2);
	Unit_test(num++, 1, 7, 10, 2, -2, -5, &x1, &x2);
	Unit_test(num++, 1, -12, 35, 2, 5, 7, &x1, &x2);
	Unit_test(num++, 5, -25, 20, 2, 1, 4, &x1, &x2);
	Unit_test(num++, 6, 666, 6666, 2, -11.123768, -99.876232, &x1, &x2);
    Unit_test(num++, 1, 0, 0, 1, 0, NAN, &x1, &x2);
    Unit_test(num++, 1, 1, 0, 2, 0, -1, &x1, &x2);
}

void Unit_test(int n, double a, double b, double c, double real_Roots, double real_x1, double real_x2, double* x1, double* x2){
	int Roots = Quadratic_equation(a, b, c, x1, x2);
	printf("*****TEST %d*****\n", n);
	if (real_Roots == 0 && real_Roots == Roots)
		printf("OK\n");
	else if (real_Roots == 1 && real_Roots == Roots && Comparison(real_x1, *x1))
		printf("OK\n");
	else if ((real_Roots == 2 && real_Roots == Roots) && (Comparison(real_x1, *x1) && Comparison(real_x2, *x2) || Comparison(real_x1, *x2) && Comparison(real_x2, *x1)))
		printf("OK\n");
	else if (real_Roots == Infinite_number_of_roots && real_Roots == Roots)
		printf("OK\n");
	else{
		printf("ERROR\n", real_Roots);
		printf("ERROR\nNumber_of_Roots = %d\n", real_Roots);
		int i;
		for (i = 1; i <= real_Roots; i++)
		{
			if (i == 1)
				printf("1) Real_Root = %lf, Root = %lf\n", real_x1, *x1);
			if (i == 2)
				printf("2) Real_Root = %lf, Root = %lf\n", real_x2, *x2);
		}
	}
}
