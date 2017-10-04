#include "CustomExpressionEvaluator.h"

#include <iostream>
#include <fstream>
#include <ctime>
#include <random>

CustomExpressionEvaluator::CustomExpressionEvaluator()
{
}


CustomExpressionEvaluator::~CustomExpressionEvaluator()
{
}

double CustomExpressionEvaluator::calculate()
{
	double* tmp_pArray = getpArray();
	int tmp_operandlenght = getoperandsLenght();
	double answer = *tmp_pArray;

	for (int i = 1; i < tmp_operandlenght; i++)
	{
		answer += *(tmp_pArray + i) / (i + 1);
	}

	return answer;
}

void CustomExpressionEvaluator::logToScreen()
{
	int tmp_operandlenght = getoperandsLenght();
	double* tmp_pArray = getpArray();


	std::cout << "Operands: " << tmp_operandlenght << std::endl;
	for (int i = 0; i < tmp_operandlenght; i++)
	{
		if (i == 0)
		{
			std::cout << *(tmp_pArray + i) << "+";
			continue;
		}
		if (*(tmp_pArray + i) >= 0)
			std::cout << *(tmp_pArray + i) << "/" << i + 1;
		else
			std::cout << "(" << *(tmp_pArray + i) << ")" << "/" << i + 1;
		if (tmp_operandlenght != i + 1)
			std::cout << "+";
	}
}

void CustomExpressionEvaluator::logToFile(const std::string& filename)
{
	int tmp_operandlenght = getoperandsLenght();
	double* tmp_pArray = getpArray();

	std::fstream fout(filename,std::ios::app);

	fout << "Operands: " << tmp_operandlenght << std::endl;
	for (int i = 0; i < tmp_operandlenght; i++)
	{
		if (i == 0)
		{
			fout << *(tmp_pArray + i) << "+";
			continue;
		}
		if (*(tmp_pArray + i) >= 0)
			fout << *(tmp_pArray + i) << "/" << i + 1;
		else
			fout << "(" << *(tmp_pArray + i) << ")" << "/" << i + 1;
		if (tmp_operandlenght != i + 1)
			fout << "+";
	}
	fout << std::endl << std::endl;
	fout.close();
}

void CustomExpressionEvaluator::shuffle()
{
	srand(time(0)); 
	
	int len = getLenght();
	int olen = getoperandsLenght();
	double* pArray = getpArray();

	for (int i = 0; i < olen; i++)
	{
		std::swap(*(pArray + i), *(pArray + (rand() % olen)));
	}

}

void CustomExpressionEvaluator::shuffle(size_t i, size_t j)
{
	double* pArray = getpArray();
	std::swap(*(pArray + i), *(pArray + j));
}