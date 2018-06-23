#pragma once

#include "person_structure.h"

struct PersonListItem{
	Person Person;
	PersonListItem *next;
	PersonListItem *prev;
};
