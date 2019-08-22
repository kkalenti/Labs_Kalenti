#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
#include "List.h"
#include "Person.h"
#include "labsevenfunctions.h"

#define ARRAY_SIZE 5

using namespace std;

void DoubleOutput(List<double> *list) {
	cout << "Список double: ";
	for (auto i = 0; i < list->GetCount(); i++) {
		cout << *list->Find(i) << ' ';
	}
	cout << endl;
}

void CreateDoubleList(List<double> *list,const int size) {
	for (auto i = 0; i < size; i++) {
		list->Add(new double(i));
	}
}

void AddDoubleElement(List<double> *list,const int index) {
	list->AddTo(new double(10), index);
}

void PersonOutput(List<Person> *list) {
	cout << "Список Person: ";
	for (auto i = 0; i < list->GetCount(); i++) {
		auto person = list->Find(i);
		auto temp = person->GetDiscription();
		cout << temp << endl;
	}

	cout << endl;
}

void CreatePersonList(List<Person> *list, const int size) {
	for (auto i = 0; i < size; i++) {
		list->Add(new Person(true));
	}
}

void AddPersonElement(List<Person> *list, const int index) {
	list->AddTo(new Person(true), index);
}

void DoubleArrayOutput(List<double*>* list) {
	cout << "Список Double*: ";
	for (auto i = 0; i < list->GetCount(); i++) {
		const auto mass = *list->Find(i);
		for (auto j = 0; j < ARRAY_SIZE; j++) {
			cout << mass[j] << ' ';
		}
		cout << endl;
	}

	cout << endl;
}

void CreateDoubleArrayList(List<double*> *list, const int size) {
	for (auto i = 0; i < size; i++) {
		const auto mass = new double*[1];
		mass[0] = new double[size];
		for (auto j = i; j < i + size; j++) {
			mass[0][j-i] = j;
		}
		list->Add(mass);
	}
}

void AddDoubleArrayElement(List<double*> *list,const int index) {
	const auto mass = new double*[1];
	mass[0] = new double[ARRAY_SIZE];
	for (auto j = 0; j < ARRAY_SIZE; j++) {
		mass[0][j] = j + 10;
	}
	list->AddTo(mass, index);
}

void DoubleListOutput(List<List<double>> *list) {
	cout << "Список List<double>: " << endl;
	Person* person;
	for (auto i = 0; i < list->GetCount(); i++) {
		auto list1 = list->Find(i);
		for (auto j = 0; j < list1->GetCount(); j++) {
			cout << *list1->Find(j) << ' ';
		}
		cout << endl;
	}

	cout << endl;
}

void CreateDoubleListList(List<List<double>> *list, const int size) {
	for (auto i = 0; i < size; i++) {
		auto list1 = new List<double>(nullptr);
		for (auto j = i; j < i + size; j++) {
			list1->Add(new double(j));
		}
		list->Add(list1);
	}
}

void AddDoubleListElement(List<List<double>> *list, const int index) {
	auto list1 = new List<double>(nullptr);
	for (auto j = 0; j < ARRAY_SIZE; j++) {
		list1->Add(new double(10));
	}
	list->AddTo(list1, index);
}