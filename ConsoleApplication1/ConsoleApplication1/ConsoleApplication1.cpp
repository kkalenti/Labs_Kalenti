// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main() {
	/*	cout << "Student: Kalentev Konstantin Anatolevich Group: 427-3";
	return 0;
	}

	{
	int a = 5;
	int b = 3;
	cout << "\n Varaible a equals " << a;
	cout << "\n Varaible b equals " << b;
	cout << "\n Summ of a and b equals" << a + b;
	return 0;
	} */


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
	return 0;
}
