#pragma once
#include "sex_enumeration.h"

class Person {
protected: int _age;
		   //TODO: должны быть динамические строки, а не предзаданные
		char *name;
		char *surname;
		Sex sex;
public:
		Person(char* name, char* surname, Sex sex, int age);
		Person(bool flag);
		int GetAge();
		void SetAge(int age);
		char* GetName();
		char* GetSurname();
		Sex GetSex();
		void SetSex(Sex _sex);
		static Person* GetRandomPerson();
		//Person* Read();
		void Show();
		virtual char* GetDiscription();
};