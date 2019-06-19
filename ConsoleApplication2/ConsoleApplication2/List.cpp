#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "List.h"

using namespace std;

template <typename T>
template <typename T>
List<T>::List(ListItem<T>* head) {
List<T>::List(ListItem<T>* head) {
	_head = head;
	_head = head;
	_count = 0;
	_count = 0;
}
}


template <typename T>
template <typename T>
void List<T>::Add(T element) {
void List<T>::Add(T element) {
	if (_head == nullptr) {
	if (_head == nullptr) {
		ListItem<T>* head_item = new ListItem<T>;
		ListItem<T>* head_item = new ListItem<T>;
		_head = head_item;
		_head = head_item;
		head_item->next = nullptr;
		head_item->next = nullptr;
		head_item->prev = nullptr;
		head_item->prev = nullptr;
		head_item->element = element;
		head_item->element = element;
		_count++;
		_count++;
		return;
		return;
	}
	}
	ListItem<T>* tail_item = new ListItem<T>;
	ListItem<T>* tail_item = new ListItem<T>;
	ListItem<T>* curent_item = _head;
	ListItem<T>* curent_item = _head;
	while (curent_item->next != nullptr) {
	while (curent_item->next != nullptr) {
		curent_item = curent_item->next;
		curent_item = curent_item->next;
	}
	}
	tail_item->element = element;
	tail_item->element = element;
	tail_item->next = nullptr;
	tail_item->next = nullptr;
	tail_item->prev = curent_item;
	tail_item->prev = curent_item;
	curent_item->next = tail_item;
	curent_item->next = tail_item;
	_count++;
	_count++;
	return;
	return;
}
}


template <typename T>
template <typename T>
T* List<T>::Find(int index) {
T* List<T>::Find(int index) {
	ListItem<T>* curent_item = _head;
	ListItem<T>* curent_item = _head;
	if (_count < index) {
	if (_count < index) {
		return nullptr;
		return nullptr;
	}
	}
	int count = 1;
	int count = 1;
	while (count != index && (curent_item->next != nullptr || curent_item != nullptr)) {
	while (count != index && (curent_item->next != nullptr || curent_item != nullptr)) {
		curent_item = curent_item->next;
		curent_item = curent_item->next;
		count++;
		count++;
	}
	}
	return (curent_item->element);
	return (curent_item->element);
}
}


template <typename T>
template <typename T>
void List<T>::RemoveAt(int index) {
void List<T>::RemoveAt(int index) {
	if (index > _count) {
	if (index > _count) {
		cout << "Элемента с таким индексом не существует";
		cout << "Элемента с таким индексом не существует";
		return;
		return;
	}
	}
	ListItem<T>* curent_item = _head;
	ListItem<T>* curent_item = _head;
	for (int i = 0; i < index; i++) {
	for (int i = 0; i < index; i++) {
		curent_item = curent_item->next;
		curent_item = curent_item->next;
	}
	}
	if (index == 0) {
	if (index == 0) {
		curent_item->next->prev = nullptr;
		curent_item->next->prev = nullptr;
		_head = curent_item->next;
		_head = curent_item->next;
		delete curent_item;
		delete curent_item;
		_count--;
		_count--;
		return;
		return;
	}
	}
	if (index == _count) {
	if (index == _count) {
		curent_item->prev->next = nullptr;
		curent_item->prev->next = nullptr;
		delete curent_item;
		delete curent_item;
		_count--;
		_count--;
		return;
		return;
	}
	}
	curent_item->prev->next = curent_item->next;
	curent_item->prev->next = curent_item->next;
	curent_item->next->prev = curent_item->prev;
	curent_item->next->prev = curent_item->prev;
	delete curent_item;
	delete curent_item;
	_count--;
	_count--;
	return;
	return;
}
}


template <typename T>
template <typename T>
void List<T>::Clear() {
void List<T>::Clear() {
	ListItem<T>* curent_item = _head;
	ListItem<T>* curent_item = _head;
	ListItem<T>* temp;
	ListItem<T>* temp;
	while (curent_item->next != nullptr) {
	while (curent_item->next != nullptr) {
		temp = curent_item;
		temp = curent_item;
		curent_item = curent_item->next;
		curent_item = curent_item->next;
		delete temp;
		delete temp;
		_head = curent_item;
		_head = curent_item;
	}
	}
	delete curent_item;
	delete curent_item;
}
}


template <typename T>
template <typename T>
int List<T>::GetCount() {
int List<T>::GetCount() {
	ListItem<T>* curent_item = _head;
	ListItem<T>* curent_item = _head;
	int count = 0;
	int count = 0;
	while (curent_item->next != nullptr) {
	while (curent_item->next != nullptr) {
		curent_item = curent_item->next;
		curent_item = curent_item->next;
		count++;
		count++;
	}
	}
	count++;
	count++;
	return count;
	return count;
}
}