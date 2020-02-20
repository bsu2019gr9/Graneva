#include"Arrr1.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
void printArr(int *A, const size_t N)
{
	for (size_t i = 0; i < N; i++)
		cout << A[i] << " ";
	cout << '\n';
}
void initArray(int *A, const size_t N)
{
	for (size_t i = 0; i < N; i++)
		cin >> A[i];
}
void initArrayRand(int *A, const size_t N)
{
	for (size_t i = 0; i < N; i++)
	{
		A[i] = rand();
	}
}
int findMax(int *A, const size_t N)
{
	int max = A[0];
	for (size_t i = 0; i < N; i++)
		if (A[i] > max)max = A[i];
	return max;
}
int findMin(int *A, const size_t N)
{
	int min = A[0];
	for (size_t i = 0; i < N; i++)if (A[i] < min)min = A[i];
	return min;
}
void findMaxMin(int *A, const size_t N)
{
	int max = A[0], min = A[0];
	for (size_t i = 0; i < N; i++)
	{
		(A[i] > max) ? max = A[i] : 1;
		(A[i] < min) ? min = A[i] : 1;
	}
	cout << "min=" << min << " max=" << max << '\n';
}
int sumArray(int *A, const size_t N)
{
	size_t sum = 0;
	for (size_t i = 0; i < N; i++) {
		sum += A[i];
	}
	return sum;
}
void positiveNegativeArray(int *A, const size_t N)
{
	size_t p = 0, n = 0;
	for (size_t i = 0; i < N; i++)
	{
		if (A[i])
		{
			if (A[i] > 0)
				++p;
			else
				++n;
		}
	}
	cout << "positive - " << p << " negative - " << n << '\n';
}
void stupidSort(int *A, const size_t N)
{
	size_t tmp;
	for (int i = 0; i + 1 < N; ++i) if (A[i] > A[i + 1])
	{
		tmp = A[i];
		A[i] = A[i + 1];
		A[i + 1] = tmp;
		if (i != 0) i -= 2;
	}
}
void giveMemory(int* A, const size_t)
{
	if (!A)
		int* A = new int[];
	else cout << "Memory already allocated";
}
void freeMemory(int* A, const size_t)
{
	delete[] A;
}