#pragma once
#include "pch.h"
#include "Math.h"
#include "Queue.h"

namespace Sort
{
	template<typename T>
	void SelectSort_Array(T* arr, int size) //size means array value num
	{
		
		for (int i = 0; i < size; i++)
		{
			T temp = arr[i];  int min = 9999; int min_index = 0;
			for (int j = i; j < size; j++)
			{
				if (arr[j] < min)
				{
					min = arr[j];
					min_index = j;
				}
			}
			arr[i] = min;
			arr[min_index] = temp;
		}
	}

	template<typename T>
	void BubbleSort_Array(T* arr, int size)
	{
		for (int i = 0; i < size; i++)
		{

			for (int j = 0; j <= (size - i) - 1; j++)
			{
				T temp = arr[j];
				if (arr[j] > arr[j - 1]) // j + 1 즉 앞의 수가 더 크다
				{
					arr[j] = arr[j - 1];
					arr[j - 1] = temp;

				}
			}
		}
		
	}
	
	template<typename T>
	void InsertSort_Array(T* arr, int size)
	{
		for (int i = 1; i < size; i++)
		{

			for (int j = i; j > 0; j--)
			{
				if (arr[j] < arr[j - 1])
				{
					int temp = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = temp;
				}

				else break;
			}
		}
	}

	namespace QuickSort
	{
		template<typename T>
		void Func_QuickSort(T* array, int start, int end)
		{
			if (start >= end) // 원소가 1개인 경우 그대로 두기
				return;

			int pivot = start; // 피봇은 첫번째 원소
			int i = start + 1, j = end, temp;

			while (i <= j) { // 엇갈릴 때까지 반복
				while (i <= end && (array[i] <= array[pivot])) { // 피봇보다 큰 값을 찾을 때까지
					i++;
				}
				while (j > start && (array[j] >= array[pivot])) { // 피봇보다 작은 값을 찾을 때까지
					j--;
				}

				if (i > j) { // 엇갈린 상태. 피봇보다 작은 값과 피봇과 교체
					temp = array[j];
					array[j] = array[pivot];
					array[pivot] = temp;
				}
				else { // 엇갈리지 않았다면 i와 j를 교체
					temp = array[i];
					array[i] = array[j];
					array[j] = temp;
				}
			}

			Func_QuickSort(array, start, j - 1);
			Func_QuickSort(array, j + 1, end);
		}
	}

	template<typename T>
	void QuickSort_Array(T* array, int size)
	{
		QuickSort::Func_QuickSort(array, 0, size - 1);
	}
	


	namespace Merge
	{
		template<typename T>
		void Merge(T* arr, T* mergeArr, int start, int end)
		{
			for (int i = start; i <= end; i++)
				mergeArr[i] = arr[i];
			int mid = (start + end) / 2;
			int nowStart = start;
			int nowEnd = mid + 1;
			int curIndex = start;
			while (nowStart <= mid && nowEnd <= end)
			{
				if (mergeArr[nowStart] <= mergeArr[nowEnd])
					arr[curIndex++] = mergeArr[nowStart++];
				else
					arr[curIndex++] = mergeArr[nowEnd++];
			}
			int left = mid - nowStart;
			for (int i = 0; i <= left; i++)
			{
				arr[curIndex++] = mergeArr[nowStart++];
			}
			
		}
		template<typename T>
		void Partition(T* arr, T* mergeArr, int start, int end)
		{
			//재귀함수
			if (start >= end)
				return;
			int mid = (start + end) / 2;
			Partition(arr, mergeArr, start, mid);
			Partition(arr, mergeArr, mid + 1, end);
			Merge(arr, mergeArr, start, end);
		}
	}
	template<typename T>
	void MergeSort_Array(T* arr, int size)
	{
		T* mergeArr = new T[size];
		Merge::Partition(arr, mergeArr, 0, size - 1);
		delete mergeArr;
		mergeArr = nullptr;
	}

	namespace Radix
	{
		template<typename T>
		void Sort(T* arr, int size, int max)
		{
			Queue<T> Q[10];
			int radix = 1;
			while (true)
			{
				if (radix >= max)
					break;
				radix *= 10;
			}

			for (int i = 1; i < radix; i *= 10)
			{
				for (int j = 0; j < size; j++)
				{
					int key;
					if (arr[j] < i)
						key = 0;
					else
					{
						key = (arr[j] / i) % 10;
					}
					Q[key].Push_Back(arr[j]);

				}

				int idx = 0;
				for (int j = 0; j < 10; j++)
				{
					while (!Q[j].Empty())
					{
						arr[idx] = Q[j].Front();
						Q[j].Pop_Front();
						idx++;
					}
				}

			}

			
		}
	}
	template<typename T>
	void RadixSort_Array(T* arr, int size)
	{
		int max = Math::Max(arr, size);
		Radix::Sort(arr, size, max);

	}
}


