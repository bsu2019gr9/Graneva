//Класс французские деньги(1 франк = 20су)
#include <iostream>
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
	FrenchMoney operator+(const FrenchMoney& m);
	FrenchMoney operator-(const FrenchMoney& m);
	FrenchMoney operator*(const int k);
	friend void operator<<(ostream& out, const FrenchMoney& m);
	friend void operator>>(istream& in, FrenchMoney& m);
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
FrenchMoney FrenchMoney::operator+(const FrenchMoney& m)
{
	return FrenchMoney(frank + m.frank + (soo + m.soo) / 20, (soo + m.soo) % 20);
}
FrenchMoney FrenchMoney::operator-(const FrenchMoney& m)
{
	return FrenchMoney(frank - m.frank - (soo - m.soo) / 20, (soo - m.soo) % 20);
}
FrenchMoney FrenchMoney::operator*(const int k)
{
	return FrenchMoney(frank * k + (soo * k) / 20, (soo * k) % 20);
}
void operator<<(ostream& out, const FrenchMoney& m)
{
	out << m.frank << " frank " << m.soo << " soo " << "\n";
}
void operator>>(istream& in, FrenchMoney& m)
{
	in >> m.frank;
	in >> m.soo;
	m.frank += m.soo / 20;
	m.soo = m.soo % 20;
}
FrenchMoney ffgg(FrenchMoney m)
{
	return m;
}
FrenchMoney fff(FrenchMoney& m)
{
	return m;
}
FrenchMoney* ggg(FrenchMoney* m)
{
	return m;
}
int main()
{
	FrenchMoney m1(4, 7);
	cout << m1;
	FrenchMoney m2;
	cin >> m2;
	cout << m2;
	FrenchMoney m3[4] = { {6, 17}, {9, 3}, 3, {4, 12} };
	for (int i = 0; i < 4; ++i)
		cout << m3[i];
	FrenchMoney* m4 = new (nothrow) FrenchMoney[3];
	*m4 = m2;
	cout<<"m4=" << *ggg(m4);
	cout<<"m1 * 2=" << m1 * 2 ;
	cout << "m1 +m2=" << m1 +m2;
	cout << "m1 -m3[3]=" << m1-m3[2];
	cout << "ffgg: " << fff(m3[0]);
	cout << "fff: " << fff(m1);
	cout << "ggg: " << *ggg(m4);
	delete[] m4;
	return 0;
}

