#include "stdafx.h"
#include <iostream>
#include "arrays.h"
#include "function.h"

using namespace std;

int lab3() {
	//1 ���������
	{
		int arrayLenth = 0;
		double array[100];
		for (int i = 0; i < 3; i++) {
			cout << "������� ������ �������\n";
			cin >> arrayLenth;
			arrayLenth = CheckingTheLetter(arrayLenth, "�� ����� �� �����! ��������� ����\n");
			MakeArray(&array[0], arrayLenth);
		}
	}
	{

	}
	system("pause");
	return 0;
}