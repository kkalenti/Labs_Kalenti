#include "stdafx.h"
#include <string.h>

int GetLength(char *string) {
	int stringCounter = 0;
	while (string[stringCounter] != '\0') {
		stringCounter++;
	}
	if (stringCounter == 0)
		return -1;
	else
		return stringCounter;
}

int IndexOf(char* string, char c) {
	int stringCounter = 0;
	int index = -1;
	do {
		stringCounter++;
		if (string[stringCounter] == c) {
			index = stringCounter;
		}
	} while ((string[stringCounter] != '\0') && index == -1);
	if (stringCounter == -1)
		return -1;
	else
		return stringCounter;
}

int LastIndexOf(char* string, char c) {
	int stringCounter = 0;
	int index=-1;
	while ((string[stringCounter] != '\0')){
		if (string[stringCounter] == c) {
			index = stringCounter;
		}
		stringCounter++;
	}
	if (index == -1)
		return -1;
	else
		return index;
}

bool GetSubstring(char*string, char* substring, int startIndex, int substringLength) {
	if (startIndex + substringLength > GetLength(string) - 1 || GetLength(string) == -1 || GetLength(substring) == -1)
		return false;
	bool exit = false;
	int stringCounter = startIndex;
	int substringCounter = 0;
	while (string[stringCounter] != '\0' && substringCounter < substringLength) {
		substring[substringCounter] = string[stringCounter];
		stringCounter++;
		substringCounter++;
	}
	substring[substringCounter] = '\0';
	return true;
}