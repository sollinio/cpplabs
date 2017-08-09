#pragma once

double* initArray1D();
double** transformArray2D(double*);
void printInfo(double*,double**);

void freeSpaceArray2D(double**&);
void freeSpaceArray1D(double*&);