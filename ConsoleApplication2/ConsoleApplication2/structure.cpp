#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
#include "checking_input_for_person.h"
#include "person_structure.h"
#include "num_enumeration.h"

using namespace std;

void PrintForLinkOfPerson(PersonStr& person) {
	cout << setw(20) << left << person.surname << setw(20) << left << person.firstname
		<< setw(8) << left << "Возраст: " << setw(10) << left << person.age
		<< setw(4) << left << "Пол:" << setw(10) << left << person.sex << endl;
}

void PrintForPointOfPerson(PersonStr* person) {
	cout << setw(20) << left << person->surname << setw(20) << left << person->firstname
		<< setw(8) << left << "Возраст: " << setw(10) << left << person->age
		<< setw(4) << left << "Пол:" << setw(10) << left << person->sex << endl;
}

void ReadPersonForPoint(PersonStr* person) {
	int sex_key;
	char temp[50];
	strcpy_s(temp, "");
	cout << "Введите имя:" << endl;
	cin.ignore();
	while (strcmp(temp, "") == NULL) {
		cin.getline(temp, 50);
		strcpy_s(person->firstname, temp);
	}
	strcpy_s(temp, "");

	cout << "Введите фамилию:" << endl;
	while (strcmp(temp, "") == NULL) {
		cin.getline(temp, 50);
		strcpy_s(person->surname, temp);
	}
	strcpy_s(temp, "");
	cout << "Введите пол (1-муж/2-жен):" << endl;
	bool is_exit;
	do {
		sex_key = _getch();
		is_exit = true;
		switch (sex_key) {
		case num_1: {
			strcpy_s(person->sex, "муж");
			is_exit = false;
			break;
		}
		case num_2: {
			strcpy_s(person->sex, "жен");
			is_exit = false;
			break;
		}
		default: {
			cout << "Неверный ввод,введите число заново" << endl;
			break;
		}
		}
	} while (is_exit == true);
	cout << "Введите возраст:" << endl;
	CheckingForPositiveForPerson(person);

}

void ReadPersonForLink(PersonStr& person) {
	int sex_key;
	char temp[50];
	strcpy_s(temp, "");
	cout << "Введите имя:" << endl;
	cin.ignore();
	while (strcmp(temp, "") == NULL) {
		cin.getline(temp, 50);
		strcpy_s(person.firstname, temp);
	}
	strcpy_s(temp, "");

	cout << "Введите фамилию:" << endl;
	while (strcmp(temp, "") == NULL) {
		cin.getline(temp, 50);
		strcpy_s(person.surname, temp);
	}
	strcpy_s(temp, "");
	cout << "Введите пол (1-муж/2-жен):" << endl;
	bool is_exit;
	do {
		sex_key = _getch();
		is_exit = true;
		switch (sex_key){
			case num_1: {
				strcpy_s(person.sex, "муж");
				is_exit = false;
				break;
			}
			case num_2: {
				strcpy_s(person.sex, "жен");
				is_exit = false;
				break;
			}
			default: {
				cout << "Неверный ввод,введите число заново" << endl;
				break;
			}
		}
	} while (is_exit == true);
	cout << "Введите возраст:" << endl;
	CheckingForPositiveForPerson(person);
	
}
