#include "stdafx.h"
#include <iostream>
#include "Person.h"
#include "Adult.h"
#include "Child.h"
#include "PersonList.h"

using namespace std;

void lab6() {
	PersonList new_list(nullptr);
	for (int count = 1; count <= 3; count++) {
		new_list.Add(Adult::GetRandomPerson());

		Adult* adult = (Adult*)new_list.Find(count);
		adult->SetMarriedOn(Adult::GetMarriedPerson(adult));
	}
	for (int count = 1; count <= 3; count++) {
		new_list.Add(Child::GetRandomPerson());

		Adult* adult = Adult::GetRandomPerson();
		Child* child = (Child*)new_list.Find(count + 3);
		if (adult->GetSex() == Муж) {
			child->SetFather(adult);
			child->SetMother(Adult::GetMarriedPerson(adult));
		}
		else
		{
			child->SetMother(adult);
			child->SetFather(Adult::GetMarriedPerson(adult));
		}
	}
	new_list.Print();

	cout << endl;
	char temp[200];
	Person* randPerson = Child::GetRandomPerson();
	if (randPerson->GetAge() < 18)
	{
		Child* child = (Child*)randPerson;
		cout << "This is a child" << endl;

		if (child->GetMother() != nullptr) {
			strcpy_s(temp, child->GetMother()->GetDiscription());
			cout << "Мама: " << temp << endl;
		}
		else {
			cout << "Нет мамы" << endl;
		}
	}
	else
	{
		Adult* adult = (Adult*)randPerson;
		strcpy_s(temp, adult->GetMarriedOn()->GetDiscription());
		cout << "This is an adult" << endl << "В браке с: " << temp << endl;
	}

	system("pause");
}
