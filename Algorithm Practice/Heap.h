#pragma once
#include "pch.h"
#include "Sort.h"


template<typename T, Sort::HeapSort::HeapType type>
class Heap
{
private:
	enum : int
	{
		HEAP_SIZE_MAX = 10,
	};
	T* arr;
	int size = 0;
	int capacity = 0;

public:
	Heap();
	~Heap();

	void Push(T value);
	void Pop();
	T Front();
	bool Empty();
	void Size() { return size; } // arr element nums
	void Capacity() { return capacity; } // arr memory size = capacity * sizeof(T)

private:
	void PrintAll();
	void Resize(int size);
	void Swap(int index1, int index2);
};

template<typename T, Sort::HeapSort::HeapType type>
inline Heap<T, type>::Heap()
{
	capacity = HEAP_SIZE_MAX;
	arr = new T[HEAP_SIZE_MAX];

}

template<typename T, Sort::HeapSort::HeapType type>
inline Heap<T, type>::~Heap()
{
	_ASSERT(arr != nullptr);

	delete arr;
	arr = nullptr;
}

template<typename T, Sort::HeapSort::HeapType type>
inline void Heap<T, type>::Push(T value)
{
	if (size >= capacity)
		Resize(capacity * 2);
	arr[size] = value;
	size++;
	Sort::HeapSort::SetHeap<T, type>(arr, size);
	PrintAll();
	
}

template<typename T, Sort::HeapSort::HeapType type>
inline void Heap<T, type>::Pop()
{
	_ASSERT(size > 0);
	arr[0] = arr[size - 1];
	size--;
	Sort::HeapSort::SetHeap<T, type>(arr, size);
	PrintAll();
}

template<typename T, Sort::HeapSort::HeapType type>
inline T Heap<T, type>::Front()
{
	if (size == 0)
		return NULL;
	return arr[0];
}

template<typename T, Sort::HeapSort::HeapType type>
inline bool Heap<T, type>::Empty()
{
	return size <= 0 ? true : false;
}

template<typename T, Sort::HeapSort::HeapType type>
inline void Heap<T, type>::PrintAll()
{
	for (int i = 0; i < size; i++)
		cout << "arr[" << i << "] : " << arr[i] << " ";
	cout << endl;
}

template<typename T, Sort::HeapSort::HeapType type>
inline void Heap<T, type>::Resize(int size)
{
	T* newArr = new T[size];
	memcpy(newArr, arr, sizeof(T) * size);
	
	delete arr;
	arr = nullptr;
	arr = newArr;
}

template<typename T, Sort::HeapSort::HeapType type>
inline void Heap<T, type>::Swap(int index1, int index2)
{
	T temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}
