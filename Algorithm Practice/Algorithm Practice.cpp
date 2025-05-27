// Algorithm Practice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include "AVLTree.h"
#include "Map.h"
#include "Sort.h"
#include "queue"
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
	Sort::RadixSort_Array(array, arr_size);

	for (int i = 0; i < 10; i++)
		cout << array[i] << " ";
	cout << endl;

	
	return 0;
}

