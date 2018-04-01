#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <time.h>
#include "function.h"


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
	srand(time(NULL));
	int random;
	random = rand() % 10;
	cout << "Представлена игра, ты должен угадать число от 0 до 9.\nТвой вариант:";
	int number = 0;
	int counter = 0;
	number = CheckingTheLetter(number, "Нужно угадывать числа, а не буквы, попробуй еще раз\n");
	while (number != random) {
		if (number > random) {
			counter++;
			cout << "Ты не угадал, число меньше введенного, попробуй еще...\n";
			number = CheckingTheLetter(number, "Нужно угадывать числа, а не буквы, попробуй еще раз\n");
		}
		if (number < random) {
			counter++;
			cout << "Ты не угадал, число больше введенного, попробуй еше раз...\n";
			number = CheckingTheLetter(number, "Нужно угадывать числа, а не буквы, попробуй еще раз\n");
		}
	}
	counter++;
	cout << "Поздравляю! Ты угадал, количество твоих попыток:" << counter;
}

int lab2() {
	//2.3 Вычислить корни
	{
		int coefficientA = 0;
		int coefficientB = 0;
		int coefficientC = 0;
		cout << "Введите стрший коэффициент\n";
		coefficientA = CheckingTheLetter(coefficientA, "Ошибка ввода! Повторите ввод\n");
		cout << "Второй коэффициент\n";
		coefficientB = CheckingTheLetter(coefficientB, "Ошибка ввода! Повторите ввод\n");
		cout << "свободный член\n";
		coefficientC = CheckingTheLetter(coefficientC, "Ошибка ввода! Повторите ввод\n");
		double *firstRootPointer, *secondRootPointer;
		double firstRoot, secondRoot;
		firstRootPointer = &firstRoot;
		secondRootPointer = &secondRoot;
		int numberOfRoots;
		numberOfRoots = GetRoots1(coefficientA, coefficientB, coefficientC, firstRootPointer, secondRootPointer);
		switch (numberOfRoots) {
		case 0:
			cout << "Нет решений\n";
			break;
		case 1:
			cout << firstRoot << " (Одно решение)\n";
			break;
		case 2:
			cout << firstRoot << " " << secondRoot << "\n";
			break;
		default:
			cout << "Ошибка программы!";
			break;
		}
		system("pause");
		cout << "-------------------------------------------------------------------\n";
	}
	//2.4 Вычислить корни
	{
		int coefficientA = 0;
		int coefficientB = 0;
		int coefficientC = 0;
		cout << "Введите стрший коэффициент\n";
		coefficientA = CheckingTheLetter(coefficientA, "Ошибка ввода! Повторите ввод\n");
		cout << "Второй коэффициент\n";
		coefficientB = CheckingTheLetter(coefficientB, "Ошибка ввода! Повторите ввод\n");
		cout << "свободный член\n";
		coefficientC = CheckingTheLetter(coefficientC, "Ошибка ввода! Повторите ввод\n");
		double firstRoot;
		double secondRoot;
		double &firstRootLink = firstRoot;
		double &secondRootLink = secondRoot;
		int numberOfRoots;
		numberOfRoots = GetRoots2(coefficientA, coefficientB, coefficientC, firstRoot, secondRoot);
		switch (numberOfRoots) {
		case 0:
			cout << "Нет решений\n";
			break;
		case 1:
			cout << firstRoot << " (Одно решение)\n";
			break;
		case 2:
			cout << firstRoot << " " << secondRoot << "\n";
			break;
		default:
			cout << "Ошибка программы!";
			break;
		}
		system("pause");
		cout << "-------------------------------------------------------------------\n";
	}
	//2.7 Степень числа
	{
		int base = 0;
		int power = 0;
		cout << "Введите основание\n";
		base = CheckingTheLetter(base, "Ошибка ввода! Повторите ввод\n");
		cout << "Введите степень\n";
		power = CheckingTheLetter(power, "Ошибка ввода! Повторите ввод\n");
		base = GetPower(base, power);
		cout << "Результат:" << base << "\n";
		system("pause");
		cout << "-------------------------------------------------------------------\n";
	}
	//2.9 Угадай число
	{
		GuessNumber();
		system("pause");
		return 0;
	}
}