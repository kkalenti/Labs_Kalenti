#pragma once
#include "Person.h"

class Adult:public Person {
private:
	Adult* married_on;
	char* work_place;
public:
	Adult(char* name, char* surname, Sex sex, int age, Adult* marriedOn, char* workPlace);
	virtual std::string GetDiscription();
	static Adult* GetRandomPerson();
	static Adult* GetMarriedPerson(Adult* MarriedOn);
	void SetAge(int age);
	int GetAge();
	void SetMarriedOn(Adult* person);
	Adult* GetMarriedOn();
};