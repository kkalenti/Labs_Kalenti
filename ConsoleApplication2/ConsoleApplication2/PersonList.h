#pragma once

#include "PersonalListItem.h"
#include "Person.h"

class PersonList{
private: 
	PersonListItem* _head; //указатель на голову списка
	int _count; //количество элементов в списке
public:
	PersonList(PersonListItem* _head, int _count); //конструктор класса
	void Add(Person* person); //добавить человека в список
	void Print();
	Person* Find(int index); //найти человека по указанному индексу
	int IndexOf(Person* person); //вернуть индекс человека, если он есть в списке
	void Remove(Person* person); //удалить человека из списка
	void RemoveAt(int index); //удалить человека из списка по индексу
	void Clear(); //очистить список
	int GetCount(); //количество элементов
};