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

void PersonPositiveCorrection(int &age) {
	do {
		PersonAgeCorrectionInput(age, "Введено не число! Повторите ввод:");
		if (age <= 0 || age > 120) {
			cout << "Число введено не верно! Повторите ввод:";
		}
	} while (age <= 0 || age > 120);
}

bool CheckingText(char *string) {
	int i = 1;
	bool key = 1;
	//TODO: ниже какой-то пиздецкий пиздец!!! Обсудим лично.
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

void MakeName(Person* person) {
	char temp[20];
	if (person->GetSex() == Муж) {
		switch (Константин + rand() % 12){
			case(Константин):{
				strncpy_s(temp, "Константин", 10);
				person->SetName(temp);
				break;
			}
			case(Алексей): {
				strncpy_s(temp, "Алексей", 7);
				person->SetName(temp);
				break;
			}
			case(Владислав): {
				strncpy_s(temp, "Владислав", 9);
				person->SetName(temp);
				break;
			}
			case(Антон): {
				strncpy_s(temp, "Антон", 5);
				person->SetName(temp);
				break;
			}
			case(Вячеслав): {
				strncpy_s(temp, "Вячеслав", 8);
				person->SetName(temp);
				break;
			}
			case(Стас): {
				strncpy_s(temp, "Стас", 4);
				person->SetName(temp);
				break;
			}
			case(Иван): {
				strncpy_s(temp, "Иван", 4);
				person->SetName(temp);
				break;
			}
			case(Генадий): {
				strncpy_s(temp, "Генадий", 7);
				person->SetName(temp);
				break;
			}
			case(Владимир): {
				strncpy_s(temp, "Владимир", 8);
				person->SetName(temp);
				break;
			}
			case(Филипп): {
				strncpy_s(temp, "Филипп", 6);
				person->SetName(temp);
				break;
			}
			case(Николай): {
				strncpy_s(temp, "Николай", 7);
				person->SetName(temp);
				break;
			}
			case(Дмитрий): {
				strncpy_s(temp, "Дмитрий", 7);
				person->SetName(temp);
				break;
			}
			case(Александр): {
				strncpy_s(temp, "Александр", 9);
				person->SetName(temp);
				break;
			}
			default:
				break;
		}
	} else {
		switch (Валерия + rand() % 10) {
			case(Валерия): {
				strncpy_s(temp, "Валерия", 7);
				person->SetName(temp);
				break;
			}
			case(Екатерина): {
				strncpy_s(temp, "Екатерина", 9);
				person->SetName(temp);
				break;
			}
			case(Елена): {
				strncpy_s(temp, "Елена", 5);
				person->SetName(temp);
				break;
			}
			case(Ирина): {
				strncpy_s(temp, "Ирина", 5);
				person->SetName(temp);
				break;
			}
			case(Полина): {
				strncpy_s(temp, "Полина", 6);
				person->SetName(temp);
				break;
			}
			case(Маргарита): {
				strncpy_s(temp, "Маргарита", 9);
				person->SetName(temp);
				break;
			}
			case(Александра): {
				strncpy_s(temp, "Александра", 10);
				person->SetName(temp);
				break;
			}
			case(Мария): {
				strncpy_s(temp, "Мария", 5);
				person->SetName(temp);
				break;
			}
			case(Наталья): {
				strncpy_s(temp, "Наталья", 7);
				person->SetName(temp);
				break;
			}
			case(Алина): {
				strncpy_s(temp, "Алина", 5);
				person->SetName(temp);
				break;
			}
			case(Марина): {
				strncpy_s(temp, "Марина", 6);
				person->SetName(temp);
				break;
			}
			default:
				break;
		}
	}
}

void MakeSurname(Person* person) {
	char temp[20];
	if (person->GetSex() == Муж) {
		switch (Иванов + rand() % 11) {
		case(Иванов): {
			strncpy_s(temp, "Иванов", 6);
			person->SetSurname(temp);
			break;
		}
		case(Смирнов): {
			strncpy_s(temp, "Смирнов", 7);
			person->SetSurname(temp);
			break;
		}
		case(Кузнецов): {
			strncpy_s(temp, "Кузнецов", 8);
			person->SetSurname(temp);
			break;
		}
		case(Попов): {
			strncpy_s(temp, "Попов", 5);
			person->SetSurname(temp);
			break;
		}
		case(Васильев): {
			strncpy_s(temp, "Васильев", 8);
			person->SetSurname(temp);
			break;
		}
		case(Петров): {
			strncpy_s(temp, "Петров", 6);
			person->SetSurname(temp);
			break;
		}
		case(Соколов): {
			strncpy_s(temp, "Соколов", 7);
			person->SetSurname(temp);
			break;
		}
		case(Михайлов): {
			strncpy_s(temp, "Михайлов", 8);
			person->SetSurname(temp);
			break;
		}
		case(Новиков): {
			strncpy_s(temp, "Новиков", 7);
			person->SetSurname(temp);
			break;
		}
		case(Федоров): {
			strncpy_s(temp, "Федоров", 7);
			person->SetSurname(temp);
			break;
		}
		case(Морозов): {
			strncpy_s(temp, "Морозов", 7);
			person->SetSurname(temp);
			break;
		}
		case(Волков): {
			strncpy_s(temp, "Волков", 6);
			person->SetSurname(temp);
			break;
		}
		default:
			break;
		}
	}
	else {
		switch (Орлова + rand() % 11) {
		case(Орлова): {
			strncpy_s(temp, "Орлова", 6);
			person->SetSurname(temp);
			break;
		}
		case(Андреева): {
			strncpy_s(temp, "Андреева", 8);
			person->SetSurname(temp);
			break;
		}
		case(Федотова): {
			strncpy_s(temp, "Федотова", 8);
			person->SetSurname(temp);
			break;
		}
		case(Федорова): {
			strncpy_s(temp, "Федорова", 8);
			person->SetSurname(temp);
			break;
		}
		case(Яковлева): {
			strncpy_s(temp, "Яковлева", 8);
			person->SetSurname(temp);
			break;
		}
		case(Романова): {
			strncpy_s(temp, "Романова", 8);
			person->SetSurname(temp);
			break;
		}
		case(Воробьева): {
			strncpy_s(temp, "Воробьева", 9);
			person->SetSurname(temp);
			break;
		}
		case(Сергеева): {
			strncpy_s(temp, "Сергеева", 8);
			person->SetSurname(temp);
			break;
		}
		case(Фролова): {
			strncpy_s(temp, "Фролова", 7);
			person->SetSurname(temp);
			break;
		}
		case(Королева): {
			strncpy_s(temp, "Королева", 8);
			person->SetSurname(temp);
			break;
		}
		case(Гусева): {
			strncpy_s(temp, "Гусева", 6);
			person->SetSurname(temp);
			break;
		}
		case(Киселева): {
			strncpy_s(temp, "Киселева", 8);
			person->SetSurname(temp);
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

