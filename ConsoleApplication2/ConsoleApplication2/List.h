#pragma once

template <typename T>
class List {
	template <typename T>
	class ListItem {
	public:
		T* element;
		ListItem<T> *next;
		ListItem<T> *prev;
	};

private:
	ListItem<T>* _head;
	int _count;
public:
	List(ListItem<T>* _head);
	void Add(T element);
	T* Find(int index);
	void RemoveAt(int index);
	void Clear();
	int GetCount();

};