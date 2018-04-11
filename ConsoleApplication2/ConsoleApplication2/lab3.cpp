#include "stdafx.h"
#include <iostream>
#include "arrays.h"
#include "functions.h"
#include "strings.h"

using namespace std;



	//1 ���������
	void Lab3_�1(){
		int arrayLenth;
		for (int i = 0; i < 3; i++) {
			cout << "������� ������ ������� (���������� �� ����� 1000 �����)" << endl;
			CheckingForPositiveNumberAndNull(&arrayLenth);
			double *array = new double[arrayLenth];
			MakeArray(&array[0], arrayLenth);
			Sort(&array[0], arrayLenth);
			delete array;
			cout << "______________________________________________________" << endl;
		}
	}
	//2 ���������
	void Lab3_�2() {
		int aCols;
		int	aRows;
		int bCols;
		int bRows;
		cout << "������� ���������� ����� ������ ������� (���������� �� ����� 100 �����):";
		CheckingForPositive(&aRows);
		cout << "������� ���������� �������� ������ ������� (���������� �� ����� 100 �����):";
		CheckingForPositive(&aCols);
		cout << "������� ���������� ����� ������ ������� (���������� �� ����� 100 �����):";
		CheckingForPositive(&bRows);
		cout << "������� ���������� �������� ������ ������� (���������� �� ����� 100 �����):";
		CheckingForPositive(&bCols);
		int **matrixA = new int *[aRows];
		InitializationOfMatrix(matrixA, aRows, aCols);
		int **matrixB = new int *[bRows];
		InitializationOfMatrix(matrixB, bRows, bCols);
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
	void Lab3_�3() {
		char string[200];
		cout << "������� ������ (�� ����� 200 ��������):";
		cin >> string;
		if (GetLength(&string[0]) >= 0) {
			cout << "������ ������:" << GetLength(&string[0]) << endl;
			cout << "������� ������, ������� ����� ��������� �� ���������:" << endl;
			char cymbol;
			cin >> cymbol;
			int indexFirst = IndexOf(&string[0], cymbol);
			if (indexFirst >= 0) {
				cout << "������ ��������� ���������� ������� � �������� ������:"
					<< indexFirst << endl;
				int indexLast = LastIndexOf(&string[0], cymbol);
				if (indexLast >= 0) {
					cout << "������ ���������� ��������� ���������� ������� � �������� ������:"
						<< indexLast << endl;
				}
			} else {
				cout << "��������� ������ �� ������ � ������" << endl;
			}
		} else {
			cout << "������ �� ������� ��� �� ����������" << endl;
		}
		cout << "______________________________________________________" << endl;
		system("pause");
	}

	void Lab3_�4() {
		char string[50];
		char substring[50];
		cout << "������� ������ (�� ����� 50 ���������):";
		cin >> string;
		cout << "������� ������ ��������, � �������� ����� ������������ ������:";
		int startIndex;
		CheckingForPositiveNumberAndNull(&startIndex);
		cout << "������� ���������� ���������������� ��������� ������:";
		int substringLength;
		CheckingForPositiveNumberAndNull(&substringLength);
		if (GetSubstring(&string[0], &substring[0], startIndex, substringLength)) {
			cout << "������������ ������:" << substring << endl;
		} else {
			cout << "�������� ������ �� �������" << endl;
		}
		cout << "______________________________________________________" << endl;
	}

	int Lab3_�5() {
		char fullFilename[300];
		char filename[150];
		char fileExtension[150];
		char filepath[300];
		cout << "������� ������ ������ ����� (�� ����� 200 ��������):";
		cin >> fullFilename;
		if (GetFilenames(&fullFilename[0], &filename[0]) == false) {
			void InvalidFilenames(char &filename);
			return 0;
		}
		if (!GetFileExtension(&fullFilename[0], &fileExtension[0])) {
			void InvalidFilenames(char &fileExtantion);
			return 0;
		}
		if (!GetFilepath(&fullFilename[0], &filepath[0])) {
			void InvalidFilenames(char &filepath);
			return 0;
		}
		cout << "��� �����:" << filename << endl;
		cout << "���������� �����:" << fileExtension << endl;
		cout << "���� � �����:" << filepath << endl;
		return 0;
	}
