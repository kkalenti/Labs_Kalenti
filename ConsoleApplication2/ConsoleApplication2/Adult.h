#pragma once
#include "Person.h"

class Adult:public Person {
private:
	Adult* married_on;
	char work_place[100];
public:
	char* GetDiscription() override;
	static Adult* GetRandomPerson();
	static Adult* GetRandomPerson(Adult* MarriedOn);
	void SetAge(int age);
	int GetAge();
	void SetMarriedOn(Adult* person);
	Adult* GetMarriedOn();
};