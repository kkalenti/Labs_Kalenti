#pragma once
#include "Person.h"
#include "Adult.h"
 
class Child:public Person{
private:
	Adult* mother_ = nullptr;
	Adult* father_ = nullptr;
	char school[100];
public:
	void SetMother(Adult* mother);
	Person* GetMother();
	void SetFather(Adult* father);
	char* GetDiscription() override;
	static Child* GetRandomPerson();
	int GetAge();
	void SetAge(int age);
};