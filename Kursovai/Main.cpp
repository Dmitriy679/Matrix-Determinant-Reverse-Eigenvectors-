
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
		cout << "�������� ��� ������ �������:" << endl <<
			"1-������� � ����������� ������� n*n �����(��������� ����� � ���������� [-10, 10])" << endl <<
			"2-������ ����� ������� n*n ������" << endl;
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
			cout << "������ �������� ���� ����������: " << endl;
			command = 0;
		}
	
	}
	while (true) {
		cout << "�������� ��� ������ �������:"<<endl<<
				"1-������� � ����������� ����� ������� n*n �����(��������� ����� � ���������� [-10, 10])" << endl <<
				"2-������ ����� ������� n*n ������" << endl <<
				"3-����� ������������ �������" << endl <<
				"4-���������������� �������" << endl <<
				"5-����� �������� �������" << endl <<
				"0-��������� ������" << endl;
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

			cout << "������������ �����: " << a.calculateDeterminant()<<endl;
		}
		else if (command == 4) {
			cout << "���������������� ������� �����:"<<endl;
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
			cout << "������������ �������" << endl;
		}
	}
	return 0;
}