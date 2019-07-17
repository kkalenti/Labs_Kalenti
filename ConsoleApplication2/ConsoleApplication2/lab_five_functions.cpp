#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <vector>
#include "num_enumeration.h"
#include "PersonList.h"

using namespace std;

#define UPPER_TO_LOWER_GAP 32
#define STRING_END '\0'

bool IsBetween(char checked, char lower, char upper) {
	//TODO: Можно сильно посокращать кол-во строк, если просто возвращать результат if-а и везде ниже тоже
	//TODO: Смотри сам, конечно, но по мне - читается такая конструкция лучше
	return checked >= lower && checked <= upper;
}

bool CheckOtherSymbols(char *string, int index) {
	return string[index] == ' ' || string[index] == '-';
}

bool CheckLowercase(char *string, int index) {
	return IsBetween(string[index], 'a', 'z')
		|| IsBetween(string[index], 'а', 'я');
}

bool CheckCapital(char *string, int index) {
	return IsBetween(string[index], 'A', 'Z')
		|| IsBetween(string[index], 'А', 'Я');
}

void Lower2Uppercase(char *string, int index) {
	//TODO: 32 - какая-то магическая хуета, лучше литеральную константу завести
	string[index] = (int)string[index] - UPPER_TO_LOWER_GAP;
}

void Upper2Lowercase(char *string, int index) {
	string[index] = (int)string[index] + UPPER_TO_LOWER_GAP;
}

void MakeShift(char *string, int index) {
	//TODO: \0 - конец строки, также можно завести литеральную константу, чтобы повысить читаемость
	while (string[index] != STRING_END) {
		string[index - 1] = string[index];
		index++;
	}
	string[index - 1] = STRING_END;
}

bool CheckingText(char *string) {
	int i = 1;
	bool key = true;
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
	//TODO: Конец строки
	while (string[i] != STRING_END && key == 1) {
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
			else if ((string[i] == ' ' && string[i - 1] == ' ')
				|| (string[i] == '-' && string[i - 1] == '-')) {
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
		//TODO: Конец строки
		string[i - 1] = STRING_END;
	}
	return key;
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

//TODO: 1- название параметров пососное, т.к. ты можешь передавать не только имена
//TODO: 2- ищи стандартные средства для улучшения масштабирования кода, в случае передачи размерности массива
//TODO: тебе всегда надо будет держать в башке, сколько элементов в массиве. Дак вот не удобнее ли будет 
//TODO: вычислять размер массива на месте? Как-нибудь типа такого 
// https://stackoverflow.com/questions/4108313/how-do-i-find-the-length-of-an-array
char* RandomArrayElement(vector<string> stringArray) {
	int randomCounter =  rand() % (stringArray.size() - 1);
	char* temp = new char[stringArray[randomCounter].length() + 1];
	strncpy(temp, stringArray[randomCounter].c_str(), stringArray[randomCounter].length() + 1);
	return temp;
}

char* MakeName(Sex sex) {
	if (sex == Муж) {
		vector<string> names = { "Константин", "Алексей", "Владислав",
			"Антон", "Вячеслав","Стас",
			"Иван", "Генадий", "Владимир",
			"Филипп", "Николай", "Дмитрий",
			"Александр" };
		return RandomArrayElement(names);
	} else {
		vector<string> names = { "Валерия", "Екатерина", "Елена",
			"Ирина", "Полина", "Маргарита", 
			"Александра", "Мария", "Наталья",
			"Алина", "Марина"};
		return RandomArrayElement(names);
	}
}

char* MakeSurname(Sex sex) {
	if (sex == Муж) {
		vector<string> surnames = { "Иванов", "Смирнов", "Кузнецов",
			"Попов", "Васильев", "Петров",
			"Соколов", "Михайлов", "Новиков",
			"Федоров", "Морозов", "Волков"};
		return RandomArrayElement(surnames);
	}
	else {
		vector<string> surnames = { "Орлова", "Андреева", "Федотова",
			"Федорова", "Яковлева", "Романова",
			"Воробьева", "Сергеева", "Фролова",
			"Королева", "Гусева",  "Киселева"};
		return RandomArrayElement(surnames);
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

char* CreateBusiness() {
	//TODO: а тут, бл., всё в куче - размер массива, магическое число 25, конец строки...
	const int wordSize = 6;
	char* business = new char[wordSize];
	business[0] = 'А' + rand() % UPPER_TO_LOWER_GAP;
	for (int i = 1; i < wordSize - 2; i++) {
		business[i] = 'а' + rand() % UPPER_TO_LOWER_GAP;
	}
	business[wordSize - 1] = STRING_END;
	return business;
}

