#include <iostream>
#include "matrix.h"
#include "main.h"
int main()
{
	matrix m1(2, 3, 1);
	matrix m2(1, 1, 0);
	m1.Get_m(0, 0) = 3;
	m1.Get_m(1, 0) = 2;
	m1.Get_m(0, 1) = 4;
	m2 = m1.transposition();
//	std::cout << m2.Get_m(1, 0) << std::endl;
	return 0;
}