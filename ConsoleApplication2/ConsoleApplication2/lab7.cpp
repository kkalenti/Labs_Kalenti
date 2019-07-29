#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "List.h"
#include "Person.h"
#include "menus.h"
#include "labsevenfunctions.h"
#include "num_enumeration.h"

using namespace std;
//TODO: “.к. методы у теб€ работают по одной схеме - добавл€ем столько-то, показываем, удал€ем 2, показываем, добавл€ем ещЄ один , показываем
//TODO: необходимо вынести саму структуру в качестве одного метода, а метода добавлени€/показывани€/другого добавлени€ передавать
//TODO: в этот обобщЄнный метод в качестве калбеков (указателей на методы) 

//template<typename T>
void lab7(void(*CreateFnc)(List<double[5]>*), void(*OutputFnc)(List<double[5]>*), void(*AddFnc)(List<double[5]>*)) {
	List<double[5]> *list = new List<double[5]>(nullptr);
	CreateFnc(list);
	OutputFnc(list);

	list->RemoveAt(2);
	OutputFnc(list);

	AddFnc(list);
	OutputFnc(list);

	delete list;
	system("pause");
}

void LabSevenMain() {
	bool is_exit_lab_four = true;
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
			lab7<double>(DoubleCreateList, DoubleOutput, AddDoubleElement);
			break;
		}
		case num_2: {
			lab7<Person>(PersonCreateList, PersonOutput, AddPersonElement);
			break;
		}
		case num_3: {
			lab7<double[5]>(DoubleArrayCreateList, DoubleArrayOutput, AddDoubleArrayElement);
			break;
		}
		case num_4: {
			lab7<List<double>>(DoubleListCreateList, DoubleListOutput, AddDoubleListElement);
			break;
		}
		case backspace: {
			is_exit_lab_four = false;
			break;
		}
		default: {
			system("cls");
			cout << "Ќе правильно введен номер задани€" << endl;
			system("pause");
			break;
		}
		}
	} while (is_exit_lab_four == true);
}

void lab7_3() {
	List<double[5]> *list = new List<double[5]>(nullptr);
	for (int i = 0; i < 5; i++) {
		double mass[5];
		for (int j = i; j < i + 5; j++) {
			mass[j-i] = j;
		}
		list->Add(&mass);
	}
	DoubleArrayOutput(list);

	list->RemoveAt(2);
	DoubleArrayOutput(list);

	double mass[5];
	for (int j = 0; j < 5; j++) {
		mass[j] = j+10;
	}
	list->AddTo(&mass, 4);
	DoubleArrayOutput(list);
	delete list;
	system("pause");
}

