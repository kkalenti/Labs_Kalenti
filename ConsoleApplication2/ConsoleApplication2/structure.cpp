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
	cout << "������� ���:" << endl;
	cin >> person->lastname;
	cout << "������� �������:" << endl;
	cin >> person->firstname;
	cout << "������� �������:" << endl;
	CheckingForPositiveForPerson(person);
	cout << "������� ��� (���/���):" << endl;
	cin >> person->sex;
}
