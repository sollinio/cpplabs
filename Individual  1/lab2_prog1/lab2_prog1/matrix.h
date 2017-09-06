#pragma once

#include "vector.h"

class Vector;

class Matrix
{
private:
	double** pMatrix;
	int N;
public:
	Matrix();
	Matrix(int n);
	Matrix(Vector& vector, int n);
	~Matrix();

	int getlenght();
	double at(int i, int j) const;
	void setAt(int i, int j, double value);


	void printMatrix();
	
};

