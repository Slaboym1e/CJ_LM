#include <iostream>
#include "matrix.h"
#include "main.h"
int main()
{
	matrix m1(2, 2, 0);
	matrix m2(2, 2, 0);
	m1.Get_m(0, 0) = m2.Get_m(0, 0) = 1;
	m1.Get_m(1, 0) = m2.Get_m(1, 0) = 2;
	m1.Get_m(0, 1) = m2.Get_m(0, 1) = 5;
	m1.Get_m(1, 1) = m2.Get_m(1, 1) = 6;
	m2 = m1 * m2;
	std::cout << m2;
	return 0;
}