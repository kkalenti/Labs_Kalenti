#include "stdafx.h"
#include <iostream>
#include <string>
#include "checking_input_for_person.h"
#include "person_structure.h"

using namespace std;

void PrintPerson(Person& person) {
	cout << person.firstname << "\t" << person.lastname << "\t" << "Возраст: " << person.age 
		<< "\t" << "Пол:" << person.sex << endl;
}

void ReadPerson(Person* person) {
	cout << "Введите имя:" << endl;
	cin.getline(person->lastname, 50);
	cout << "Введите фамилию:" << endl;
	cin.getline(person->firstname, 50);
	cout << "Введите пол (муж/жен):" << endl;
	cin.getline(person->sex, 5);
	cout << "Введите возраст:" << endl;
	CheckingForPositiveForPerson(person);
	
}
