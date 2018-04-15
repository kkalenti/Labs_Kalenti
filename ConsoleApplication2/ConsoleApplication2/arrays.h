#pragma once

void MakeArray(double *array, int array_lenth);
void Sort(double *array, int array_lenth);
void MakeMatrix(int** matrix, int rows, int cols);
bool MultiplyMatrices(int**matrix_a, int a_rows, int a_cols, int** matrix_b,
	int b_rows, int b_cols, int** result_matrix);
void ShowMatrix(int **matrix, int rows, int cols);
void InitializationOfMatrix(int **matrix, int rows, int cols);
