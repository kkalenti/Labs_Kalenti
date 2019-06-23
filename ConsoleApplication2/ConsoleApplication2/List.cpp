#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "List.h"

using namespace std;

//template <typename T>
//List<T>::List(ListItem* head) {
//	_head = head;
//	_count = 0;
//}
//
//
//template <typename T>
//void List<T>::Add(T element) {
//	if (_head == nullptr) {
//		ListItem* head_item = new ListItem;
//		_head = head_item;
//		head_item->next = nullptr;
//		head_item->prev = nullptr;
//		head_item->element = element;
//		_count++;
//		return;
//	}
//	ListItem* tail_item = new ListItem;
//	ListItem* curent_item = _head;
//	while (curent_item->next != nullptr) {
//		curent_item = curent_item->next;
//	}
//	tail_item->element = element;
//	tail_item->next = nullptr;
//	tail_item->prev = curent_item;
//	curent_item->next = tail_item;
//	_count++;
//	return;
//}
//
//
//template <typename T>
//T* List<T>::Find(int index) {
//	ListItem* curent_item = _head;
//	if (_count < index) {
//		return nullptr;
//	}
//	int count = 1;
//	while (count != index && (curent_item->next != nullptr || curent_item != nullptr)) {
//		curent_item = curent_item->next;
//		count++;
//	}
//	return (curent_item->element);
//}
//
//
//template <typename T>
//void List<T>::RemoveAt(int index) {
//	if (index > _count) {
//		cout << "Элемента с таким индексом не существует";
//		return;
//	}
//	ListItem* curent_item = _head;
//	for (int i = 0; i < index; i++) {
//		curent_item = curent_item->next;
//	}
//	if (index == 0) {
//		curent_item->next->prev = nullptr;
//		_head = curent_item->next;
//		delete curent_item;
//		_count--;
//		return;
//	}
//	if (index == _count) {
//		curent_item->prev->next = nullptr;
//		delete curent_item;
//		_count--;
//		return;
//	}
//	curent_item->prev->next = curent_item->next;
//	curent_item->next->prev = curent_item->prev;
//	delete curent_item;
//	_count--;
//	return;
//}
//
//
//template <typename T>
//void List<T>::Clear() {
//	ListItem* curent_item = _head;
//	ListItem* temp;
//	while (curent_item->next != nullptr) {
//		temp = curent_item;
//		curent_item = curent_item->next;
//		delete temp;
//		_head = curent_item;
//	}
//	delete curent_item;
//}
//
//
//template <typename T>
//int List<T>::GetCount() {
//	ListItem* curent_item = _head;
//	int count = 0;
//	while (curent_item->next != nullptr) {
//		curent_item = curent_item->next;
//		count++;
//	}
//	count++;
//	return count;
//}