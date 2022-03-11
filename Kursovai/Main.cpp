
#include <iostream>
#include "Matrix.h"

using namespace std;


int main() {

	setlocale(0, "rus");
	srand(time(0));
	int command=0;
	int n;
	Matrix a;

	while (command==0) {
		cout << "Выберите что хотите сделать:" << endl <<
			"1-Создать и распечатать матрицу n*n строк(рандомные числа в промежутке [-10, 10])" << endl <<
			"2-Ввести новую матрицу n*n самому" << endl;
		cin >> command;
		if (command == 1) {
			a.random();
			cout << a;
		}
		else if (command == 2) {

			cin >> a;
			cout << a;
		}
		else {
			cout << "Другие комманды пока недоступны: " << endl;
			command = 0;
		}
	
	}
	while (true) {
		cout << "Выберите что хотите сделать:"<<endl<<
				"1-Создать и распечатать новую матрицу n*n строк(рандомные числа в промежутке [-10, 10])" << endl <<
				"2-Ввести новую матрицу n*n самому" << endl <<
				"3-Найти определитель матрицы" << endl <<
				"4-Транспортировать матрицу" << endl <<
				"5-Найти обратную матрицу" << endl <<
				"0-Закончить работу" << endl;
		cin >> command;
		if (command == 1) {
			a.random();
			cout << a;
		}
		else if (command == 2) {
			cin >> a;
			cout << a;
		}
		else if (command == 3) {

			cout << "Определитель равен: " << a.calculateDeterminant()<<endl;
		}
		else if (command == 4) {
			cout << "Транспонированая матрица равна:"<<endl;
			a.transposeMatrix();
			cout << a;
		}
		else if (command == 5) {
			a.inverseMatrix();
			cout << a;
		}
		else if(command == 0) {
			break;
		}
		else {
			cout << "Недопустимая команда" << endl;
		}
	}
	return 0;
}