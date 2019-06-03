#include "stdafx.h"
#include <iostream>
#include "Person.h"
#include "Adult.h"
#include "Child.h"
#include "PersonList.h"

using namespace std;

void lab6() {
	PersonList new_list(nullptr, 7);
	Person *rand_child;
	Person *rand_adult;
	for (int count = 0; count < 3; count++) {
		new_list.Add(Adult::GetRandomPerson());
	}
	for (int count = 0; count < 3; count++) {
		new_list.Add(Child::GetRandomPerson());
	}
	new_list.Print();
	cout << endl;
	char temp[200];
	rand_child = Child::GetRandomPerson();
	if (rand_child->GetAge() < 18)
	{
		Child* child = (Child*)rand_child;
		strcpy_s(temp, child->GetMother()->GetDiscription());
		cout << "This is a child" << endl << "Родитель: " << temp << endl;
	}
	else
	{
		Adult* adult = (Adult*)rand_child;
		strcpy_s(temp, adult->GetMarriedOn()->GetDiscription());
		cout << "This is an adult" << endl << "В браке с: " << temp << endl;
	}

	system("pause");
}
