#pragma once;

#include <iostream>
#include "Matrix.h"




	void Matrix::getNewMatrix(int row, int col, Matrix newMatrix) {

		int jumpVariableRow = 0;
		int jumpVariableCol = 0;
		for (int i = 0; i < size - 1; i++) {
			if (i == row) {
				jumpVariableRow = 1;
			}

			jumpVariableCol = 0;
			for (int j = 0; j < size - 1; j++) {

				if (j == col) {

					jumpVariableCol = 1;
				}
				newMatrix.Matr[i][j] = Matr[jumpVariableRow + i][j + jumpVariableCol];
			}
		}
	}

	Matrix::Matrix(int n) {
		size = n;
		Matr = new double* [n];
		for (int i = 0; i < n; i++)
		{
			Matr[i] = new double[n];
		}
	}
	Matrix::Matrix() {}
	Matrix::~Matrix() {
		/*for (int i = 0; i < size; i++)
		{
			delete[] Matr[i];
		}
		delete[] Matr;*/
	}
	double Matrix::calculateDeterminant() {

		if (size == 1) {

			return Matr[0][0];
		}
		if (size == 2) {

			return Matr[0][0] * Matr[1][1] - Matr[0][1] * Matr[1][0];
		}
		double determinant = 0;
		Matrix newMatrix(size - 1);

		for (int j = 0; j < size; j++) {

			getNewMatrix(0, j, newMatrix);
			determinant += (pow(-1, j) * Matr[0][j] * newMatrix.calculateDeterminant());
		}
		return determinant;
	}
	void Matrix::random() {

		cout << "¬ведите количество строк и столбцов:" << endl;
		cin >> size;
		Matr = new double* [size];
		for (int i = 0; i < size; i++) {

			Matr[i] = new double[size];
			for (int j = 0; j < size; j++)
			{
				Matr[i][j] = (-10 + rand() % 21);
			}
		}

	}
	void  Matrix::transposeMatrix() {
		for (int i = 0; i < size; i++) {

			for (int j = i; j < size; j++) {

				swap(Matr[i][j], Matr[j][i]);
			}
		}
	}
	void Matrix::inverseMatrix() {

		double determinant = calculateDeterminant();
		if (determinant == 0) {

			cout << "ќбратной матрицы не существует." << endl;
			return;
		}
		cout << "ќбратна€ матрица равна:" << endl;

		if (size == 1) {
			cout << pow(Matr[0][0], -1) << endl;
			return;
		}
		Matrix algebraicComplement(size);
		Matrix newMatrix(size - 1);
		for (int i = 0; i < size; i++) {

			for (int j = 0; j < size; j++) {

				getNewMatrix(i, j, newMatrix);
				algebraicComplement.Matr[i][j] = pow(-1, i + j) * newMatrix.calculateDeterminant() / determinant;
			}
		}
		algebraicComplement.transposeMatrix();
		*this = algebraicComplement;
	}

	//что то придумать с удалением
	ostream& operator<<(ostream& out, Matrix x)
	{
		for (int i = 0; i < x.size; i++)
		{
			for (int j = 0; j < x.size; j++)
			{
				cout << x.Matr[i][j] << "\t";
			}
			cout << endl;
		}
		return out;
	}

	istream& operator>>(istream& in, Matrix& x)
	{

		cout << "¬ведите количество строк и столбцов:" << endl;
		cin >> x.size;
		cout << "¬ведите значени€ матрицы:" << endl;
		x.Matr = new double* [x.size];
		for (int i = 0; i < x.size; i++)
		{
			x.Matr[i] = new double[x.size];
			for (int j = 0; j < x.size; j++)
			{
				cin >> x.Matr[i][j];
			}
		}
		return in;
	}



