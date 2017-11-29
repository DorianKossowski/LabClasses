#ifndef MAIN_H
#define MAIN_H

//struct of fraction
struct Fraction
{
	int total;
	int top;
	int bottom;
};

//typedef of Matrix
typedef Fraction*** Matrix;

//initialization of matrix
void InitMatrix (Matrix* matrix, const int size);
//initialization of cells
void InitCells (Matrix* matrix, const int size);
//setting fractions
void SetFraction(Fraction* area, int top, int bottom);
//print one fraction
void Print(Fraction* area);
//fill all areas in matrix 
void FillRowByColumnPlus1 (Matrix* matrix, const int size);
//fill all areas in matrix 
void FillRowByColumnPlus5 (Matrix* matrix, const int size);
//print all matrix
void PrintMatrix(Matrix matrix, const int size);
//sum two matrix
void Sum (Matrix first, Matrix second, const int size, Matrix* sumFirstSecond);
//free memory
void Clear (Matrix matrix, const int size);

#endif