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
	/*_matrix.resize(rowSize);
	for (int i = 0; i < _matrix.size(); i++)
	{
		_matrix[i].resize(colsize, Init);
	}*/
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
	//_matrix.resize(rowsize);
	/*for (int i = 0; i < _matrix.size(); i++)
	{
		_matrix[i].resize(colsize);
	}*/
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
	delete __matrix;
	this->rowsize = cur_mat.Get_rowSize();
	this->colsize = cur_mat.Get_colSize();
	__matrix = new int* [this->rowsize];
	for (int i = 0; i < rowsize; i++)
	{
		__matrix[i] = new int[colsize];
	}
	//this->__matrix.resize(rowsize);
	//for (int i = 0; i < _matrix.size(); i++)
	//{
	//	_matrix[i].resize(colsize);
	//}
	for (int i = 0; i < rowsize; i++)
	{
		for (int j = 0; j < colsize; j++)
		{
			__matrix[i][j]=cur_mat.Get_m(i,j);
		}
	}
	return *this;
}
//
//matrix operator*(matrix matrix1, matrix matrix2)
//{
//	return matrix();
//}
