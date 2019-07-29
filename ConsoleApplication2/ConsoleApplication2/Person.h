#pragma once
#include "sex_enumeration.h"

class Person {
protected: int age_;
		   char *name_;
		   char *surname_;
		   Sex sex_;
public:
		Person(char* name, char* surname, Sex sex, int age);
		Person(bool flag);
		std::string GetInfo();
		int GetAge();
		void SetAge(int age);
		char* GetName();
		char* GetSurname();
		Sex GetSex();
		void SetSex(Sex _sex);
		void Show();
		virtual std::string GetDiscription();
};