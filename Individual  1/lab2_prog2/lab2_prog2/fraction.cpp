#include "fraction.h"

#include <iostream>
#include <iomanip> 
#include <sstream>
#include <cmath>
#include <cstdio>

using namespace std;

int Fraction::countFraction = 0;

Fraction::Fraction(int numerator, int denumerator) : numerator(numerator), denumerator(denumerator)
{
	countFraction++;
}

int Fraction::gcd(int n, int m)
{
	int i;
	if (n > m) i = n;
	else i = m;

	for (; i > 0; i--)
	{
		if (m % i == 0 && n % i == 0)
		{
			return i;
		}
	}
	return 1;
}

void Fraction::printAsFraction(double decimal_fraction)
{
	double tmp_upper, tmp_down;
	int tmp_deNumerator = 1, tmp_numerator;
	tmp_down = std::modf(decimal_fraction, &tmp_upper);

	stringstream ss;
	ss << tmp_down;
	string str = ss.str();
	int position = str.find(".");
	int count_after = str.size() - 2;
	for (int i(0); i < count_after; i++) tmp_deNumerator *= 10;
	tmp_numerator = (tmp_upper * tmp_deNumerator) + (tmp_down * tmp_deNumerator);

	int gdc = gcd(tmp_numerator, tmp_deNumerator);
	tmp_numerator = tmp_numerator / gdc;
	tmp_deNumerator = tmp_deNumerator / gdc;

	cout << tmp_numerator << "/" << tmp_deNumerator << endl;
}

void Fraction::printAsFraction(char* char_decimal_fraction)
{
	stringstream ss(char_decimal_fraction);
	double decimal_fraction;
	ss >> decimal_fraction;

	double tmp_upper, tmp_down;
	int tmp_deNumerator = 1, tmp_numerator;
	tmp_down = std::modf(decimal_fraction, &tmp_upper);

	ss << tmp_down;
	string str = ss.str();
	int position = str.find(",");
	int count_after = str.size() - 2;
	for (int i(0); i < count_after; i++) tmp_deNumerator *= 10;
	tmp_numerator = (tmp_upper * tmp_deNumerator) + (tmp_down * tmp_deNumerator);

	int gdc = gcd(tmp_numerator, tmp_deNumerator);
	tmp_numerator = tmp_numerator / gdc;
	tmp_deNumerator = tmp_deNumerator / gdc;

	cout << tmp_numerator << "/" << tmp_deNumerator << endl;
}

void Fraction::reduce(int gdc, int& tmp_numerator, int& tmp_denumerator)
{
	 tmp_numerator = tmp_numerator / gdc;
	 tmp_denumerator = tmp_denumerator / gdc;
}

void Fraction::print()
{
	cout << numerator << "/" << denumerator << endl;
}

Fraction Fraction::operator+(const Fraction& frac)
{
	int all_tmp_numerator, all_tmp_deNumerator;
	all_tmp_deNumerator = denumerator * frac.denumerator;
	all_tmp_numerator = ((all_tmp_deNumerator / frac.denumerator) * (frac.numerator)) + ((all_tmp_deNumerator / denumerator) * (numerator));
	reduce(gcd(all_tmp_numerator, all_tmp_deNumerator), all_tmp_numerator, all_tmp_deNumerator);
	Fraction tmp_frac(all_tmp_numerator, all_tmp_deNumerator);
	countFraction++;
	return tmp_frac;
}

Fraction Fraction::operator-(const Fraction& frac)
{
	int all_tmp_numerator, all_tmp_deNumerator;
	all_tmp_deNumerator = denumerator * frac.denumerator;
	all_tmp_numerator = ((all_tmp_deNumerator / frac.denumerator) * (frac.numerator)) - ((all_tmp_deNumerator / denumerator) * (numerator));
	reduce(gcd(all_tmp_numerator, all_tmp_deNumerator), all_tmp_numerator, all_tmp_deNumerator);
	Fraction tmp_frac(all_tmp_numerator, all_tmp_deNumerator);
	countFraction++;
	return tmp_frac;
}

Fraction Fraction::operator*(const Fraction& frac)
{
	int all_tmp_numerator, all_tmp_deNumerator;
	all_tmp_deNumerator = denumerator * frac.denumerator;
	all_tmp_numerator = numerator * frac.numerator;
	reduce(gcd(all_tmp_numerator, all_tmp_deNumerator), all_tmp_numerator, all_tmp_deNumerator);
	Fraction tmp_frac(all_tmp_numerator, all_tmp_deNumerator);
	countFraction++;
	return tmp_frac;
}

Fraction Fraction::operator/(const Fraction& frac)
{
	int all_tmp_numerator, all_tmp_deNumerator;
	all_tmp_deNumerator = denumerator * frac.numerator;
	all_tmp_numerator = numerator * frac.denumerator;
	reduce(gcd(all_tmp_numerator, all_tmp_deNumerator), all_tmp_numerator, all_tmp_deNumerator);
	Fraction tmp_frac(all_tmp_numerator, all_tmp_deNumerator);
	countFraction++;
	return tmp_frac;
}


Fraction::~Fraction()
{
	countFraction--;
}