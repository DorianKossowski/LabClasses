#include "MyArray.h"

#include <iostream>

MyArray::MyArray(int length) : size(_size), _size(length)
{
	_array = new int[length];
}
MyArray::MyArray(MyArray& array) : size(_size), _size(array.size)
{
	_array = new int[size];

	for(int i=0; i<size; i++)
		_array[i] = array._array[i];
}
MyArray::~MyArray()
{
	delete[] _array;
}
int& MyArray::at(int index) const
{
	return _array[index]; 
}
void MyArray::print() const
{
	std::cout << "Array content:\n";
	for(int i=0; i<size; i++)
		std::cout << "array[" << i << "] = " << _array[i] << std::endl;
}
void MyArray::resize(int length)
{
	int* temp = new int[length];
	for(int i=0; i<size; i++)
		temp[i] = _array[i];

	delete[] _array;
	
	_array = temp;
	_size = length;
}