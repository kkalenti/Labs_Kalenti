#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include "PersonList.h"
#include "Child.h"
#include "Adult.h"
#include "num_enumeration.h"
#include "checking_input_for_person.h"
#include "PersonalListItem.h"
#include "lab_five_functions.h"

using namespace std;

PersonList::PersonList(PersonListItem* head, int count) {
	_head = head;
	_count = count;
}

void PersonList::Add(Person* person) {
	if (_head == nullptr) {
		PersonListItem* head_item = new PersonListItem;
		_head = head_item;
		head_item->next = nullptr;
		head_item->prev = nullptr;
		head_item->person = person;
		return;
	}
	PersonListItem* tail_item = new PersonListItem;
	PersonListItem* curent_item = _head;
	while (curent_item->next != nullptr) {
		curent_item = curent_item->next;
	}
	tail_item->person = person;
	tail_item->next = nullptr;
	tail_item->prev = curent_item;
	curent_item->next = tail_item;
	return;
}

void PersonList::Print() {
	PersonListItem* curent_item = _head;
	char temp[100];
	strcpy_s(temp,curent_item->person->GetDiscription());
	cout << temp << endl;
	while (curent_item->next != nullptr) {
		curent_item = curent_item->next;
		strcpy_s(temp,curent_item->person->GetDiscription());
		cout << temp << endl;
	}
}

Person* PersonList::Find(int index) {
	PersonListItem* curent_item = _head;
	if (_count < index) {
		return nullptr;
	}
	int count = 1;
	while (count != index && (curent_item->next != nullptr || curent_item != nullptr)) {
		curent_item = curent_item->next;
		count++;
	}
	return (curent_item->person);
}

int PersonList::IndexOf(Person* person) {
	PersonListItem* curent_item = _head;
	int count = 1;
	while (curent_item->next != nullptr && curent_item != nullptr){
		if (person->age == curent_item->person->age && strcmp(person->name,curent_item->person->name) == 0 &&
			strcmp(person->surname,curent_item->person->surname) == 0 && person->sex == curent_item->person->sex) {
			return count;
		}
		curent_item = curent_item->next;
		count++;
	}
	return 0;
}

void PersonList::Remove(Person* person) {
	int index = IndexOf(person);
	//TODO:я по индексу ищу персону в след. функции надо сделать то же самое?
}

void PersonList::RemoveAt(int index) {
	if (index > _count) {
		cout << "Ёлемента с таким индексом не существует";
		return;
	}
	PersonListItem* curent_item = _head;
	for (int i = 0; i < index; i++) {
		curent_item = curent_item->next;
	}
	if (index == 0) {
		curent_item->next->prev = nullptr;
		_head = curent_item->next;
		delete curent_item;
		return;
	}
	if (index == _count) {
		curent_item->prev->next = nullptr;
		delete curent_item;
		return;
	}
	curent_item->prev->next = curent_item->next;
	curent_item->next->prev = curent_item->prev;
	delete curent_item;
	return;
}

void PersonList::Clear() {
	PersonListItem* curent_item = _head;
	PersonListItem* temp;
	while(curent_item->next != nullptr) {
		temp = curent_item;
		curent_item = curent_item->next;
		delete temp;
		_head = curent_item;
	}
	delete curent_item;
}

int PersonList::GetCount() {
	PersonListItem* curent_item = _head;
	int count = 0;
	while (curent_item->next != nullptr) {
		curent_item = curent_item->next;
		count++;
	}
	count++;
	return count;
}