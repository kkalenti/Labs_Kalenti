#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "PersonList.h"
#include "class_functions.h"
#include "functions.h"

using namespace std; 

void lab5() {
	/*cout << "������� ������ ������ ������:";
	int size_person;
	CheckingForPositive(&size_person);
	PersonListItem* head = new PersonListItem;
	PersonList list(head, size_person);
	for (int i = 0; i < size_person; i++) {
		MakeListItem(head, list, i);
	}
	// ���������� �� �������
	list.Print();
	// ���������� �� �������
	cout << "������� ������ �������� (�� �������), ������� ���� �������:";
	int index;
	CheckingForPositive(&index);
	Person* curent_person = list.Find(index);
	if (curent_person != nullptr) {
		PrintForLinkOfPerson(*curent_person);
	} else {
		cout << "�������� � ��������� �������� �� ����������" << endl;
	}
	// ���������� �� �������
	Person* new_curent_person = new Person;
	cout << "������� ������ �������, ������ ������� ���� �������:";
	list.Add(new_curent_person);
	int new_index = list.IndexOf(new_curent_person);
	if (new_index != 0) {
		cout << "������ ������� ��������:" << new_index << endl;
	} else {
		cout << "����� ������� �� �������" << endl;
	}
	// ���������� �� �������
	cout << "������� ������ ��� ��������:";
	CheckingForPositive(&index);
	list.RemoveAt(index);
	list.Print();
	// ���������� �� �������
	list.Clear();
	// ���������� �� �������
	system("pause");*/
	Person rand_person;
	PersonList list_1(nullptr, 3);
	for (int i = 0; i < 3; i++) {
		list_1.Add(rand_person.GetRandomPerson());
	}
	PersonList list_2(nullptr, 3);
	for (int i = 0; i < 3; i++) {
		list_2.Add(rand_person.GetRandomPerson());
	}
	cout << "������ �������" << endl << "������� ����� ������" << endl;
	bool key = _getch();
	system("cls");

	cout << "������ ������:" << endl;
	list_1.Print();
	cout << endl;
	cout << "������ ������:" << endl;
	list_2.Print();
	cout << "������� ����� ������";
	key = _getch();
	system("cls");

	cout << "������� ������ ������ ������������:" << endl;
	list_1.Add(rand_person.Read());
	cout << "������ ������:" << endl;
	list_1.Print();
	cout << endl;
	cout << "������ ������:" << endl;
	list_2.Print();
	cout << "������� ����� ������";
	key = _getch();
	system("cls");

	list_2.Add(list_1.Find(2));
	cout << "������ ������:" << endl;
	list_1.Print();
	cout << endl;
	cout << "������ ������:" << endl;
	list_2.Print();
	cout << "������� ����� ������";
	key = _getch();
	system("cls");

	list_1.RemoveAt(2);
	cout << "������ ������:" << endl;
	list_1.Print();
	cout << endl;
	cout << "������ ������:" << endl;
	list_2.Print();
	cout << "������� ����� ������";
	key = _getch();
	system("cls");

	list_2.Clear();
	cout << "������ ������:" << endl;
	list_1.Print();
	cout << endl;
	cout << "������ ������:" << endl;
	list_2.Print();
	cout << "������� ����� ������";
	key = _getch();
	system("cls");

	system("pause");
}