#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <iomanip>
#include "Person.h"
#include "class_functions.h"
#include "num_enumeration.h"

using namespace std;

Person::Person() {

}

Person* Person::GetRandomPerson() {
	char temp[5];
	//TODO: Ниже дубли и куча магических чисел.
	temp[0] = 65 + rand() % 25;
	for (int i = 1; i < 5; i++) {
		temp[i] = 97 + rand() % 25;
	}
	Person* person = new Person;
	strncpy_s(person->Name, temp,5);
	
	temp[1] = 65 + rand() % 25;
	for (int i = 1; i < 5; i++) {
		temp[i] = 97 + rand() % 25;
	}
	strncpy_s(person->Surname, temp,5);
	
	int sex_key = 1 + rand() % 2;
	if (sex_key == 1) {
		person->Sex = Муж;
	} else {
		person->Sex = Жен;
	}

	person->Age = 1 + rand() % 100;
	return person;
}

Person* Person::Read() {
	Person* person = new Person;
	int sex_key;
	int key = 0;
	//TODO: 50 повторяется
	char temp[50];
	strcpy_s(temp, "");
	//TODO: два дубля ниже
	while (strcmp(temp, "") == NULL) {
		while (key == 0) {
			cout << "Введите имя:";
			cin.getline(temp, 50);
			key = CheckingText(temp);
		}
		strcpy_s(person->Name, temp);
	}
	strcpy_s(temp, "");
	key = 0;

	while (strcmp(temp, "") == NULL) {
		while (key == 0) {
			cout << "Введите фамилию:";
			cin.getline(temp, 50);
			key = CheckingText(temp);
		}
		strcpy_s(person->Surname, temp);
	}
	strcpy_s(temp, "");
	cout << "Введите пол (1-муж/2-жен):" << endl;
	bool is_exit;
	do {
		sex_key = _getch();
		is_exit = true;
		switch (sex_key) {
		case num_1: {
			person->Sex = Муж;
			is_exit = false;
			break;
		}
		case num_2: {
			person->Sex = Жен;
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
	return person;
}

void Person::Show() {
	cout << setw(20) << left << Surname << setw(20) << left << Name
		<< setw(8) << left << "Возраст: " << setw(10) << left << Age
		<< setw(4) << left << "Пол:" << setw(10) << left;
	if (Sex == Муж) {
		cout << "Мужской" << endl;
	}
	else {
		cout << "Женский" << endl;
	}
}