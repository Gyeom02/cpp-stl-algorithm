#pragma once
#include "pch.h"

template<typename T>
class Stack
{
private:
	enum : int
	{
		SIZE = 10,
	};
	T* arr;
	int arrSize; //배열에 담긴 오브젝트 수
	int capacity; //memory적 배열 수
public:
	Stack();
	~Stack();

	void Push(const T& value);
	T Top();
	void Pop();
	int Size() { return arrSize; }
	int Capacity() { return capacity; }
	void Resize(int size);
	bool Empty() { return arrSize == 0 ? true : false; }
};

template<typename T>
inline Stack<T>::Stack()
{
	capacity = SIZE;
	arr = new T[SIZE];

}

template<typename T>
inline Stack<T>::~Stack()
{
	delete arr;
	arr = nullptr;
}

template<typename T>
inline void Stack<T>::Push(const T& value)
{
	arrSize++;
	if (capacity <= arrSize)
	{
		
		Resize(capacity * 2);
	}
	arr[arrSize - 1] = value;
}

template<typename T>
inline T Stack<T>::Top()
{
	_ASSERT(arrSize > 0);
	return arr[arrSize - 1];
}

template<typename T>
inline void Stack<T>::Pop()
{
	_ASSERT(arrSize > 0);
	arrSize--;
}

template<typename T>
inline void Stack<T>::Resize(int size)
{
	T* resized = new T[size];
	memcpy(resized, arr, sizeof(T) * arrSize);

	_ASSERT(arr != nullptr);

	delete arr;
	arr = resized;
	capacity = size;
}
