#include "stdafx.h"
#include <iostream>
#include <string>
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
	string temp;

	int index = 1 + rand() % 6;
	Person* randPerson = new_list.Find(index);
	if (typeid(*randPerson) == typeid(Child))
	{
		Child* child = (Child*)randPerson;
		cout << "This is a child" << endl;

		if (child->GetMother() != nullptr) {
			temp = child->GetMother()->GetDiscription();
			cout << "Мама: " << temp << endl;
		}
		else {
			cout << "Нет мамы" << endl;
		}
	}
	else
	{
		Adult* adult = (Adult*)randPerson;
		temp = adult->GetMarriedOn()->GetDiscription();
		cout << "This is an adult" << endl << "В браке с: " << temp << endl;
	}
	system("pause");
	//TODO: Спросить по утечек памяти
}
