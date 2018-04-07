#include "stdafx.h"
#include <iostream>
#include "arrays.h"
#include "function.h"
#include "strings.h"

using namespace std;



int lab3() {
	//1 программа
	{
		int arrayLenth = 0;
		double array[100];
		for (int i = 0; i < 3; i++) {
			cout << "Введите размер массива" << endl;
			arrayLenth = CheckingTheLetter(arrayLenth, "Вы ввели не число! Повторите ввод\n");
			MakeArray(&array[0], arrayLenth);
			Sort(&array[0], arrayLenth);
			cout << "______________________________________________________" << endl;
		}
	}
	//2 программа
	{
		int aCols=0, aRows=0;
		int bCols=0, bRows=0;
		cout << "Введите количество строк первой матрицы:";
		aRows = CheckingForPositive(aRows, "Вы ввели не число! Повторите ввод\n", "Число не соответствует условию (n<=0)\nВведите число повторно:");
		cout << "Введите количество столбцов первой матрицы:";
		aCols = CheckingForPositive(aCols, "Вы ввели не число! Повторите ввод\n", "Число не соответствует условию (n<=0)\nВведите число повторно:");
		cout << "Введите количество строк второй матрицы:";
		bRows = CheckingForPositive(bRows, "Вы ввели не число! Повторите ввод\n", "Число не соответствует условию (n<=0)\nВведите число повторно:");
		cout << "Введите количество столбцов второй матрицы:";
		bCols = CheckingForPositive(aCols, "Вы ввели не число! Повторите ввод\n", "Число не соответствует условию (n<=0)\nВведите число повторно:");
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
	//3,4,5 программы
	{
		char string[100];
		cout << "Введите строку:";
		cin >> string;
		if (GetLength(&string[0]) >= 0) {
			cout << "Длинна строки:" << GetLength(&string[0]) << endl;
			cout << "Введите возможное вхождение в строку:" << endl;
			char c;
			cin >> c;
			int indexFirst = IndexOf(&string[0], c);
			if (indexFirst >= 0) {
				cout << "Индекс вхождения введенного символа в введеную строку:" << indexFirst << endl;
				int indexLast = LastIndexOf(&string[0], c);
				if (indexLast >= 0)
					cout << "Индекс последнего вхождения введенного символа в введеную строку:" << indexLast << endl;
			}
			else cout << "Введенный символ не найден в строке" << endl;
		}
		else cout << "Строка не введена или не существует" << endl;
		cout << "______________________________________________________" << endl;
	}
	{
		char string[50];
		char substring[50];
		cout << "Введите строку:";
		cin >> string;
		cout << "Введите индекс элемента, с которого будет перезаписана строка:";
		int startIndex = 0;
		startIndex = CheckingForPositiveNumberAndNull(startIndex, "Введено не число! Повторите ввод:", "Число не соответствует условию (Индекс < 0)! Повторите ввод:");
		cout << "Введите количество перезаписываемых элементов строки:";
		int substringLength = 0;
		substringLength = CheckingForPositiveNumberAndNull(substringLength, "Введено не число! Повторите ввод:", "Число не соответствует условию (Индекс < 0)! Повторите ввод:");
		if (GetSubstring(&string[0], &substring[0], startIndex, substringLength))
			cout << "Получившаяся строка:" << substring << endl;
		else cout << "Выделить строку не удалось" << endl;
		cout << "______________________________________________________" << endl;
	}
	{
		char fullFilename[100];
		char filename[50];
		char fileExtension[50];
		char filepath[100];
		cout << "Введите полный адресс файла:";
		cin >> fullFilename;
		if (!GetFilenames(&fullFilename[0], &filename[0])) {
			filename[0] = '\0';
			cout << "Невозможно найти данные о файле" << endl;
			system("pause");
			return 0;
		}
		if (!GetFileExtension(&fullFilename[0], &fileExtension[0])) {
			fileExtension[0] = '\0';
			cout << "Невозможно найти данные о файле" << endl;
			system("pause");
			return 0;
		}
		if (!GetFilepath(&fullFilename[0], &filepath[0])) {
			filepath[0] = '\0';
			cout << "Невозможно найти данные о файле" << endl;
			system("pause");
			return 0;
		}
		cout << "Имя файла:" << filename << endl;
		cout << "Расширение файла:" << fileExtension << endl;
		cout << "Путь к файлу:" << filepath << endl;
	}
	system("pause");
	return 0;
}