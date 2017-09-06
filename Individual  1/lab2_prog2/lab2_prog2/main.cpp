#include "fraction.h"
#include <iostream>

using namespace std;

void main()
{
	Fraction f1(1, 2), f2(1, 4);
	cout << "\ttwo fraction" << endl;
	f1.print();
	f2.print();
	cout << "\tstatic method`s" << endl;
	Fraction::printAsFraction(0.25);
	Fraction::printAsFraction("0.25");
	cout << Fraction::gcd(10, 20) << endl;
	cout << "\toperator`s" << endl;
	Fraction f3 = f1 + f2;
	f3.print();
	Fraction f4 = f1 - f2;
	f4.print();
	Fraction f5 = f1 * f2;
	f5.print();
	Fraction f6 = f1 / f2;
	f6.print();

	cout << "\tstatic countFranction" << endl;
	cout << Fraction::countFraction << endl;

	return;
}