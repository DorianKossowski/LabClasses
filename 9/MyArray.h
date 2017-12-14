#pragma once

//class containing array of integers
class MyArray
{
public:
	//creating new array, setting size
	MyArray(int length);
	//creating copy of array
	MyArray(MyArray& array);
	//free memory
	~MyArray();
	//return particular element of array
	int& at(int index) const;
	//printing array
	void print() const;
	//changing size of array
	void resize(int length);

	const int& size;

private:
	int _size;
	int* _array;
};