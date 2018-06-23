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
	strcpy_s(first_person.surname, "���������");
	strcpy_s(first_person.firstname, "�����");
	first_person.age = 18;
	strcpy_s(first_person.sex, "���");

	Person second_person;
	strcpy_s(second_person.surname, "���������");
	strcpy_s(second_person.firstname, "�������");
	second_person.age = 28;
	strcpy_s(second_person.sex, "���");

	cout << "������� � ��� ������� ��������:" << first_person.surname <<
		" " << first_person.firstname << endl << endl;

	strcpy_s(first_person.surname, "�����");
	strcpy_s(first_person.firstname, "����");
	cout << "������� � ��� ������� ��������, ��������� ��������:" << first_person.surname <<
		" " << first_person.firstname << endl << endl;

	Person *first_person_pointer = &first_person;
	cout << "�����:" << first_person_pointer << endl;
	cout << "�������, ���������� ����� ���������:" << first_person_pointer->surname << endl << endl;

	Person *second_person_pointer = &second_person;
	strcpy_s(second_person_pointer->firstname, "�����");
	second_person_pointer->age = 18;

	cout << "������� ��� ������ ���������� �� ���������" << endl;
	PrintForLinkOfPerson(first_person);

	cout << "������� ��� ����� ���������� � �������" << endl;
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
	cout << "���� ������� ��������" << endl;
	for (int i = 0; i < 5; i++) {
		cout << "������������ �" << i+1 << endl;
		cin.ignore();
		cout << "������� ���:" << endl;
		while (strcmp(temp,"") == NULL) {
			cin.getline(temp, 50);
			strcpy_s(person_massive[i].firstname, temp);
		}
		strcpy_s(temp, "");

		cout << "������� �������:" << endl;
		while (strcmp(temp, "") == NULL) {
			cin.getline(temp, 50);
			strcpy_s(person_massive[i].surname, temp);
		}			
		strcpy_s(temp, "");

		cout << "������� �������:" << endl;
		CheckingForPositiveForPerson(&person_massive[i]);
		cout << "������� ��� (1-���/2-���):" << endl;
		bool is_exit;
		do {
			sex_key = _getch();
			is_exit = true;
			switch (sex_key)
				{
				case num_1: {
					strcpy_s(person_massive[i].sex, "���");
					is_exit = false;
					break;
				}
				case num_2: {
					strcpy_s(person_massive[i].sex, "���");
					is_exit = false;
					break;
				}
				default: {
					cout << "�������� ����,������� ����� ������" << endl;
					break;
				}
			}
		} while (is_exit == true);
		system("cls");
	}
	for (int i = 0; i < 5; i++) {
		cout << i+1 << "." << person_massive[i].surname << "\t" << person_massive[i].firstname 
			<< "\t" << "�������: " << person_massive[i].age << "\t" 
			<< "���:" << person_massive[i].sex << endl;
	}
	delete [5] person_massive;
	system("pause");
}

void lab4_�5() {
	vector<int> my_vector;
	for(int i = 0; i < 5; i++){
		my_vector.push_back(i);
	}
	cout << "����� ��������������� �������" << endl;
	copy(my_vector.begin(), my_vector.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	my_vector.erase(my_vector.begin() + 3);
	my_vector.emplace(my_vector.begin() + 2, 15);
	cout << "����� ��������� �������" << endl;
	copy(my_vector.begin(), my_vector.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	system("pause");
	system("cls");
}

void lab4_�6() {
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
	cout << "������� ��������� ������" << endl << endl;
	PrintPersonList(person_list_head);

	DeleteElementOfAPersonList(person_list_head, person_list_tail, 3);
	cout << "������� ������ � ��������� ������� ���������" << endl;
	PrintPersonList(person_list_head);
	while (person_list_head->next != nullptr) {
		person_list_head = person_list_head->next;
		delete person_list_head->prev;
	}
	delete person_list_head;
	system("pause");
	system("cls");
}