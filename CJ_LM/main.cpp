#include <iostream>
#include "matrix.h"
#include "main.h"
int main()
{
	matrix m1(3, 3, 0);
	int counter = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			m1.Get_m(i, j) = counter;
			counter++;
		}
	matrix m2(3, 3, 1);
	//std::cout << m2;
	matrix m3(3, 3, 0);
	m3 = m1 - m2;
	std::cout << m1;
	std::cout << std::endl;
	std::cout << m2;
	std::cout << std::endl;
	std::cout << m3;

	return 0;
}