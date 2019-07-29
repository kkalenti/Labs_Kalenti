#include "stdafx.h"
#include <iostream>
#include <string>
#include "Person.h"
#include "Adult.h"
#include "lab_five_functions.h"

using namespace std;

Adult::Adult(char* name, char* surname, Sex sex,
	int age, Adult* marriedOn, char* workPlace)
	: Person(name, surname, sex, age) {
	married_on = marriedOn;
	work_place = workPlace;
}

int Adult::GetAge() {
	return age_;
}

void Adult::SetAge(int age) {
	if (age >= 18) {
		age = age;
	}
	else {
		age = 18;
	}
}

void Adult::SetMarriedOn(Adult* person) {
	married_on = person;
}

Adult* Adult::GetMarriedOn() {
	return married_on;
}

string Adult::GetDiscription() {
	//TODO: Чё за привычка со статикой работать? А если у тебя инфа не влезет в 200 символов? Переделай на динамику!
	string inform;
	string temp;
	inform = surname_;
	inform += " ";
	inform += name_;
	inform += ", ";
	temp = to_string(GetAge());
	inform += temp;
	inform += " лет, ";
	if (sex_ == Муж) {
		inform += "мужчина, ";
		if (married_on != NULL) {
			inform += "женат на: ";
			inform += married_on->GetInfo();
		}
		else {
			inform += "одинок";
		}
	}
	else {
		inform += "женщина, ";
		if (married_on != NULL) {
			inform += "замужем за: ";
			inform += married_on->GetInfo();
		}
		else {
			inform += "одинока";
		}
	}
	inform += ", работа:";
	inform += work_place;
	return inform;
}

//TODO: Ниже дубль, почти один в один.
// Как здесь лучше?
Adult* Adult::GetRandomPerson() {
	Sex sex;
	int sex_key = 1 + rand() % 2;
	if (sex_key == 1) {
		sex = Муж;
	}
	else {
		sex = Жен;
	}

	int age = 18 + rand() % 70;

	char* work_place = CreateBusiness();

	return new Adult(MakeName(sex), MakeSurname(sex), sex, age, nullptr, work_place);
}

Adult* Adult::GetMarriedPerson(Adult* MarriedOn) {
	Sex sex;
	if (MarriedOn->sex_ == Жен) {
		sex = Муж;
	}
	else {
		sex = Жен;
	}
	int age = 18 + rand() % 70;

	char* work_place = CreateBusiness();

	return new Adult(MakeName(sex), MakeSurname(sex), sex, age, MarriedOn, work_place);
}