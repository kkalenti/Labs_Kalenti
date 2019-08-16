#pragma once

void DoubleOutput(List<double> *list);
void CreateDoubleList(List<double> *list, const int size);
void AddDoubleElement(List<double> *list, const int index);

void PersonOutput(List<Person>* list);
void CreatePersonList(List<Person> *list, const int size);
void AddPersonElement(List<Person> *list, const int index);

void DoubleArrayOutput(List<double*>* list);
void CreateDoubleArrayList(List<double*> *list, const int size);
void AddDoubleArrayElement(List<double*> *list, const int index);

void DoubleListOutput(List<List<double>>* list);
void CreateDoubleListList(List<List<double>> *list, const int size);
void AddDoubleListElement(List<List<double>> *list, const int index);