#include "lab2.h"
#include "stdafx.h"
#include <iostream>

using namespace std;

int CheckingTheLetter(int input,const char invalidMessage[]){
	while (!(cin >> input) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << invalidMessage;
	}
	return input;
}