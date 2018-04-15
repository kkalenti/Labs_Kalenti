#pragma once

int GetLength(char *string);
int IndexOf(char* string, char cymbol);
int LastIndexOf(char* string, char cymbol);
bool GetSubstring(char*string, char* substring, int start_index, int substring_length);
bool GetFilenames(char *full_filename, char *filename);
bool GetFileExtension(char* full_filename, char* file_extension);
bool GetFilepath(char* full_filename, char* filepath);
void InvalidFilenames(char *string);