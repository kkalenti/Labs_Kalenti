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
	cout << "����������! �� ������, ���������� ����� �������:" << counter;
}

	void Lab2_�1(){
		int coefficientA = 0;
		int coefficientB = 0;
		int coefficientC = 0;
		cout << "������� ������ �����������\n";
		CheckingOfCorrectInputOfNumber(&coefficientA,
			"������ �����! ��������� ����\n");
		cout << "������ �����������\n";
		CheckingOfCorrectInputOfNumber(&coefficientB, 
			"������ �����! ��������� ����\n");
		cout << "��������� ����\n";
		CheckingOfCorrectInputOfNumber(&coefficientC,
			"������ �����! ��������� ����\n");
		double *firstRootPointer, *secondRootPointer;
		double firstRoot, secondRoot;
		firstRootPointer = &firstRoot;
		secondRootPointer = &secondRoot;
		int numberOfRoots;
		numberOfRoots = GetRoots1(coefficientA, coefficientB,
			coefficientC, firstRootPointer, secondRootPointer);
		switch (numberOfRoots) {
			case 0:
				cout << "��� �������\n";
				break;
			case 1:
				cout << firstRoot << " (���� �������)\n";
				break;
			case 2:
				cout << firstRoot << " " << secondRoot << "\n";
				break;
			default:
				cout << "������ ���������!";
				break;
		}
		system("pause");
		cout << "-------------------------------------------------------------------\n";
	}

	void Lab2_�2(){
		int coefficientA = 0;
		int coefficientB = 0;
		int coefficientC = 0;
		cout << "������� ������ �����������\n";
		CheckingOfCorrectInputOfNumber(&coefficientA,
			"������ �����! ��������� ����\n");
		cout << "������ �����������\n";
		CheckingOfCorrectInputOfNumber(&coefficientB,
			"������ �����! ��������� ����\n");
		cout << "��������� ����\n";
		CheckingOfCorrectInputOfNumber(&coefficientC, 
			"������ �����! ��������� ����\n");
		double firstRoot;
		double secondRoot;
		double &firstRootLink = firstRoot;
		double &secondRootLink = secondRoot;
		int numberOfRoots;
		numberOfRoots = GetRoots2(coefficientA, coefficientB,
			coefficientC, firstRoot, secondRoot);
		switch (numberOfRoots) {
			case 0:
				cout << "��� �������\n";
				break;
			case 1:
				cout << firstRoot << " (���� �������)\n";
				break;
			case 2:
				cout << firstRoot << " " << secondRoot << "\n";
				break;
			default:
				cout << "������ ���������!";
				break;
		}
		system("pause");
		cout << "-------------------------------------------------------------------\n";
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
		cout << "-------------------------------------------------------------------\n";
	}

	void Lab2_�4(){
		GuessNumber();
		system("pause");
	}