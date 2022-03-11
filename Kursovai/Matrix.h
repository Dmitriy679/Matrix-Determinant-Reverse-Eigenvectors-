#pragma once;
#include <iostream>
using namespace std;
class Matrix {
public:
	double** Matr;
	int size;
	void getNewMatrix(int row, int col, Matrix newMatrix);
	Matrix(int n);
	~Matrix();
	Matrix();

		double calculateDeterminant();
		void random();
		void  transposeMatrix();
		void inverseMatrix();


		friend ostream& operator<<(ostream& out, Matrix x);
		friend istream& operator>>(istream& in, Matrix& x);
		
};

