//Класс французские деньги(1 франк = 20су)
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class FrenchMoney
{
private:
	int frank;
	int soo;
public:
	FrenchMoney();
	FrenchMoney(int a, int b=0);
	~FrenchMoney();
	void operator=(const FrenchMoney& m);
	FrenchMoney operator+(const FrenchMoney& m) const;
	FrenchMoney operator-(const FrenchMoney& m) const;
	FrenchMoney operator*(const int k) const;
	bool operator==(const FrenchMoney& m) const;
	bool operator!=(const FrenchMoney& m) const;
	bool operator>(const FrenchMoney& m) const;
	bool operator>=(const FrenchMoney& m) const;
	bool operator<(const FrenchMoney& m) const;
	bool operator<=(const FrenchMoney& m) const;
	friend ostream& operator<<(ostream& out, const FrenchMoney& m);
	friend istream& operator>>(istream& in, FrenchMoney& m);
};

FrenchMoney::FrenchMoney() :
	frank(0),
	soo(0)
{
	cout << "no params constructor working \n";
}
FrenchMoney::FrenchMoney(int a, int b) :
	frank(a + b / 20),
	soo(b % 20)
{
	cout << "constructor working for " << this->frank << ' ' << this->soo << "\n";
}
FrenchMoney::~FrenchMoney()
{
	cout << "destructor working\n";
}

void FrenchMoney::operator=(const FrenchMoney& m)
{
	frank = m.frank;
	soo = m.soo;
}
FrenchMoney FrenchMoney::operator+(const FrenchMoney& m) const
{
	return FrenchMoney(frank + m.frank + (soo + m.soo) / 20, (soo + m.soo) % 20);
}
FrenchMoney FrenchMoney::operator-(const FrenchMoney& m) const
{
	return FrenchMoney(frank - m.frank - (soo - m.soo) / 20, (soo - m.soo) % 20);
}
FrenchMoney FrenchMoney::operator*(const int k) const
{
	return FrenchMoney(frank * k + (soo * k) / 20, (soo * k) % 20);
}
bool FrenchMoney::operator==(const FrenchMoney& m) const
{
	return(frank == m.frank && soo == m.soo);
}

bool FrenchMoney::operator!=(const FrenchMoney& m) const
{
	return(frank != m.frank || soo != m.soo);
}
bool FrenchMoney::operator>(const FrenchMoney& m) const
{
	return(frank * 20 + soo > m.frank * 20 + m.soo);
}
bool FrenchMoney::operator>=(const FrenchMoney& m) const
{
	return(frank * 20 + soo >= m.frank * 20 + m.soo);
}
bool FrenchMoney::operator<(const FrenchMoney& m) const
{
	return(frank * 20 + soo < m.frank * 20 + m.soo);
}
bool FrenchMoney::operator<=(const FrenchMoney& m) const
{
	return(frank * 20 + soo <= m.frank * 20 + m.soo);
}
ostream& operator<<(ostream& out, const FrenchMoney& m)
{
	out << m.frank << " frank " << m.soo << " soo " << "\n";
	return out;
}
istream& operator>>(istream& in, FrenchMoney& m)
{
	in >> m.frank;
	in >> m.soo;
	m.frank += m.soo / 20;
	m.soo = m.soo % 20;
	return in;
}
void initArrayRand(FrenchMoney* beg, FrenchMoney* end, int min, int max) {
	srand(time(NULL));
	int d = (max - min + 1);
	for (FrenchMoney* p = beg; p < end; ++p)
		* p = { rand() % d + min, rand() % d + min };

}
void inputArray(FrenchMoney* beg, FrenchMoney* end) {
	for (FrenchMoney* p = beg; p < end; ++p)
		cin >> *p;
}
void printArray(FrenchMoney* beg, FrenchMoney* end) {
	for (FrenchMoney* p = beg; p < end; ++p)
		cout << *p << '\t';
	cout << '\n';
}
FrenchMoney findMax(FrenchMoney* beg, FrenchMoney* end) {
	FrenchMoney max = *beg;
	for (FrenchMoney* p = beg; p < end; ++p)
		if (*p > max) max = *p;
	return max;
}
FrenchMoney findMin(FrenchMoney* beg, FrenchMoney* end) {
	FrenchMoney min = *beg;
	for (FrenchMoney* p = beg; p < end; ++p)
		if (*p < min)min = *p;
	return min;
}
FrenchMoney sumArray(FrenchMoney* beg, FrenchMoney* end) {
	FrenchMoney sum = 0;
	for (FrenchMoney* p = beg; p < end; ++p)
		sum =sum+*p;
	return sum;
}
void bubbleSort(FrenchMoney* beg, FrenchMoney* end) {
	int b = 1;
	while (b) {
		b = 0;
		for (FrenchMoney* p = beg; p + 1 < end; ++p)
			if (*p > * (p + 1)) {
				swap(*p, *(p + 1));
				b = 1;
			}
		end--;
	}
}
void insertionSort(FrenchMoney* beg, FrenchMoney* end) {
	for (FrenchMoney* p = beg + 1; p < end; ++p) {
		FrenchMoney* i = p;
		while (i > beg&&* (i - 1) > * i) {
			swap(*(i - 1), *i);
			i--;
		}
	}
}
void gnomeSort(FrenchMoney* beg, FrenchMoney* end) {
	FrenchMoney* p = beg;
	while (p < end) {
		if (p == 0 || *(p - 1) < *p)
			++p;
		else {
			swap(*(p - 1), *p);
			--p;
		}
	}
}
int main()
{
	const int N = 10;
	FrenchMoney* A = new (nothrow) FrenchMoney[N];
	initArrayRand(A, A + N, 0, 60);
	printArray(A, A + N);
	//inputArray(A, A + N);
	//printArray(A, A + N);
	cout<<"sumArray=" << sumArray(A, A + N) << '\n' << "Min=" << findMin(A, A + N) << '\n' <<"Max="<< findMax(A, A+N)<<'\n';
	bubbleSort(A, A + N);
	printArray(A, A + N);
	return 0;
}

