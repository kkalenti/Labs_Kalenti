#include "stdafx.h"
#include <iostream>
#include "weekday_enumeration.h"
#include "month_enumeration.h"

using namespace std;

void IdentifyWeekday(int number_of_weekday){
	while (number_of_weekday > 7) {
		number_of_weekday = number_of_weekday - 7;
	}
	switch (number_of_weekday) {
		case Monday: {
			cout << "���� ������: �����������" << endl;
			break;
		}
		case Tuesday: {
			cout << "���� ������: �������" << endl;
			break;
		}
		case Wendsday: {
			cout << "���� ������: �����" << endl;
			break;
		}
		case Thursday: {
			cout << "���� ������: �������" << endl;
			break;
		}
		case Friday: {
			cout << "���� ������: �������" << endl;
			break;
		}
		case Saturday: {
			cout << "���� ������: �������" << endl;
			break;
		}
		case Sunday: {
			cout << "���� ������: ����������" << endl;
			break;
		}
		default: {
			cout << "������ �����" << endl;
			break;
		}
	}
}

void IdentifyMonth(int number_of_month) {
	switch (number_of_month)
	{
		case January:{
			cout << "����� ������" << endl;
			break;
		}
		case February: {
			cout << "����� �������" << endl;
			break;
		}
		case March: {
			cout << "����� ����" << endl;
			break;
		}
		case April: {
			cout << "����� ������" << endl;
			break;
		}
		case May: {
			cout << "����� ���" << endl;
			break;
		}
		case June: {
			cout << "����� ����" << endl;
			break;
		}
		case July: {
			cout << "����� ����" << endl;
			break;
		}
		case August: {
			cout << "����� ������" << endl;
			break;
		}
		case September: {
			cout << "����� ��������" << endl;
			break;
		}
		case October: {
			cout << "����� �������" << endl;
			break;
		}
		case November: {
			cout << "����� ������" << endl;
			break;
		}
		case December: {
			cout << "����� �������" << endl;
			break;
		}
		default: {
			cout << "������ �����" << endl;
			break;
		}
	}
}