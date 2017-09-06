#pragma once

#include "matrix.h"

class Matrix;

class Vector
{
private:
	int nLenght;
	double* pArray;
public:
	Vector();
	Vector(int lenght);
	~Vector();

	Vector& operator++();
	Vector& operator--();
	double operator[](int index);

	void initialize();
	void printVector();
	Matrix* make2DArray();

	 
};

