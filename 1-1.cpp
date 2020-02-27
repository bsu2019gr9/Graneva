//функции для одномерных массивов
#include <iostream>
#include <cstdlib>
#include <ctime>
#include"Arrays-1Dem.h"
int task1(int*, int*);//подсчитывает количество элементов, встречающихся более одного раза
int task2(int*, int*);//определяет максимальную длину последовательности равных элементов
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int N;
	cout << "Введите размер массива ";
	cin >> N;
	int* A = nullptr;
	mkArrOfInt(N, A);
	initArrayRand(A, A+N,-10, 10);
	printArr(A, A+N);
	cout << "Количество элементов, встречающихся более одного раза = " << task1(A, A + N) << '\n';
	cout<<"Максимальная длина последовательности равных элементов = " << task2(A, A + N) << '\n';
	freeMemory(A);
	return 0;
}
//подсчитывает количество элементов, встречающихся более одного раза
int task1(int* beg, int* end) {
	bubbleSort(beg, end);
	int k = 0;
	for (int* p = beg; p < end; ++p)
	{
		if (*p == *(p + 1))
			++k;
		while (*p == *(p + 1))
			++p;
	}
	return k;
}
//определяет максимальную длину последовательности равных элементов
int task2(int* beg, int* end){
	int maxLenght =0, lenght=1;
	for (int* p = beg; p < end; ++p)
	{
		if (*p == *(p + 1))
			++lenght;
		else
		{
			if (lenght > maxLenght)
				maxLenght = lenght;
			lenght = 1;
		}
		if (lenght > maxLenght)
			maxLenght = lenght;
	}
	return maxLenght;
}
