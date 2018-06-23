#include "stdafx.h"
#include <iostream>

using namespace std;

void CheckingOfCorrectInputOfNumber(int *input, const char kInvalidMessage[]) {
	while (!(cin >> *input) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << kInvalidMessage;
	}
}

void CheckingForPositive(int *input) {
	do {
		CheckingOfCorrectInputOfNumber(input, "Введено не число! Повторите ввод:");
		if (*input <= 0) {
			cout << "Число не соответствует условию (Индекс <= 0)! Повторите ввод:";
		}
	} while (*input <= 0);
}

void CheckingForPositiveNumberAndNull(int *input) {
	do {
		CheckingOfCorrectInputOfNumber(input, "Введено не число! Повторите ввод:");
		if (*input < 0) {
			cout << "Число не соответствует условию (Число < 0)! Повторите ввод:";
		}
	} while (*input < 0);
}