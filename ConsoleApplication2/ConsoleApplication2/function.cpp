#include "stdafx.h"
#include <iostream>

using namespace std;

int CheckingTheLetter(int input,const char invalidMessage[]){
	while (!(cin >> input) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << invalidMessage;
	}
	return input;
}

int CheckingForArray(int input, const char invalidMessageForLetter[], const char invalidMessageForNumber[]) {
	do {
		input = CheckingTheLetter(input, invalidMessageForLetter);
		if (input <= 0)
			cout << "����� �� ������������� ������� (n<=0)\n������� ����� ��������:";
	} while (input <= 0);
	return input;
}