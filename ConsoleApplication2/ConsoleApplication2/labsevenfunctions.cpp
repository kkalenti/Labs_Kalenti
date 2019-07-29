#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
#include "List.h"
#include "Person.h"
#include "labsevenfunctions.h"

using namespace std;

void DoubleOutput(List<double> *list) {
	cout << "������ double: ";
	for (int i = 0; i < list->GetCount(); i++) {
		cout << *list->Find(i) << ' ';
	}
	cout << endl;
}

void PersonOutput(List<Person> *list) {
	cout << "������ Person: ";
	string temp;
	Person* person;
	for (int i = 0; i < list->GetCount(); i++) {
		person = list->Find(i);
		temp = person->GetDiscription();
		cout << temp << endl;
	}

	cout << endl;
}

void DoubleFiveOutput(List<double[5]>* list) {
	cout << "������ Double[5]: ";
	for (int i = 0; i < list->GetCount(); i++) {
		double* mass = *list->Find(i);
		for (int j = 0; j < 5; j++) {
			cout << mass[j] << ' ';
		}
		cout << endl;
	}

	cout << endl;
}

void ListOutput(List<List<double>> *list) {
	cout << "������ List<double>: " << endl;
	Person* person;
	for (int i = 0; i < list->GetCount(); i++) {
		List<double>* list1 = list->Find(i);
		for (int j = 0; j < list1->GetCount(); j++) {
			cout << *list1->Find(j) << ' ';
		}
		cout << endl;
	}

	cout << endl;
}