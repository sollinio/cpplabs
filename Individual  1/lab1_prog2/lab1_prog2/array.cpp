#include "array.h"

#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

#define PI 3.14159265358979323846

int n = 5;

size_t lenghtArray1D = 25;

void printInfo(double* array1D, double** array2D)
{
	cout << "[";
	for (int i(0); i < lenghtArray1D; i++)
	{
		cout << " " << setprecision(5) << *(array1D + i) ;
	}
	cout << " ]";
	cout << "\n\n\n" << "=>" <<"\n\n\n";

	cout << "[";
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < n; j++)
		{
			if (i == 0 && j == 0)
			{
				cout << setprecision(5) << setw(9) << *(*(array2D + i) + j);
			}
			else if (i == n - 1 && j == n - 1)
			{
				cout << setprecision(5) << setw(10) << *(*(array2D + i) + j) << "  ]";
			}
			else
			{
				cout << setprecision(5) << setw(10) << *(*(array2D + i) + j);
			}
		}
		cout << "\n";
	}
	

}

double* initArray1D()
{
	double* outputArray1D = new double[lenghtArray1D];

	for (int i(0); i < lenghtArray1D; i++)
	{
		*(outputArray1D + i) = i * sin(PI * i / 25);
	}

	return outputArray1D;
}

double** transformArray2D(double* innerArray1D)
{
	double** outputArray2D = new double*[n];

	for (int i(0); i < n; i++)
		*(outputArray2D + i) = new double[n];
	
	int arrayMarkSum = 0;
	int arrayMark = 0;
	

	for (int i(0); i < n; i++)
	{
		for (int j(0); j < n; j++)
		{
			*(*(outputArray2D + i) + j) = *(innerArray1D + arrayMark++);

			if (j == 0)
			{

				*(*(outputArray2D + i) + j) = 0;
				arrayMarkSum++;

				for (int k(0); k < n - 1; k++)
				{
					*(*(outputArray2D + i) + j) += *(innerArray1D + arrayMarkSum);
					arrayMarkSum++;
				}
				
			}
		}
	}

	return outputArray2D;
}

void freeSpaceArray1D(double* &innerArray)
{
	delete[] innerArray;
}

void freeSpaceArray2D(double** &innerArray)
{
	for (int i(0); i < n; i++)
	{
		delete[] *(innerArray + i);
	}
}