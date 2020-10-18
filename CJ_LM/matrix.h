#pragma once
#include <vector>
class matrix
{
public:
	 matrix(int rowSize,int colSize,int Init);
	 matrix(char* fileName);
	 //matrix(matrix&);
	 //
	 ~matrix();
	//
	matrix transposition();
	//friend matrix operator*(matrix matrix1, matrix matrix2);//composition
	matrix& operator=(matrix cur_mat);
	inline int& Get_m(int x, int y) { return this->__matrix[x][y]; };
	inline int Get_rowSize() { return this->rowsize; };
	inline int Get_colSize() { return this->colsize; };
private:
	//std::vector<std::vector<int>>_matrix;
	int** __matrix;
	int rowsize, colsize;
};

