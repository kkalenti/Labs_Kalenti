#include "stdafx.h"
#include <iostream>
#include "person_structure.h"

using namespace std;

void CheckingOfCorrectInputOfNumberForPerson(PersonStr *person, const char kInvalidMessage[]) {
	while (!(cin >> person->_age) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << kInvalidMessage;
	}
}

void CheckingForPositiveForPerson(PersonStr *person) {
	do {
		CheckingOfCorrectInputOfNumberForPerson(person, "������� �� �����! ��������� ����:");
		if (person->_age <= 0) {
			cout << "����� �� ������������� ������� (������ <= 0)! ��������� ����:";
		}
	} while (person->_age <= 0);
}

void CheckingOfCorrectInputOfNumberForPerson(PersonStr &person, const char kInvalidMessage[]) {
	while (!(cin >> person._age) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << kInvalidMessage;
	}
}

void CheckingForPositiveForPerson(PersonStr &person) {
	do {
		CheckingOfCorrectInputOfNumberForPerson(person, "������� �� �����! ��������� ����:");
		if (person._age <= 0) {
			cout << "����� �� ������������� ������� (������ <= 0)! ��������� ����:";
		}
	} while (person._age <= 0);
}
