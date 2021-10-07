
#include <stdio.h>
#include <math.h>
int Checking_the_input_data(const double* a, const double* b, const double* c);
int Quadratic_equation(const double a, const double b, const double c, double* x1, double* x2);
int Linear_equation(const double a, const double b, double* x1);
void Output_Roots(const int Number_of_Roots, double* x1, double* x2);
int Comparison_with_Zero(const double Number);
int Comparison(const double a, const double b); //if a == b return 1. else return 0.
void Unit_tests();
void Unit_test(int n, double a, double b, double c, double result_Roots, double result_x1, double result_x2, double* x1, double* x2);
enum Numbers_of_roots_Quadratic_equation {
	Infinite_number_of_roots = -1,
	No_real_roots,
	One_real_root,
	Two_real_roots
};

int main()
{

	double a = NAN, b = NAN, c = NAN;
	double x1 = NAN, x2 = NAN;

	printf("Enter quadratic equation coefficients a b c:\n");
	scanf("%lf %lf %lf", &a, &b, &c); /*проверка на коэф. зациклить. документация. if def для юнит тестов*/

	if (a != NAN && b != NAN && c != NAN) { //??? ??? как писать проверку на вводимые значения
		int Number_of_Roots = Quadratic_equation(a, b, c, &x1, &x2);
		Output_Roots(Number_of_Roots, &x1, &x2);
	}
	else
		printf("ERROR");



	//Unit_tests();
}

void Unit_tests(){
	int num = 1;
	double x1 = NAN, x2 = NAN;
	// Unit_test(num++, a, b, c, result_Roots, result_x1, result_x1, &x1, &x2);
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
}

void Unit_test(int n, double a, double b, double c, double result_Roots, double result_x1, double result_x2, double* x1, double* x2){
	int Roots = Quadratic_equation(a, b, c, x1, x2);
	printf("*****TEST %d*****\n", n);
	if (result_Roots == 0 && result_Roots == Roots)
		printf("OK\n");
	else if (result_Roots == 1 && result_Roots == Roots && Comparison(result_x1, *x1))
		printf("OK\n");
	else if ((result_Roots == 2 && result_Roots == Roots) && (Comparison(result_x1, *x1) && Comparison(result_x2, *x2) || Comparison(result_x1, *x2) && Comparison(result_x2, *x1)))
		printf("OK\n");
	else if (result_Roots == Infinite_number_of_roots && result_Roots == Roots)
		printf("OK\n");
	else{
		printf("ERROR\n", result_Roots);
		printf("ERROR\nNumber_of_Roots = %d\n", result_Roots);
		int i;
		for (i = 1; i <= result_Roots; i++)
		{
			if (i == 1)
				printf("1) Real_Root = %lf, Root = %lf\n", result_x1, *x1);
			if (i == 2)
				printf("2) Real_Root = %lf, Root = %lf\n", result_x2, *x2);
		}
	}
}

int Quadratic_equation(const double a, const double b, const double c, double *x1, double *x2) {
	if (Comparison_with_Zero(a))
		return Linear_equation(b, c, x1);
	else if (Comparison_with_Zero(c)){
		Linear_equation(a, b, x1);
		*x2 = 0;
	}
	else
	{
		double D = b * b - 4.0 * a * c;
		if (D < 0)
			return No_real_roots;
		if (Comparison_with_Zero(D))
		{
			*x1 = -b / (2 * a);
			return One_real_root;
		}
		if (D > 0)
		{
			double square_root_of_D = 0;
			square_root_of_D = sqrt(D);
			*x1 = (-b + square_root_of_D) / (2 * a);
			*x2 = (-b - square_root_of_D) / (2 * a);
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
		*x1 = -b / a;
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

/*
int Checking_the_input_data(const double* a, const double* b, const double* c){
	if (a != NAN && b != NAN && c != NAN)
		return 1;
	return 0;
}
*/
