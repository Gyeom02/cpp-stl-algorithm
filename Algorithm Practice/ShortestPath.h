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
	//�ʿ��Լ���
	//1. � Node ���ؿ��� ��������Ǿ��ִ� Node���� Dist�� ������Ʈ�ϴ� �Լ�
	//2. ����Ǿ��ִ� Node�� �߿� ���� visit���� ���� Node�� �� ���� Dist�� ª�� Node�� �̵��ϴ� �Լ�
	
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