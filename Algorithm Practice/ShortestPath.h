#pragma once
#include "pch.h"
#include <map>
#include <set>
namespace Dijkstra
{
	enum : int
	{
		MAX = 10000,
	};
	//필요함수들
	//1. 어떤 Node 기준에서 직접연결되어있는 Node들의 Dist를 업데이트하는 함수
	//2. 연결되어있는 Node들 중에 아직 visit하지 않은 Node들 중 제일 Dist가 짧은 Node로 이동하는 함수
	
	namespace Functions
	{
		void UpdateDist(map<int, set<int>>& map, int* dist, int* visited, int index)
		{
			_ASSERT(index <= MAX);
			visited[index] = true;
			
			
		}
	}
	int GetShortestPath(int* map[MAX], int start, int target, int size)
	{
		int dist[MAX];
		int visited[MAX];
		

	}
}