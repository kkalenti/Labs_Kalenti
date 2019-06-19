#pragma once
#include "Person.h"

class PersonList{
	
private: 
	class PersonListItem {
	public:
		Person* person;
		PersonListItem *next;
		PersonListItem *prev;
	};

	PersonListItem* _head; 
	int _count; 
public:	
	//TODO: Нахер count передаёшь в конструктор?
	//Больше не передаю
	PersonList(PersonListItem* _head);
	void Add(Person* person); 
	void Print();
	Person* Find(int index); 
	int IndexOf(Person* person);
	void Remove(Person* person);
	void RemoveAt(int index); 
	void Clear(); 
	int GetCount();
};