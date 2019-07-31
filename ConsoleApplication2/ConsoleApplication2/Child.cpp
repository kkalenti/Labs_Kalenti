#include "stdafx.h"
#include <iostream>
#include <string>
#include "Person.h"
#include "Child.h"
#include "Adult.h"
#include "lab_five_functions.h"

using namespace std;

Child::Child(char* name, char* surname, Sex sex,
	int age, Adult* mother, Adult* father, char* school)
	: Person(name, surname, sex, age) {
	mother_ = mother;
	father_ = father;
	school_ = school;
}

int Child::GetAge() {
	return age_;
}

void Child::SetAge(int age) {
	if (age < 18 && age > 0) {
		age = age;
	}
	else if (age < 1) {
		age = 1;
	}
	else {
		age = 17;
	}
}

void Child::SetMother(Adult* mother) {
	mother_ = mother;
}

Adult* Child::GetMother() {
	return mother_;
}

void Child::SetFather(Adult* father) {
	father_ = father;
}

string Child::GetDiscription() {

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
	}
	else {
		inform += "женщина, ";
	}
	if (mother_ != nullptr && father_ != nullptr) {
		inform += "Родители: ";
		inform += mother_->GetInfo();
		inform += " и ";
		inform += father_->GetInfo();
	}
	else if (mother_ == nullptr && father_ != nullptr) {
		inform += "Отец";
		inform += father_->GetInfo();
	}
	else if (mother_ != nullptr && father_ == nullptr) {
		inform += "Мать";
		inform += mother_->GetInfo();
	}
	else {
		inform += "нет родителей";
	}
	inform += ", ";
	inform += "учится в: ";
	inform += school_;
	return inform;
}

Child* Child::GetRandomPerson() {
	Sex sex;
	int sex_key = 1 + rand() % 2;
	if (sex_key == 1) {
		sex = Муж;
	}
	else {
		sex = Жен;
	}

	int _age = 1 + rand() % 17;

	char* school = CreateBusiness();

	return new Child(MakeName(sex), MakeSurname(sex), sex, _age, nullptr, nullptr, school);
}