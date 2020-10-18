#include <iostream>
#include "matrix.h"
#include "main.h"

matrix matrix_input()
{
	int temprow, tempcol;
	std::cout << "Input row quantity";
	std::cin >> temprow;
	std::cout << "Input col quantity";
	std::cin >> tempcol;
	matrix mat(temprow, tempcol, 0);
	std::cout << "Input matrix";
	for (int i = 0; i < tempcol; i++)
		for (int j = 0; j < temprow; j++)
			std::cin >> mat.Get_m(j, i);
	return mat;
}

int main()
{
	char select;
	do
	{
		system("cls");
		std::cout << "Selected option:\n1.Transpose the matrix\n2.To add up the matrix\n3.Subtract matrices\n4.Multiply matrices\n5.Exit\n";
		std::cin >> select;
		switch (select)
		{
		case '1':
		{
			matrix m1(0,0,0);
			m1 = matrix_input();
			std::cout << "/*******************************/\n";
			std::cout << "Original matrix\n" << m1 << std::endl;
			m1 = m1.transposition();
			std::cout <<"Transposed matrix\n" << m1 << std::endl;
			system("pause");
			break;
		}
		case '2':
		{
			matrix m1(0, 0, 0);
			std::cout << "First matrix\n";
			m1 = matrix_input();
			matrix m2(0, 0, 0);
			std::cout << "Second matrix\n";
			m2 = matrix_input();
			std::cout << "/*******************************/\n";
			std::cout << "First matrix\n" << m1 << std::endl;
			m1 += m2;
			std::cout << "Second matrix\n" << m2 << std::endl;
			std::cout << "/***************************/\n";
			std::cout << "Matrix sum\n" << m1 << std::endl;
			system("pause");
			break;
		}
		case '3':
		{
			matrix m1(0, 0, 0);
			std::cout << "First matrix\n";
			m1 = matrix_input();
			matrix m2(0, 0, 0);
			std::cout << "Second matrix\n";
			m2 = matrix_input();
			std::cout << "/*******************************/\n";
			std::cout << "First matrix\n" << m1 << std::endl;
			m1 -= m2;
			std::cout << "Second matrix\n" << m2 << std::endl;
			std::cout << "/***************************/\n";
			std::cout << "Matrix difference\n" << m1 << std::endl;
			system("pause");
			break;
		}
		case '4' :
		{
			matrix m1(0, 0, 0);
			std::cout << "First matrix\n";
			m1 = matrix_input();
			matrix m2(0, 0, 0);
			std::cout << "Second matrix\n";
			m2 = matrix_input();
			std::cout << "/*******************************/\n";
			std::cout << "First matrix\n" << m1 << std::endl;
			m1 = m1 * m2;
			std::cout << "Second matrix\n" << m2 << std::endl;
			std::cout << "/***************************/\n";
			std::cout << "Matrix composition\n" << m1 << std::endl;
			system("pause");
			break;
		}
		}
	} while (select != '5');
	return 0;
}