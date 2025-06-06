#pragma once
#include "pch.h"
#include "Sort.h"

template<typename T, Sort::HeapSort::HeapType type = Sort::HeapSort::UNORDERED>
class Queue
{
	enum : int
	{
		SIZE = 10,
	};
protected:
	
	T* arr;
	int size;
	int capacity;

public:
	Queue();
	virtual ~Queue();

	virtual void Push_Back(const T& value);
	virtual void Pop_Front();
	T Front();
	int Size() { return size; }
	int Capacity() { return capacity; }
	bool Empty() { return size == 0 ? true : false; }
	void Resize(int size);

	void PrintAll();
};

template<typename T, Sort::HeapSort::HeapType type>
inline Queue<T, type>::Queue()
	: size(0), capacity(SIZE)
{
	arr = new T[SIZE];
}

template<typename T, Sort::HeapSort::HeapType type>
inline Queue<T, type>::~Queue()
{
	delete arr;
	arr = nullptr;
}

template<typename T, Sort::HeapSort::HeapType type>
inline void Queue<T, type>::Push_Back(const T& value)
{
	size++;
	if (size >= capacity)
		Resize(capacity * 2);
	arr[size - 1] = value;
}

template<typename T, Sort::HeapSort::HeapType type>
inline void Queue<T, type>::Pop_Front()
{
	_ASSERT(size > 0);
	for (int i = 1; i <= size - 1; i++)
		arr[i - 1] = arr[i];
	size--;
}

template<typename T, Sort::HeapSort::HeapType type>
inline T Queue<T, type>::Front()
{
	_ASSERT(size > 0);
	return arr[0];
}

template<typename T, Sort::HeapSort::HeapType type>
inline void Queue<T, type>::Resize(int size)
{
	T* newArr = new T[size];
	memcpy(newArr, arr, sizeof(T) * size);
	delete arr;
	arr = newArr;
	capacity = size;
}


template<typename T, Sort::HeapSort::HeapType type>
inline void Queue<T, type>::PrintAll()
{
	for (int i = 0; i < size; i++)
	{
		cout << "Arr[" << i << "] : " << arr[i] << " ";
	}
	cout << endl;
}


////////////////////////////////////////////////////
//   Priority Queue
////////////////////////////////////////////////////



template<typename T, Sort::HeapSort::HeapType type = Sort::HeapSort::MAX>
class Priority_Queue : public Queue<T, type>
{
public:
	Priority_Queue() {}
	virtual ~Priority_Queue() {}

	virtual void Push_Back(const T& value) override;
	virtual void Pop_Front() override;
};

template<typename T, Sort::HeapSort::HeapType type>
inline void Priority_Queue<T, type>::Push_Back(const T& value)
{
	Queue<T, type>::Push_Back(value);
	Sort::HeapSort::Sort<T, type>(Queue<T, type>::arr, Queue<T, type>::size);
	Queue<T, type>::PrintAll();
}

template<typename T, Sort::HeapSort::HeapType type>
inline void Priority_Queue<T, type>::Pop_Front()
{
	Queue<T, type>::Pop_Front();
	Sort::HeapSort::Sort<T, type>(Queue<T, type>::arr, Queue<T, type>::size);
	Queue<T, type>::PrintAll();
}
