#include "matrix.h"
#include "vector.h"

#include <iostream>



int main()
{
	Vector vector;
	vector.initialize();
	vector.printVector();
	Matrix* matrix = vector.make2DArray();
	matrix->printMatrix();

	return 0;
}