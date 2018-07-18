#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include "PersonList.h"
#include "num_enumeration.h"
#include "checking_input_for_person.h"
#include "PersonalListItem.h"
#include "class_functions.h"

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
		head_item->Person = *person;
		return;
	}
	PersonListItem* tail_item = new PersonListItem;
	PersonListItem* curent_item = _head;
	while (curent_item->next != nullptr) {
		curent_item = curent_item->next;
	}
	tail_item->Person = *person;
	tail_item->next = nullptr;
	tail_item->prev = curent_item;
	curent_item->next = tail_item;
	return;
}

void PersonList::Print() {
	PersonListItem* curent_item = _head;
	curent_item->Person.Show();
	while (curent_item->next != nullptr) {
		curent_item = curent_item->next;
		curent_item->Person.Show();
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
	return &(curent_item->Person);
}

int PersonList::IndexOf(Person* person) {
	PersonListItem* curent_item = _head;
	int count = 1;
	while (curent_item->next != nullptr && curent_item != nullptr){
		if (person->Age == curent_item->Person.Age && strcmp(person->Name,curent_item->Person.Name) == 0 &&
			strcmp(person->Surname,curent_item->Person.Surname) == 0 && person->Sex == curent_item->Person.Sex) {
			return count;
		}
		curent_item = curent_item->next;
		count++;
	}
	return 0;
}

void PersonList::Remove(Person* person) {
	//Не понимаю смысл действия
}

void PersonList::RemoveAt(int index) {
	if (index > _count) {
		cout << "Элемента с таким индексом не существует";
		return;
	}
	PersonListItem* curent_item = _head;
	for (int i = 1; i < index; i++) {
		curent_item = curent_item->next;
	}
	if (index == 1) {
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