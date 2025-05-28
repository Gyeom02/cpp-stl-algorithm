#pragma once
#include "pch.h"
#include "Sort.h"

template<typename T>
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
};

template<typename T>
inline Queue<T>::Queue()
	: size(0), capacity(SIZE)
{
	arr = new T[SIZE];
}

template<typename T>
inline Queue<T>::~Queue()
{
	delete arr;
	arr = nullptr;
}

template<typename T>
inline void Queue<T>::Push_Back(const T& value)
{
	size++;
	if (size >= capacity)
		Resize(capacity * 2);
	arr[size - 1] = value;
}

template<typename T>
inline void Queue<T>::Pop_Front()
{
	_ASSERT(size > 0);
	for (int i = 1; i <= size - 1; i++)
		arr[i - 1] = arr[i];
	size--;
}

template<typename T>
inline T Queue<T>::Front()
{
	_ASSERT(size > 0);
	return arr[0];
}

template<typename T>
inline void Queue<T>::Resize(int size)
{
	T* newArr = new T[size];
	memcpy(newArr, arr, sizeof(T) * size);
	delete arr;
	arr = newArr;
	capacity = size;
}

template<typename T, Sort::HeapSort::HeapType type>
class Priority_Queue : public Queue
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
}

template<typename T, Sort::HeapSort::HeapType type>
inline void Priority_Queue<T, type>::Pop_Front()
{
}
