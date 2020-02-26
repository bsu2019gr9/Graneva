//функции для одномерных массивов
#include <iostream>
#include <cstdlib>
#include <ctime>
void mkArrOfInt(int, int*&);
void freeMemory(int*&);
void printArr(int*, int*);
void initArray(int*, int*);
void initArrayRand(int*, int*, const int min = -10, const int max = 10);
void inputArray(int*, int*);
int findMax(int*, int*);
int findMin(int*, int*);
int sumArray(int*, int*);
void countpositiveNegative(int*, int*);
void reverse(int*, int*);
void bubbleSort(int*, int*);
void insertionSort(int*, int*);
void gnomeSort(int*, int*);
void shiftLeft(int*, int*);
void shifRight(int*, int*);
int task1(int*, int*);
int task2(int*, int*);
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
	initArrayRand(A, A + N, -10, 20);
	printArr(A, A + N);
	cout<<"Максимальная длина последовательности равных элементов = " << task2(A, A + N) << '\n';
	freeMemory(A);
	return 0;
}
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
void initArrayRand(int* beg, int* end, int min, int max){
	srand(time(NULL));
	int d = (max - min + 1);
	for (int* p = beg; p < end; ++p)
		*p = rand() % d + min;

}
void inputArray(int* beg, int* end){
	for (int* p = beg; p < end; ++p)
		cin >> *p;
}
int findMax(int* beg, int* end){
	int max = *beg;
	for (int* p = beg; p < end; ++p)
		if (*p > max)max = *p;
	return max;
}
int findMin(int* beg, int* end){
	int min = *beg;
	for (int* p = beg; p < end; ++p)
		if (*p < min)min = *p;
	return min;
}
int sumArray(int* beg, int* end){
	int sum = 0;
	for (int* p = beg; p < end; ++p) {
		sum += *p;
	}
	return sum;
}
void countpositiveNegative(int* beg, int* end){
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
void bubbleSort(int* beg, int* end){
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
