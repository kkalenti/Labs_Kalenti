#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "List.h"
#include "Person.h"
#include "menus.h"
#include "labsevenfunctions.h"
#include "num_enumeration.h"

using namespace std;

template<typename T>
void lab7(void(*CreateFnc)(List<T>*, int size), void(*OutputFnc)(List<T>*), void(*AddFnc)(List<T>*)) {
	List<T> *list = new List<T>(nullptr);
	CreateFnc(list,5);
	OutputFnc(list);

	list->RemoveAt(2);
	OutputFnc(list);

	AddFnc(list);
	OutputFnc(list);

	delete list;
	system("pause");
}

void LabSevenMain() {
	//TODO: �������� ������, ���������� ���� - "���� � ���� ����� �� ���� 4, ��..." ����� ������ ��������
	bool is_exit_lab_seven = true;
	do {
		system("cls");
		int key_of_task = 0;
		SeventhLabMenu();
		while (key_of_task == 0) {
			key_of_task = _getch();
		}
		system("cls");
		switch (key_of_task) {
		case num_1: {
			lab7<double>(CreateDoubleList, DoubleOutput, AddDoubleElement);
			break;
		}
		case num_2: {
			lab7<Person>(CreatePersonList, PersonOutput, AddPersonElement);
			break;
		}
		case num_3: {
			lab7<double*>(CreateDoubleArrayList, DoubleArrayOutput, AddDoubleArrayElement);
			break;
		}
		case num_4: {
			lab7<List<double>>(CreateDoubleListList, DoubleListOutput, AddDoubleListElement);
			break;
		}
		case backspace: {
			is_exit_lab_seven = false;
			break;
		}
		default: {
			system("cls");
			cout << "�� ��������� ������ ����� �������" << endl;
			system("pause");
			break;
		}
		}
	} while (is_exit_lab_seven == true);
}
