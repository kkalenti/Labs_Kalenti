#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "functions.h"
#include "enumeration.h"
#include "structure.h"
#include "color_enumeration.h"
#include "num_enumeration.h"
#include "person_structure.h"
#include "sex_enumeration.h"

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
			case backspace: {
				exit_color = false;
				break;
			}
			default:
				cout << "Нет такого цвета" << endl;
				break;
			}

	} while (exit_color == true);
	system("color 07");
}

void lab4_№4() {
	Person first_person;
	strcpy_s(first_person.firstname, "Калентьев");
	strcpy_s(first_person.lastname, "Костя");
	first_person.age = 18;
	strcpy_s(first_person.sex, "муж");

	Person second_person;
	strcpy_s(second_person.firstname, "Калентьев");
	strcpy_s(second_person.lastname, "Алексей");
	second_person.age = 28;
	strcpy_s(second_person.sex, "муж");

	cout << "Фамилия и имя первого человека:" << first_person.firstname <<
		" " << first_person.lastname << endl << endl;

	strcpy_s(first_person.firstname, "Котов");
	strcpy_s(first_person.lastname, "Влад");
	cout << "Фамилия и имя первого человека, введенные повторно:" << first_person.firstname <<
		" " << first_person.lastname << endl << endl;

	Person *first_person_pointer = &first_person;
	cout << "Адрес:" << first_person_pointer << endl;
	cout << "Фамилия, выведенная через указатель:" << first_person_pointer->firstname << endl << endl;

	Person *second_person_pointer = &second_person;
	strcpy_s(second_person_pointer->lastname, "Костя");
	second_person_pointer->age = 18;

	cout << "Функция для вывода информации из структуры" << endl;
	PrintPerson(first_person);

	cout << "Функция для вводы информации в функцию" << endl;
	Person third_person;
	Person *third_person_pointer = &third_person;
	ReadPerson(third_person_pointer);
	PrintPerson(third_person);
	system("pause");
}