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
		sex = ���;
	}
	else {
		sex = ���;
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
		person->sex = ���;
	}
	else {
		person->sex = ���;
	}
	//TODO: ���� ����� � ���� ���������� �����.
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

	strcpy_s(person->name, NameInput("������� ���:"));

	strcpy_s(person->surname, NameInput("������� �������:"));
	cout << "������� ��� (1-���/2-���):" << endl;
	bool is_exit;
	do {
		while (sex_key == 0) {
			sex_key = getchar();
		}
		is_exit = true;
		switch (sex_key) {
		case num_1: {
			person->sex = ���;
			is_exit = false;
			break;
		}
		case num_2: {
			person->sex = ���;
			is_exit = false;
			break;
		}
		default: {
			cout << "�������� ����,������� ����� ������" << endl;
			break;
		}
		}
	} while (is_exit == true);
	cout << "������� �������:" << endl;
	int age = 0;
	person->SetAge(age);
	return person;
}

void Person::Show() {
	cout << setw(20) << left << surname << setw(20) << left << name
		<< setw(8) << left << "�������: " << setw(10) << left << _age
		<< setw(4) << left << "���:" << setw(10) << left;
	if (sex == ���) {
		cout << "�������" << endl;
	}
	else {
		cout << "�������" << endl;
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
	strcat_s(inform, " ��� ,");
	if (sex == ���) {
		strcat_s(inform, "���");
	}
	else {
		strcat_s(inform, "���");
	}
	strcat_s(inform, "\0");
	return inform;
}