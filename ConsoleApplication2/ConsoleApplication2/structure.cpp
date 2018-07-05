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
		<< setw(8) << left << "�������: " << setw(10) << left << person.age
		<< setw(4) << left << "���:" << setw(10) << left << person.sex << endl;
}

void PrintForPointOfPerson(PersonStr* person) {
	cout << setw(20) << left << person->surname << setw(20) << left << person->firstname
		<< setw(8) << left << "�������: " << setw(10) << left << person->age
		<< setw(4) << left << "���:" << setw(10) << left << person->sex << endl;
}

void ReadPersonForPoint(PersonStr* person) {
	int sex_key;
	char temp[50];
	strcpy_s(temp, "");
	cout << "������� ���:" << endl;
	cin.ignore();
	while (strcmp(temp, "") == NULL) {
		cin.getline(temp, 50);
		strcpy_s(person->firstname, temp);
	}
	strcpy_s(temp, "");

	cout << "������� �������:" << endl;
	while (strcmp(temp, "") == NULL) {
		cin.getline(temp, 50);
		strcpy_s(person->surname, temp);
	}
	strcpy_s(temp, "");
	cout << "������� ��� (1-���/2-���):" << endl;
	bool is_exit;
	do {
		sex_key = _getch();
		is_exit = true;
		switch (sex_key) {
		case num_1: {
			strcpy_s(person->sex, "���");
			is_exit = false;
			break;
		}
		case num_2: {
			strcpy_s(person->sex, "���");
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
	CheckingForPositiveForPerson(person);

}

void ReadPersonForLink(PersonStr& person) {
	int sex_key;
	char temp[50];
	strcpy_s(temp, "");
	cout << "������� ���:" << endl;
	cin.ignore();
	while (strcmp(temp, "") == NULL) {
		cin.getline(temp, 50);
		strcpy_s(person.firstname, temp);
	}
	strcpy_s(temp, "");

	cout << "������� �������:" << endl;
	while (strcmp(temp, "") == NULL) {
		cin.getline(temp, 50);
		strcpy_s(person.surname, temp);
	}
	strcpy_s(temp, "");
	cout << "������� ��� (1-���/2-���):" << endl;
	bool is_exit;
	do {
		sex_key = _getch();
		is_exit = true;
		switch (sex_key){
			case num_1: {
				strcpy_s(person.sex, "���");
				is_exit = false;
				break;
			}
			case num_2: {
				strcpy_s(person.sex, "���");
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
	CheckingForPositiveForPerson(person);
	
}
