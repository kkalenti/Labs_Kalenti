#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <Windows.h>
#include "Person.h"
#include "lab_five_functions.h"
#include "num_enumeration.h"

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
	age = age;
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
	sex = sex;
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

void Person::PersonAgeCorrectionInput(int& age, const char kInvalidMessage[]) {
	while (!(cin >> age) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << kInvalidMessage;
	}
}

void Person::PersonPositiveCorrection(int& age) {
	//TODO: Корректнее будет сделать minAge и maxAge константами
	do {
		PersonAgeCorrectionInput(age, "Введено не число! Повторите ввод:");
		if (age <= kMinAge_ || age > kMaxAge_) {
			cout << "Число введено не верно! Повторите ввод:";
		}
	} while (age <= kMinAge_ || age > kMaxAge_);
}