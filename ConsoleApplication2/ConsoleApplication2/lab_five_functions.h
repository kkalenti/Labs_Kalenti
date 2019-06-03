#pragma once 
#include "PersonList.h"

void PersonAgeCorrectionInput(int &age, const char kInvalidMessage[]);
void PersonPositiveCorrection(int *age);
bool CheckingText(char *string);
PersonList MakeList(int count);
void ListsPrint(PersonList list_1, PersonList list_2, bool key);
void MakeName(Person* person);
void MakeSurname(Person* person);