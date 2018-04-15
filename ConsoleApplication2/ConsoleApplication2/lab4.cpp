#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "functions.h"
#include "enumeration.h"
#include "color_enumeration.h"

using namespace std;

void lab4_�1() {
	int number_of_weekday;
	cout << "������� ����� �� 1 �� 365 (����� ��� � ����):\n";
	do {
		CheckingForPositive(&number_of_weekday);
		if (number_of_weekday > 365) {
			cout << "������� ����� ������ 365! ��������� ����:\n";
		}
	} while (number_of_weekday > 365);
	IdentifyWeekday(number_of_weekday);
	system("pause");
}

void lab4_�2() {
	int number_of_month;
	cout << "������� ����� �� 1 �� 12 (����� ������):\n";
	do {
		CheckingForPositive(&number_of_month);
		if (number_of_month > 12) {
			cout << "������� ����� ������ 12! ��������� ����:\n";
		}
	} while (number_of_month > 12);
	IdentifyMonth(number_of_month);
	system("pause");
}

void lab4_�3() {
	bool exit_color = true;
	int number_of_color;
	do{
		system("cls");
		cout << "�������� ����:" << endl << "1.�������" << endl << 
			"2.�����" << endl << "3.������" << endl << "4.�������" << endl <<
			"5.����������" << endl << "Backspace. ����� � ������ �������" << endl;
		cout << "�������� ����:" << endl;
		number_of_color = _getch();
		system("cls");
			switch (number_of_color){
			case red: {
				system("color 04");
				break;
			}
			case blue: {
				system("color 01");
				break;
			}
			case yellow: {
				system("color 0E");
				break;
			}
			case green: {
				system("color 02");
				break;
			}
			case purple: {
				system("color 05");
				break;
			}
			case 8: {
				exit_color = false;
				break;
			}
			default:
				cout << "��� ������ �����" << endl;
				break;
			}

	} while (exit_color == true);
	system("color 0F");
}