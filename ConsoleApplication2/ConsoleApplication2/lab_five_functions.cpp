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
		PersonAgeCorrectionInput(age, "������� �� �����! ��������� ����:");
		if (age <= 0 || age > 120) {
			cout << "����� ������� �� �����! ��������� ����:";
		}
	} while (age <= 0 || age > 120);
}

bool CheckingText(char *string) {
	int i = 1;
	bool key = 1;
	//TODO: ���� �����-�� ��������� ������!!! ������� �����.
	if ((string[0] >= 'A' && string[0] <= 'Z') || (string[0] >= '�' && string[0] <= '�')) {
		
	} else if (string[0] == ' ' || string[0] == '-') {
		int j = 1;
		while (string[j] != '\0') {
			string[j - 1] = string[j];
			j++;
		}
		string[j - 1] = '\0';
	} else if (string[0] >= 'a' && string[0] <= 'z') {
		string[0] = (int)string[0] - 32;
	} else if (string[0] >= '�' && string[0] <= '�') {
		string[0] = (int)string[0] - 32;
	} else {
		key = 0;
		return key;
	}
	while (string[i] != '\0' && key == 1) {
		if ((string[i - 2] == ' ') || (string[i - 2] == '-')) {
			if (string[i - 1] >= 'A' && string[i - 1] <= 'Z' || string[i - 1] >= 'A' && string[i - 1] <= '�') {

			}
			else if (string[i + 1] >= 'a' && string[i + 1] <= 'z') {
				string[i - 1] = (int)string[i - 1] - 32;
			}
			else if (string[i] >= '�' && string[i] <= '�') {
				string[i - 1] = (int)string[i - 1] - 32;
			}
			else {
				key = 0;
				return key;
			}
		}
		if (string[i] >= 'a' && string[i] <= 'z' || string[i] >= '�' && string[i] <= '�') {

		} else if (string[i] >= 'A' && string[i] <= 'Z') {
			string[i] = (int)string[i] + 32;
		}  else if((string[i] == ' ' && string[i-1] == ' ') || (string[i] == '-' && string[i - 1] == '-')){
			int j = i;
			while (string[j] != '\0') {
				string[j - 1] = string[j];
				j++;
			}
			string[j - 1] = '\0';
		} else if (string[i] >= '�' && string[i] <= '�') {
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
	cout << "������ ������:" << endl;
	list_1.Print();
	cout << endl;
	cout << "������ ������:" << endl;
	list_2.Print();
	cout << "������� ����� ������";
	while (key == false) {
		key = _getch();
	}
	system("cls");
}

void MakeName(Person* person) {
	char temp[20];
	if (person->GetSex() == ���) {
		switch (���������� + rand() % 12){
			case(����������):{
				strncpy_s(temp, "����������", 10);
				person->SetName(temp);
				break;
			}
			case(�������): {
				strncpy_s(temp, "�������", 7);
				person->SetName(temp);
				break;
			}
			case(���������): {
				strncpy_s(temp, "���������", 9);
				person->SetName(temp);
				break;
			}
			case(�����): {
				strncpy_s(temp, "�����", 5);
				person->SetName(temp);
				break;
			}
			case(��������): {
				strncpy_s(temp, "��������", 8);
				person->SetName(temp);
				break;
			}
			case(����): {
				strncpy_s(temp, "����", 4);
				person->SetName(temp);
				break;
			}
			case(����): {
				strncpy_s(temp, "����", 4);
				person->SetName(temp);
				break;
			}
			case(�������): {
				strncpy_s(temp, "�������", 7);
				person->SetName(temp);
				break;
			}
			case(��������): {
				strncpy_s(temp, "��������", 8);
				person->SetName(temp);
				break;
			}
			case(������): {
				strncpy_s(temp, "������", 6);
				person->SetName(temp);
				break;
			}
			case(�������): {
				strncpy_s(temp, "�������", 7);
				person->SetName(temp);
				break;
			}
			case(�������): {
				strncpy_s(temp, "�������", 7);
				person->SetName(temp);
				break;
			}
			case(���������): {
				strncpy_s(temp, "���������", 9);
				person->SetName(temp);
				break;
			}
			default:
				break;
		}
	} else {
		switch (������� + rand() % 10) {
			case(�������): {
				strncpy_s(temp, "�������", 7);
				person->SetName(temp);
				break;
			}
			case(���������): {
				strncpy_s(temp, "���������", 9);
				person->SetName(temp);
				break;
			}
			case(�����): {
				strncpy_s(temp, "�����", 5);
				person->SetName(temp);
				break;
			}
			case(�����): {
				strncpy_s(temp, "�����", 5);
				person->SetName(temp);
				break;
			}
			case(������): {
				strncpy_s(temp, "������", 6);
				person->SetName(temp);
				break;
			}
			case(���������): {
				strncpy_s(temp, "���������", 9);
				person->SetName(temp);
				break;
			}
			case(����������): {
				strncpy_s(temp, "����������", 10);
				person->SetName(temp);
				break;
			}
			case(�����): {
				strncpy_s(temp, "�����", 5);
				person->SetName(temp);
				break;
			}
			case(�������): {
				strncpy_s(temp, "�������", 7);
				person->SetName(temp);
				break;
			}
			case(�����): {
				strncpy_s(temp, "�����", 5);
				person->SetName(temp);
				break;
			}
			case(������): {
				strncpy_s(temp, "������", 6);
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
	if (person->GetSex() == ���) {
		switch (������ + rand() % 11) {
		case(������): {
			strncpy_s(temp, "������", 6);
			person->SetSurname(temp);
			break;
		}
		case(�������): {
			strncpy_s(temp, "�������", 7);
			person->SetSurname(temp);
			break;
		}
		case(��������): {
			strncpy_s(temp, "��������", 8);
			person->SetSurname(temp);
			break;
		}
		case(�����): {
			strncpy_s(temp, "�����", 5);
			person->SetSurname(temp);
			break;
		}
		case(��������): {
			strncpy_s(temp, "��������", 8);
			person->SetSurname(temp);
			break;
		}
		case(������): {
			strncpy_s(temp, "������", 6);
			person->SetSurname(temp);
			break;
		}
		case(�������): {
			strncpy_s(temp, "�������", 7);
			person->SetSurname(temp);
			break;
		}
		case(��������): {
			strncpy_s(temp, "��������", 8);
			person->SetSurname(temp);
			break;
		}
		case(�������): {
			strncpy_s(temp, "�������", 7);
			person->SetSurname(temp);
			break;
		}
		case(�������): {
			strncpy_s(temp, "�������", 7);
			person->SetSurname(temp);
			break;
		}
		case(�������): {
			strncpy_s(temp, "�������", 7);
			person->SetSurname(temp);
			break;
		}
		case(������): {
			strncpy_s(temp, "������", 6);
			person->SetSurname(temp);
			break;
		}
		default:
			break;
		}
	}
	else {
		switch (������ + rand() % 11) {
		case(������): {
			strncpy_s(temp, "������", 6);
			person->SetSurname(temp);
			break;
		}
		case(��������): {
			strncpy_s(temp, "��������", 8);
			person->SetSurname(temp);
			break;
		}
		case(��������): {
			strncpy_s(temp, "��������", 8);
			person->SetSurname(temp);
			break;
		}
		case(��������): {
			strncpy_s(temp, "��������", 8);
			person->SetSurname(temp);
			break;
		}
		case(��������): {
			strncpy_s(temp, "��������", 8);
			person->SetSurname(temp);
			break;
		}
		case(��������): {
			strncpy_s(temp, "��������", 8);
			person->SetSurname(temp);
			break;
		}
		case(���������): {
			strncpy_s(temp, "���������", 9);
			person->SetSurname(temp);
			break;
		}
		case(��������): {
			strncpy_s(temp, "��������", 8);
			person->SetSurname(temp);
			break;
		}
		case(�������): {
			strncpy_s(temp, "�������", 7);
			person->SetSurname(temp);
			break;
		}
		case(��������): {
			strncpy_s(temp, "��������", 8);
			person->SetSurname(temp);
			break;
		}
		case(������): {
			strncpy_s(temp, "������", 6);
			person->SetSurname(temp);
			break;
		}
		case(��������): {
			strncpy_s(temp, "��������", 8);
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

