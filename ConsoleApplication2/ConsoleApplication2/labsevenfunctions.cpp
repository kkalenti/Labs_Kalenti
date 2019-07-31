#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
#include "List.h"
#include "Person.h"
#include "labsevenfunctions.h"
#define ARRAY_SIZE 5

using namespace std;

//TODO: ����������� ������� ���������� ���������� �������, �.�. ����� ������ �� 5 ��������, ��������, ����� ���-�� ������������ �������
void DoubleOutput(List<double> *list) {
	cout << "������ double: ";
	for (int i = 0; i < list->GetCount(); i++) {
		cout << *list->Find(i) << ' ';
	}
	cout << endl;
}

void CreateDoubleList(List<double> *list, int size) {
	for (int i = 0; i < size; i++) {
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

void CreatePersonList(List<Person> *list, int size) {
	for (int i = 0; i < size; i++) {
		list->Add(new Person(true));
	}
}

void AddPersonElement(List<Person> *list) {
	list->AddTo(new Person(true), 4);
}

void DoubleArrayOutput(List<double*>* list) {
	cout << "������ Double*: ";
	for (int i = 0; i < list->GetCount(); i++) {
		double* mass = *list->Find(i);
		for (int j = 0; j < ARRAY_SIZE; j++) {
			cout << mass[j] << ' ';
		}
		cout << endl;
	}

	cout << endl;
}

void CreateDoubleArrayList(List<double*> *list, int size) {
	for (int i = 0; i < size; i++) {
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
	double** mass;
	mass = new double*[1];
	mass[0] = new double[ARRAY_SIZE];
	for (int j = 0; j < ARRAY_SIZE; j++) {
		mass[0][j] = j + 10;
	}
	list->AddTo(mass, 4);
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

void CreateDoubleListList(List<List<double>> *list, int size) {
	double *element;
	for (int i = 0; i < size; i++) {
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
	double *element;
	List<double> *list1 = new List<double>(nullptr);
	for (int j = 0; j < ARRAY_SIZE; j++) {
		element = new double;
		*element = j + 10;
		list1->Add(element);
	}
	list->AddTo(list1, 4);
}