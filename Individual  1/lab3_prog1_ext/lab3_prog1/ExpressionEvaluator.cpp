#include "ExpressionEvaluator.h"


ExpressionEvaluator::ExpressionEvaluator()
{

	lenght = 20;
	pArray = new double[lenght];

	for (int i = 0; i < lenght; i++)
	{
		*(pArray + i) = 0;
	}
}

ExpressionEvaluator::ExpressionEvaluator(int lenght) : lenght(lenght)
{
	pArray = new double[lenght];

	for (int i = 0; i < lenght; i++)
	{
		*(pArray + i) = 0;
	}
}

int ExpressionEvaluator::getoperandsLenght()
{
	return operandslenght;
}

int ExpressionEvaluator::getLenght()
{
	return lenght;
}

void ExpressionEvaluator::setOperand(size_t pos, double value)
{
	*(pArray + pos) = value;

	calculateoperandslenght();
}

void ExpressionEvaluator::setOperands(double ops[], size_t lenght)
{
	for (int i = 0; i < lenght; i++)
	{
		*(pArray + i) = ops[i];
	}

	calculateoperandslenght();
}

void ExpressionEvaluator::calculateoperandslenght()
{
	for (int i = 0; i < lenght; i++)
	{
		if (*(pArray + i) != 0)
		{
			operandslenght = i + 1;
		}
	}
}

double* ExpressionEvaluator::getpArray()
{
	return pArray;
}

ExpressionEvaluator::~ExpressionEvaluator()
{
	delete[] pArray;
}
