#pragma once

void MakeArray(double *array, int arrayLenth);
void Sort(double *array, int arrayLenth);
void MakeMatrix(int** matrix, int Rows, int Cols);
bool MultiplyMatrices(int**matrixA, int aRows, int aCols, int** matrixB,
	int bRows, int bCols, int** resultMatrix);
void ShowMatrix(int **matrix, int rows, int cols);
void InitializationOfMatrix(int **matrix, int rows, int cols);
