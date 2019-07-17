#pragma once
#include "sex_enumeration.h"

class Person {
protected: 
	static const int kMinAge_ = 0;
	static const int kMaxAge_ = 120;
	int age_;
	char *name_;
	char *surname_;
	Sex sex_;
public:
	Person(char* name, char* surname, Sex sex, int age);
	Person(bool flag);
	std::string GetInfo();
	int GetAge();
	void SetAge(int age);
	char* GetName();
	char* GetSurname();
	Sex GetSex();
	void SetSex(Sex _sex);
	void Show();
	virtual std::string GetDiscription() = 0;
	static void PersonAgeCorrectionInput(int& age, const char kInvalidMessage[]);
	static void PersonPositiveCorrection(int& age);
};