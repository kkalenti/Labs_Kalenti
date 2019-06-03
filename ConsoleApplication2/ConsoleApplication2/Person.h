#pragma once
#include "sex_enumeration.h"

class Person {
protected: int _age;
public: Person();
		char name[50];
		char surname[50];
		int GetAge();
		void SetAge(int age);
		int age = _age;

		Sex sex;
		static Person* GetRandomPerson();
		Person* Read();
		void Show();
		virtual char* GetDiscription();
};