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
#include "lab_five_functions.h"

using namespace std;

PersonList::PersonList(PersonListItem* head) {
	_head = head;
	_count = 0;
}


void PersonList::Add(Person* person) {
	if (_head == nullptr) {
		PersonListItem* head_item = new PersonListItem;
		_head = head_item;
		head_item->next = nullptr;
		head_item->prev = nullptr;
		head_item->person = person;
		_count++;
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
	_count++;
	return;
}

void PersonList::Print() {
	PersonListItem* curent_item = _head;
	string temp;
	temp = curent_item->person->GetDiscription();
	cout << temp << endl;
	while (curent_item->next != nullptr) {
		curent_item = curent_item->next;
		temp = curent_item->person->GetDiscription();
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
	while (curent_item->next != nullptr && curent_item != nullptr) {
		if (person->GetAge() == curent_item->person->GetAge() &&
			strcmp(person->GetName(), curent_item->person->GetName()) == 0 &&
			strcmp(person->GetSurname(), curent_item->person->GetSurname()) == 0 &&
			person->GetSex() == curent_item->person->GetSex()) {
			return count;
		}
		curent_item = curent_item->next;
		count++;
	}
	return -1;
}

void PersonList::Remove(Person* person) {
	int index = IndexOf(person);
	RemoveAt(index);
}

void PersonList::RemoveAt(int index) {
	if (index > _count) {
		cout << "Элемента с таким индексом не существует";
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
		_count--;
		return;
	}
	if (index == _count) {
		curent_item->prev->next = nullptr;
		delete curent_item;
		_count--;
		return;
	}
	curent_item->prev->next = curent_item->next;
	curent_item->next->prev = curent_item->prev;
	delete curent_item;
	_count--;
	return;
}

void PersonList::Clear() {
	PersonListItem* curent_item = _head;
	PersonListItem* temp;
	while (curent_item->next != nullptr) {
		temp = curent_item;
		curent_item = curent_item->next;
		delete temp;
		_head = curent_item;
	}
	delete curent_item;
}
