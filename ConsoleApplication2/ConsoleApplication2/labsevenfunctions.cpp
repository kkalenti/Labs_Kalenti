#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
#include "List.h"
#include "Person.h"
#include "labsevenfunctions.h"
//TODO: Зачем, если можно передать в метод?
#define ARRAY_SIZE 5

using namespace std;

void DoubleOutput(List<double> *list) {
	cout << "Список double: ";
	for (int i = 0; i < list->GetCount(); i++) {
		cout << *list->Find(i) << ' ';
	}
	cout << endl;
}

//TODO Везде, где есть size правильнее его сделать const параметром
void CreateDoubleList(List<double> *list, int size) {
	//TODO: можно использовать auto вместо int и других инициализаций
	for (int i = 0; i < size; i++) {
		auto element = new double;
		*element = i;
		list->Add(element);
	}
}

void AddDoubleElement(List<double> *list) {
	//TODO auto
	double *element = new double;
	*element = 10;
	list->AddTo(element, 4);
}

void PersonOutput(List<Person> *list) {
	cout << "Список Person: ";
	//TODO: почему за for сделано?
	string temp;
	Person* person;
	//TODO auto
	for (int i = 0; i < list->GetCount(); i++) {
		person = list->Find(i);
		temp = person->GetDiscription();
		cout << temp << endl;
	}

	cout << endl;
}

//TODO Везде, где есть size правильнее его сделать const параметром
void CreatePersonList(List<Person> *list, int size) {
	//TODO auto
	for (int i = 0; i < size; i++) {
		list->Add(new Person(true));
	}
}

void AddPersonElement(List<Person> *list) {
	//TODO: 4 прибита гвоздями - не очень правильно!
	list->AddTo(new Person(true), 4);
}

void DoubleArrayOutput(List<double*>* list) {
	cout << "Список Double*: ";
	//TODO auto
	for (int i = 0; i < list->GetCount(); i++) {
		double* mass = *list->Find(i);
		for (int j = 0; j < ARRAY_SIZE; j++) {
			cout << mass[j] << ' ';
		}
		cout << endl;
	}

	cout << endl;
}

//TODO Везде, где есть size правильнее его сделать const параметром
void CreateDoubleArrayList(List<double*> *list, int size) {
	//TODO auto
	for (int i = 0; i < size; i++) {
		//TODO: Зачем разделил?
		double** mass;
		mass = new double*[1];
		mass[0] = new double[size];
		for (int j = i; j < i + size; j++) {
			mass[0][j-i] = j;
		}
		list->Add(mass);
	}
}

void AddDoubleArrayElement(List<double*> *list) {
	//TODO: Зачем разделил?
	double** mass;
	mass = new double*[1];
	mass[0] = new double[ARRAY_SIZE];
	//TODO auto
	for (int j = 0; j < ARRAY_SIZE; j++) {
		mass[0][j] = j + 10;
	}
	list->AddTo(mass, 4);
}

void DoubleListOutput(List<List<double>> *list) {
	cout << "Список List<double>: " << endl;
	Person* person;
	//TODO auto
	for (int i = 0; i < list->GetCount(); i++) {
		//TODO auto
		List<double>* list1 = list->Find(i);
		//TODO auto
		for (int j = 0; j < list1->GetCount(); j++) {
			cout << *list1->Find(j) << ' ';
		}
		cout << endl;
	}

	cout << endl;
}

//TODO Везде, где есть size правильнее его сделать const параметром
void CreateDoubleListList(List<List<double>> *list, int size) {
	//TODO: Зачем разделил?
	double *element;
	//TODO auto
	for (int i = 0; i < size; i++) {
		//TODO auto
		List<double> *list1 = new List<double>(nullptr);
		for (int j = i; j < i + size; j++) {
			element = new double;
			*element = j;
			list1->Add(element);
		}
		list->Add(list1);
	}
}

void AddDoubleListElement(List<List<double>> *list) {
	//TODO: Зачем разделил?
	double *element;
	//TODO auto
	List<double> *list1 = new List<double>(nullptr);
	//TODO auto
	for (int j = 0; j < ARRAY_SIZE; j++) {
		element = new double;
		*element = j + 10;
		list1->Add(element);
	}
	list->AddTo(list1, 4);
}