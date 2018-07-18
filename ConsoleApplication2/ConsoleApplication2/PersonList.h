#pragma once

#include "PersonalListItem.h"
#include "Person.h"

class PersonList{
private: 
	PersonListItem* _head; //��������� �� ������ ������
	int _count; //���������� ��������� � ������
public:
	PersonList(PersonListItem* _head, int _count); //����������� ������
	void Add(Person* person); //�������� �������� � ������
	void Print();
	Person* Find(int index); //����� �������� �� ���������� �������
	int IndexOf(Person* person); //������� ������ ��������, ���� �� ���� � ������
	void Remove(Person* person); //������� �������� �� ������
	void RemoveAt(int index); //������� �������� �� ������ �� �������
	void Clear(); //�������� ������
	int GetCount(); //���������� ���������
};