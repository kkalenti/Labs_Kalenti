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
		CheckingOfCorrectInputOfNumberForPerson(input, "Введено не число! Повторите ввод:");
		if (input->age <= 0) {
			cout << "Число не соответствует условию (Индекс <= 0)! Повторите ввод:";
		}
	} while (input->age <= 0);
}
