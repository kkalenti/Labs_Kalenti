// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <locale.h>
#include <math.h>


using namespace std;

int main() {

	/*int lab1(){
		setlocale(LC_ALL, "Rus");
	{
		//задания 2-5
		cout << "Student: Kalentev Konstantin Anatolevich Group: 427-3";
		system("pause");
		//return 0;
	}

	{
		int a = 5;
		int b = 3;
		cout << "\n Varaible a equals " << a;
		cout << "\n Varaible b equals " << b;
		cout << "\n Summ of a and b equals" << a + b;
		system("pause");
		//return 0;
	}

	{
		int a = 5;
		{
			int b = 3;
			int c = a + b;
			a = 7;
			int e;
		}
		//int d = c; ошибка компиляции
		int e;
		{
			int b = 7;
			//int a = 10; Ошибка компиляции
		}
		cout << a;
		system("pause");
		//return 0;
	}

	{
		//задание 6
		cout << "Проверка простого числа. Введите число.\n";
		int n;
		cin >> n;
		while (n <= 0) {
			cout << "Число введено некорректно. Введите число\n";
			cin >> n;
		}
		bool isValuePrime = true;
		int i; //= ++i + i++;
		for (i = 2; i < n; i++) {
			if (n % i != 0) {
				isValuePrime = false;
				break;
			}
		}
		if (isValuePrime) {
			cout << "n является простым числом\n";
		}
		else {
			cout << "n не является простым числом\n";
		}
		system("pause");
		return 0;
	}
	}*/
	int lab2() {
		int GetRoots(int a, int b, int c, double* x1, double* x2) {
			int discriminant;
			if (a && b && c) {
				discriminant = b * b + 4 * a*c;
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
			if ((!a && !b && c) || (!a && !b && !c) || (a && !b && !c)) return 0;
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

		int main() {
			setlocale(LC_ALL, "Rus");
			int coefficientA, coefficientB, coefficientC;
			cout << "Введите стрший коэффициент\n";
			cin >> coefficientA;
			cout << "Второй коэффициент\n";
			cin >> coefficientB;
			cout << "свободный член\n";
			cin >> coefficientC;
			double *firstRoot, *secondRoot;
			int numberOfRoots;
			numberOfRoots = GetRoots(coefficientA, coefficientB, coefficientC, firstRoot, secondRoot);
			if (numberOfRoots == 0) cout << "Нет решений";
			if (numberOfRoots == 1) cout << *firstRoot << "Одно решение";
			if (numberOfRoots == 2) cout << *firstRoot << " " << *secondRoot;
			system("pause");
			return 0;
		}
	}
}