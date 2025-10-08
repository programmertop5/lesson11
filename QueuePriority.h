#pragma once
#include <iostream>
using namespace std;

template<class T>
class QueuePriority
{
	T* items;
	int* priorityArray;
	int maxSize;
	int currentSize;
public:
	QueuePriority(int size);
	~QueuePriority();
	void Add(T item, int priority = 0);
	T Extract();
	void Clear();
	bool IsEmpty();
	bool IsFull();
	int getCount();
	void Print();
};

template<class T>
QueuePriority<T>::QueuePriority(int size)
{
	maxSize = size;
	currentSize = 0;
	priorityArray = new int[maxSize];
	items = new T[maxSize];
}

template<class T>
QueuePriority<T>::~QueuePriority()
{
	delete[] priorityArray;
	delete[] items;
}

template<class T>
void QueuePriority<T>::Add(T item, int priority)
{
	if (!IsFull()) {
		items[currentSize] = item;
		priorityArray[currentSize] = priority;
		currentSize++;
	}
}

template<class T>
T QueuePriority<T>::Extract()
{
	if (!IsEmpty()) {
		int maxPri = priorityArray[0];
		int maxPriPos = 0;
		for (int i = 0; i < currentSize; i++) {
			if (maxPri < priorityArray[i]) {
				maxPri = priorityArray[i];
				maxPriPos = i;
			}
		}
		T item = items[maxPriPos];
		for (int i = maxPriPos; i < currentSize - 1; i++) {
			items[i] = items[i + 1];
			priorityArray[i] = priorityArray[i + 1];
		}
		currentSize--;
		return item;
	}
	return T();
}

template<class T>
void QueuePriority<T>::Clear()
{
	currentSize = 0;
}

template<class T>
bool QueuePriority<T>::IsEmpty()
{
	return currentSize == 0;
}

template<class T>
bool QueuePriority<T>::IsFull()
{
	return currentSize == maxSize;
}

template<class T>
int QueuePriority<T>::getCount()
{
	return currentSize;
}

template<class T>
void QueuePriority<T>::Print()
{
	cout << "Current size: " << currentSize << endl;
	cout << "(priority|item):" << endl;
	for (int i = 0; i < currentSize; i++) {
		cout << "(" << priorityArray[i] << "|" << items[i] << ")" << endl;
	}
	cout << endl;
}
