#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <locale.h>
#include <time.h>
#include <conio.h>
#include "lab1.h"
#include "lab2.h"
#include "lab3.h"


using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	char keyOfTask;
	char keyOfLab;
	int numberOfLab;
	int numberOfTask;
	do {
		keyOfLab == NULL;
		numberOfLab == NULL;
		cout << "�������� ������������ ������:\n"
			"1.�������� �������� ����� ��++\n"
			"2.�������, ��������� � �������� ����������\n"
			"3.������� � ������\n\n";
		cin >> numberOfLab;
		switch (numberOfLab) {
		case 1: {
			lab1();
			break;
		}
		case 2: {
			do {
				keyOfTask == NULL;
				numberOfTask == NULL;
				cout << "�������� ����� �������:\n"
					"1.������ ���������� ���������\n"
					"2.������ ���������� ���������2\n"
					"3.���������� � �������\n"
					"4.������� �����\n\n";
				cin >> numberOfTask;
				switch (numberOfTask) {
				case 1: {
					Lab2_�1();
					break;
				}
				case 2: {
					Lab2_�2();
					break;
				}
				case 3: {
					Lab2_�3();
					break;
				}
				case 4: {
					Lab2_�4();
					break;
				}
				default: {
					cout << "������ ������� �� ����������";
					break;
				}
				}
				cout << "���� ������ ���������� ����� �������, ������� Enter,"
					"���� ������ ��������� �������, Backspace\n\n";
				keyOfTask = _getch();
			} while (keyOfTask != 8);
			break;
		}
		case 3: {
			do {
				keyOfTask == NULL;
				numberOfTask == NULL;
				cout << "�������� ����� �������:\n"
					"1.���������� �������\n"
					"2.������������ ���� ������\n"
					"3.���������� ����� ������ � ��������� � ��� ������������� �������\n"
					"4.�������� ��������� �� ��������� ������\n"
					"5.������ � ����� �����\n\n";
				cin >> numberOfTask;
				switch (numberOfTask) {
					case 1: {
						Lab3_�1();
						break;
					}
					case 2: {
						Lab3_�2();
						break;
					}
					case 3: {
						Lab3_�3();
						break;
					}
					case 4: {
						Lab3_�4();
						break;
					}
					case 5: {
						Lab3_�5();
						break;
					}
					default: {
						cout << "������ ������� �� ����������";				
						break;
					}
				}
				cout << "���� ������ ���������� ����� �������, ������� Enter," 
					"���� ������ ��������� �������, Backspace\n\n";
				keyOfTask = _getch();
			} while (keyOfTask != 8);
			break;
		}
		default:
			cout << "�� ���������� ����� ������������ ������\n";
			break;
		}
		cout << "���� ������ ���������� ������ � �������������, ������� Enter. "
			"� �������� ������, ������� Backspace";
		keyOfLab = _getch();
	} while (keyOfLab != 8);
	return 0;
}