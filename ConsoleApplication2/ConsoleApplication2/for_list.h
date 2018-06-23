#pragma once
#include "person_list.h"

PersonListItem* AddToEndOfAPersonList(PersonListItem* person_list_head);
void DeleteElementOfAPersonList(PersonListItem* person_list_head, PersonListItem* person_list_tail, int number_of_element);
void PrintPersonList(PersonListItem* person_list_head);
