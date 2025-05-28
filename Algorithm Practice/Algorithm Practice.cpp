// Algorithm Practice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include "AVLTree.h"
#include "Map.h"
#include "Sort.h"
#include "queue"
#include "Heap.h"
int main()
{
	/*Map<int, char> map;

	map.Insert(1, 'a');
	map.Insert(4, 'b');
	map.Insert(10, 'c');
	map.Insert(2, 'd');
	map.Insert(6, 'e');
	map.Insert(7, 'f');
	map.Insert(3, 'g');
	map.Insert(8, 'h');
	map.Insert(5, 'i');
	map.Insert(9, 'j');
	map.InrderTraversal();*/
	//int array[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
	char array[10] = { 'd', 'c', 'z', 'h', 'e', 'a', 'r', 'b', 'f', 'j' };
	int arr_size = 10;
	Sort::HeapSort::Sort<char, Sort::HeapSort::HeapType::MAX>(array, arr_size);
	
	for (int i = 0; i < 10; i++)
		cout << array[i] << " ";
	cout << endl;
	/*Heap<int, Sort::HeapSort::HeapType::MIN> heap;
	heap.Push(1);
	heap.Push(10);
	heap.Push(5);
	heap.Push(6);
	heap.Push(7);
	heap.Push(6);
	heap.Push(4);
	heap.Push(3);
	heap.Push(2);
	heap.Push(9);

	heap.Pop();
	heap.Pop();
	heap.Pop();
	heap.Pop();
	heap.Pop();
	heap.Pop();
	heap.Pop();
	heap.Pop();
	heap.Pop();
	heap.Pop();*/
	return 0;
}

