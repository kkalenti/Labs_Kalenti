#include "stdafx.h"
#include <iostream>
#include "arrays.h"
#include "functions.h"
#include "strings.h"

using namespace std;



	//1 программа
	void Lab3_№1(){
		int array_lenth;
		for (int i = 0; i < 3; i++) {
			cout << "Введите размер массива (Желательно не более 1000 чисел)" << endl;
			CheckingForPositiveNumberAndNull(&array_lenth);
			double *array = new double[array_lenth];
			MakeArray(&array[0], array_lenth);
			Sort(&array[0], array_lenth);
			delete array;
		}
		system("pause");
	}
	//2 программа
	void Lab3_№2() {
		int a_cols;
		int	a_rows;
		int b_cols;
		int b_rows;
		cout << "Введите количество строк первой матрицы (Желательно не более 100 чисел):";
		CheckingForPositive(&a_rows);
		cout << "Введите количество столбцов первой матрицы (Желательно не более 100 чисел):";
		CheckingForPositive(&a_cols);
		cout << "Введите количество строк второй матрицы (Желательно не более 100 чисел):";
		CheckingForPositive(&b_rows);
		cout << "Введите количество столбцов второй матрицы (Желательно не более 100 чисел):";
		CheckingForPositive(&b_cols);
		int **matrix_a = new int *[a_rows];
		InitializationOfMatrix(matrix_a, a_rows, a_cols);
		int **matrix_b = new int *[b_rows];
		InitializationOfMatrix(matrix_b, b_rows, b_cols);
		int result_rows = a_rows;
		int result_cols = b_cols;
		int **result_matrix = new int *[result_rows];
		for (int row_counter = 0; row_counter < result_rows; row_counter++) {
			result_matrix[row_counter] = new int[result_cols];
		}
		MakeMatrix(matrix_a, a_rows, a_cols);
		MakeMatrix(matrix_b, b_rows, b_cols);
		MultiplyMatrices(matrix_a, a_rows, a_cols, matrix_b, b_rows, b_cols, result_matrix);
		system("pause");
	}
	//3,4,5 программы
	void Lab3_№3() {
		char string[200];
		cout << "Введите строку (Не более 200 символов):";
		cin >> string;
		if (GetLength(&string[0]) >= 0) {
			cout << "Длинна строки:" << GetLength(&string[0]) << endl;
			cout << "Введите символ, который нужно проверить на вхождение:" << endl;
			char cymbol;
			cin >> cymbol;
			int index_first = IndexOf(&string[0], cymbol);
			if (index_first >= 0) {
				cout << "Индекс вхождения введенного символа в введеную строку:"
					<< index_first << endl;
				int index_last = LastIndexOf(&string[0], cymbol);
				if (index_last >= 0) {
					cout << "Индекс последнего вхождения введенного символа в введеную строку:"
						<< index_last << endl;
				}
			} else {
				cout << "Введенный символ не найден в строке" << endl;
			}
		} else {
			cout << "Строка не введена или не существует" << endl;
		}
		system("pause");
	}

	void Lab3_№4() {
		char string[50];
		char substring[50];
		cout << "Введите строку (Не более 50 элементов):";
		cin >> string;
		cout << "Введите индекс элемента, с которого будет перезаписана строка:";
		int start_index;
		CheckingForPositiveNumberAndNull(&start_index);
		cout << "Введите количество перезаписываемых элементов строки:";
		int substring_length;
		CheckingForPositiveNumberAndNull(&substring_length);
		if (GetSubstring(&string[0], &substring[0], start_index, substring_length)) {
			cout << "Получившаяся строка:" << substring << endl;
		} else {
			cout << "Выделить строку не удалось" << endl;
		}
		system("pause");
	}

	int Lab3_№5() {
		//TODO: Сломал работу введя C:\Program Files (x86)\Apple Software Update\
		
		char full_filename[300];
		char filename[150];
		char file_extension[150];
		char filepath[300];
		cout << "Введите полный адресс файла (не более 200 символов):";
		cin >> full_filename;
		if (GetFilenames(&full_filename[0], &filename[0]) == false) {
			void InvalidFilenames(char &filename);
			return 0;
		}
		if (!GetFileExtension(&full_filename[0], &file_extension[0])) {
			void InvalidFilenames(char &fileExtantion);
			return 0;
		}
		if (!GetFilepath(&full_filename[0], &filepath[0])) {
			void InvalidFilenames(char &filepath);
			return 0;
		}
		cout << "Имя файла:" << filename << endl;
		cout << "Расширение файла:" << file_extension << endl;
		cout << "Путь к файлу:" << filepath << endl;
		system("pause");
		return 0;
	}
