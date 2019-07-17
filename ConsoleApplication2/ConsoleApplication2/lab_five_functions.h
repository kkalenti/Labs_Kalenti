#pragma once 
#include "PersonList.h"

void PersonAgeCorrectionInput(int &age, const char kInvalidMessage[]);
void PersonPositiveCorrection(int &age);
bool CheckingText(char *string);
bool IsBetween(char checked, char lower, char upper);
PersonList MakeList(int count);
void ListsPrint(PersonList list_1, PersonList list_2, bool key);
char* MakeName(Sex sex);
char* MakeSurname(Sex sex);
char* NameInput(const char* text);
//Person* Read();
char* CreateBusiness();