#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

void MakeArray(double *array, int arrayLenth) {
	cout << "Массив из " << arrayLenth << " элементов:";
	for (int i = 0; i < arrayLenth; i++) {
		array[i] = rand() % 50;
		cout << array[i] << setw(3);
	}
	cout << endl;
}