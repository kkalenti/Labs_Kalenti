#include "stdafx.h"
#include <iostream>
#include "person_structure.h"

using namespace std;

void CheckingOfCorrectInputOfNumberForPerson(Person *input, const char kInvalidMessage[]) {
	while (!(cin >> input->age) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << kInvalidMessage;
	}
}

void CheckingForPositiveForPerson(Person *input) {
	do {
		CheckingOfCorrectInputOfNumberForPerson(input, "������� �� �����! ��������� ����:");
		if (input->age <= 0) {
			cout << "����� �� ������������� ������� (������ <= 0)! ��������� ����:";
		}
	} while (input->age <= 0);
}
