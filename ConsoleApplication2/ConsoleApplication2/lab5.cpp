#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "PersonList.h"
#include "class_functions.h"
#include "functions.h"

using namespace std; 

void lab5() {
	/*cout << "Введите размер списка персон:";
	int size_person;
	CheckingForPositive(&size_person);
	PersonListItem* head = new PersonListItem;
	PersonList list(head, size_person);
	for (int i = 0; i < size_person; i++) {
		MakeListItem(head, list, i);
	}
	// Разделение на функции
	list.Print();
	// Разделение на функции
	cout << "Введите индекс элемента (от единицы), который надо вывести:";
	int index;
	CheckingForPositive(&index);
	Person* curent_person = list.Find(index);
	if (curent_person != nullptr) {
		PrintForLinkOfPerson(*curent_person);
	} else {
		cout << "Элемента с введенным индексом не существует" << endl;
	}
	// Разделение на функции
	Person* new_curent_person = new Person;
	cout << "Введите данные персоны, индекс которой надо вывести:";
	list.Add(new_curent_person);
	int new_index = list.IndexOf(new_curent_person);
	if (new_index != 0) {
		cout << "Индекс нужного элемента:" << new_index << endl;
	} else {
		cout << "Такая персона не найдена" << endl;
	}
	// Разделение на функции
	cout << "Введите индекс для удаления:";
	CheckingForPositive(&index);
	list.RemoveAt(index);
	list.Print();
	// Разделение на функции
	list.Clear();
	// Разделение на функции
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
	cout << "Списки созданы" << endl << "Нажмите любую кнопку" << endl;
	bool key = _getch();
	system("cls");

	cout << "Первый список:" << endl;
	list_1.Print();
	cout << endl;
	cout << "Второй список:" << endl;
	list_2.Print();
	cout << "Нажмите любую кнопку";
	key = _getch();
	system("cls");

	cout << "Введите данные нового пользователя:" << endl;
	list_1.Add(rand_person.Read());
	cout << "Первый список:" << endl;
	list_1.Print();
	cout << endl;
	cout << "Второй список:" << endl;
	list_2.Print();
	cout << "Нажмите любую кнопку";
	key = _getch();
	system("cls");

	list_2.Add(list_1.Find(2));
	cout << "Первый список:" << endl;
	list_1.Print();
	cout << endl;
	cout << "Второй список:" << endl;
	list_2.Print();
	cout << "Нажмите любую кнопку";
	key = _getch();
	system("cls");

	list_1.RemoveAt(2);
	cout << "Первый список:" << endl;
	list_1.Print();
	cout << endl;
	cout << "Второй список:" << endl;
	list_2.Print();
	cout << "Нажмите любую кнопку";
	key = _getch();
	system("cls");

	list_2.Clear();
	cout << "Первый список:" << endl;
	list_1.Print();
	cout << endl;
	cout << "Второй список:" << endl;
	list_2.Print();
	cout << "Нажмите любую кнопку";
	key = _getch();
	system("cls");

	system("pause");
}