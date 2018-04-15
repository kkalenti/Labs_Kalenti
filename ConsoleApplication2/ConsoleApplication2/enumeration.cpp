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
			cout << "ƒень недели: ѕонедельник" << endl;
			break;
		}
		case Tuesday: {
			cout << "ƒень недели: ¬троник" << endl;
			break;
		}
		case Wendsday: {
			cout << "ƒень недели: —реда" << endl;
			break;
		}
		case Thursday: {
			cout << "ƒень недели: „етверг" << endl;
			break;
		}
		case Friday: {
			cout << "ƒень недели: ѕ€тница" << endl;
			break;
		}
		case Saturday: {
			cout << "ƒень недели: —уббота" << endl;
			break;
		}
		case Sunday: {
			cout << "ƒень недели: ¬оскреенье" << endl;
			break;
		}
		default: {
			cout << "ќшибка ввода" << endl;
			break;
		}
	}
}

void IdentifyMonth(int number_of_month) {
	switch (number_of_month)
	{
		case January:{
			cout << "ћес€ц январь" << endl;
			break;
		}
		case February: {
			cout << "ћес€ц ‘евраль" << endl;
			break;
		}
		case March: {
			cout << "ћес€ц ћарт" << endl;
			break;
		}
		case April: {
			cout << "ћес€ц јпрель" << endl;
			break;
		}
		case May: {
			cout << "ћес€ц ћай" << endl;
			break;
		}
		case June: {
			cout << "ћес€ц »юнь" << endl;
			break;
		}
		case July: {
			cout << "ћес€ц »юль" << endl;
			break;
		}
		case August: {
			cout << "ћес€ц јвгуст" << endl;
			break;
		}
		case September: {
			cout << "ћес€ц —ент€брь" << endl;
			break;
		}
		case October: {
			cout << "ћес€ц ќкт€брь" << endl;
			break;
		}
		case November: {
			cout << "ћес€ц Ќо€брь" << endl;
			break;
		}
		case December: {
			cout << "ћес€ц ƒекабрь" << endl;
			break;
		}
		default: {
			cout << "ќшибка ввода" << endl;
			break;
		}
	}
}