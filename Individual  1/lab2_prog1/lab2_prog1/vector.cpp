#include "vector.h"

#include <iostream>
#include <iomanip>

using namespace std;

#define PI 3.14159265358979323846

Vector::Vector()
{
	nLenght = 25;
}

Vector::Vector(int lenght)
{
	nLenght = lenght;
}

void Vector::initialize()
{
	pArray = new double[nLenght];

	for (int i(0); i < nLenght; i++)
	{
		*(pArray + i) = i * sin(PI * i / 25);
	}
}

Vector& Vector::operator++()
{
	for (int i(0); i < nLenght; i++)
	{
		*(pArray + i) += 1.0;
	}
	return *this;
}

Vector& Vector::operator--()
{
	for (int i(0); i < nLenght; i++)
	{
		*(pArray + i) -= 1.0;
	}
	return *this;
}

double Vector::operator[](int index)
{
	if (index < nLenght && index >= 0)
		return *(pArray + index);
	else
		return NULL;
}

void Vector::printVector()
{
	cout << "[";
	for (int i(0); i < nLenght; i++)
	{
		cout << setprecision(5) << " " << *(pArray + i);
	}
	cout << " ]";
}

Matrix* Vector::make2DArray()
{
	Matrix* tmp_matrix = new Matrix(5);
	int n = tmp_matrix->getlenght();
	int arrayMarkSum = 0;
	int arrayMark = 0;


	for (int i(0); i < n; i++)
	{
		for (int j(0); j < n; j++)
		{
			tmp_matrix->setAt(i,j,(*this)[arrayMark++]);

			if (j == 0)
			{

				tmp_matrix->setAt(i, j, 0);
				arrayMarkSum++;

				for (int k(0); k < n - 1; k++)
				{
					tmp_matrix->setAt(i, j, (*this)[arrayMarkSum++] + tmp_matrix->at(i,j));
				}

			}
		}
	}

	return tmp_matrix;

}

Vector::~Vector()
{
	delete[] pArray;
}
