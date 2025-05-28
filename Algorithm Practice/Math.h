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

	namespace Series // 연속된 값들의 합을 구하는 함수들 네임스페이스
	{
		int Arithmetic(int n) //연속된 정수의 합을 말함
		{
			/*
			* //logic ex)
			 int start = 0;
			while (start <= n)
			{
				temp += start;
				start++;
			}
			*/
			int temp = 0;
			temp = n * (n + 1) / 2;
			return temp;
			
		}

		int Polynomial(int n, int k) //제곱들의 합을 리턴함 | n = 0부터 n까지의 k 제곱의 수를 리턴함
		{
			int temp = 1;
			for (int i = 0; i < k + 1;)
				temp *= n;
			return temp / (k + 1);
		}
	}
	
}