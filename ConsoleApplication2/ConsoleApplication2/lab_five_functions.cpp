#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
#include "num_enumeration.h"
#include "PersonList.h"

using namespace std;

void PersonAgeCorrectionInput(int &age, const char kInvalidMessage[]) {
	while (!(cin >> age) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << kInvalidMessage;
	}
}

void PersonPositiveCorrection(int &age) {
	do {
		PersonAgeCorrectionInput(age, "Введено не число! Повторите ввод:");
		if (age <= 0 || age > 120) {
			cout << "Число введено не верно! Повторите ввод:";
		}
	} while (age <= 0 || age > 120);
}

bool IsBetween(char checked, char lower, char upper) {
	if (checked >= lower && checked <= upper) {
		return true;
	}
	else {
		return false;
	}
}

bool CheckOtherSymbols(char *string, int index) {
	if (string[index] == ' ' || string[index] == '-') {
		return true;
	}
	return false;
}

bool CheckLowercase(char *string, int index) {
	if (IsBetween(string[index], 'a', 'z') || IsBetween(string[index], 'а', 'я')) {
		return true;
	}
	return false;
}

bool CheckCapital(char *string, int index) {
	if (IsBetween(string[index], 'A', 'Z') || IsBetween(string[index], 'А', 'Я')) {
		return true;
	}
	return false;
}

void Lower2Uppercase(char *string, int index) {
	string[index] = (int)string[index] - 32;
}

void Upper2Lowercase(char *string, int index) {
	string[index] = (int)string[index] + 32;
}

void MakeShift(char *string, int index) {
	while (string[index] != '\0') {
		string[index - 1] = string[index];
		index++;
	}
	string[index - 1] = '\0';
}

bool CheckingText(char *string) {
	int i = 1;
	bool key = 1;
	if (!CheckCapital(string, 0)) {
		if (CheckOtherSymbols(string, 0)) {
			int j = 1;
			MakeShift(string, j);
		}
		else if (CheckLowercase(string, 0)) {
			Lower2Uppercase(string, 0);
		}
		else {
			key = 0;
			return key;
		}
	}
	while (string[i] != '\0' && key == 1) {
		if (CheckOtherSymbols(string, i-2)) {
			if (!CheckCapital(string, i-1)) {
				if (CheckLowercase(string, i+1)) {
					Lower2Uppercase(string, i-1);
				}
				else {
					key = 0;
					return key;
				}
			}
		}
		if (!CheckLowercase(string, i)) {
			if (CheckCapital(string, i)) {
				Upper2Lowercase(string, i);
			}
			else if ((string[i] == ' ' && string[i - 1] == ' ') || (string[i] == '-' && string[i - 1] == '-')) {
				int j = i;
				MakeShift(string, j);
			}
			if (!CheckOtherSymbols(string, i)) {
				key = 0;
				return key;
			}
		}
		i++;
	}
	if (CheckOtherSymbols(string, i-1)) {
		string[i - 1] = '\0';
	}
	return key;
}

PersonList MakeList(int count) {
	PersonList list(nullptr);
	for (int i = 0; i < count; i++) {
		list.Add(new Person(true));
	}
	return list;
}

void ListsPrint(PersonList list_1, PersonList list_2, bool key) {
	key = false;
	cout << "Первый список:" << endl;
	list_1.Print();
	cout << endl;
	cout << "Второй список:" << endl;
	list_2.Print();
	cout << "Нажмите любую кнопку";
	while (key == false) {
		key = _getch();
	}
	system("cls");
}

char* RandomName(string* names, int namesArrayLength) {
	int randomCounter =  rand() % (namesArrayLength - 1);
	char* temp = new char[names[randomCounter].length() + 1];
	strncpy(temp, names[randomCounter].c_str(), names[randomCounter].length() + 1);
	return temp;
}

char* MakeName(Sex sex) {
	if (sex == Муж) {
		string names[13] = { "Константин", "Алексей", "Владислав", "Антон", "Вячеслав",
			"Стас", "Иван", "Генадий", "Владимир", "Филипп", "Николай", "Дмитрий", "Александр" };
		return RandomName(names, 13);
	} else {
		string names[11] = { "Валерия", "Екатерина", "Елена", "Ирина", "Полина",
			"Маргарита", "Александра", "Мария", "Наталья", "Алина", "Марина"};
		return RandomName(names, 11);
	}
}

char* MakeSurname(Sex sex) {
	if (sex == Муж) {
		string surnames[12] = { "Иванов", "Смирнов", "Кузнецов", "Попов", "Васильев",
			"Петров", "Соколов", "Михайлов", "Новиков", "Федоров", "Морозов", "Волков"};
		return RandomName(surnames, 12);
	}
	else {
		string surnames[12] = { "Орлова", "Андреева", "Федотова", "Федорова", "Яковлева",
			"Романова", "Воробьева", "Сергеева", "Фролова", "Королева", "Гусева",  "Киселева"};
		return RandomName(surnames, 12);
	}
}

char* NameInput(const char* text) {
	string temp = "";
	int key = 0;
	char* myName = nullptr;
	while (myName == nullptr) {
		while (key == 0) {
			cout << text; 
			getline(cin, temp);
			myName = new char[temp.length() + 1];
			strncpy(myName, temp.c_str(), temp.length() + 1);
			key = CheckingText(myName);
		}
	}
	return myName;
}

Person* Read() {
	int sex_key = 0;

	char* name = NameInput("Введите имя:");

	char* surname = NameInput("Введите фамилию:");
	cout << "Введите пол (1-муж/2-жен):" << endl;
	bool is_exit;
	Sex sex;
	do {
		while (sex_key == 0) {
			sex_key = _getch();
			if (sex_key != num_1 && sex_key != num_2)	sex_key = 0;
		}
		is_exit = true;
		switch (sex_key) {
		case num_1: {
			sex = Муж;
			is_exit = false;
			break;
		}
		case num_2: {
			sex = Жен;
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
	int age;
	PersonPositiveCorrection(age);

	return new Person(name, surname, sex, age);
}

char* CreateBusiness() {
	char* business = new char[6];
	business[0] = 'A' + rand() % 25;
	for (int i = 1; i < 5; i++) {
		business[i] = 'a' + rand() % 25;
	}
	business[6] = '\0';
	return business;
}

