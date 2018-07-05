#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <iomanip>
#include "num_enumeration.h"
#include "PersonalListItem.h"

using namespace std;

void CheckingOfCorrectInputOfNumberForPerson(Person &person, const char kInvalidMessage[]) {
	while (!(cin >> person.Age) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << kInvalidMessage;
	}
}

void CheckingForPositiveForPerson(Person *person) {
	do {
		CheckingOfCorrectInputOfNumberForPerson(*person, "Введено не число! Повторите ввод:");
		if (person->Age <= 0) {
			cout << "Число не соответствует условию (Индекс <= 0)! Повторите ввод:";
		}
	} while (person->Age <= 0);
}

bool CheckingText(char *string) {
	int i = 1;
	bool key = 1;
	if ((string[0] >= 65 && string[0] <= 90 ) || (string[0] >= -64 && string[0] <= -33)) {
		
	} else if (string[0] == 32 || string[0] == 45) {
		int j = 1;
		while (string[j] != '\0') {
			string[j - 1] = string[j];
			j++;
		}
		string[j - 1] = '\0';
	} else if (string[0] >= 97 && string[0] <= 122) {
		string[0] = (int)string[0] - 32;
	} else if (string[0] >= -32 && string[0] <= -1) {
		string[0] = (int)string[0] - 32;
	} else {
		key = 0;
		return key;
	}
	while (string[i] != '\0' && key == 1) {
		if ((string[i - 2] == 32) || (string[i - 2] == 45)) {
			if (string[i - 1] >= 65 && string[i - 1] <= 90 || string[i - 1] >= -64 && string[i - 1] <= -33) {

			}
			else if (string[i + 1] >= 97 && string[i + 1] <= 122) {
				string[i - 1] = (int)string[i - 1] - 32;
			}
			else if (string[i] >= -32 && string[i] <= -1) {
				string[i - 1] = (int)string[i - 1] - 32;
			}
			else {
				key = 0;
				return key;
			}
		}
		if (string[i] >= 97 && string[i] <= 122 || string[i] >= -32 && string[i] <= -1) {

		} else if (string[i] >= 65 && string[i] <= 90) {
			string[i] = (int)string[i] + 32;
		}  else if((string[i] == 32 && string[i-1] == 32) || (string[i] == 45 && string[i - 1] == 45)){
			int j = i;
			while (string[j] != '\0') {
				string[j - 1] = string[j];
				j++;
			}
			string[j - 1] = '\0';
		} else if (string[i] >= -64 && string[i] <= -33) {
			string[i] = (int)string[i] + 32;
		} else if (string[i] == 32 || string[i] == 45) {

		} else {
			key = 0;
			return key;
		}
		i++;
	}
	if (string[i - 1] == 32 || string[i - 1] == 45) {
		string[i - 1] = '\0';
	}
	return key;
}