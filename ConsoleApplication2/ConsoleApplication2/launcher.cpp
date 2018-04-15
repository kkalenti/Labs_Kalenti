#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <locale.h>
#include <time.h>
#include <conio.h>
#include "lab1.h"
#include "lab2.h"
#include "lab3.h"


using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	char keyOfTask;
	char keyOfLab;
	int numberOfLab;
	int numberOfTask;
	do {
		keyOfLab == NULL;
		numberOfLab == NULL;
		cout << "Выберите лабораторную работу:\n"
			"1.Основные элементы языка Си++\n"
			"2.Функции, указатели и адресная арифметика\n"
			"3.Массивы и строки\n\n";
		cin >> numberOfLab;
		switch (numberOfLab) {
		case 1: {
			lab1();
			break;
		}
		case 2: {
			do {
				keyOfTask == NULL;
				numberOfTask == NULL;
				cout << "Выберите номер задания:\n"
					"1.Расчет квадратных уравнений\n"
					"2.Расчет квадратных уравнений2\n"
					"3.Возведение в степень\n"
					"4.Угадать число\n\n";
				cin >> numberOfTask;
				switch (numberOfTask) {
				case 1: {
					Lab2_№1();
					break;
				}
				case 2: {
					Lab2_№2();
					break;
				}
				case 3: {
					Lab2_№3();
					break;
				}
				case 4: {
					Lab2_№4();
					break;
				}
				default: {
					cout << "Такого задания не существует";
					break;
				}
				}
				cout << "Если хотите продолжить выбор заданий, нажмите Enter,"
					"если хотите вернуться обратно, Backspace\n\n";
				keyOfTask = _getch();
			} while (keyOfTask != 8);
			break;
		}
		case 3: {
			do {
				keyOfTask == NULL;
				numberOfTask == NULL;
				cout << "Выберите номер задания:\n"
					"1.Сортировка массива\n"
					"2.Перемножение двух матриц\n"
					"3.Вычисление длины строки и вхождение в нее определенного символа\n"
					"4.Создание подстроки из введенной строки\n"
					"5.Работа с путем файла\n\n";
				cin >> numberOfTask;
				switch (numberOfTask) {
					case 1: {
						Lab3_№1();
						break;
					}
					case 2: {
						Lab3_№2();
						break;
					}
					case 3: {
						Lab3_№3();
						break;
					}
					case 4: {
						Lab3_№4();
						break;
					}
					case 5: {
						Lab3_№5();
						break;
					}
					default: {
						cout << "Такого задания не существует";				
						break;
					}
				}
				cout << "Если хотите продолжить выбор заданий, нажмите Enter," 
					"если хотите вернуться обратно, Backspace\n\n";
				keyOfTask = _getch();
			} while (keyOfTask != 8);
			break;
		}
		default:
			cout << "Не существует такой лабораторной работы\n";
			break;
		}
		cout << "Если хотите продолжить работу с лабораторными, нажмите Enter. "
			"В обратном случае, нажмите Backspace";
		keyOfLab = _getch();
	} while (keyOfLab != 8);
	return 0;
}