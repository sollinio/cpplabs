#include "matrix.h"

#include <iostream>
#include <iomanip>



using namespace std;

Matrix::Matrix()
{

}

Matrix::Matrix(int n) : N(n)
{
	pMatrix = new double*[n];

	for (int i(0); i < n; i++)
		*(pMatrix + i) = new double[n];
}

Matrix::Matrix(Vector& vector, int n) : N(n)
{
	pMatrix = new double*[n];

	for (int i(0); i < n; i++)
		*(pMatrix + i) = new double[n];

	int arrayMarkSum = 0;
	int arrayMark = 0;


	for (int i(0); i < n; i++)
	{
		for (int j(0); j < n; j++)
		{
			*(*(pMatrix + i) + j) = vector[arrayMark++];

			if (j == 0)
			{

				*(*(pMatrix + i) + j) = 0;
				arrayMarkSum++;

				for (int k(0); k < n - 1; k++)
				{
					*(*(pMatrix + i) + j) += vector[arrayMarkSum++];
				}

			}
		}
	}
}

void Matrix::printMatrix()
{
	cout << "\n\n\n" << "=>" << "\n\n\n";

	cout << "[";
	for (int i(0); i < N; i++)
	{
		for (int j(0); j < N; j++)
		{
			if (i == 0 && j == 0)
			{
				cout << setprecision(5) << setw(9) << *(*(pMatrix + i) + j);
			}
			else if (i == N - 1 && j == N - 1)
			{
				cout << setprecision(5) << setw(10) << *(*(pMatrix + i) + j) << "  ]";
			}
			else
			{
				cout << setprecision(5) << setw(10) << *(*(pMatrix + i) + j);
			}
		}
		cout << "\n";
	}
}

double Matrix::at(int i, int j) const
{
	return *(*(pMatrix + i) + j);
}

void Matrix::setAt(int i, int j, double value)
{
	*(*(pMatrix + i) + j) = value;
}

int Matrix::getlenght()
{
	return N;
}

Matrix::~Matrix()
{
	for (int i(0); i < N; i++)
	{
		delete[] *(pMatrix + i);
	}
}
