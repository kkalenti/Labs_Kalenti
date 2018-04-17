#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <locale.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include "lab1.h"
#include "lab2.h"
#include "lab3.h"
#include "lab4.h"


using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char key_of_task;
	char key_of_lab;
	bool exit_labs = true;
	do {
		key_of_lab == NULL;
		cout << "Выберите лабораторную работу:" << endl <<
			"1.Основные элементы языка Си++" << endl <<
			"2.Функции, указатели и адресная арифметика" << endl <<
			"3.Массивы и строки" << endl <<
			"4.Работа с динамической памятью" << endl <<
			"Backspace. Выход из программы" << endl << endl;
		key_of_lab = _getch();
		//TODO: Сами менюшки можно было бы прям в лабы перенести, так было бы правильнее, чтобы не захламлять общий лаунчер.
		switch (key_of_lab) {
			//TODO: Алярм, бл..., что за 49? Ты там совсем охуел?!) Всё должно быть понятно, какого хера я должен вспоминать ASCII, проверяя твою лабу?
			case 49: {	//первая лаба
			lab1();
			break;
		}
			case 50: { //вторая лаба
			bool exit_lab_two = true;
			do {
				system("cls");
				key_of_task == NULL;
				cout << "Лабораторная №1." << endl << "Выберите номер задания:" << endl <<
					"1.Расчет квадратных уравнений" << endl <<
					"2.Расчет квадратных уравнений2" << endl <<
					"3.Возведение в степень" << endl <<
					"4.Угадать число" << endl <<
					"Backspace. Перейти к выбору лабораторной" << endl << endl;
				key_of_task = _getch();
				system("cls");
				switch (key_of_task) {
					case 49: {	//первое задание второй лабы
						Lab2_№1();
						break;
					}
					case 50: {	//второе задание второй лабы
						Lab2_№2();
						break;
					}
					case 51: {	//третье задание второй лабы
						Lab2_№3();
						break;
					}
					case 52: {	//четвертое задание второй лабы
						Lab2_№4();
						break;
					}
					case 8: {	//выход из лабы
						exit_lab_two = false;
						break;
					}
					default: {
						cout << "Такого задания не существует";
						break;
					}
				}
			} while (exit_lab_two == true);
			break;
		}
			case 51: { // третья лаба
			bool exit_task_three = true;
			do {
				system("cls");
				key_of_task == NULL;
				cout << "Лабораторная №3." << endl << "Выберите номер задания:" << endl <<
					"1.Сортировка массива" << endl << 
					"2.Перемножение двух матриц" << endl <<
					"3.Вычисление длины строки и вхождение в нее определенного символа" << endl <<
					"4.Создание подстроки из введенной строки" << endl <<
					"5.Работа с путем файла" << endl << 
					"Backspace. Вернуться к выбору программы" << endl << endl;
				key_of_task = _getch();
				system("cls");
				switch (key_of_task) {
					case 49: {	 //первое задание третьей лабы
						Lab3_№1();
						break;
					}
					case 50: {	//второе задание третьей лабы
						Lab3_№2();
						break;
					}
					case 51: {	//третье задание третьей лабы
						Lab3_№3();
						break;
					}
					case 52: {	//четвертое задание третьей лабы
						Lab3_№4();
						break;
					}
					case 53: {	//пятое задание третьей лабы
						Lab3_№5();
						break;
					}
					case 8: {	//выход из лабы
						exit_task_three = false;
						break;
					}
					default: {
						cout << "Такого задания не существует\n";
						break;
					}
				}
			} while (exit_task_three == true);
			break;
		}
			case 52: { // четвертая лаба
			bool exit_task_four = true;
			do {
				system("cls");
				key_of_task == NULL;
				cout << "Лабораторная №4." << endl << "Выберите номер задания:" << endl <<
					"1.Выбор дня недели" << endl << 
					"2.Выбор месяца" << endl <<
					"3.Работа с цветом" << endl <<
					"4.Работа со структурами" << endl <<
					"Backspace. Перейти к выбору лабораторных" << endl << endl;
				key_of_task = _getch();
				system("cls");
				switch (key_of_task) {
					case 49: {	//первое задание четвертой лабы
						lab4_№1();
						break;
					}
					case 50: {	 //второе задание четверотй лабы
						lab4_№2();
						break;
					}
					case 51: {	//третье задание четвертой лабы
						lab4_№3();
						break;
					}
					case 52: { //четвертое задание четвертой лабы
						lab4_№4();
						break;
					}
					case 8: {
						exit_task_four = false;
						break;
					}
					default: {
						cout << "Такого задания не существует";
						break;
					}
				}
			} while (exit_task_four == true);
			break;
		}
			case 8: {
			exit_labs = false;
			break;
		}
			default:
				cout << "Не существует такой лабораторной работы" << endl;
				break;
			}
		} while (exit_labs == true);
	return 0;
}