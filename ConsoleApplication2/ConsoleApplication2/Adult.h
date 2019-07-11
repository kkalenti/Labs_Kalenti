#pragma once
#include "Person.h"

class Adult:public Person {
private:
	Adult* married_on;
	char* work_place;
public:
	//TODO: Почему входные параметры с нижним подчёркиванием?
	Adult(char* _name, char* _surname, Sex _sex, int age, Adult* married_on, char* work_place);
	char* GetDiscription() override;
	static Adult* GetRandomPerson();
	static Adult* GetMarriedPerson(Adult* MarriedOn);
	void SetAge(int age);
	int GetAge();
	void SetMarriedOn(Adult* person);
	Adult* GetMarriedOn();
};