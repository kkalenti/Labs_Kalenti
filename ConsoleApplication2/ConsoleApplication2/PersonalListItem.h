#pragma once
#include "Person.h"

class PersonListItem {
public:
	Person person;
	PersonListItem *next;
	PersonListItem *prev;
};