#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

void MakeArray(double *array, int array_lenth) {
	cout << "Массив из " << array_lenth << " элементов:";
	//TODO: Вот в for-ах лучше использовать короткие i,j иначе получается многобукаф ни о чём.
	for (int array_counter = 0; array_counter < array_lenth; array_counter++) {
		array[array_counter] = rand() % 50;
		cout << array[array_counter] << setw(3);
	}
	cout << endl;
}

void Sort(double *array, int array_lenth) {
	double temp = 0;
	//TODO: Були лучше называть начиная с is, типа isExit - будет корректнее читаться.
	bool exit = false;
	while (!exit) {
		exit = true;
		for (int array_counter = 0; array_counter < array_lenth-1; array_counter++) {
			if (array[array_counter] > array[array_counter + 1]) {
				temp = array[array_counter];
				array[array_counter] = array[array_counter + 1];
				array[array_counter + 1] = temp;
				exit = false;
			}
		}
	}
	cout << "Отсортированный массив:";
	for (int array_counter = 0; array_counter < array_lenth; array_counter++) {
		cout << array[array_counter] << setw(3);
	}
	cout << endl;
}
//TODO: Название... Можно подумать, что ты в ручную задаёшь. А ты задаёшь рандомно, пусть это и будет в названии.
void MakeMatrix(int** matrix, int rows, int cols) {
	cout << "Матрица из " << rows << "*" << cols << " элементов:" << endl;
	cout.setf(ios::left);
	for (int matrix_counter_of_rows = 0; matrix_counter_of_rows < rows; 
		matrix_counter_of_rows++) {
		for (int matrix_counter_of_cols = 0; matrix_counter_of_cols < cols;
			matrix_counter_of_cols++){
			cout.width(3);
			matrix[matrix_counter_of_rows][matrix_counter_of_cols] = rand() % 50;
			cout << matrix[matrix_counter_of_rows][matrix_counter_of_cols];
		}
		cout << endl;
	}
}

void ShowMatrix(int **matrix, int rows, int cols) {
	cout.setf(ios::left);
	for (int matrix_counter_of_rows = 0; matrix_counter_of_rows < rows; 
		matrix_counter_of_rows++) {
		for (int matrix_counter_of_cols = 0; matrix_counter_of_cols < cols;
			matrix_counter_of_cols++) {
			cout.width(5);
			cout << matrix[matrix_counter_of_rows][matrix_counter_of_cols] << ' ';
		}
		cout << endl;
	}
}


bool MultiplyMatrices(int **matrix_a, int a_rows, int a_cols, int **matrix_b,
	int b_rows, int b_cols, int **result_matrix) {
	int summ = 0;
	switch (a_cols == b_rows) {
	case 1: {
		for (int multiply_rows_of_matrix_a = 0; multiply_rows_of_matrix_a < a_rows;
			multiply_rows_of_matrix_a++) {
			for (int multiply_cols_of_matrix_b = 0; multiply_cols_of_matrix_b < b_cols;
				multiply_cols_of_matrix_b++) {
				summ = 0;
				//TODO: Ёбни себе в глаз за такое название итератора
				for (int cols_of_matrixa_a_and_rows_of_matrix_b = 0; 
					cols_of_matrixa_a_and_rows_of_matrix_b < a_cols; 
					cols_of_matrixa_a_and_rows_of_matrix_b++) {
					summ += matrix_a[multiply_rows_of_matrix_a][cols_of_matrixa_a_and_rows_of_matrix_b]*
						matrix_b[cols_of_matrixa_a_and_rows_of_matrix_b][multiply_cols_of_matrix_b];
				}
				result_matrix[multiply_rows_of_matrix_a][multiply_cols_of_matrix_b] = summ;
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
//TODO: Название - можно без Of, будет читабельнее.
void InitializationOfMatrix(int **matrix, int rows, int cols) {
	for (int row_counter = 0; row_counter < rows; row_counter++) {
		matrix[row_counter] = new int[cols];
	}
}