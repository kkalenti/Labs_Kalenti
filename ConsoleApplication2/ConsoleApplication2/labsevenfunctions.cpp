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

void DoubleCreateList(List<double> *list) {
	for (int i = 0; i < 5; i++) {
		double *element = new double;
		*element = i;
		list->Add(element);
	}
}

void AddDoubleElement(List<double> *list) {
	double *element = new double;
	*element = 10;
	list->AddTo(element, 4);
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

void PersonCreateList(List<Person> *list) {
	for (int i = 0; i < 5; i++) {
		list->Add(new Person(true));
	}
}

void AddPersonElement(List<Person> *list) {
	list->AddTo(new Person(true), 4);
}

void DoubleArrayOutput(List<double[5]>* list) {
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

void DoubleArrayCreateList(List<double[5]> *list) {
	for (int i = 0; i < 5; i++) {
		double mass[5];
		for (int j = i; j < i + 5; j++) {
			mass[j - i] = j;
		}
		list->Add(&mass);
	}
}

void AddDoubleArrayElement(List<double[5]> *list) {
	double mass[5];
	for (int j = 0; j < 5; j++) {
		mass[j] = j + 10;
	}
	list->AddTo(&mass, 4);
}

void DoubleListOutput(List<List<double>> *list) {
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

void DoubleListCreateList(List<List<double>> *list) {
	double *element;
	for (int i = 0; i < 5; i++) {
		List<double> *list1 = new List<double>(nullptr);
		for (int j = i; j < i + 5; j++) {
			element = new double;
			*element = j;
			list1->Add(element);
		}
		list->Add(list1);
	}
}

void AddDoubleListElement(List<List<double>> *list) {
	double *element;
	List<double> *list1 = new List<double>(nullptr);
	for (int j = 0; j < 5; j++) {
		element = new double;
		*element = j + 10;
		list1->Add(element);
	}
	list->AddTo(list1, 4);
}