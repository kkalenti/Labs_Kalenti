#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "functions.h"
#include "enumeration.h"
#include "color_enumeration.h"

using namespace std;

void lab4_№1() {
	int number_of_weekday;
	cout << "Введите число от 1 до 365 (Номер дня в году):\n";
	do {
		CheckingForPositive(&number_of_weekday);
		if (number_of_weekday > 365) {
			cout << "Введено число больше 365! Повторите ввод:\n";
		}
	} while (number_of_weekday > 365);
	IdentifyWeekday(number_of_weekday);
	system("pause");
}

void lab4_№2() {
	int number_of_month;
	cout << "Введите число от 1 до 12 (Номер месяца):\n";
	do {
		CheckingForPositive(&number_of_month);
		if (number_of_month > 12) {
			cout << "Введено число больше 12! Повторите ввод:\n";
		}
	} while (number_of_month > 12);
	IdentifyMonth(number_of_month);
	system("pause");
}

void lab4_№3() {
	bool exit_color = true;
	int number_of_color;
	do{
		system("cls");
		cout << "Выберите цвет:" << endl << "1.Красный" << endl << 
			"2.Синий" << endl << "3.Желтый" << endl << "4.Зеленый" << endl <<
			"5.Феолетовый" << endl << "Backspace. Выйти к выбору заданий" << endl;
		cout << "Выберите цвет:" << endl;
		number_of_color = _getch();
		system("cls");
			switch (number_of_color){
			case red: {
				system("color 04");
				break;
			}
			case blue: {
				system("color 01");
				break;
			}
			case yellow: {
				system("color 0E");
				break;
			}
			case green: {
				system("color 02");
				break;
			}
			case purple: {
				system("color 05");
				break;
			}
			case 8: {
				exit_color = false;
				break;
			}
			default:
				cout << "Нет такого цвета" << endl;
				break;
			}

	} while (exit_color == true);
	system("color 0F");
}