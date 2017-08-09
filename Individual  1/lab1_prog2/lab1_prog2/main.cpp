#include "array.h"

void main()
{
	double* array1D = initArray1D();
	double** array2D = transformArray2D(array1D);
	printInfo(array1D,array2D);

	freeSpaceArray1D(array1D);
	freeSpaceArray2D(array2D);
}