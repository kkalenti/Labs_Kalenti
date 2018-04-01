#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <locale.h>
#include "lab1.h"
#include "lab2.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	int numberOfLab;
	cout << "¬ведите номер нужной лабы:";
	cin >> numberOfLab;
	switch (numberOfLab) {
	case 1:
		lab1();
		break;
	case 2:
		lab2();
		break;
	}
		return 0;
}