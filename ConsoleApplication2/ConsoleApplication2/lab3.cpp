#include "stdafx.h"
#include <iostream>
#include "arrays.h"
#include "function.h"

using namespace std;



int lab3() {
	//1 программа
	{
		int arrayLenth = 0;
		double array[100];
		for (int i = 0; i < 3; i++) {
			cout << "Введите размер массива\n";
			arrayLenth = CheckingTheLetter(arrayLenth, "Вы ввели не число! Повторите ввод\n");
			MakeArray(&array[0], arrayLenth);
			Sort(&array[0], arrayLenth);
			cout << "______________________________________________________\n";
		}
	}
	//2 программа
	{
		int aCols=0, aRows=0;
		int bCols=0, bRows=0;
		cout << "Введите количество строк первой матрицы:";
		aRows = CheckingForArray(aRows, "Вы ввели не число! Повторите ввод\n", "Число не соответствует условию (n<=0)\nВведите число повторно:");
		cout << "Введите количество столбцов первой матрицы:";
		aCols = CheckingForArray(aCols, "Вы ввели не число! Повторите ввод\n", "Число не соответствует условию (n<=0)\nВведите число повторно:");
		cout << "Введите количество строк второй матрицы:";
		bRows = CheckingForArray(bRows, "Вы ввели не число! Повторите ввод\n", "Число не соответствует условию (n<=0)\nВведите число повторно:");
		cout << "Введите количество столбцов второй матрицы:";
		bCols = CheckingForArray(aCols, "Вы ввели не число! Повторите ввод\n", "Число не соответствует условию (n<=0)\nВведите число повторно:");
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