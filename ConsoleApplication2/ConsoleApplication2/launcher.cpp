#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <locale.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include "lab1.h"
#include "lab2.h"
#include "lab3.h"
#include "lab4.h"


using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char key_of_task;
	char key_of_lab;
	bool exit_labs = true;
	do {
		key_of_lab == NULL;
		cout << "�������� ������������ ������:" << endl <<
			"1.�������� �������� ����� ��++" << endl <<
			"2.�������, ��������� � �������� ����������" << endl <<
			"3.������� � ������" << endl <<
			"4.������ � ������������ �������" << endl <<
			"Backspace. ����� �� ���������" << endl << endl;
		key_of_lab = _getch();
		//TODO: ���� ������� ����� ���� �� ���� � ���� ���������, ��� ���� �� ����������, ����� �� ���������� ����� �������.
		switch (key_of_lab) {
			//TODO: �����, ��..., ��� �� 49? �� ��� ������ �����?!) �� ������ ���� �������, ������ ���� � ������ ���������� ASCII, �������� ���� ����?
			case 49: {	//������ ����
			lab1();
			break;
		}
			case 50: { //������ ����
			bool exit_lab_two = true;
			do {
				system("cls");
				key_of_task == NULL;
				cout << "������������ �1." << endl << "�������� ����� �������:" << endl <<
					"1.������ ���������� ���������" << endl <<
					"2.������ ���������� ���������2" << endl <<
					"3.���������� � �������" << endl <<
					"4.������� �����" << endl <<
					"Backspace. ������� � ������ ������������" << endl << endl;
				key_of_task = _getch();
				system("cls");
				switch (key_of_task) {
					case 49: {	//������ ������� ������ ����
						Lab2_�1();
						break;
					}
					case 50: {	//������ ������� ������ ����
						Lab2_�2();
						break;
					}
					case 51: {	//������ ������� ������ ����
						Lab2_�3();
						break;
					}
					case 52: {	//��������� ������� ������ ����
						Lab2_�4();
						break;
					}
					case 8: {	//����� �� ����
						exit_lab_two = false;
						break;
					}
					default: {
						cout << "������ ������� �� ����������";
						break;
					}
				}
			} while (exit_lab_two == true);
			break;
		}
			case 51: { // ������ ����
			bool exit_task_three = true;
			do {
				system("cls");
				key_of_task == NULL;
				cout << "������������ �3." << endl << "�������� ����� �������:" << endl <<
					"1.���������� �������" << endl << 
					"2.������������ ���� ������" << endl <<
					"3.���������� ����� ������ � ��������� � ��� ������������� �������" << endl <<
					"4.�������� ��������� �� ��������� ������" << endl <<
					"5.������ � ����� �����" << endl << 
					"Backspace. ��������� � ������ ���������" << endl << endl;
				key_of_task = _getch();
				system("cls");
				switch (key_of_task) {
					case 49: {	 //������ ������� ������� ����
						Lab3_�1();
						break;
					}
					case 50: {	//������ ������� ������� ����
						Lab3_�2();
						break;
					}
					case 51: {	//������ ������� ������� ����
						Lab3_�3();
						break;
					}
					case 52: {	//��������� ������� ������� ����
						Lab3_�4();
						break;
					}
					case 53: {	//����� ������� ������� ����
						Lab3_�5();
						break;
					}
					case 8: {	//����� �� ����
						exit_task_three = false;
						break;
					}
					default: {
						cout << "������ ������� �� ����������\n";
						break;
					}
				}
			} while (exit_task_three == true);
			break;
		}
			case 52: { // ��������� ����
			bool exit_task_four = true;
			do {
				system("cls");
				key_of_task == NULL;
				cout << "������������ �4." << endl << "�������� ����� �������:" << endl <<
					"1.����� ��� ������" << endl << 
					"2.����� ������" << endl <<
					"3.������ � ������" << endl <<
					"4.������ �� �����������" << endl <<
					"Backspace. ������� � ������ ������������" << endl << endl;
				key_of_task = _getch();
				system("cls");
				switch (key_of_task) {
					case 49: {	//������ ������� ��������� ����
						lab4_�1();
						break;
					}
					case 50: {	 //������ ������� ��������� ����
						lab4_�2();
						break;
					}
					case 51: {	//������ ������� ��������� ����
						lab4_�3();
						break;
					}
					case 52: { //��������� ������� ��������� ����
						lab4_�4();
						break;
					}
					case 8: {
						exit_task_four = false;
						break;
					}
					default: {
						cout << "������ ������� �� ����������";
						break;
					}
				}
			} while (exit_task_four == true);
			break;
		}
			case 8: {
			exit_labs = false;
			break;
		}
			default:
				cout << "�� ���������� ����� ������������ ������" << endl;
				break;
			}
		} while (exit_labs == true);
	return 0;
}