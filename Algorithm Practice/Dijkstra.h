#pragma once
#include "pch.h"


namespace Dijkstra
{
	const int inf = 9999;
	
	int GetShortestWay(int* arr, int size, bool* visited)
	{
		int shortest = inf;
		int key = -1;
		for (int i = 0; i < size; i++)
		{
			if (visited[i])
				continue;
			if (arr[i] < shortest && arr[i] > 0)
			{
				key = i;
				shortest = arr[i];
			} 
		}
		return key;
	}

	int Dijkstra(int* costMap, int size, int start, int target)
	{
		int* shortway = new int[size];
		bool* visited = new bool[size];
		memset(shortway, inf, size * sizeof(int));
		memset(visited, false, size * sizeof(bool));

		shortway[start] = 0;
		visited[start] = true;
		while (true)
		{
			for (int i = 0; i < size; i++)
			{
				if (visited[i])
				{
					continue;
				}
				if (costMap[start * size + i] > 0 && shortway[i] > shortway[start] + costMap[start * size + i])
				{
					shortway[i] = shortway[start] + costMap[start * size + i];
					cout << i << " : " << shortway[i] << endl;
				}
			}

			int s_m = GetShortestWay(&costMap[start * size], size, visited);
			if (s_m < 0)
				break;
			visited[s_m] = true;
			
			start = s_m;
		}
		
		int shorest = shortway[target];
		delete[] visited;
		visited = nullptr;
		delete [] shortway;
		shortway = nullptr;

		return shorest;
	}
}