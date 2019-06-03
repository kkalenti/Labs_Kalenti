#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <iomanip>
#include "num_enumeration.h"
#include "PersonalListItem.h"
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

void PersonPositiveCorrection(int *age) {
	do {
		PersonAgeCorrectionInput(*age, "Введено не число! Повторите ввод:");
		if (age <= 0) {
			cout << "Число не соответствует условию (Индекс <= 0)! Повторите ввод:";
		}
	} while (age <= 0);
}

bool CheckingText(char *string) {
	int i = 1;
	bool key = 1;
	//TODO:
	if ((string[0] >= 'A' && string[0] <= 'Z') || (string[0] >= 'А' && string[0] <= 'Я')) {
		
	} else if (string[0] == ' ' || string[0] == '-') {
		int j = 1;
		while (string[j] != '\0') {
			string[j - 1] = string[j];
			j++;
		}
		string[j - 1] = '\0';
	} else if (string[0] >= 'a' && string[0] <= 'z') {
		string[0] = (int)string[0] - 32;
	} else if (string[0] >= 'а' && string[0] <= 'я') {
		string[0] = (int)string[0] - 32;
	} else {
		key = 0;
		return key;
	}
	while (string[i] != '\0' && key == 1) {
		if ((string[i - 2] == ' ') || (string[i - 2] == '-')) {
			if (string[i - 1] >= 'A' && string[i - 1] <= 'Z' || string[i - 1] >= 'A' && string[i - 1] <= 'Я') {

			}
			else if (string[i + 1] >= 'a' && string[i + 1] <= 'z') {
				string[i - 1] = (int)string[i - 1] - 32;
			}
			else if (string[i] >= 'а' && string[i] <= 'я') {
				string[i - 1] = (int)string[i - 1] - 32;
			}
			else {
				key = 0;
				return key;
			}
		}
		if (string[i] >= 'a' && string[i] <= 'z' || string[i] >= 'а' && string[i] <= 'я') {

		} else if (string[i] >= 'A' && string[i] <= 'Z') {
			string[i] = (int)string[i] + 32;
		}  else if((string[i] == ' ' && string[i-1] == ' ') || (string[i] == '-' && string[i - 1] == '-')){
			int j = i;
			while (string[j] != '\0') {
				string[j - 1] = string[j];
				j++;
			}
			string[j - 1] = '\0';
		} else if (string[i] >= 'А' && string[i] <= 'Я') {
			string[i] = (int)string[i] + 32;
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
	PersonList list(nullptr, count);
	for (int i = 0; i < count; i++) {
		list.Add(Person::GetRandomPerson());
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

void MakeName(Person* person) {
	if (person->sex == Муж) {
		switch (Константин + rand() % 12){
			case(Константин):{
				strncpy_s(person->name, "Константин", 10);
				break;
			}
			case(Алексей): {
				strncpy_s(person->name, "Алексей", 7);
				break;
			}
			case(Владислав): {
				strncpy_s(person->name, "Владислав", 9);
				break;
			}
			case(Антон): {
				strncpy_s(person->name, "Антон", 5);
				break;
			}
			case(Вячеслав): {
				strncpy_s(person->name, "Вячеслав", 8);
				break;
			}
			case(Стас): {
				strncpy_s(person->name, "Стас", 4);
				break;
			}
			case(Иван): {
				strncpy_s(person->name, "Иван", 4);
				break;
			}
			case(Генадий): {
				strncpy_s(person->name, "Генадий", 7);
				break;
			}
			case(Владимир): {
				strncpy_s(person->name, "Владимир", 8);
				break;
			}
			case(Филипп): {
				strncpy_s(person->name, "Филипп", 6);
				break;
			}
			case(Николай): {
				strncpy_s(person->name, "Николай", 7);
				break;
			}
			case(Дмитрий): {
				strncpy_s(person->name, "Дмитрий", 7);
				break;
			}
			case(Александр): {
				strncpy_s(person->name, "Александр", 9);
				break;
			}
			default:
				break;
		}
	} else {
		switch (Валерия + rand() % 10) {
			case(Валерия): {
				strncpy_s(person->name, "Валерия", 7);
				break;
			}
			case(Екатерина): {
				strncpy_s(person->name, "Екатерина", 9);
				break;
			}
			case(Елена): {
				strncpy_s(person->name, "Елена", 5);
				break;
			}
			case(Ирина): {
				strncpy_s(person->name, "Ирина", 5);
				break;
			}
			case(Полина): {
				strncpy_s(person->name, "Полина", 6);
				break;
			}
			case(Маргарита): {
				strncpy_s(person->name, "Маргарита", 9);
				break;
			}
			case(Александра): {
				strncpy_s(person->name, "Александра", 10);
				break;
			}
			case(Мария): {
				strncpy_s(person->name, "Мария", 5);
				break;
			}
			case(Наталья): {
				strncpy_s(person->name, "Наталья", 7);
				break;
			}
			case(Алина): {
				strncpy_s(person->name, "Алина", 5);
				break;
			}
			case(Марина): {
				strncpy_s(person->name, "Марина", 6);
				break;
			}
			default:
				break;
		}
	}
}

void MakeSurname(Person* person) {
	if (person->sex == Муж) {
		switch (Иванов + rand() % 11) {
		case(Иванов): {
			strncpy_s(person->surname, "Иванов", 6);
			break;
		}
		case(Смирнов): {
			strncpy_s(person->surname, "Смирнов", 7);
			break;
		}
		case(Кузнецов): {
			strncpy_s(person->surname, "Кузнецов", 8);
			break;
		}
		case(Попов): {
			strncpy_s(person->surname, "Попов", 5);
			break;
		}
		case(Васильев): {
			strncpy_s(person->surname, "Васильев", 8);
			break;
		}
		case(Петров): {
			strncpy_s(person->surname, "Петров", 6);
			break;
		}
		case(Соколов): {
			strncpy_s(person->surname, "Соколов", 7);
			break;
		}
		case(Михайлов): {
			strncpy_s(person->surname, "Михайлов", 8);
			break;
		}
		case(Новиков): {
			strncpy_s(person->surname, "Новиков", 7);
			break;
		}
		case(Федоров): {
			strncpy_s(person->surname, "Федоров", 7);
			break;
		}
		case(Морозов): {
			strncpy_s(person->surname, "Морозов", 7);
			break;
		}
		case(Волков): {
			strncpy_s(person->surname, "Волков", 6);
			break;
		}
		default:
			break;
		}
	}
	else {
		switch (Орлова + rand() % 11) {
		case(Орлова): {
			strncpy_s(person->surname, "Орлова", 6);
			break;
		}
		case(Андреева): {
			strncpy_s(person->surname, "Андреева", 8);
			break;
		}
		case(Федотова): {
			strncpy_s(person->surname, "Федотова", 8);
			break;
		}
		case(Федорова): {
			strncpy_s(person->surname, "Федорова", 8);
			break;
		}
		case(Яковлева): {
			strncpy_s(person->surname, "Яковлева", 8);
			break;
		}
		case(Романова): {
			strncpy_s(person->surname, "Романова", 8);
			break;
		}
		case(Воробьева): {
			strncpy_s(person->surname, "Воробьева", 9);
			break;
		}
		case(Сергеева): {
			strncpy_s(person->surname, "Сергеева", 8);
			break;
		}
		case(Фролова): {
			strncpy_s(person->surname, "Фролова", 7);
			break;
		}
		case(Королева): {
			strncpy_s(person->surname, "Королева", 8);
			break;
		}
		case(Гусева): {
			strncpy_s(person->surname, "Гусева", 6);
			break;
		}
		case(Киселева): {
			strncpy_s(person->surname, "Киселева", 8);
			break;
		}
		default:
			break;
		}
	}
}