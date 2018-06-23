#include "stdafx.h"
#include <iostream>
#include "person_structure.h"

using namespace std;

void CheckingOfCorrectInputOfNumberForPerson(Person *person, const char kInvalidMessage[]) {
	while (!(cin >> person->age) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << kInvalidMessage;
	}
}

void CheckingForPositiveForPerson(Person *person) {
	do {
		CheckingOfCorrectInputOfNumberForPerson(person, "Введено не число! Повторите ввод:");
		if (person->age <= 0) {
			cout << "Число не соответствует условию (Индекс <= 0)! Повторите ввод:";
		}
	} while (person->age <= 0);
}

void CheckingOfCorrectInputOfNumberForPerson(Person &person, const char kInvalidMessage[]) {
	while (!(cin >> person.age) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << kInvalidMessage;
	}
}

void CheckingForPositiveForPerson(Person &person) {
	do {
		CheckingOfCorrectInputOfNumberForPerson(person, "Введено не число! Повторите ввод:");
		if (person.age <= 0) {
			cout << "Число не соответствует условию (Индекс <= 0)! Повторите ввод:";
		}
	} while (person.age <= 0);
}
