#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <iomanip>
#include "num_enumeration.h"
#include "PersonList.h"
#include "male_name_enumeration.h"
#include "female_name_enumeration.h"
#include "male_surname_enumerations.h"
#include "female_surname_enumeration.h"

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

bool CheckingText(char *string) {
	int i = 1;
	bool key = 1;
	//TODO: ниже какой-то пиздецкий пиздец!!! Обсудим лично.
	//TODO: все диапазонные сравнения можно вынести в метод IsBetween(char checked, char lower, char upper)
	if (IsBetween(string[0], 'A', 'Z') || IsBetween(string[0], 'А', 'Я')) {
		//TODO: Где код?
	} else if (string[0] == ' ' || string[0] == '-') {
		int j = 1;
		while (string[j] != '\0') {
			string[j - 1] = string[j];
			j++;
		}
		string[j - 1] = '\0';
	} else if (IsBetween(string[0], 'a', 'z') || IsBetween(string[0], 'а', 'я')) {
		string[0] = (int)string[0] - 32;
	} else {
		key = 0;
		return key;
	}
	while (string[i] != '\0' && key == 1) {
		if ((string[i - 2] == ' ') || (string[i - 2] == '-')) {
			if (IsBetween(string[i-1], 'A', 'Z') || IsBetween(string[i-1], 'А', 'Я')) {
				//TODO: Где код?
			} else if (IsBetween(string[i+1], 'a', 'z') || IsBetween(string[i+1], 'а', 'я')) {
				string[i - 1] = (int)string[i - 1] - 32;
			} else {
				key = 0;
				return key;
			}
		}
		if (IsBetween(string[i], 'a', 'z') || IsBetween(string[i], 'а', 'я')) {
			//TODO: Где код?
		} else if (IsBetween(string[i], 'A', 'Z') || IsBetween(string[i], 'А', 'Я')) {
			string[i] = (int)string[i] + 32;
		}  else if((string[i] == ' ' && string[i-1] == ' ') || (string[i] == '-' && string[i - 1] == '-')){
			int j = i;
			while (string[j] != '\0') {
				string[j - 1] = string[j];
				j++;
			}
			string[j - 1] = '\0';
		} else if (string[i] == ' ' || string[i] == '-') {

		} else {
			key = 0;
			return key;
		}
		i++;
	}
	if (string[i - 1] == ' ' || string[i - 1] == '-') {
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

//TODO: всё срань! Переделай на массивы строк.
//TODO: и нехрен сюда персону передавать.
char* MakeName(Sex sex) {
	char* temp = new char[20];
	if (sex == Муж) {
		switch (Константин + rand() % 12){
			case(Константин):{
				strncpy(temp, "Константин", 11);
				return temp;
				break;
			}
			case(Алексей): {
				strncpy(temp, "Алексей", 8);
				return temp;
				break;
			}
			case(Владислав): {
				strncpy(temp, "Владислав", 10);
				return temp;
				break;
			}
			case(Антон): {
				strncpy(temp, "Антон", 6);
				return temp;
				break;
			}
			case(Вячеслав): {
				strncpy(temp, "Вячеслав", 9);
				return temp;
				break;
			}
			case(Стас): {
				strncpy(temp, "Стас", 5);
				return temp;
				break;
			}
			case(Иван): {
				strncpy(temp, "Иван", 5);
				return temp;
				break;
			}
			case(Генадий): {
				strncpy(temp, "Генадий", 8);
				return temp;
				break;
			}
			case(Владимир): {
				strncpy(temp, "Владимир", 9);
				return temp;
				break;
			}
			case(Филипп): {
				strncpy(temp, "Филипп", 7);
				return temp;
				break;
			}
			case(Николай): {
				strncpy(temp, "Николай", 8);
				return temp;
				break;
			}
			case(Дмитрий): {
				strncpy(temp, "Дмитрий", 8);
				return temp;
				break;
			}
			case(Александр): {
				strncpy(temp, "Александр", 10);
				return temp;
				break;
			}
			default:
				break;
		}
	} else {
		switch (Валерия + rand() % 10) {
			case(Валерия): {
				strncpy(temp, "Валерия", 8);
				return temp;
				break;
			}
			case(Екатерина): {
				strncpy(temp, "Екатерина", 10);
				return temp;
				break;
			}
			case(Елена): {
				strncpy(temp, "Елена", 6);
				return temp;
				break;
			}
			case(Ирина): {
				strncpy(temp, "Ирина", 6);
				return temp;
				break;
			}
			case(Полина): {
				strncpy(temp, "Полина", 7);
				return temp;
				break;
			}
			case(Маргарита): {
				strncpy(temp, "Маргарита", 10);
				return temp;
				break;
			}
			case(Александра): {
				strncpy(temp, "Александра", 11);
				return temp;
				break;
			}
			case(Мария): {
				strncpy(temp, "Мария", 6);
				return temp;
				break;
			}
			case(Наталья): {
				strncpy(temp, "Наталья", 8);
				return temp;
				break;
			}
			case(Алина): {
				strncpy(temp, "Алина", 6);
				return temp;
				break;
			}
			case(Марина): {
				strncpy(temp, "Марина", 7);
				return temp;
				break;
			}
			default:
				break;
		}
	}
}

char* MakeSurname(Sex sex) {
	char* temp = new char[20];
	if (sex == Муж) {
		switch (Иванов + rand() % 11) {
		case(Иванов): {
			strncpy(temp, "Иванов", 7);
			return temp;
			break;
		}
		case(Смирнов): {
			strncpy(temp, "Смирнов", 8);
			return temp;
			break;
		}
		case(Кузнецов): {
			strncpy(temp, "Кузнецов", 9);
			return temp;
			break;
		}
		case(Попов): {
			strncpy(temp, "Попов", 6);
			return temp;
			break;
		}
		case(Васильев): {
			strncpy(temp, "Васильев", 9);
			return temp;
			break;
		}
		case(Петров): {
			strncpy(temp, "Петров", 7);
			return temp;
			break;
		}
		case(Соколов): {
			strncpy(temp, "Соколов", 8);
			return temp;
			break;
		}
		case(Михайлов): {
			strncpy(temp, "Михайлов", 9);
			return temp;
			break;
		}
		case(Новиков): {
			strncpy(temp, "Новиков", 8);
			return temp;
			break;
		}
		case(Федоров): {
			strncpy(temp, "Федоров", 8);
			return temp;
			break;
		}
		case(Морозов): {
			strncpy(temp, "Морозов", 8);
			return temp;
			break;
		}
		case(Волков): {
			strncpy(temp, "Волков", 7);
			return temp;
			break;
		}
		default:
			break;
		}
	}
	else {
		switch (Орлова + rand() % 11) {
		case(Орлова): {
			strncpy(temp, "Орлова", 7);
			return temp;
			break;
		}
		case(Андреева): {
			strncpy(temp, "Андреева", 9);
			return temp;
			break;
		}
		case(Федотова): {
			strncpy(temp, "Федотова", 9);
			return temp;
			break;
		}
		case(Федорова): {
			strncpy(temp, "Федорова", 9);
			return temp;
			break;
		}
		case(Яковлева): {
			strncpy(temp, "Яковлева", 9);
			return temp;
			break;
		}
		case(Романова): {
			strncpy(temp, "Романова", 9);
			return temp;
			break;
		}
		case(Воробьева): {
			strncpy(temp, "Воробьева", 10);
			return temp;
			break;
		}
		case(Сергеева): {
			strncpy(temp, "Сергеева", 9);
			return temp;
			break;
		}
		case(Фролова): {
			strncpy(temp, "Фролова", 8);
			return temp;
			break;
		}
		case(Королева): {
			strncpy(temp, "Королева", 9);
			return temp;
			break;
		}
		case(Гусева): {
			strncpy(temp, "Гусева", 7);
			return temp;
			break;
		}
		case(Киселева): {
			strncpy(temp, "Киселева", 9);
			return temp;
			break;
		}
		default:
			break;
		}
	}
}

char* NameInput(const char* text) {
	const char kTempSize = 50;
	char temp[kTempSize];
	int key = 0;
	strcpy_s(temp, "");
	while (strcmp(temp, "") == NULL) {
		while (key == 0) {
			cout << text;
			cin.getline(temp, kTempSize);
			key = CheckingText(temp);
		}
	}
	return temp;
}

