#include "stdafx.h"
#include <iostream>
#include "Person.h"
#include "Child.h"
#include "Adult.h"
#include "lab_five_functions.h"

using namespace std;

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

Person* Child::GetMother() {
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
	if (mother_ != nullptr && father_ != nullptr) {
		strcat_s(inform, "Родители: ");
		strcat_s(inform, mother_->surname);
		strcat_s(inform, " ");
		strcat_s(inform, mother_->name);
		strcat_s(inform, " и ");
		strcat_s(inform, father_->surname);
		strcat_s(inform, " ");
		strcat_s(inform, father_->name);
	}
	else if (mother_ == nullptr && father_ != nullptr) {
		strcat_s(inform, "Отец");
		strcat_s(inform, father_->surname);
		strcat_s(inform, " ");
		strcat_s(inform, father_->name);
	}
	else if (mother_ != nullptr && father_ == nullptr) {
		strcat_s(inform, "Мать");
		strcat_s(inform, mother_->surname);
		strcat_s(inform, " ");
		strcat_s(inform, mother_->name);
	} else {
		strcat_s(inform, "нет родителей");
	}
	strcat_s(inform, ", ");
	strcat_s(inform, "учится в: ");
	strcat_s(inform, school);
	return inform;
}

Child* Child::GetRandomPerson() {
	char temp[5];
	Child* child = new Child;

	int sex_key = 1 + rand() % 2;
	if (sex_key == 1) {
		child->sex = Муж;
	}
	else {
		child->sex = Жен;
	}

	MakeName(child);

	MakeSurname(child);

	child->_age = 1 + rand() % 17;

	
	child->SetMother(Adult::GetRandomPerson());
	if (child->mother_->sex == Жен) {
		child->SetFather(child->mother_->GetMarriedOn());
	} else {
		child->SetFather(child->mother_);
		child->SetMother(child->father_->GetMarriedOn());
	}


	for (int i = 0; i < 5; i++) {
		temp[i] = 97 + rand() % 25;
	}
	strncpy_s(child->school, temp, 5);
	return child;
}

/*Adult* Adult::GetRandomPerson() {
	char temp[5];
	temp[0] = 65 + rand() % 25;
	for (int i = 1; i < 5; i++) {
		temp[i] = 97 + rand() % 25;
	}
	Adult* adult = new Adult();
	strncpy_s(adult->name, temp, 5);

	temp[0] = 65 + rand() % 25;
	for (int i = 1; i < 5; i++) {
		temp[i] = 97 + rand() % 25;
	}
	strncpy_s(adult->surname, temp, 5);

	adult->sex = Жен;

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
	temp[0] = 65 + rand() % 25;
	for (int i = 1; i < 5; i++) {
		temp[i] = 97 + rand() % 25;
	}
	Adult* adult = new Adult();
	strncpy_s(adult->name, temp, 5);

	temp[0] = 65 + rand() % 25;
	for (int i = 1; i < 5; i++) {
		temp[i] = 97 + rand() % 25;
	}
	strncpy_s(adult->surname, temp, 5);

	adult->sex = Муж;

	adult->_age = 18 + rand() % 100;

	adult->SetMarriedOn(MarriedOn);

	temp[0] = 65 + rand() % 25;
	for (int i = 1; i < 5; i++) {
		temp[i] = 97 + rand() % 25;
	}
	strncpy_s(adult->work_place, temp, 5);
	return adult;
}*/