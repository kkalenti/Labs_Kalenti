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
		list->Add(i);
	}
	DoubleOutput(list);
	system("pause");
}

void lab7_2() {
	List<Person*>* list = new List<Person*>(nullptr);
	for (int i = 0; i < 5; i++) {
		list->Add(new Person(true));
	}
	PersonOutput(list);
	system("pause");
}

void lab7_3() {
	//List<double[5]>* list = new List<double[5]>(nullptr);
	//for (int i = 0; i < 5; i++) {
	//	double mass[5];
	//	for (int j = i; j < i + 5; j++) {
	//		mass[j] = j;
	//	}
	//	list->Add(mass);
	//}
	//DoubleFiveOutput(list);
	system("pause");
}

void lab7_4() {
	List<List<double>*>* list = new List<List<double>*>(nullptr);
	for (int i = 0; i < 5; i++) {
		List<double>* list1 = new List<double>(nullptr);
		for (int j = i; j < i + 5; j++) {
			list1->Add(j);
		}
		list->Add(list1);
	}
	ListOutput(list);
	system("pause");
}