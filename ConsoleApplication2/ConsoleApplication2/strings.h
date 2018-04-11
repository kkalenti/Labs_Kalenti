#pragma once

int GetLength(char *string);//TODO:
int IndexOf(char* string, char c);
int LastIndexOf(char* string, char c);
bool GetSubstring(char*string, char* substring, int startIndex, int substringLength);
bool GetFilenames(char *fullFilename, char *filename);
bool GetFileExtension(char* fullFilename, char* fileExtension);
bool GetFilepath(char* fullFilename, char* filepath);
void InvalidFilenames(char *string);