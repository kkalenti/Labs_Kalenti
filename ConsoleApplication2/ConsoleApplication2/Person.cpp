#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include "Person.h"
#include "lab_five_functions.h"
#include "num_enumeration.h"

using namespace std;

Person::Person() {

}

Person::Person(bool flag) {
	int sex_key = 1 + rand() % 2;
	if (sex_key == 1) {
		sex = Муж;
	}
	else {
		sex = Жен;
	}

	MakeName(this);

	MakeSurname(this);

	_age = 1 + rand() % 100;
}

int Person::GetAge() {
	return _age;
}

void Person::SetAge(int age) {
	PersonPositiveCorrection(age);
	_age = age;
}

char* Person::GetName() {
	return name;
}

void Person::SetName(char* _name) {
	bool key = CheckingText(_name);
	if (key == true) {
		strcpy_s(name, _name);
	}
}

char* Person::GetSurname() {
	return surname;
}

void Person::SetSurname(char* _surname) {
	bool key = CheckingText(_surname);
	if (key == true) {
		strcpy_s(surname, _surname);
	}
}

Sex Person::GetSex() {
	return sex;
}

void Person::SetSex(Sex sex) {
	sex = sex;
}

Person* Person::GetRandomPerson() {
	Person* person = new Person;

	int sex_key = 1 + rand() % 2;
	if (sex_key == 1) {
		person->sex = Муж;
	}
	else {
		person->sex = Жен;
	}
	//TODO: Ниже дубли и куча магических чисел.
	MakeName(person);
	
	MakeSurname(person);

	person->_age = 1 + rand() % 100;
	return person;
}

Person* Person::Read() {
	const int kTempSize = 50;
	Person* person = new Person;
	int sex_key = 0;
	int key = 0;

	strcpy_s(person->name, NameInput("Введите имя:"));

	strcpy_s(person->surname, NameInput("Введите фамилию:"));
	cout << "Введите пол (1-муж/2-жен):" << endl;
	bool is_exit;
	do {
		while (sex_key == 0) {
			sex_key = getchar();
		}
		is_exit = true;
		switch (sex_key) {
		case num_1: {
			person->sex = Муж;
			is_exit = false;
			break;
		}
		case num_2: {
			person->sex = Жен;
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
	int age = 0;
	person->SetAge(age);
	return person;
}

void Person::Show() {
	cout << setw(20) << left << surname << setw(20) << left << name
		<< setw(8) << left << "Возраст: " << setw(10) << left << _age
		<< setw(4) << left << "Пол:" << setw(10) << left;
	if (sex == Муж) {
		cout << "Мужской" << endl;
	}
	else {
		cout << "Женский" << endl;
	}
}

char* Person::GetDiscription() {
	char inform[100];
	char temp[100];
	strcpy_s(inform, surname);
	strcat_s(inform, " ");
	strcat_s(inform, name);
	strcat_s(inform, ", ");
	sprintf_s(temp,"%d" ,GetAge());
	strcat_s(inform, temp);
	strcat_s(inform, " лет ,");
	if (sex == Муж) {
		strcat_s(inform, "муж");
	}
	else {
		strcat_s(inform, "жен");
	}
	strcat_s(inform, "\0");
	return inform;
}