#pragma once
#include "sex_enumeration.h"

class Person {
	//TODO: ������������ ���� � �������.
	//TODO: ��� ���������� �����������?
	//TODO: GetRandomPerson ������� ���� static
protected: int _age;
		char name[50];
		char surname[50];
		Sex sex;
public: Person();
		Person(bool flag);
		int GetAge();
		void SetAge(int age);
		char* GetName();
		void SetName(char* _name);
		char* GetSurname();
		void SetSurname(char* _name);
		Sex GetSex();
		void SetSex(Sex _sex);

		static Person* GetRandomPerson();
		Person* Read();
		void Show();
		virtual char* GetDiscription();
};