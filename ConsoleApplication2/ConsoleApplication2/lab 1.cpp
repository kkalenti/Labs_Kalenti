// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>


using namespace std;

int lab1() {
	//lab1
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
}