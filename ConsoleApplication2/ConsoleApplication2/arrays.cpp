#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

void MakeArray(double *array, int arrayLenth) {
	cout << "Массив из " << arrayLenth << " элементов:";
	for (int arrayCounter = 0; arrayCounter < arrayLenth; arrayCounter++) {
		array[arrayCounter] = rand() % 50;
		cout << array[arrayCounter] << setw(3);
	}
	cout << endl;
}

void Sort(double *array, int arrayLenth) {
	double temp = 0;
	bool exit = false;
	while (!exit) {
		exit = true;
		for (int arrayCounter = 0; arrayCounter < arrayLenth-1; arrayCounter++) {
			if (array[arrayCounter] > array[arrayCounter + 1]) {
				temp = array[arrayCounter];
				array[arrayCounter] = array[arrayCounter + 1];
				array[arrayCounter + 1] = temp;
				exit = false;
			}
		}
	}
	cout << "Отсортированный массив:";
	for (int arrayCounter = 0; arrayCounter < arrayLenth; arrayCounter++) {
		cout << array[arrayCounter] << setw(3);
	}
	cout << endl;
}

void MakeMatrix(int** matrix, int rows, int cols) {
	cout << "Матрица из " << rows << "*" << cols << " элементов:" << endl;
	cout.setf(ios::left);
	for (int matrixCounterOfRows = 0; matrixCounterOfRows < rows; 
		matrixCounterOfRows++) {
		for (int matrixCounterOfCols = 0; matrixCounterOfCols < cols;
			matrixCounterOfCols++){
			cout.width(3);
			matrix[matrixCounterOfRows][matrixCounterOfCols] = rand() % 50;
			cout << matrix[matrixCounterOfRows][matrixCounterOfCols];
		}
		cout << endl;
	}
}

void ShowMatrix(int **matrix, int rows, int cols) {
	cout.setf(ios::left);
	for (int matrixCounterOfRows = 0; matrixCounterOfRows < rows; 
		matrixCounterOfRows++) {
		for (int matrixCounterOfCols = 0; matrixCounterOfCols < cols;
			matrixCounterOfCols++) {
			cout.width(5);
			cout << matrix[matrixCounterOfRows][matrixCounterOfCols] << ' ';
		}
		cout << endl;
	}
}


bool MultiplyMatrices(int **matrixA, int aRows, int aCols, int **matrixB,
	int bRows, int bCols, int **resultMatrix) {
	int summ = 0;
	switch (aCols == bRows) {
	case 1: {
		for (int multiplyRowsOfMatrixA = 0; multiplyRowsOfMatrixA < aRows;
			multiplyRowsOfMatrixA++) {
			for (int multiplyColsOfMatrixB = 0; multiplyColsOfMatrixB < bCols;
				multiplyColsOfMatrixB++) {
				summ = 0;
				for (int colsOfMatrixAAndRowsOfMatrixB = 0; 
					colsOfMatrixAAndRowsOfMatrixB < aCols; colsOfMatrixAAndRowsOfMatrixB++) {
					summ += matrixA[multiplyRowsOfMatrixA][colsOfMatrixAAndRowsOfMatrixB] *
						matrixB[colsOfMatrixAAndRowsOfMatrixB][multiplyColsOfMatrixB];
				}
				resultMatrix[multiplyRowsOfMatrixA][multiplyColsOfMatrixB] = summ;
			}
		}
		cout << "Итоговая матрица:" << endl;
		int resultRows = aRows;
		int resultCols = bCols;
		ShowMatrix(resultMatrix, resultRows, resultCols);
		return 1;
		break;
	}
	default:
		cout << "Невозможно перемножить данные матрицы.\n";
		return 0;
		break;
	}

}

void InitializationOfMatrix(int **matrix, int rows, int cols) {
	for (int rowCounter = 0; rowCounter < rows; rowCounter++) {
		matrix[rowCounter] = new int[cols];
	}
}