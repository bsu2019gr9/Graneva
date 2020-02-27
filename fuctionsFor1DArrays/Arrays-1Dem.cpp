#include <iostream>
#include <cstdlib>
#include <ctime>
#include"Arrays-1Dem.h"
using namespace std;
void mkArrOfInt(int n, int*& p) {
	p = new (nothrow) int[n];
	if (!p) exit(404);
}
void freeMemory(int*& p) {
	delete[] p;
	p = nullptr;
}
void printArr(int* beg, int* end) {
	for (int* p = beg; p < end; ++p)
		cout << *p << '\t';
	cout << '\n';
}
void initArray(int* beg, int* end) {
	for (int* p = beg, i = 1; p < end; ++p, ++i)
		*p = i;
}
void initArrayRand(int* beg, int* end, int min, int max) {
	srand(time(NULL));
	int d = (max - min + 1);
	for (int* p = beg; p < end; ++p)
		*p = rand() % d + min;

}
void inputArray(int* beg, int* end) {
	for (int* p = beg; p < end; ++p)
		cin >> *p;
}
int findMax(int* beg, int* end) {
	int max = *beg;
	for (int* p = beg; p < end; ++p)
		if (*p > max)max = *p;
	return max;
}
int findMin(int* beg, int* end) {
	int min = *beg;
	for (int* p = beg; p < end; ++p)
		if (*p < min)min = *p;
	return min;
}
int sumArray(int* beg, int* end) {
	int sum = 0;
	for (int* p = beg; p < end; ++p) {
		sum += *p;
	}
	return sum;
}
void countpositiveNegative(int* beg, int* end) {
	int pos = 0, neg = 0;
	for (int* p = beg; p < end; ++p)
	{
		if (*p)
		{
			if (*p > 0)
				++pos;
			else
				++neg;
		}
	}
	cout << "positive - " << pos << " negative - " << neg << '\n';
}
void reverse(int* beg, int* end)
{

	for (int* p = beg, *q = end - 1; p < q; ++p, --q)
	{
		swap(*p, *q);
	}
}
void bubbleSort(int* beg, int* end) {
	int b = 1;
	while (b) {
		b = 0;
		for (int* p = beg; p + 1 < end; ++p)
			if (*p > * (p + 1)) {
				swap(*p, *(p + 1));
				b = 1;
			}
		end--;
	}
}
void insertionSort(int* beg, int* end) {
	for (int* p = beg + 1; p < end; ++p) {
		int* i = p;
		while (i > beg&&* (i - 1) > * i) {
			swap(*(i - 1), *i);
			i--;
		}
	}
}
void gnomeSort(int* beg, int* end) {
	int* p = beg;
	while (p < end) {
		if (p == 0 || *(p - 1) < *p)
			++p;
		else {
			swap(*(p - 1), *p);
			--p;
		}
	}
}
void shiftLeft(int* beg, int* end) {
	reverse(beg, end);
	reverse(beg + 1, end);
}
void shifRight(int* beg, int* end) {
	reverse(beg, end);
	reverse(beg, end - 1);
}

