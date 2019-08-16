#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
#include "List.h"
#include "Person.h"
#include "labsevenfunctions.h"
//TODO: Зачем, если можно передать в метод? done
#define ARRAY_SIZE 5

using namespace std;

void DoubleOutput(List<double> *list) {
	cout << "Список double: ";
	for (auto i = 0; i < list->GetCount(); i++) {
		cout << *list->Find(i) << ' ';
	}
	cout << endl;
}

//TODO Везде, где есть size правильнее его сделать const параметром done
void CreateDoubleList(List<double> *list,const int size) {
	//TODO: можно использовать auto вместо int и других инициализаций done
	for (auto i = 0; i < size; i++) {
		list->Add(new double(i));
	}
}

void AddDoubleElement(List<double> *list,const int index) {
	//TODO auto done
	list->AddTo(new double(10), index);
}

void PersonOutput(List<Person> *list) {
	cout << "Список Person: ";
	//TODO: почему за for сделано? done
	//TODO auto done
	for (auto i = 0; i < list->GetCount(); i++) {
		auto person = list->Find(i);
		auto temp = person->GetDiscription();
		cout << temp << endl;
	}

	cout << endl;
}

//TODO Везде, где есть size правильнее его сделать const параметром done
void CreatePersonList(List<Person> *list, const int size) {
	//TODO auto done
	for (auto i = 0; i < size; i++) {
		list->Add(new Person(true));
	}
}

void AddPersonElement(List<Person> *list, const int index) {
	//TODO: 4 прибита гвоздями - не очень правильно! done
	list->AddTo(new Person(true), index);
}

void DoubleArrayOutput(List<double*>* list) {
	cout << "Список Double*: ";
	//TODO auto done
	for (auto i = 0; i < list->GetCount(); i++) {
		const auto mass = *list->Find(i);
		for (auto j = 0; j < ARRAY_SIZE; j++) {
			cout << mass[j] << ' ';
		}
		cout << endl;
	}

	cout << endl;
}

//TODO Везде, где есть size правильнее его сделать const параметром done
void CreateDoubleArrayList(List<double*> *list, const int size) {
	//TODO auto done
	for (auto i = 0; i < size; i++) {
		//TODO: Зачем разделил? done
		const auto mass = new double*[1];
		mass[0] = new double[size];
		for (auto j = i; j < i + size; j++) {
			mass[0][j-i] = j;
		}
		list->Add(mass);
	}
}

void AddDoubleArrayElement(List<double*> *list,const int index) {
	//TODO: Зачем разделил? done
	const auto mass = new double*[1];
	mass[0] = new double[ARRAY_SIZE];
	//TODO auto
	for (auto j = 0; j < ARRAY_SIZE; j++) {
		mass[0][j] = j + 10;
	}
	list->AddTo(mass, index);
}

void DoubleListOutput(List<List<double>> *list) {
	cout << "Список List<double>: " << endl;
	Person* person;
	//TODO auto done
	for (auto i = 0; i < list->GetCount(); i++) {
		//TODO auto done
		auto list1 = list->Find(i);
		//TODO auto done 
		for (auto j = 0; j < list1->GetCount(); j++) {
			cout << *list1->Find(j) << ' ';
		}
		cout << endl;
	}

	cout << endl;
}

//TODO Везде, где есть size правильнее его сделать const параметром done
void CreateDoubleListList(List<List<double>> *list, const int size) {
	//TODO: Зачем разделил? done 
	//TODO auto done
	for (auto i = 0; i < size; i++) {
		//TODO auto done
		auto list1 = new List<double>(nullptr);
		for (auto j = i; j < i + size; j++) {
			list1->Add(new double(j));
		}
		list->Add(list1);
	}
}

void AddDoubleListElement(List<List<double>> *list, const int index) {
	//TODO: Зачем разделил? done 
	//TODO auto done 
	auto list1 = new List<double>(nullptr);
	//TODO auto done
	for (auto j = 0; j < ARRAY_SIZE; j++) {
		list1->Add(new double(10));
	}
	list->AddTo(list1, index);
}