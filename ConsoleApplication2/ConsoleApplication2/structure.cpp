#include "stdafx.h"
#include <iostream>
#include <string>
#include "checking_input_for_person.h"
#include "person_structure.h"

using namespace std;

void PrintPerson(Person& person) {
	cout << person.firstname << "\t" << person.lastname << "\t" << "�������: " << person.age 
		<< "\t" << "���:" << person.sex << endl;
}

void ReadPerson(Person* person) {
	cout << "������� ���:" << endl;
	cin.getline(person->lastname, 50);
	cout << "������� �������:" << endl;
	cin.getline(person->firstname, 50);
	cout << "������� ��� (���/���):" << endl;
	cin.getline(person->sex, 5);
	cout << "������� �������:" << endl;
	CheckingForPositiveForPerson(person);
	
}
