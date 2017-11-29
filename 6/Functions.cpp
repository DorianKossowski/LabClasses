#include "Main.h"
#include "iostream"

using namespace std;

void InitMatrix (Matrix* matrix, const int size)
{
	*matrix = new Fraction**[size];

	for(int row=0; row<size; row++)
	{
		(*matrix)[row] = new Fraction*[size];
	}
}
void InitCells (Matrix* matrix, const int size)
{
	for(int row=0; row<size; row++)
	{
		for(int column=0; column<size; column++)
		{
			(*matrix)[row][column] = new Fraction;
		}
	}
}
void SetFraction(Fraction* area, int top, int bottom)
{
	if(top >= bottom)
	{
		area->total = top / bottom;
		area->top = top % bottom;
	}
	else
	{
		area->total = 0;
		area->top = top;
	}
	area->bottom = bottom;
} 
void Print(Fraction* area)
{
	if(area->total)
		cout<< area->total << " ";
	if(area->top)
		cout << area->top << "/" << area->bottom;

	delete area;
}
void FillRowByColumnPlus1 (Matrix* matrix, const int size)
{
	InitCells(matrix, size);

	for(int row=0; row<size; row++)
	{
		for(int column=0; column<size; column++)
		{
			(*matrix)[row][column]->top = row+1;
			(*matrix)[row][column]->bottom = column+1;
		}
	}
}
void FillRowByColumnPlus5 (Matrix* matrix, const int size)
{
	InitCells(matrix, size);

	for(int row=0; row<size; row++)
	{
		for(int column=0; column<size; column++)
		{
			(*matrix)[row][column]->top = row+1;
			(*matrix)[row][column]->bottom = column+5;
		}
	}
}
void PrintMatrix(Matrix matrix, const int size)
{
	for(int row=0; row<size; row++)
	{
		for(int column=0; column<size; column++)
		{
			if(matrix[row][column]->top/matrix[row][column]->bottom)
				cout<< matrix[row][column]->top / matrix[row][column]->bottom << " ";
			int top = matrix[row][column]->top % matrix[row][column]->bottom;
			if(top)
				cout << top << "/" << matrix[row][column]->bottom << "\t";
		}
		cout<<""<<endl;
	}
}
void Sum (Matrix first, Matrix second, const int size, Matrix* sumFirstSecond)
{
	InitMatrix(sumFirstSecond, size);
	InitCells(sumFirstSecond, size);

	for(int row=0; row<size; row++)
	{
		for(int column=0; column<size; column++)
		{
			int top = first[row][column]->top * second[row][column]->bottom + second[row][column]->top * first[row][column]->bottom;
			int bottom = first[row][column]->bottom * second[row][column]->bottom;
			(*sumFirstSecond)[row][column]->total = first[row][column]->total + second[row][column]->total;
			(*sumFirstSecond)[row][column]->top = top;
			(*sumFirstSecond)[row][column]->bottom = bottom;
		}	
	}
}
void Clear (Matrix matrix, const int size)
{
	for(int row=0; row<size; row++)
	{
		for(int column=0; column<size; column++)
		{
			delete matrix[row][column];
		}
		delete[] matrix[row];
	}
	delete[] matrix;
}