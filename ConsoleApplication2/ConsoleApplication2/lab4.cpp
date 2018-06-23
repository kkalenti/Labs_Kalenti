#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <vector>
#include <iterator>
#include "functions.h"
#include "enumeration.h"
#include "structure.h"
#include "color_enumeration.h"
#include "num_enumeration.h"
#include "person_structure.h"
#include "sex_enumeration.h"
#include "checking_input_for_person.h"
#include "person_list.h"
#include "for_list.h"

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
	strcpy_s(first_person.surname, "Калентьев");
	strcpy_s(first_person.firstname, "Костя");
	first_person.age = 18;
	strcpy_s(first_person.sex, "муж");

	Person second_person;
	strcpy_s(second_person.surname, "Калентьев");
	strcpy_s(second_person.firstname, "Алексей");
	second_person.age = 28;
	strcpy_s(second_person.sex, "муж");

	cout << "Фамилия и имя первого человека:" << first_person.surname <<
		" " << first_person.firstname << endl << endl;

	strcpy_s(first_person.surname, "Котов");
	strcpy_s(first_person.firstname, "Влад");
	cout << "Фамилия и имя первого человека, введенные повторно:" << first_person.surname <<
		" " << first_person.firstname << endl << endl;

	Person *first_person_pointer = &first_person;
	cout << "Адрес:" << first_person_pointer << endl;
	cout << "Фамилия, выведенная через указатель:" << first_person_pointer->surname << endl << endl;

	Person *second_person_pointer = &second_person;
	strcpy_s(second_person_pointer->firstname, "Костя");
	second_person_pointer->age = 18;

	cout << "Функция для вывода информации из структуры" << endl;
	PrintForLinkOfPerson(first_person);

	cout << "Функция для вводы информации в функцию" << endl;
	Person *third_person_pointer = new Person;
	ReadPersonForPoint(third_person_pointer);
	PrintForPointOfPerson(third_person_pointer);
	cout << endl;
	delete third_person_pointer;
	system("pause");
	system("cls");

	Person *person_massive = new Person[5];
	int sex_key;
	char temp[50];
	strcpy_s(temp, "");
	cout << "Ввод массива структур" << endl;
	for (int i = 0; i < 5; i++) {
		cout << "Пользователь №" << i+1 << endl;
		cin.ignore();
		cout << "Введите имя:" << endl;
		while (strcmp(temp,"") == NULL) {
			cin.getline(temp, 50);
			strcpy_s(person_massive[i].firstname, temp);
		}
		strcpy_s(temp, "");

		cout << "Введите фамилию:" << endl;
		while (strcmp(temp, "") == NULL) {
			cin.getline(temp, 50);
			strcpy_s(person_massive[i].surname, temp);
		}			
		strcpy_s(temp, "");

		cout << "Введите возраст:" << endl;
		CheckingForPositiveForPerson(&person_massive[i]);
		cout << "Введите пол (1-муж/2-жен):" << endl;
		bool is_exit;
		do {
			sex_key = _getch();
			is_exit = true;
			switch (sex_key)
				{
				case num_1: {
					strcpy_s(person_massive[i].sex, "муж");
					is_exit = false;
					break;
				}
				case num_2: {
					strcpy_s(person_massive[i].sex, "жен");
					is_exit = false;
					break;
				}
				default: {
					cout << "Неверный ввод,введите число заново" << endl;
					break;
				}
			}
		} while (is_exit == true);
		system("cls");
	}
	for (int i = 0; i < 5; i++) {
		cout << i+1 << "." << person_massive[i].surname << "\t" << person_massive[i].firstname 
			<< "\t" << "Возраст: " << person_massive[i].age << "\t" 
			<< "Пол:" << person_massive[i].sex << endl;
	}
	delete [5] person_massive;
	system("pause");
}

void lab4_№5() {
	vector<int> my_vector;
	for(int i = 0; i < 5; i++){
		my_vector.push_back(i);
	}
	cout << "Вывод первоначального массива" << endl;
	copy(my_vector.begin(), my_vector.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	my_vector.erase(my_vector.begin() + 3);
	my_vector.emplace(my_vector.begin() + 2, 15);
	cout << "Вывод итогового массива" << endl;
	copy(my_vector.begin(), my_vector.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	system("pause");
	system("cls");
}

void lab4_№6() {
	PersonListItem *person_list_head = new PersonListItem;
	cout << "1.";
	ReadPersonForLink(person_list_head->Person);
	person_list_head->next = nullptr;
	person_list_head->prev = nullptr;
	system("cls");
	PersonListItem *person_list_tail = new PersonListItem;
	for (int i = 2; i < 6; i++) {
		cout << i << '.';
		person_list_tail = AddToEndOfAPersonList(person_list_head);
		system("cls");
	}
	cout << "Выведен введенный список" << endl << endl;
	PrintPersonList(person_list_head);

	DeleteElementOfAPersonList(person_list_head, person_list_tail, 3);
	cout << "Выведен список с удаленным третьим элементом" << endl;
	PrintPersonList(person_list_head);
	while (person_list_head->next != nullptr) {
		person_list_head = person_list_head->next;
		delete person_list_head->prev;
	}
	delete person_list_head;
	system("pause");
	system("cls");
}