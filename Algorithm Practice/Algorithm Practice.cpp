// Algorithm Practice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include "AVLTree.h"
#include "Map.h"
#include "Sort.h"
#include "queue"
#include "Heap.h"
#include "Queue.h"
#include "BST.h"
#include <thread>
#include <chrono>
#include "Dijkstra.h"
int main()
{
	Map<int, char> map;

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
	map.InorderTraversal();
	
	
	//int array[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
	/*char array[10] = { 'f', 'c', 'b', 'h', 'e', 'a', 'r', 'z', 'd', 'j' };
	int arr_size = 10;
	Sort::InsertSort_Array(array, arr_size);

	for (int i = 0; i < 10; i++)
		cout << array[i] << " ";
	cout << endl;*/
	//
	//{
	//	std::this_thread::sleep_for(2s);
	//	BST<int> heap; //MAX = greater, MIN = lower
	//	std::this_thread::sleep_for(1s);
	//	//srand(GetTickCount64());
	//	for (int i = 0; i < 1000; i++)
	//	{
	//		heap.Insert(i);
	//		//heap.PrintAll();
	//	}
	//	//heap.PrintAll();
	//	std::this_thread::sleep_for(1s);
	//	for (int i = 500; i >= 0; i--)
	//	{
	//		heap.Erase(i);
	//		//heap.PrintAll();
	//	}
	//	for (int i = 501; i < 1000; i++)
	//	{
	//		heap.Erase(i);
	//		//heap.PrintAll();
	//	}
	//}
	//while (true)
	//{

	//}
	//cout << "end" << endl;
	/*heap.Push(1);
	heap.Push(10);
	heap.Push(5);
	heap.Push(6);
	heap.Push(7);
	heap.Push(11);
	heap.Push(4);
	heap.Push(3);
	heap.Push(2);
	heap.Push(9);
	
	heap.Erase(6);
	heap.Erase(7);
	heap.Erase(5);
	heap.Erase(2);
	heap.Erase(9);
	heap.Erase(11);
	heap.Erase(1);
	heap.Erase(10);
	heap.Erase(4);
	heap.Erase(3);*/
	/*int max = 7;
	int map[7][7];
	int* mapp = (int*)map;
	
	memset(mapp, 0, max * sizeof(int) * max);
	map[0][1] = 2;
	map[0][2] = 6;
	map[0][4] = 5;
	map[1][0] = 2;
	map[2][0] = 6;
	map[4][0] = 5;
	map[2][1] = 2;
	map[2][3] = 4;
	map[1][2] = 2;
	map[3][2] = 4;
	map[1][3] = 1;
	map[3][1] = 1;
	map[1][5] = 7;
	map[3][6] = 3;
	map[4][5] = 5;
	map[5][6] = 2;
	map[5][1] = 7;
	map[6][3] = 3;
	map[5][4] = 5;
	map[6][5] = 2;

	cout << Dijkstra::Dijkstra((int*)map, max, 0, 6) << endl;*/

	return 0;
}

