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

void lab4_�1() {
	int number_of_weekday;
	cout << "������� ����� �� 1 �� 365 (����� ��� � ����):\n";
	do {
		CheckingForPositive(&number_of_weekday);
		if (number_of_weekday > 365) {
			cout << "������� ����� ������ 365! ��������� ����:\n";
		}
	} while (number_of_weekday > 365);
	IdentifyWeekday(number_of_weekday);
	system("pause");
}

void lab4_�2() {
	int number_of_month;
	cout << "������� ����� �� 1 �� 12 (����� ������):\n";
	do {
		CheckingForPositive(&number_of_month);
		if (number_of_month > 12) {
			cout << "������� ����� ������ 12! ��������� ����:\n";
		}
	} while (number_of_month > 12);
	IdentifyMonth(number_of_month);
	system("pause");
}

void lab4_�3() {
	bool exit_color = true;
	int number_of_color;
	do{
		system("cls");
		cout << "�������� ����:" << endl << "1.�������" << endl << 
			"2.�����" << endl << "3.������" << endl << "4.�������" << endl <<
			"5.����������" << endl << "Backspace. ����� � ������ �������" << endl;
		cout << "�������� ����:" << endl;
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
				cout << "��� ������ �����" << endl;
				break;
			}

	} while (exit_color == true);
	system("color 07");
}

void lab4_�4() {
	Person first_person;
	strcpy_s(first_person.firstname, "���������");
	strcpy_s(first_person.lastname, "�����");
	first_person.age = 18;
	strcpy_s(first_person.sex, "���");

	Person second_person;
	strcpy_s(second_person.firstname, "���������");
	strcpy_s(second_person.lastname, "�������");
	second_person.age = 28;
	strcpy_s(second_person.sex, "���");

	cout << "������� � ��� ������� ��������:" << first_person.firstname <<
		" " << first_person.lastname << endl << endl;

	strcpy_s(first_person.firstname, "�����");
	strcpy_s(first_person.lastname, "����");
	cout << "������� � ��� ������� ��������, ��������� ��������:" << first_person.firstname <<
		" " << first_person.lastname << endl << endl;

	Person *first_person_pointer = &first_person;
	cout << "�����:" << first_person_pointer << endl;
	cout << "�������, ���������� ����� ���������:" << first_person_pointer->firstname << endl << endl;

	Person *second_person_pointer = &second_person;
	strcpy_s(second_person_pointer->lastname, "�����");
	second_person_pointer->age = 18;

	cout << "������� ��� ������ ���������� �� ���������" << endl;
	PrintPerson(first_person);

	cout << "������� ��� ����� ���������� � �������" << endl;
	Person third_person;
	Person *third_person_pointer = &third_person;
	ReadPerson(third_person_pointer);
	PrintPerson(third_person);
	system("pause");
}