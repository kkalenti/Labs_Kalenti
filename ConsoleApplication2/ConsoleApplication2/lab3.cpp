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
			arrayLenth = CheckingTheLetter(arrayLenth, "�� ����� �� �����! ��������� ����\n");
			MakeArray(&array[0], arrayLenth);
			Sort(&array[0], arrayLenth);
			cout << "______________________________________________________\n";
		}
	}
	//2 ���������
	{
		int aCols=0, aRows=0;
		int bCols=0, bRows=0;
		cout << "������� ���������� ����� ������ �������:";
		aRows = CheckingForArray(aRows, "�� ����� �� �����! ��������� ����\n", "����� �� ������������� ������� (n<=0)\n������� ����� ��������:");
		cout << "������� ���������� �������� ������ �������:";
		aCols = CheckingForArray(aCols, "�� ����� �� �����! ��������� ����\n", "����� �� ������������� ������� (n<=0)\n������� ����� ��������:");
		cout << "������� ���������� ����� ������ �������:";
		bRows = CheckingForArray(bRows, "�� ����� �� �����! ��������� ����\n", "����� �� ������������� ������� (n<=0)\n������� ����� ��������:");
		cout << "������� ���������� �������� ������ �������:";
		bCols = CheckingForArray(aCols, "�� ����� �� �����! ��������� ����\n", "����� �� ������������� ������� (n<=0)\n������� ����� ��������:");
		int **matrixA = new int *[aRows];
		for (int rowCounter = 0; rowCounter < aRows; rowCounter++) {
			matrixA[rowCounter] = new int [aCols];
		}
		int **matrixB = new int *[bRows];
		for (int rowCounter = 0; rowCounter < bRows; rowCounter++) {
			matrixB[rowCounter] = new int [bCols];
		}
		int resultRows = aRows;
		int resultCols = bCols;
		int **resultMatrix = new int *[resultRows];
		for (int rowCounter = 0; rowCounter < resultRows; rowCounter++) {
			resultMatrix[rowCounter] = new int[resultCols];
		}
		MakeMatrix(matrixA, aRows, aCols);
		MakeMatrix(matrixB, bRows, bCols);
		MultiplyMatrices(matrixA, aRows, aCols, matrixB, bRows, bCols, resultMatrix);
		cout << "______________________________________________________\n";
	}
	system("pause");
	return 0;
}