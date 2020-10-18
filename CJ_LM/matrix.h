#pragma once
#include <iostream>
class matrix
{
public:
	 matrix(int rowSize,int colSize,int Init);
	 //
	 ~matrix();
	//
	matrix transposition();
	//friend matrix operator*(matrix matrix1, matrix matrix2);//composition
	//
	matrix& operator=(matrix cur_mat); 
	matrix operator+=(matrix mat2);
	friend matrix operator+(matrix mat1, matrix mat2);
	matrix operator-=(matrix mat2);
	friend matrix operator-(matrix mat1, matrix mat2);
	friend matrix operator*(matrix mat1,matrix mat2);
	//
	friend std::ostream& operator<<(std::ostream& ostr, matrix& _matrix); //output operator
	//
	inline double& Get_m(int x, int y) { return this->__matrix[x][y]; }; //you can change the return value
	inline int Get_rowSize() { return this->rowsize; };
	inline int Get_colSize() { return this->colsize; };
private:
	double** __matrix;
	int rowsize, colsize;
};

