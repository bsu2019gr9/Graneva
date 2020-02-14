//построить таблицу приближённых значений функции e^(-x)*cos(3*x) на отрезке [a, b] с шагом h
#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
double Exp(double, double);
double Cos(double, double);
int main()
{
	double a, b, h, eps;
	a = -3.14159265359;
	b = 3.14159265359;
	h = 3.14159265359 / 6;
	eps = 0.0001;
	for (double x = a; x <= b + h/2; x += h)
	{
		cout << "x=";
		cout.width(6);
		cout << x;
		cout.width(15);
		cout << Cos(3*x, eps)*Exp(-x, eps);
		cout.width(15);
		cout << cos(3*x)*exp(-x) << endl;
	}
	system("pause");
	return 0; 
}
double Exp(double x, double eps)
{
	double Sum = 1, Term = 1;
	for (int i = 1; fabs(Term) > eps; i++)
	{
		Term = Term * x / i;
		Sum = Sum + Term;
	}
	return Sum;
}
double Cos(double x, double eps)
{
	double Sum = 1, Term = 1, n=0;
	for (int i = 1; fabs(Term) > eps; i++)
	{
		Term = -(Term * x * x) / ((2*n+2)*(2*n+1)); 
			Sum = Sum + Term;
		n++;
	}
	return Sum;
}