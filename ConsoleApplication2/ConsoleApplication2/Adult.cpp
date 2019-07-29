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
	//TODO: ׸ �� �������� �� �������� ��������? � ���� � ���� ���� �� ������ � 200 ��������? ��������� �� ��������!
	string inform;
	string temp;
	inform = surname_;
	inform += " ";
	inform += name_;
	inform += ", ";
	temp = to_string(GetAge());
	inform += temp;
	inform += " ���, ";
	if (sex_ == ���) {
		inform += "�������, ";
		if (married_on != NULL) {
			inform += "����� ��: ";
			inform += married_on->GetInfo();
		}
		else {
			inform += "������";
		}
	}
	else {
		inform += "�������, ";
		if (married_on != NULL) {
			inform += "������� ��: ";
			inform += married_on->GetInfo();
		}
		else {
			inform += "�������";
		}
	}
	inform += ", ������:";
	inform += work_place;
	return inform;
}

//TODO: ���� �����, ����� ���� � ����.
// ��� ����� �����?
Adult* Adult::GetRandomPerson() {
	Sex sex;
	int sex_key = 1 + rand() % 2;
	if (sex_key == 1) {
		sex = ���;
	}
	else {
		sex = ���;
	}

	int age = 18 + rand() % 70;

	char* work_place = CreateBusiness();

	return new Adult(MakeName(sex), MakeSurname(sex), sex, age, nullptr, work_place);
}

Adult* Adult::GetMarriedPerson(Adult* MarriedOn) {
	Sex sex;
	if (MarriedOn->sex_ == ���) {
		sex = ���;
	}
	else {
		sex = ���;
	}
	int age = 18 + rand() % 70;

	char* work_place = CreateBusiness();

	return new Adult(MakeName(sex), MakeSurname(sex), sex, age, MarriedOn, work_place);
}