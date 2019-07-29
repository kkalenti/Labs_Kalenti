#pragma once
#include "Person.h"
#include "Adult.h"
 
class Child :public Person {
private:
	Adult* mother_ = nullptr;
	Adult* father_ = nullptr;
	char* school_;
public:
	Child(char* name, char* surname, Sex sex, int age, Adult* mother, Adult* father, char* school);
	void SetMother(Adult* mother);
	Adult* GetMother();
	void SetFather(Adult* father);
	virtual std::string GetDiscription();
	static Child* GetRandomPerson();
	int GetAge();
	void SetAge(int age);
};