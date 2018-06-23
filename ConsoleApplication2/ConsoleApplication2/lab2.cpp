#include "stdafx.h"
#include <iostream>
#include <math.h>
#include "functions.h"


using namespace std;

int GetRoots1(int a, int b, int c, double* x1, double* x2) {
	int discriminant;
	if (a && b && c) {
		discriminant = b * b - 4 * a*c;
		if (discriminant < 0) {
			return 0;
		}
		if (discriminant == 0) {
			*x1 = -b / (2 * a);
			return 1;
		}
		if (discriminant > 0) {
			*x1 = (-b + sqrt(discriminant)) / (2 * a);
			*x2 = (-b - sqrt(discriminant)) / (2 * a);
			return 2;
		}
	}
	if (!a && b && c) {
		*x1 = (-c) / b;
		return 1;
	}
	if ((!a && !b && c) || (!a && !b && !c))return 0;
	if ((a && !b && !c) || (!a && b && !c)) {
		*x1 = 0;
		return 1;
	}
	if (a && !b && c) {
		*x1 = sqrt((-c) / a);
		*x2 = -sqrt((-c) / a);
		return 2;
	}
	if (a && b && !c) {
		*x1 = 0;
		*x2 = (-b) / a;
		return 2;
	}
}

int GetRoots2(const int& a, const int& b, const int &c, double& x1, double& x2) {
	int discriminant;
	if (a && b && c) {
		discriminant = b * b - 4 * a*c;
		if (discriminant < 0) {
			return 0;
		}
		if (discriminant == 0) {
			x1 = -b / (2 * a);
			return 1;
		}
		if (discriminant > 0) {
			x1 = (-b + sqrt(discriminant)) / (2 * a);
			x2 = (-b - sqrt(discriminant)) / (2 * a);
			return 2;
		}
	}
	if (!a && b && c) {
		x1 = (-c) / b;
		return 1;
	}
	if ((!a && !b && c) || (!a && !b && !c))return 0;
	if ((a && !b && !c) || (!a && b && !c)) {
		x1 = 0;
		return 1;
	}
	if (a && !b && c) {
		x1 = sqrt((-c) / a);
		x2 = -sqrt((-c) / a);
		return 2;
	}
	if (a && b && !c) {
		x1 = 0;
		x2 = (-b) / a;
		return 2;
	}
}

int GetPower(int base, int power) {
	if (power > 1) {
		power--;
		return base * GetPower(base, power);
	}
	else return base;
}

void GuessNumber() {
	int random = rand() % 10;
	cout << "������������ ����, �� ������ ������� ����� �� 0 �� 9.\n���� �������:";
	int number = 0;
	int counter = 0;
	CheckingOfCorrectInputOfNumber(&number,
		"����� ��������� �����, � �� �����, �������� ��� ���\n");
	while (number != random) {
		if (number > random) {
			counter++;
			cout << "�� �� ������, ����� ������ ����������, �������� ���...\n";
			CheckingOfCorrectInputOfNumber(&number, 
				"����� ��������� �����, � �� �����, �������� ��� ���\n");
		}
		if (number < random) {
			counter++;
			cout << "�� �� ������, ����� ������ ����������, �������� ��� ���...\n";
			CheckingOfCorrectInputOfNumber(&number,
				"����� ��������� �����, � �� �����, �������� ��� ���\n");
		}
	}
	counter++;
	cout << "����������! �� ������, ���������� ����� �������:" << counter << endl;
	system("pause");
}

	void Lab2_�1(){
		int coefficient_a = 0;
		int coefficient_b = 0;
		int coefficient_c = 0;
		cout << "������� ������ �����������\n";
		CheckingOfCorrectInputOfNumber(&coefficient_a,
			"������ �����! ��������� ����\n");
		cout << "������ �����������\n";
		CheckingOfCorrectInputOfNumber(&coefficient_b, 
			"������ �����! ��������� ����\n");
		cout << "��������� ����\n";
		CheckingOfCorrectInputOfNumber(&coefficient_c,
			"������ �����! ��������� ����\n");
		double *first_root_pointer, *second_root_pointer;
		double first_root, second_root;
		first_root_pointer = &first_root;
		second_root_pointer = &second_root;
		int number_of_roots;
		number_of_roots = GetRoots1(coefficient_a, coefficient_b,
			coefficient_c, first_root_pointer, second_root_pointer);
		switch (number_of_roots) {
			case 0:
				cout << "��� �������\n";
				break;
			case 1:
				cout << first_root << " (���� �������)\n";
				break;
			case 2:
				cout << first_root << " " << second_root << "\n";
				break;
			default:
				cout << "������ ���������!";
				break;
		}
		system("pause");
	}

	void Lab2_�2(){
		int coefficient_a = 0;
		int coefficient_b = 0;
		int coefficient_c = 0;
		cout << "������� ������ �����������\n";
		CheckingOfCorrectInputOfNumber(&coefficient_a,
			"������ �����! ��������� ����\n");
		cout << "������ �����������\n";
		CheckingOfCorrectInputOfNumber(&coefficient_b,
			"������ �����! ��������� ����\n");
		cout << "��������� ����\n";
		CheckingOfCorrectInputOfNumber(&coefficient_c, 
			"������ �����! ��������� ����\n");
		double first_root;
		double second_root;
		double &first_root_link = first_root;
		double &second_root_link = second_root;
		int number_of_roots;
		number_of_roots = GetRoots2(coefficient_a, coefficient_b,
			coefficient_c, first_root, second_root);
		switch (number_of_roots) {
			case 0:
				cout << "��� �������\n";
				break;
			case 1:
				cout << first_root << " (���� �������)\n";
				break;
			case 2:
				cout << first_root << " " << second_root << "\n";
				break;
			default:
				cout << "������ ���������!";
				break;
		}
		system("pause");
	}

	void Lab2_�3(){
		int base = 0;
		int power = 0;
		cout << "������� ���������\n";
		CheckingOfCorrectInputOfNumber(&base, 
			"������ �����! ��������� ����\n");
		cout << "������� �������\n";
		CheckingOfCorrectInputOfNumber(&power, 
			"������ �����! ��������� ����\n");
		base = GetPower(base, power);
		cout << "���������:" << base << "\n";
		system("pause");
	}

	void Lab2_�4(){
		GuessNumber();
		system("pause");
	}