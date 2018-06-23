#include "stdafx.h"
#include <iostream>
#include "person_list.h"
#include "structure.h"

using namespace std;

PersonListItem* AddToEndOfAPersonList(PersonListItem* person_list_head) {
	PersonListItem* person_list_tail = new PersonListItem;
	PersonListItem* curent_item = person_list_head;
	while (curent_item->next != nullptr) {
		curent_item = curent_item->next;
	}
	ReadPersonForLink(person_list_tail->Person);
	person_list_tail->next = nullptr;
	person_list_tail->prev = curent_item;
	curent_item->next = person_list_tail;
	return person_list_tail;
}

void DeleteElementOfAPersonList(PersonListItem* person_list_head, PersonListItem* person_list_tail, int number_of_element) {
	PersonListItem* curent_item = new PersonListItem;
	curent_item = person_list_head;
	for (int i = 1; i <= number_of_element; i++) {
		curent_item = curent_item->next;
	}
	if (curent_item == person_list_head) {
		curent_item->next->prev = nullptr;
		person_list_head = person_list_head->next;
	} else if (curent_item == person_list_tail) {
		curent_item->prev->next = nullptr;
		person_list_tail = person_list_tail->prev;
	} else {
		curent_item->prev->next = curent_item->next;
		curent_item->next->prev = curent_item->prev;
	}
	delete curent_item;
}

void PrintPersonList(PersonListItem* person_list_head) {
	PersonListItem* curent_item = person_list_head;
	PrintForLinkOfPerson(curent_item->Person);
	while (curent_item->next != nullptr) {
		curent_item = curent_item->next;
		PrintForLinkOfPerson(curent_item->Person);
	}
}