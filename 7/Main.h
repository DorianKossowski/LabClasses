#ifndef MAIN_H
#define MAIN_H

typedef int** Array;

//create new array (first row as backup of dates)
void CreateArray (Array* &array, const int* rows, const int columns);
//fill array with numbers
void FillWith(Array* array, int number);
//print array
void Print (Array array);
//set individual elements
void SetElement(int row, int column, Array** array, int number);
//print max values
void PrintMax (Array* array);
//free memory
void Clear (Array** array);

#endif