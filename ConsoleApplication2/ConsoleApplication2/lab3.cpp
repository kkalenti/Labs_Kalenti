#include "stdafx.h"
#include <iostream>
#include "arrays.h"
#include "functions.h"
#include "strings.h"

using namespace std;



	//1 программа
	void Lab3_№1(){
		int arrayLenth;
		for (int i = 0; i < 3; i++) {
			cout << "Введите размер массива (Желательно не более 1000 чисел)" << endl;
			CheckingForPositiveNumberAndNull(&arrayLenth);
			double *array = new double[arrayLenth];
			MakeArray(&array[0], arrayLenth);
			Sort(&array[0], arrayLenth);
			delete array;
			cout << "______________________________________________________" << endl;
		}
	}
	//2 программа
	void Lab3_№2() {
		int aCols;
		int	aRows;
		int bCols;
		int bRows;
		cout << "Введите количество строк первой матрицы (Желательно не более 100 чисел):";
		CheckingForPositive(&aRows);
		cout << "Введите количество столбцов первой матрицы (Желательно не более 100 чисел):";
		CheckingForPositive(&aCols);
		cout << "Введите количество строк второй матрицы (Желательно не более 100 чисел):";
		CheckingForPositive(&bRows);
		cout << "Введите количество столбцов второй матрицы (Желательно не более 100 чисел):";
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
			int indexFirst = IndexOf(&string[0], cymbol);
			if (indexFirst >= 0) {
				cout << "Индекс вхождения введенного символа в введеную строку:"
					<< indexFirst << endl;
				int indexLast = LastIndexOf(&string[0], cymbol);
				if (indexLast >= 0) {
					cout << "Индекс последнего вхождения введенного символа в введеную строку:"
						<< indexLast << endl;
				}
			} else {
				cout << "Введенный символ не найден в строке" << endl;
			}
		} else {
			cout << "Строка не введена или не существует" << endl;
		}
		cout << "______________________________________________________" << endl;
		system("pause");
	}

	void Lab3_№4() {
		char string[50];
		char substring[50];
		cout << "Введите строку (Не более 50 элементов):";
		cin >> string;
		cout << "Введите индекс элемента, с которого будет перезаписана строка:";
		int startIndex;
		CheckingForPositiveNumberAndNull(&startIndex);
		cout << "Введите количество перезаписываемых элементов строки:";
		int substringLength;
		CheckingForPositiveNumberAndNull(&substringLength);
		if (GetSubstring(&string[0], &substring[0], startIndex, substringLength)) {
			cout << "Получившаяся строка:" << substring << endl;
		} else {
			cout << "Выделить строку не удалось" << endl;
		}
		cout << "______________________________________________________" << endl;
	}

	int Lab3_№5() {
		char fullFilename[300];
		char filename[150];
		char fileExtension[150];
		char filepath[300];
		cout << "Введите полный адресс файла (не более 200 символов):";
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
		cout << "Имя файла:" << filename << endl;
		cout << "Расширение файла:" << fileExtension << endl;
		cout << "Путь к файлу:" << filepath << endl;
		return 0;
	}
