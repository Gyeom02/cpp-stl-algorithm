#pragma once

namespace Math
{
	int GetDigits(int v, int digits) //digits는 자릿수를 의미한다
	{
		int temp = 1;
		for (int i = 0; i < digits - 1; i++)
			temp *= 10;
		return (v / temp) % 10;
	}

	template<typename T>
	int Max(T* arr, int size)
	{
		int max = 0;
		for (int i = 0; i < size; i++)
			max = arr[i] > max ? arr[i] : max;
	
		return max;
	}
}