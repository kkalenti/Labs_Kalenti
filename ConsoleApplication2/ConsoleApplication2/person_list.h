#pragma once
#include "person_structure.h"

struct PersonListItem{
	PersonStr Person;
	PersonListItem *next;
	PersonListItem *prev;
};
