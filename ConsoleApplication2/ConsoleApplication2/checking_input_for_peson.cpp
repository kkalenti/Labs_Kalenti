#include "stdafx.h"
#include <iostream>
#include "person_structure.h"

using namespace std;

void CheckingOfCorrectInputOfNumberForPerson(PersonStr *person, const char kInvalidMessage[]) {
	while (!(cin >> person->age) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << kInvalidMessage;
	}
}

void CheckingForPositiveForPerson(PersonStr *person) {
	do {
		CheckingOfCorrectInputOfNumberForPerson(person, "Введено не число! Повторите ввод:");
		if (person->age <= 0) {
			cout << "Число не соответствует условию (Индекс <= 0)! Повторите ввод:";
		}
	} while (person->age <= 0);
}

void CheckingOfCorrectInputOfNumberForPerson(PersonStr &person, const char kInvalidMessage[]) {
	while (!(cin >> person.age) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << kInvalidMessage;
	}
}

void CheckingForPositiveForPerson(PersonStr &person) {
	do {
		CheckingOfCorrectInputOfNumberForPerson(person, "Введено не число! Повторите ввод:");
		if (person.age <= 0) {
			cout << "Число не соответствует условию (Индекс <= 0)! Повторите ввод:";
		}
	} while (person.age <= 0);
}
