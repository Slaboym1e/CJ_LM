#include "matrix.h"
#include <fstream>

matrix::matrix(int rowSize, int colSize, int Init)
{
	this->rowsize = rowSize;
	this->colsize = colSize;
	__matrix = new int* [rowsize];
		for (int i = 0; i < rowsize; i++)
		{
			__matrix[i] = new int[colsize];
		}
		for (int i = 0; i < rowsize; i++)
		{
			for (int j = 0; j < colsize; j++)
			{
				__matrix[i][j] = Init;
			}
		}
}

matrix::matrix(char* fileName)
{
	std::ifstream _input;
	_input.open(fileName);
	_input >> rowsize >> colsize;
	__matrix = new int* [this->rowsize];
	for (int i = 0; i < rowsize; i++)
	{
		__matrix[i] = new int[colsize];
	}
	for (int i = 0; i < rowsize; i++)
	{
		for (int j = 0; j < colsize; j++)
		{
			_input >> __matrix[i][j];
		}
	}
	_input.close();
}

matrix::~matrix()
{

}

matrix matrix::transposition()
{
	matrix temp(this->colsize,this->rowsize,0);
	for (int i = 0; i < rowsize; i++)
	{
		for (int j = 0; j < colsize; j++)
		{
			temp.Get_m(j, i) = this->__matrix[i][j];
		}
	}
	return temp;
}

matrix& matrix::operator=(matrix cur_mat)
{
	for (int i = 0; i < rowsize; i++)
		delete[] __matrix[i];
	delete[] __matrix;
	this->rowsize = cur_mat.Get_rowSize();
	this->colsize = cur_mat.Get_colSize();
	__matrix = new int* [this->rowsize];
	for (int i = 0; i < rowsize; i++)
	{
		__matrix[i] = new int[colsize];
	}
	for (int i = 0; i < rowsize; i++)
	{
		for (int j = 0; j < colsize; j++)
		{
			__matrix[i][j]=cur_mat.Get_m(i,j);
		}
	}
	return *this;
}

std::ostream& operator<<(std::ostream& ostr, matrix& _matrix)
{
	for (int i = 0; i < _matrix.Get_colSize(); i++)
	{
		for (int j = 0; j < _matrix.Get_rowSize(); j++)
			ostr << _matrix.Get_m(j, i) << "\t";
		ostr << std::endl;
	}
	return ostr;
}

matrix matrix::operator+=(matrix mat2)
{
	if (rowsize != mat2.Get_rowSize() || colsize != mat2.Get_colSize())
		exit(EXIT_FAILURE);
	for(int i=0;i < rowsize;i++)
		for (int j = 0; j < colsize; j++)
		{
			__matrix[i][j] += mat2.Get_m(i, j);
		}
	return *this;
}

matrix operator+(matrix mat1, matrix mat2)
{
	if (mat1.Get_rowSize() != mat2.Get_rowSize() || mat1.Get_colSize() != mat2.Get_colSize())
		exit(EXIT_FAILURE);
	matrix TempMat(mat1.Get_rowSize(), mat1.Get_colSize(), 0);
	TempMat = mat1;
	TempMat += mat2;
	return TempMat;
}

matrix matrix::operator-=(matrix mat2)
{
	if (rowsize != mat2.Get_rowSize() || colsize != mat2.Get_colSize())
		exit(EXIT_FAILURE);
	for (int i = 0; i < rowsize; i++)
		for (int j = 0; j < colsize; j++)
		{
			__matrix[i][j] = __matrix[i][j] - mat2.Get_m(i, j);
		}
	return *this;
}

matrix operator-(matrix mat1, matrix mat2)
{
	if (mat1.Get_rowSize() != mat2.Get_rowSize() || mat1.Get_colSize() != mat2.Get_colSize())
		exit(EXIT_FAILURE);
	matrix TempMat(mat1.Get_rowSize(), mat1.Get_colSize(), 0);
	TempMat = mat1;
	TempMat -= mat2;
	return TempMat;
}

matrix operator*(matrix mat1,matrix mat2)
{
	if (mat1.Get_rowSize() != mat2.Get_colSize())
		exit(EXIT_FAILURE);
	matrix TempMat(mat1.Get_rowSize(), mat2.Get_colSize(), 0);
	for (int i = 0; i < TempMat.Get_rowSize(); i++)
		for (int j = 0; j < TempMat.Get_colSize(); j++)
			for(int k=0;k<mat2.Get_colSize();k++)
			TempMat.Get_m(i,j) += mat1.Get_m(i,k) * mat2.Get_m(k, j);
	return TempMat;
}
