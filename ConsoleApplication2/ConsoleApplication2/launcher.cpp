#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <locale.h>
#include <time.h>
#include "lab1.h"
#include "lab2.h"
#include "lab3.h"


using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
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
	case 3:
		lab3();
		break;
	}
		return 0;
}