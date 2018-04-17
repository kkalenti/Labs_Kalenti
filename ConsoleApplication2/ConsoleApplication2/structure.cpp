#include "stdafx.h"
#include <iostream>
#include "checking_input_for_person.h"
#include "person_structure.h"

using namespace std;

void PrintPerson(Person& person) {
	cout << person.firstname << "\t" << person.lastname << "\t" <<
		person.age << "\t" << person.sex << endl;
}

void ReadPerson(Person* person) {
	cout << "¬ведите им€:" << endl;
	cin >> person->lastname;
	cout << "¬ведите фамилию:" << endl;
	cin >> person->firstname;
	cout << "¬ведите возраст:" << endl;
	CheckingForPositiveForPerson(person);
	cout << "¬ведите пол (муж/жен):" << endl;
	cin >> person->sex;
}
