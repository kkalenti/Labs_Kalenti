#include "stdafx.h"
#include <iostream>

using namespace std;

void CheckingOfCorrectInputOfNumber(int *input, const char invalidMessage[]) {
	while (!(cin >> *input) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << invalidMessage;
	}
}

void CheckingForPositive(int *input) {
	do {
		CheckingOfCorrectInputOfNumber(input, "������� �� �����! ��������� ����:");
		if (*input <= 0) {
			cout << "����� �� ������������� ������� (������ <= 0)! ��������� ����:";
		}
	} while (*input <= 0);
}

void CheckingForPositiveNumberAndNull(int *input) {
	do {
		CheckingOfCorrectInputOfNumber(input, "������� �� �����! ��������� ����:");
		if (*input < 0) {
			cout << "����� �� ������������� ������� (����� < 0)! ��������� ����:";
		}
	} while (*input < 0);
}