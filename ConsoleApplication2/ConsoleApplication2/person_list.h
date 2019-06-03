#pragma once
#include "person_structure.h"

struct PersonListItem{
	PersonStr person;
	PersonListItem *next;
	PersonListItem *prev;
};
