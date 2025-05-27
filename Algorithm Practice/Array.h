#pragma once
#include "pch.h"

template<typename T>
class Array
{
private:
	T* arr;
	int arrSize;

public:
	Array(int size);
	~Array();
	T At(int idx) { return arr[idx]; }
	void Add(int idx, const T& value);
	void Remove(int idx);
	void Set(int idx, const T& value);
	void PrintValues();
	int GetSize() { return arrSize; }
};

template<typename T>
Array<T>::Array(int size)
{
	arrSize = size;
	arr = new T[arrSize];

}

template<typename T>
Array<T>::~Array()
{
	delete arr;
	arr = nullptr;
}

template<typename T>
void Array<T>::Add(int idx, const T& value)
{
	_ASSERT(idx <= arrSize - 1); // OverFlow
	_ASSERT(idx >= 0);
	for (int i = arrSize - 2; i >= idx; i--)
		arr[i + 1] = arr[i];
	arr[idx] = value;
}

template<typename T>
void Array<T>::Remove(int idx)
{
	_ASSERT(idx <= arrSize - 1); // OverFlow
	_ASSERT(idx >= 0);
	for (int i = idx + 1; i < arrSize - 1; i--)
		arr[i - 1] = arr[i];
	arr[arrSize - 1] = 0;

}

template<typename T>
void Array<T>::Set(int idx, const T& value)
{
	_ASSERT(idx <= arrSize - 1); // OverFlow
	_ASSERT(idx >= 0);

	arr[idx] = value;
}
template<typename T>
void Array<T>::PrintValues()
{
	for (int i = 0; i < arrSize; i++)
		cout << " Arr[" << i << "] : " << arr[i];

	cout << endl;
}
