
#include "array.h"

#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cmath>


size_t sourceLenght = 15;

int nA;
int nB;

int step = 2;

void initA()
{
	printf("Введите A: ");
	scanf("%d",&nA);

	if (nA >= 0)
	{
		printf("A должно быть меньше 0\n");
		initA();
	}
	else
		return;
}
int GetA()
{
	return nA;
}

void initB()
{
	printf("Введите B: ");
	scanf("%d",&nB);
}
int GetB()
{
	return nB;
}


void printInfo(double* innerArray, double* outputArray, int count)
{
	printf("Вход [");
	for (int i(0); i < sourceLenght; i++)
	{
		printf(" %0.f", *(innerArray + i));
	}
	printf(" ]\n");

	printf("Выход [");
	for (int i(0); i < count; i++)
	{
		printf(" %0.f", *(outputArray + i));
	}
	printf(" ]\n");

	printf("count = %d\n", count);
}

double* initArray()
{
	double* mainArray = new double[sourceLenght];

	for (int i(0); i < sourceLenght; i++)
	{
		*(mainArray + i) = 1;
	}
	return mainArray;
}

int processArray(double* sourceArray, double* &outputArray)
{
	int count = 0;
	srand(0);

	initA();
	initB();

	for (int i(0); i < sourceLenght; i+=step)
	{
		*(sourceArray + i) = rand() % (abs(GetA()) + GetB()) + GetA();

		if (*(sourceArray + i) < 0)
		{
			count++;
		}
	}

	double* output = new double[count];

	for (int i(0), j(0); i < sourceLenght; i+=step)
	{
		if (*(sourceArray + i) < 0)
		{
			*(output + j) = *(sourceArray + i);
			j++;
		}
	}

	outputArray = output;

	return count;
}
