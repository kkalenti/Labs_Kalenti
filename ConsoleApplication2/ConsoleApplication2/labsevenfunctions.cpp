#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "List.h"
#include "Person.h"
#include "labsevenfunctions.h"

using namespace std;

void DoubleOutput(List<double> *list) {
	cout << "Список double: ";
	for (int i = 0; i < list->GetCount(); i++) {
		cout << *list->Find(i) << ' ';
	}
}

void PersonOutput(List<Person*>* list) {
	cout << "Список Person: ";
	char temp[150];
	Person* person;
	for (int i = 0; i < list->GetCount(); i++) {
		person = *list->Find(i);
		strcpy_s(temp, person->GetDiscription());
		cout << temp << endl;
	}
}

//void DoubleFiveOutput(List<double[5]>* list) {
//	cout << "Список Double[5]: ";
//	for (int i = 0; i < list->GetCount(); i++) {
//		double* mass = *list->Find(i);
//		for (int j = 0; j < 5; j++) {
//			cout << mass[j] << ' ';
//		}
//		cout << endl;
//	}
//}

void ListOutput(List<List<double>*>* list) {
	cout << "Список List<double>: " << endl;
	Person* person;
	for (int i = 0; i < list->GetCount(); i++) {
		List<double>* list1 = *list->Find(i);
		for (int j = 0; j < list1->GetCount(); j++) {
			cout << *list1->Find(j) << ' ';
		}
		cout << endl;
	}
}