#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

void MakeArray(double *array, int array_lenth) {
	cout << "Массив из " << array_lenth << " элементов:";
	for (int i = 0; i < array_lenth; i++) {
		array[i] = rand() % 50;
		cout << array[i] << setw(3);
	}
	cout << endl;
}

void Sort(double *array, int array_lenth) {
	double temp = 0;
	bool is_exit = false;
	while (!is_exit) {
		is_exit = true;
		for (int i = 0; i < array_lenth-1; i++) {
			if (array[i] > array[i + 1]) {
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				is_exit = false;
			}
		}
	}
	cout << "Отсортированный массив:";
	for (int j = 0; j < array_lenth; j++) {
		cout << array[j] << setw(3);
	}
	cout << endl;
}

void MakeRandomMatrix(int** matrix, int rows, int cols) {
	cout << "Матрица из " << rows << "*" << cols << " элементов:" << endl;
	cout.setf(ios::left);
	for (int i = 0; i < rows; 
		i++) {
		for (int j = 0; j < cols;
			j++){
			cout.width(3);
			matrix[i][j] = rand() % 50;
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

void ShowMatrix(int **matrix, int rows, int cols) {
	cout.setf(ios::left);
	for (int i = 0; i < rows; 
		i++) {
		for (int j = 0; j < cols;
			j++) {
			cout.width(5);
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}


bool MultiplyMatrices(int **matrix_a, int a_rows, int a_cols, int **matrix_b,
	int b_rows, int b_cols, int **result_matrix) {
	int summ = 0;
	switch (a_cols == b_rows) {
	case 1: {
		for (int i = 0; i < a_rows; i++) {
			for (int j = 0; j < b_cols; j++) {
				summ = 0;
				for (int k = 0; k < a_cols; k++) {
					summ += matrix_a[i][k]*
						matrix_b[k][j];
				}
				result_matrix[i][j] = summ;
			}
		}
		cout << "Итоговая матрица:" << endl;
		int result_rows = a_rows;
		int result_cols = b_cols;
		ShowMatrix(result_matrix, result_rows, result_cols);
		return 1;
		break;
	}
	default:
		cout << "Невозможно перемножить данные матрицы.\n";
		return 0;
		break;
	}

}

void MatrixInitialization(int **matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[cols];
	}
}