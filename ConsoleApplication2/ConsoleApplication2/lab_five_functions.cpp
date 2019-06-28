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
		PersonAgeCorrectionInput(age, "������� �� �����! ��������� ����:");
		if (age <= 0 || age > 120) {
			cout << "����� ������� �� �����! ��������� ����:";
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
	//TODO: ���� �����-�� ��������� ������!!! ������� �����.
	//TODO: ��� ����������� ��������� ����� ������� � ����� IsBetween(char checked, char lower, char upper)
	if (IsBetween(string[0], 'A', 'Z') || IsBetween(string[0], '�', '�')) {
		//TODO: ��� ���?
	} else if (string[0] == ' ' || string[0] == '-') {
		int j = 1;
		while (string[j] != '\0') {
			string[j - 1] = string[j];
			j++;
		}
		string[j - 1] = '\0';
	} else if (IsBetween(string[0], 'a', 'z') || IsBetween(string[0], '�', '�')) {
		string[0] = (int)string[0] - 32;
	} else {
		key = 0;
		return key;
	}
	while (string[i] != '\0' && key == 1) {
		if ((string[i - 2] == ' ') || (string[i - 2] == '-')) {
			if (IsBetween(string[i-1], 'A', 'Z') || IsBetween(string[i-1], '�', '�')) {
				//TODO: ��� ���?
			} else if (IsBetween(string[i+1], 'a', 'z') || IsBetween(string[i+1], '�', '�')) {
				string[i - 1] = (int)string[i - 1] - 32;
			} else {
				key = 0;
				return key;
			}
		}
		if (IsBetween(string[i], 'a', 'z') || IsBetween(string[i], '�', '�')) {
			//TODO: ��� ���?
		} else if (IsBetween(string[i], 'A', 'Z') || IsBetween(string[i], '�', '�')) {
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

//TODO: �� �����! ��������� �� ������� �����.
//TODO: � ������ ���� ������� ����������.
char* MakeName(Sex sex) {
	char* temp = new char[20];
	if (sex == ���) {
		switch (���������� + rand() % 12){
			case(����������):{
				strncpy(temp, "����������", 11);
				return temp;
				break;
			}
			case(�������): {
				strncpy(temp, "�������", 8);
				return temp;
				break;
			}
			case(���������): {
				strncpy(temp, "���������", 10);
				return temp;
				break;
			}
			case(�����): {
				strncpy(temp, "�����", 6);
				return temp;
				break;
			}
			case(��������): {
				strncpy(temp, "��������", 9);
				return temp;
				break;
			}
			case(����): {
				strncpy(temp, "����", 5);
				return temp;
				break;
			}
			case(����): {
				strncpy(temp, "����", 5);
				return temp;
				break;
			}
			case(�������): {
				strncpy(temp, "�������", 8);
				return temp;
				break;
			}
			case(��������): {
				strncpy(temp, "��������", 9);
				return temp;
				break;
			}
			case(������): {
				strncpy(temp, "������", 7);
				return temp;
				break;
			}
			case(�������): {
				strncpy(temp, "�������", 8);
				return temp;
				break;
			}
			case(�������): {
				strncpy(temp, "�������", 8);
				return temp;
				break;
			}
			case(���������): {
				strncpy(temp, "���������", 10);
				return temp;
				break;
			}
			default:
				break;
		}
	} else {
		switch (������� + rand() % 10) {
			case(�������): {
				strncpy(temp, "�������", 8);
				return temp;
				break;
			}
			case(���������): {
				strncpy(temp, "���������", 10);
				return temp;
				break;
			}
			case(�����): {
				strncpy(temp, "�����", 6);
				return temp;
				break;
			}
			case(�����): {
				strncpy(temp, "�����", 6);
				return temp;
				break;
			}
			case(������): {
				strncpy(temp, "������", 7);
				return temp;
				break;
			}
			case(���������): {
				strncpy(temp, "���������", 10);
				return temp;
				break;
			}
			case(����������): {
				strncpy(temp, "����������", 11);
				return temp;
				break;
			}
			case(�����): {
				strncpy(temp, "�����", 6);
				return temp;
				break;
			}
			case(�������): {
				strncpy(temp, "�������", 8);
				return temp;
				break;
			}
			case(�����): {
				strncpy(temp, "�����", 6);
				return temp;
				break;
			}
			case(������): {
				strncpy(temp, "������", 7);
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
	if (sex == ���) {
		switch (������ + rand() % 11) {
		case(������): {
			strncpy(temp, "������", 7);
			return temp;
			break;
		}
		case(�������): {
			strncpy(temp, "�������", 8);
			return temp;
			break;
		}
		case(��������): {
			strncpy(temp, "��������", 9);
			return temp;
			break;
		}
		case(�����): {
			strncpy(temp, "�����", 6);
			return temp;
			break;
		}
		case(��������): {
			strncpy(temp, "��������", 9);
			return temp;
			break;
		}
		case(������): {
			strncpy(temp, "������", 7);
			return temp;
			break;
		}
		case(�������): {
			strncpy(temp, "�������", 8);
			return temp;
			break;
		}
		case(��������): {
			strncpy(temp, "��������", 9);
			return temp;
			break;
		}
		case(�������): {
			strncpy(temp, "�������", 8);
			return temp;
			break;
		}
		case(�������): {
			strncpy(temp, "�������", 8);
			return temp;
			break;
		}
		case(�������): {
			strncpy(temp, "�������", 8);
			return temp;
			break;
		}
		case(������): {
			strncpy(temp, "������", 7);
			return temp;
			break;
		}
		default:
			break;
		}
	}
	else {
		switch (������ + rand() % 11) {
		case(������): {
			strncpy(temp, "������", 7);
			return temp;
			break;
		}
		case(��������): {
			strncpy(temp, "��������", 9);
			return temp;
			break;
		}
		case(��������): {
			strncpy(temp, "��������", 9);
			return temp;
			break;
		}
		case(��������): {
			strncpy(temp, "��������", 9);
			return temp;
			break;
		}
		case(��������): {
			strncpy(temp, "��������", 9);
			return temp;
			break;
		}
		case(��������): {
			strncpy(temp, "��������", 9);
			return temp;
			break;
		}
		case(���������): {
			strncpy(temp, "���������", 10);
			return temp;
			break;
		}
		case(��������): {
			strncpy(temp, "��������", 9);
			return temp;
			break;
		}
		case(�������): {
			strncpy(temp, "�������", 8);
			return temp;
			break;
		}
		case(��������): {
			strncpy(temp, "��������", 9);
			return temp;
			break;
		}
		case(������): {
			strncpy(temp, "������", 7);
			return temp;
			break;
		}
		case(��������): {
			strncpy(temp, "��������", 9);
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

