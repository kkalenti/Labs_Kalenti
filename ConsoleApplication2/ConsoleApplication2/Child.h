#pragma once
#include "Person.h"
#include "Adult.h"
 
class Child:public Person{
private:
	Adult* mother_ = nullptr;
	Adult* father_ = nullptr;
	char* school_;
public:
	Child(char* _name, char* _surname, Sex _sex, int age, Adult* mother, Adult* father, char* school);
	void SetMother(Adult* mother);
	Adult* GetMother();
	void SetFather(Adult* father);
	char* GetDiscription() override;
	static Child* GetRandomPerson();
	int GetAge();
	void SetAge(int age);
};