#include "stdafx.h"
#include <iostream>
#include <locale.h>
#include <math.h>
#include <ctime>

using namespace std;

int GetRoots1(int a, int b, int c, double* x1, double* x2) {
	int discriminant;
	if (a && b && c){
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
	if ((!a && !b && c) || (!a && !b && !c) || (a && !b && !c) || (!a && b && !c))return 0;
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

int GetRoots2(int a, int b, int c, double& x1, double& x2) {
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
	if ((!a && !b && c) || (!a && !b && !c) || (a && !b && !c) || (!a && b && !c))return 0;
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
		base * GetPower(base, power);
		return base * GetPower(base, power);
	}
	else return base;
}

void GuessNumber() {
	srand(time(NULL));
	int random;
	random = rand() % 10;
	cout << "������������ ����, �� ������ ������� ����� �� 0 �� 9.\n���� �������:";
	int number, counter = 0;
	while (!(cin >> number) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "����� ��������� �����, � �� �����, �������� ��� ���\n";
	}
	while (number != random) {
		if (number > random) {
			counter++;
			cout << "�� �� ������, ����� ������ ����������, �������� ���...\n";
			while (!(cin >> number) || (cin.peek() != '\n')) {
				cin.clear();
				while (cin.get() != '\n');
				cout << "����� ��������� �����, � �� �����, �������� ��� ���\n";
			}
		}
		if (number < random) {
			counter++;
			cout << "�� �� ������, ����� ������ ����������, �������� ��� ���...\n";
			while (!(cin >> number) || (cin.peek() != '\n')) {
				cin.clear();
				while (cin.get() != '\n');
				cout << "����� ��������� �����, � �� �����, �������� ��� ���\n";
			}
		}
	}
	counter++;
	cout << "����������! �� ������, ���������� ����� �������:" << counter;
}

int main(){
	setlocale(LC_ALL, "Rus");
	{
		int coefficientA, coefficientB, coefficientC;
		cout << "������� ������ �����������\n";
		while (!(cin >> coefficientA) || (cin.peek() != '\n')) {
			cin.clear();
			while (cin.get() != '\n');
			cout << "������ �����! ��������� ����\n";
		}
		cout << "������ �����������\n";
		while (!(cin >> coefficientB) || (cin.peek() != '\n')) {
			cin.clear();
			while (cin.get() != '\n');
			cout << "������ �����! ��������� ����\n";
		}
		cout << "��������� ����\n";
		while (!(cin >> coefficientC) || (cin.peek() != '\n')) {
			cin.clear();
			while (cin.get() != '\n');
			cout << "������ �����! ��������� ����\n";
		}
		double *firstRootLink, *secondRootLink, firstRoot, secondRoot;
		firstRootLink = &firstRoot;
		secondRootLink = &secondRoot;
		int numberOfRoots;
		numberOfRoots = GetRoots1(coefficientA, coefficientB, coefficientC, firstRootLink, secondRootLink);
		if (numberOfRoots == 0) cout << "��� �������\n";
		if (numberOfRoots == 1) cout << firstRoot << " (���� �������)\n";
		if (numberOfRoots == 2) cout << firstRoot << " " << secondRoot << "\n";
		system("pause");
	}
	{
		int coefficientA, coefficientB, coefficientC;
		cout << "������� ������ �����������\n";
		while (!(cin >> coefficientA) || (cin.peek() != '\n')) {
			cin.clear();
			while (cin.get() != '\n');
			cout << "������ �����! ��������� ����\n";
		}
		cout << "������ �����������\n";
		while (!(cin >> coefficientB) || (cin.peek() != '\n')) {
			cin.clear();
			while (cin.get() != '\n');
			cout << "������ �����! ��������� ����\n";
		}
		cout << "��������� ����\n";
		while (!(cin >> coefficientC) || (cin.peek() != '\n')) {
			cin.clear();
			while (cin.get() != '\n');
			cout << "������ �����! ��������� ����\n";
		}
		double firstRoot, secondRoot;
		double &firstRootLink = firstRoot, &secondRootLink = secondRoot;
		int numberOfRoots;
		numberOfRoots = GetRoots2(coefficientA, coefficientB, coefficientC, firstRootLink, secondRootLink);
		if (numberOfRoots == 0) cout << "��� �������\n";
		if (numberOfRoots == 1) cout << firstRoot << " (���� �������)\n";
		if (numberOfRoots == 2) cout << firstRoot << " " << secondRoot << "\n";
		system("pause");
	}
	{
		int base, power;
		cout << "������� ���������\n";
		while (!(cin >> base) || (cin.peek() != '\n')) {
			cin.clear();
			while (cin.get() != '\n');
			cout << "������ �����! ��������� ����\n";
		}
		cout << "������� �������\n";
		while (!(cin >> power) || (cin.peek() != '\n')) {
			cin.clear();
			while (cin.get() != '\n');
			cout << "������ �����! ��������� ����\n";
		}
		base = GetPower(base, power);
		cout << "���������:" << base;
		system("pause");
		return 0;
	}
	{
		GuessNumber();
		system("pause");
		return 0;
	}
}