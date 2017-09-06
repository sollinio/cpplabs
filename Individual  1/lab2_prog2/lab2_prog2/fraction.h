#pragma once



class Fraction
{
private:
	int numerator;
	int denumerator;
public:
	Fraction(int numerator, int denumerator);
	static int gcd(int n, int m);
	void reduce(int gdc, int& numerator, int& denumerator);
    static void printAsFraction(double decimal_fraction);
	static void printAsFraction(char* decimal_fraction);
	void print();
	~Fraction();
	static int countFraction;
	
	Fraction operator+(const Fraction& frac);
	Fraction operator-(const Fraction& frac);
	Fraction operator*(const Fraction& frac);
	Fraction operator/(const Fraction& frac);
};

