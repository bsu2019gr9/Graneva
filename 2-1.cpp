
#include <iostream>
#include <iomanip>
using namespace std;
int** mkArrOfInt(int, int);
void freeMemory(int**&, int);
void printArray(int**, int, int);
void inputArray(int**, int, int);
void initRandomArray(int**, int, int, const int min = -10, const int max = 10);
//В массиве А(N,M) найти первую строку, 
//не содержащую отрицательных элементов,
//и поменять её с последней строкой
void changeFirstRowWithoutNegativeElementsAndLastRow(int**, int, int);
int main()
{
	int N, M;
	cin >> N >> M;
	int** A = mkArrOfInt(N, M);
	inputArray(A, N, M);
	printArray(A, N, M);
	cout << '\n';
	changeFirstRowWithoutNegativeElementsAndLastRow(A, N, M);
	printArray(A, N, M);
	freeMemory(A, N);
	return 0;
}
int** mkArrOfInt(int N, int M) {
	int** p = new (nothrow) int* [N];
	if (!p) exit(404);
	for (int i = 0; i < N; i++) {
		p[i] = new (nothrow) int[M];
		if (!p[i]) exit(404);
	}
	return p;
}
void freeMemory(int**& p, int N) {
	for (int i = 0; i < N; i++)
		delete[] p[i];
	delete[] p;
	p = nullptr;
}
void printArray(int** p, int N, int M) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << setw(3) << p[i][j] << ";";
		cout << '\n';
	}
}
void inputArray(int** p, int N, int M) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin>> p[i][j];
		cout << '\n';
	}
}
void initRandomArray(int** p, int N, int M, int min, int max) {
	srand(time(NULL));
	int d = (max - min + 1);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) p[i][j] = rand() % d + min;
}
//В массиве А(N,M) найти первую строку, 
//не содержащую отрицательных элементов,
//и поменять её с последней строкой
void changeFirstRowWithoutNegativeElementsAndLastRow(int** A, int N, int M)
{
	int* tmp;
	int i=0, j = 0, k=0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			if (A[i][j] < 0)
				break;
			else
				if (j == M - 1)
				{
					swap(A[i], A[N - 1]);
					k = 1;
				}
		if (k) break;
	}
}


