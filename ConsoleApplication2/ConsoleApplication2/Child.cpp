#include "stdafx.h"
#include <iostream>
#include "Person.h"
#include "Child.h"
#include "Adult.h"
#include "lab_five_functions.h"

using namespace std;

Child::Child(char* _name, char* _surname, Sex _sex, int age, Adult* mother, Adult* father, char* school) : Person(_name, _surname, _sex, age) {
	mother_ = mother;
	father_ = father;
	school_ = school;
}

int Child::GetAge() {
	return _age;
}

void Child::SetAge(int age) {
	if (age < 18 && age > 0) {
		_age = age;
	}
	else if (age < 1) {
		_age = 1;
	}
	else {
		_age = 17;
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

char* Child::GetDiscription() {
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
	}
	else {
		strcat_s(inform, "женщина, ");
	}
	if (mother_ != nullptr && father_ != nullptr) { //TODO: Спросить здесь
		strcat_s(inform, "Родители: ");
		strcat_s(inform, mother_->GetSurname());
		strcat_s(inform, " ");
		strcat_s(inform, mother_->GetName());
		strcat_s(inform, " и ");
		strcat_s(inform, father_->GetSurname());
		strcat_s(inform, " ");
		strcat_s(inform, father_->GetName());
	}
	else if (mother_ == nullptr && father_ != nullptr) {
		strcat_s(inform, "Отец");
		strcat_s(inform, father_->GetSurname());
		strcat_s(inform, " ");
		strcat_s(inform, father_->GetName());
	}
	else if (mother_ != nullptr && father_ == nullptr) {
		strcat_s(inform, "Мать");
		strcat_s(inform, mother_->GetSurname());
		strcat_s(inform, " ");
		strcat_s(inform, mother_->GetName());
	} else {
		strcat_s(inform, "нет родителей");
	}
	strcat_s(inform, ", ");
	strcat_s(inform, "учится в: ");
	strcat_s(inform, school_);
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