#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "List.h"
#include "Person.h"
#include "labsevenfunctions.h"

using namespace std;

void lab7_1 () {
	List<double> *list = new List<double>(nullptr);
	for (int i = 0; i < 5; i++) {
		double *element = new double;
		*element = i;
		list->Add(element);
	}
	DoubleOutput(list);

	list->RemoveAt(2);
	DoubleOutput(list);

	double *element = new double;
	*element = 10;
	list->AddTo(element,4);
	DoubleOutput(list);

	delete list;//где что € не удал€ю?
	system("pause");
}

void lab7_2() {
	List<Person> *list = new List<Person>(nullptr);
	for (int i = 0; i < 5; i++) {
		list->Add(new Person(true));
	}
	PersonOutput(list);

	list->RemoveAt(2);
	PersonOutput(list);

	list->AddTo(new Person(true), 4);
	PersonOutput(list);

	delete list;
	system("pause");
}

void lab7_3() {
	List<double[5]> *list = new List<double[5]>(nullptr);
	for (int i = 0; i < 5; i++) {
		double mass[5];
		for (int j = i; j < i + 5; j++) {
			mass[j-i] = j;
		}
		list->Add(&mass);
	}
	DoubleFiveOutput(list);

	list->RemoveAt(2);
	DoubleFiveOutput(list);

	double mass[5];
	for (int j = 0; j < 5; j++) {
		mass[j] = j+10;
	}
	list->AddTo(&mass, 4);
	DoubleFiveOutput(list);

	system("pause");
}

void lab7_4() {
	double *element;
	List<List<double>> *list = new List<List<double>>(nullptr);
	for (int i = 0; i < 5; i++) {
		List<double> *list1 = new List<double>(nullptr);
		for (int j = i; j < i + 5; j++) {
			element = new double;
			*element = j;
			list1->Add(element);
		}
		list->Add(list1);
	}
	ListOutput(list);

	list->RemoveAt(2);
	ListOutput(list);

	List<double> *list1 = new List<double>(nullptr);
	for (int j = 0; j < 5; j++) {
		element = new double;
		*element = j+10;
		list1->Add(element);
	}
	list->AddTo(list1, 4);
	ListOutput(list);

	delete list;
	system("pause");
}