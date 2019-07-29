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
#include "lab5.h"
#include "lab6.h"
#include "lab7.h"
#include "menus.h"
#include "num_enumeration.h"


using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char key_of_task;
	char key_of_lab;
	bool is_exit_labs = true;
	do {
		system("cls");
		key_of_lab = 0;
		GeneralMenu();
		while (key_of_lab == 0) {
		key_of_lab = _getch();
		}
		switch (key_of_lab) {
			case '1': {	//первая лаба
				system("cls");
				lab1();
				break;
			}
			case num_2: { //вторая лаба
			bool is_exit_lab_two = true;
			do {
				system("cls");
				key_of_task = NULL;
				SecondLabMenu();

				key_of_task = _getch();
				system("cls");
				switch (key_of_task) {
					case num_1: {	//первое задание второй лабы
						Lab2_№1();
						break;
					}
					case num_2: {	//второе задание второй лабы
						Lab2_№2();
						break;
					}
					case num_3: {	//третье задание второй лабы
						Lab2_№3();
						break;
					}
					case num_4: {	//четвертое задание второй лабы
						Lab2_№4();
						break;
					}
					case backspace: {	//выход из лабы
						is_exit_lab_two = false;
						break;
					}
					default: {
						system("cls");
						cout << "Не правильно введен номер задания" << endl;
						system("pause");
						break;
					}
				}
			} while (is_exit_lab_two == true);
			break;
			}
			case num_3: { // третья лаба
			bool is_exit_lab_three = true;
			do {
				system("cls");
				key_of_task = NULL;
				ThirdLabMenu();

				key_of_task = _getch();
				system("cls");
				switch (key_of_task) {
					case num_1: {	 //первое задание третьей лабы
						Lab3_№1();
						break;
					}
					case num_2: {	//второе задание третьей лабы
						Lab3_№2();
						break;
					}
					case num_3: {	//третье задание третьей лабы
						Lab3_№3();
						break;
					}
					case num_4: {	//четвертое задание третьей лабы
						Lab3_№4();
						break;
					}
					case num_5: {	//пятое задание третьей лабы
						Lab3_№5();
						break;
					}
					case backspace: {	//выход из лабы
						is_exit_lab_three = false;
						break;
					}
					default: {
						system("cls");
						cout << "Не правильно введен номер задания" << endl;
						system("pause");
						break;
					}
				}
			} while (is_exit_lab_three == true);
			break;
			}
			case num_4: { // четвертая лаба
				bool is_exit_lab_four = true;
				do {
					system("cls");
					key_of_task = 0;
					FourthLabMenu();

					key_of_task = _getch();
					system("cls");
					switch (key_of_task) {
					case num_1: {	//первое задание четвертой лабы
						lab4_№1();
						break;
					}
					case num_2: {	 //второе задание четверотй лабы
						lab4_№2();
						break;
					}
					case num_3: {	//третье задание четвертой лабы
						lab4_№3();
						break;
					}
					case num_4: { //четвертое задание четвертой лабы
						lab4_№4();
						break;
					}
					case num_5: { //пятое задание четвертой лабы
						lab4_№5();
						break;
					}
					case num_6: {
						lab4_№6();
						break;
					}
					case backspace: {
						is_exit_lab_four = false;
						break;
					}
					default: {
						system("cls");
						cout << "Не правильно введен номер задания" << endl;
						system("pause");
						break;
					}
					}
				} while (is_exit_lab_four == true);
				break;
			}
			case num_5: { //пятая лаба
				bool is_exit_lab_four = true;
				do {
					system("cls");
					key_of_task = 0;
					FifthLabMenu();
					while (key_of_task == 0) {
						key_of_task = _getch();
					}
					system("cls");
					switch (key_of_task) {
					case num_1: {
						lab5();
						break;
					}
					case backspace: {
						is_exit_lab_four = false;
						break;
					}
					default: {
						system("cls");
						cout << "Не правильно введен номер задания" << endl;
						system("pause");
						break;
					}
					}
				} while (is_exit_lab_four == true);
				break;
			}
			case num_6: { //шестая лаба
				bool is_exit_lab_four = true;
				do {
					system("cls");
					key_of_task = 0;
					SixthLabMenu(); 
					while (key_of_task == 0) {
						key_of_task = _getch();
					}
					system("cls");
					switch (key_of_task) {
					case num_1: {
						lab6();
						break;
					}
					case backspace: {
						is_exit_lab_four = false;
						break;
					}
					default: {
						system("cls");
						cout << "Не правильно введен номер задания" << endl;
						system("pause");
						break;
					}
					}
				} while (is_exit_lab_four == true);
				break;
			}
			case num_7: { //седьмая лаба
				LabSevenMain();
				break;
			}
			case backspace: {
				is_exit_labs = false;
				break;
			}
			default: {
				system("cls");
				cout << "Не правильно введен номер лаборатоорной" << endl;
				system("pause");
				break;
			}
		}

	} while (is_exit_labs == true);
	return 0;
}