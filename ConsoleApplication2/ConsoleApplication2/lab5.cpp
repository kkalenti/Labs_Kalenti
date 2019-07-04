#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "PersonList.h"
#include "lab_five_functions.h"
#include "functions.h"

using namespace std; 

void lab5() {
	//TODO: с конструктором хуйня, нужно править
	PersonList list_1 = MakeList(3);
	PersonList list_2 = MakeList(3);
	cout << "Списки созданы" << endl << "Нажмите любую кнопку" << endl;
	bool key = _getch();
	system("cls");
	
	ListsPrint(list_1,list_2,key);

	cout << "Введите данные нового пользователя:" << endl;
	list_1.Add(Read());
	ListsPrint(list_1, list_2, key);

	list_2.Add(list_1.Find(2));
	ListsPrint(list_1, list_2, key);

	list_1.RemoveAt(2);
	ListsPrint(list_1, list_2, key);

	list_2.Clear();
	ListsPrint(list_1, list_2, key);

	system("pause");
}