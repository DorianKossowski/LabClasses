#include "Main.h"
#include <iostream>

using namespace std;

void CreateArray (Array* &array, const int* rows, const int columns)
{
	array = new int**;

	(*array) = new int*[columns + 1];

	(*array)[0] = new int[columns + 1];
	(*array)[0][0] = columns + 1;

	for(int i=1; i<columns+1; i++)
	{
		(*array)[0][i] = rows[i-1];
		(*array)[i] = new int[rows[i-1]];
	}
}
void FillWith(Array* array, int number)
{
	for(int row=1; row<(*array)[0][0]; row++)
	{
		for(int column=0; column<(*array)[0][row]; column++)
		{
			(*array)[row][column] = number;
		}
	}
}
void Print (Array array)
{
	for(int row=1; row<array[0][0]; row++)
	{
		for(int column=0; column<array[0][row]; column++)
		{
			cout << array[row][column] << " ";
 		}
 		cout << "" << endl;
	}
}
void SetElement(int row, int column, Array** array, int number)
{
	if(row >= (**array)[0][0] - 1 || column >= (**array)[0][row+1])
		cout << "Index out of bounds" <<endl;
	else
	{
		(**array)[row+1][column] = number;
	}
}
void PrintMax (Array* array)
{
	int globalMax = (*array)[1][0];
	cout << "\nmaximum" << endl;
	for(int row=1; row<(*array)[0][0]; row++)
	{
		int localMax = (*array)[row][0];
		cout << "max " << row-1 <<": ";

		for(int column=1; column<(*array)[0][row]; column++)
		{
			if((*array)[row][column] > localMax)
				localMax = (*array)[row][column];
 		}
 		cout << localMax << endl;
 		if(localMax > globalMax)
 			globalMax = localMax;
	}

	cout << "global max: " << globalMax << endl;
}
void Clear (Array** array)
{
	for(int i = 1; i<(**array)[0][0]; i++)
	{
		delete[] (**array)[i];
	}

	delete[] (**array)[0];
	delete[] **array;

	delete *array;
}