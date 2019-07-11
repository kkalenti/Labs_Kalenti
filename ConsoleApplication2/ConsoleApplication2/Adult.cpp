#include "stdafx.h"
#include <iostream>
#include "Person.h"
#include "Adult.h"
#include "lab_five_functions.h"

using namespace std;

//TODO: ������� ������, ��������
Adult::Adult(char* _name, char* _surname, Sex _sex, int age, Adult* _married_on, char* _work_place) : Person(_name, _surname, _sex, age) {
	married_on = _married_on;
	work_place = _work_place;
}

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
	//TODO: ׸ �� �������� �� �������� ��������? � ���� � ���� ���� �� ������ � 200 ��������? ��������� �� ��������!
	char inform[200];
	char temp[200];
	strcpy_s(inform, surname);
	strcat_s(inform, " ");
	strcat_s(inform, name);
	strcat_s(inform, ", ");
	sprintf_s(temp, "%d", GetAge());
	strcat_s(inform, temp);
	strcat_s(inform, " ���, ");
	if (sex == ���) {
		strcat_s(inform, "�������, ");
		if (married_on != NULL) {
			strcat_s(inform, "����� ��: ");
			strcat_s(inform, married_on->name);
			strcat_s(inform, " ");
			strcat_s(inform, married_on->surname);
		} else {
			strcat_s(inform, "������");
		}
	}
	else {
		strcat_s(inform, "�������, ");
		if (married_on != NULL) { 
			strcat_s(inform, "������� ��: ");
			strcat_s(inform, married_on->name);
			strcat_s(inform, " ");
			strcat_s(inform, married_on->surname);
		}
		else {
			strcat_s(inform, "�������");
		}
	}
	strcat_s(inform, ", ������:");
	strcat_s(inform, work_place);
	return inform;
}

//TODO: ���� �����, ����� ���� � ����.
Adult* Adult::GetRandomPerson() {
	Sex sex;
	int sex_key = 1 + rand() % 2;
	if (sex_key == 1) {
		sex = ���;
	}
	else {
		sex = ���;
	}
	//TODO: �������� ����������, ����� ���������� ��������� ���������� �� �����.
	int _age = 18 + rand() % 70;
	
	char* work_place = CreateBusiness();

	return new Adult(MakeName(sex), MakeSurname(sex), sex, _age, nullptr, work_place);
}

Adult* Adult::GetMarriedPerson(Adult* MarriedOn) {
	Sex sex;
	if (MarriedOn->sex == ���) {
		sex = ���;
	}
	else {
		sex = ���;
	}
	//TODO: �������� ����������, ����� ���������� ��������� ���������� �� �����.
	int _age = 18 + rand() % 70;

	char* work_place = CreateBusiness();

	return new Adult(MakeName(sex), MakeSurname(sex), sex, _age, MarriedOn, work_place);
}