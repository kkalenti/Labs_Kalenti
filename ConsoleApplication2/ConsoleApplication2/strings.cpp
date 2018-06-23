#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;

int GetLength(char *string) {
	
	if (string == nullptr) return -1;

	int string_counter = 0;
	while (string[string_counter] != '\0') {
		string_counter++;
	}
	if (string_counter == 0) {
		return -1;
	} else {
		return string_counter;
	}
}

int IndexOf(char* string, char cymbol) {
	if (string == nullptr) return -1;
	int string_counter = 0;
	int index = -1;
	do {
		string_counter++;
		if (string[string_counter] == cymbol) {
			index = string_counter;
		}
	} while ((string[string_counter] != '\0') && index == -1);
	if (string_counter == -1) {
		return -1;
	} else {
		return string_counter;
	}
}

int LastIndexOf(char* string, char cymbol) {
	if (string == nullptr) return -1;
	int string_counter = 0;
	int index=-1;
	while ((string[string_counter] != '\0')){
		if (string[string_counter] == cymbol) {
			index = string_counter;
		}
		string_counter++;
	}
	if (index == -1)
		return -1;
	else
		return index;
}

bool GetSubstring(char*string, char* substring, int start_index, int substring_length) {
	if (string == nullptr || substring == nullptr) return false;

	if (start_index + substring_length > GetLength(string)
		|| GetLength(string) == -1
		|| GetLength(substring) == -1)	return false;

	int string_counter = start_index;
	int substring_counter = 0;
	while (string[string_counter] != '\0' && substring_counter < substring_length) {
		substring[substring_counter] = string[string_counter];
		string_counter++;
		substring_counter++;
	}
	substring[substring_counter] = '\0';
	return true;
}

bool GetFilenames(char *fullFilename, char *filename) {
	if (fullFilename == nullptr || filename == nullptr) return false;

	int first_index_of_name = LastIndexOf(fullFilename, '\\');
	if (first_index_of_name == -1)	return false;

	int last_index_of_name = LastIndexOf(fullFilename, '.');
	if (last_index_of_name == -1) return false;

	if (!GetSubstring(fullFilename, filename, first_index_of_name + 1,
		last_index_of_name - first_index_of_name - 1)) return false;

	return true;
}

bool GetFileExtension(char* full_filename, char* file_extension) {
	if (full_filename == nullptr || file_extension == nullptr) return false;

	int first_index_of_name = LastIndexOf(full_filename, '.');
	if (first_index_of_name == -1) return false;

	int last_index_of_name = GetLength(full_filename) - 1;
	if (last_index_of_name == -2) return false;

	if (!GetSubstring(full_filename, file_extension, first_index_of_name + 1,
		last_index_of_name - first_index_of_name)) return false;

	return true;
}

bool GetFilepath(char* full_filename, char* filepath) {
	if (full_filename == nullptr || filepath == nullptr) return false;

	int first_index_of_name = 0;
	int last_index_of_name = LastIndexOf(full_filename, '\\');
	if (first_index_of_name == -1) return false;

	if (!GetSubstring(full_filename, filepath, first_index_of_name,
		last_index_of_name - first_index_of_name)) return false;

	return true;
}

void InvalidFilenames(char *string) {
	string[0] = '\0';
	cout << "Невозможно найти данные о файле" << endl;
	system("pause");
}