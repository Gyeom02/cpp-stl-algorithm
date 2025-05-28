#pragma once

namespace Math
{
	int GetDigits(int v, int digits) //digits�� �ڸ����� �ǹ��Ѵ�
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

	namespace Series // ���ӵ� ������ ���� ���ϴ� �Լ��� ���ӽ����̽�
	{
		int Arithmetic(int n) //���ӵ� ������ ���� ����
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

		int Polynomial(int n, int k) //�������� ���� ������ | n = 0���� n������ k ������ ���� ������
		{
			int temp = 1;
			for (int i = 0; i < k + 1;)
				temp *= n;
			return temp / (k + 1);
		}
	}
	
}