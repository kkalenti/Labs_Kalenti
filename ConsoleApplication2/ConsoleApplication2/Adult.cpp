#include "stdafx.h"
#include <iostream>
#include "Person.h"
#include "Adult.h"
#include "lab_five_functions.h"

using namespace std;

int Adult::GetAge() {
	return _age;
}

void Adult::SetAge(int age) {
	if (age >= 18) {
		_age = age;
	}
	else {
		_age = 18;
	}
}

void Adult::SetMarriedOn(Adult* person) {
	married_on = person;
}

Adult* Adult::GetMarriedOn() {
	return married_on;
}

char* Adult::GetDiscription() {
	char inform[200];
	char temp[200];
	strcpy_s(inform, surname);
	strcat_s(inform, " ");
	strcat_s(inform, name);
	strcat_s(inform, ", ");
	sprintf_s(temp, "%d", GetAge());
	strcat_s(inform, temp);
	strcat_s(inform, " лет, ");
	if (sex == Муж) {
		strcat_s(inform, "мужчина, ");
		if (married_on != NULL) {
			strcat_s(inform, "женат на: ");
			strcat_s(inform, married_on->name);
			strcat_s(inform, " ");
			strcat_s(inform, married_on->surname);
		} else {
			strcat_s(inform, "одинок");
		}
	}
	else {
		strcat_s(inform, "женщина, ");
		if (married_on != NULL) { 
			strcat_s(inform, "замужем за: ");
			strcat_s(inform, married_on->name);
			strcat_s(inform, " ");
			strcat_s(inform, married_on->surname);
		}
		else {
			strcat_s(inform, "одинока");
		}
	}
	strcat_s(inform, ", работа:");
	strcat_s(inform, work_place);
	return inform;
}

Adult* Adult::GetRandomPerson() {
	char temp[5];
	
	Adult* adult = new Adult();

	int sex_key = 1 + rand() % 2;
	if (sex_key == 1) {
		adult->sex = Муж;
	}
	else {
		adult->sex = Жен;
	}

	MakeName(adult);

	MakeSurname(adult);

	adult->_age = 18 + rand() % 100;

	adult->SetMarriedOn(Adult::GetRandomPerson(adult));
	
	temp[0] = 65 + rand() % 25;
	for (int i = 1; i < 5; i++) {
		temp[i] = 97 + rand() % 25;
	}
	strncpy_s(adult->work_place, temp, 5);
	return adult;
}

Adult* Adult::GetRandomPerson(Adult* MarriedOn) {
	char temp[5];

	Adult* adult = new Adult();

	if (MarriedOn->sex == Жен) {
		adult->sex = Муж;
	}
	else {
		adult->sex = Жен;
	}

	MakeName(adult);

	MakeSurname(adult);

	adult->_age = 18 + rand() % 70;

	adult->SetMarriedOn(MarriedOn);

	temp[0] = 65 + rand() % 25;
	for (int i = 1; i < 5; i++) {
		temp[i] = 97 + rand() % 25;
	}
	strncpy_s(adult->work_place, temp, 5);
	return adult;
}