int Quadratic_equation(const double a, const double b, const double c, double* x1, double* x2);
/** ****************************************************************************
* @brief finds the roots of the quadratic equation
* @param a teh coefficient of the X^2
* @param b the coefficient of the X
* @param c the free coefficient
* @param x1 the first root
* @param x2 the second root
*
* The function returns the number of roots (infinite_number_of_roots,
* No_real_roots, One_real_root, Two_real_roots) and records the roots at the
* transmitted addresses.
*/

int Linear_equation(const double a, const double b, double* x1);
/** ****************************************************************************
* @brief finds the root of the linear equation
* @param a the coefficient of the X
* @param b the free coefficient
* @param x1 the root
*
* The function returns the number of roots (infinite_number_of_roots,
* No_real_roots, One_real_root) and records the roots at the transmitted
* addresses.
*/

void Output_Roots(const int Number_of_Roots, double* x1, double* x2);
/** ****************************************************************************
* @brief outputs the roots of the quadratic equation
* @param Number_of_Roots the number of roots of the equation
* @param x1 the first root
* @param x2 the second root
*
* The function prints the value of the roots of the quadratic equation to the
* console or writes that there are No real roots or Infinite number of roots.
*/

int Comparison_with_Zero(const double Number);
/** ****************************************************************************
* @brief checks whether a number of type double == 0
* @param Number double number
*
* The function returns 1 if the number == 0 else returns 0.
*/

int Comparison(const double a, const double b);
/** ****************************************************************************
* @brief checks whether two numbers of the double type are equal
* @param a double number
* @param b double number
*
* The function returns 1 if the numbers are equal, otherwise it returns 0.
*/

double Checking_for_minus_zero(const double a);
/** ****************************************************************************
* @brief checks if the number != -0
* @param a double number
*
* The function returns a if a != -0 else return 0.
*/

void Unit_tests();
/** ****************************************************************************
* @brief checks the correctness of the function Quadratic_equation
*
* Checks the correctness of the root search function by running the program on
* different values and comparing its result with the real values.
*/

void Unit_test(int n, double a, double b, double c, double real_Roots, double real_x1, double real_x2, double* x1, double* x2);
/** ****************************************************************************
* @brief checks the results of the function by comparing with real values
* @param n test number
* @param a teh coefficient of the X^2
* @param b the coefficient of the X
* @param c the free coefficient
* @param real_Roots the number of roots of this equation
* @param real_x1 the first root of this equation
* @param real_x2 the second root of this equation
* @param x1 the first root is the result of the function
* @param x2 the second root is the result of the function
*
* The function compares the result of the function Quadratic_equation with the
* real number of roots and the values of the roots of the quadratic equation.
* If there is a mismatch, it outputs the real roots and the result of the work
* of Quadratic_equation.
*/

enum Numbers_of_roots {
	Infinite_number_of_roots = -1,
	No_real_roots,
	One_real_root,
	Two_real_roots
};
