#pragma once
#include "sex_enumeration.h"

class Person {
	//TODO: ������������ ���� � �������.
	//TODO: ��� ���������� �����������?
	//TODO: GetRandomPerson ������� ���� static
public: char Name[50];
		char Surname[50];
		int Age;
		Sex Sex;
		Person* GetRandomPerson();
		Person* Read();
		void Show();
		Person();
};