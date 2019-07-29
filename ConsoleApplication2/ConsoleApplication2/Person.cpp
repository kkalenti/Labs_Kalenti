#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <string>
#include "Person.h"
#include "lab_five_functions.h"

using namespace std;

Person::Person(char* _name, char* _surname, Sex _sex, int age) {
	name_ = _name;
	surname_ = _surname;
	sex_ = _sex;
	age_ = age;
}

Person::Person(bool flag) {
	int sex_key = 1 + rand() % 2;
	if (sex_key == 1) {
		sex_ = Муж;
	}
	else {
		sex_ = Жен;
	}

	name_ = MakeName(this->GetSex());
	surname_ = MakeSurname(this->GetSex());

	age_ = 1 + rand() % 100;
}

string Person::GetInfo() {
	string info;
	info = GetName();
	info += " ";
	info += GetSurname();
	return info;
}

int Person::GetAge() {
	return age_;
}

void Person::SetAge(int age) {
	PersonPositiveCorrection(age);
	age_ = age;
}

char* Person::GetName() {
	return name_;
}

char* Person::GetSurname() {
	return surname_;
}

Sex Person::GetSex() {
	return sex_;
}

void Person::SetSex(Sex sex) {
	sex_ = sex;
}

void Person::Show() {
	cout << setw(20) << left << surname_ << setw(20) << left << name_
		<< setw(8) << left << "Возраст: " << setw(10) << left << age_
		<< setw(4) << left << "Пол:" << setw(10) << left;
	if (sex_ == Муж) {
		cout << "Мужской" << endl;
	}
	else {
		cout << "Женский" << endl;
	}
}

string Person::GetDiscription() {
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
		inform += "муж";
	}
	else {
		inform += "жен";
	}
	inform += "\0";
	return inform;
}