#pragma once
#include "Person.h"

class PersonListItem {
public:
	Person Person;
	PersonListItem *next;
	PersonListItem *prev;
};