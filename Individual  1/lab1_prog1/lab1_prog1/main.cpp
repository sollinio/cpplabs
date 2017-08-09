#include "array.h"

#include <clocale>

using namespace std;

void main()
{
	setlocale(LC_ALL,"Russian");

	double* pMainArray = initArray();
	double* pOutArray = NULL;
	int count = processArray(pMainArray, pOutArray);
	printInfo(pMainArray, pOutArray, count);

	return;
}