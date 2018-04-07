#include "stdafx.h"
#include <iostream>
#include "arrays.h"
#include "function.h"
#include "strings.h"

using namespace std;



int lab3() {
	//1 ���������
	{
		int arrayLenth = 0;
		double array[100];
		for (int i = 0; i < 3; i++) {
			cout << "������� ������ �������" << endl;
			arrayLenth = CheckingTheLetter(arrayLenth, "�� ����� �� �����! ��������� ����\n");
			MakeArray(&array[0], arrayLenth);
			Sort(&array[0], arrayLenth);
			cout << "______________________________________________________" << endl;
		}
	}
	//2 ���������
	{
		int aCols=0, aRows=0;
		int bCols=0, bRows=0;
		cout << "������� ���������� ����� ������ �������:";
		aRows = CheckingForPositive(aRows, "�� ����� �� �����! ��������� ����\n", "����� �� ������������� ������� (n<=0)\n������� ����� ��������:");
		cout << "������� ���������� �������� ������ �������:";
		aCols = CheckingForPositive(aCols, "�� ����� �� �����! ��������� ����\n", "����� �� ������������� ������� (n<=0)\n������� ����� ��������:");
		cout << "������� ���������� ����� ������ �������:";
		bRows = CheckingForPositive(bRows, "�� ����� �� �����! ��������� ����\n", "����� �� ������������� ������� (n<=0)\n������� ����� ��������:");
		cout << "������� ���������� �������� ������ �������:";
		bCols = CheckingForPositive(aCols, "�� ����� �� �����! ��������� ����\n", "����� �� ������������� ������� (n<=0)\n������� ����� ��������:");
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
		cout << "______________________________________________________" << endl;
	}
	//3,4,5 ���������
	{
		char string[100];
		cout << "������� ������:";
		cin >> string;
		if (GetLength(&string[0]) >= 0) {
			cout << "������ ������:" << GetLength(&string[0]) << endl;
			cout << "������� ��������� ��������� � ������:" << endl;
			char c;
			cin >> c;
			int indexFirst = IndexOf(&string[0], c);
			if (indexFirst >= 0) {
				cout << "������ ��������� ���������� ������� � �������� ������:" << indexFirst << endl;
				int indexLast = LastIndexOf(&string[0], c);
				if (indexLast >= 0)
					cout << "������ ���������� ��������� ���������� ������� � �������� ������:" << indexLast << endl;
			}
			else cout << "��������� ������ �� ������ � ������" << endl;
		}
		else cout << "������ �� ������� ��� �� ����������" << endl;
		cout << "______________________________________________________" << endl;
	}
	{
		char string[50];
		char substring[50];
		cout << "������� ������:";
		cin >> string;
		cout << "������� ������ ��������, � �������� ����� ������������ ������:";
		int startIndex = 0;
		startIndex = CheckingForPositiveNumberAndNull(startIndex, "������� �� �����! ��������� ����:", "����� �� ������������� ������� (������ < 0)! ��������� ����:");
		cout << "������� ���������� ���������������� ��������� ������:";
		int substringLength = 0;
		substringLength = CheckingForPositiveNumberAndNull(substringLength, "������� �� �����! ��������� ����:", "����� �� ������������� ������� (������ < 0)! ��������� ����:");
		if (GetSubstring(&string[0], &substring[0], startIndex, substringLength))
			cout << "������������ ������:" << substring << endl;
		else cout << "�������� ������ �� �������" << endl;
		cout << "______________________________________________________" << endl;
	}
	{
		char fullFilename[100];
		char filename[50];
		char fileExtension[50];
		char filepath[100];
		cout << "������� ������ ������ �����:";
		cin >> fullFilename;
		if (!GetFilenames(&fullFilename[0], &filename[0])) {
			filename[0] = '\0';
			cout << "���������� ����� ������ � �����" << endl;
			system("pause");
			return 0;
		}
		if (!GetFileExtension(&fullFilename[0], &fileExtension[0])) {
			fileExtension[0] = '\0';
			cout << "���������� ����� ������ � �����" << endl;
			system("pause");
			return 0;
		}
		if (!GetFilepath(&fullFilename[0], &filepath[0])) {
			filepath[0] = '\0';
			cout << "���������� ����� ������ � �����" << endl;
			system("pause");
			return 0;
		}
		cout << "��� �����:" << filename << endl;
		cout << "���������� �����:" << fileExtension << endl;
		cout << "���� � �����:" << filepath << endl;
	}
	system("pause");
	return 0;
}