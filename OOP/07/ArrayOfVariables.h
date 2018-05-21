#pragma once

#include "Variable.h"
#include <vector>

// class keeping vector of pointers to Type instances
class ArrayOfVariables
{
public:
	// constructor that reserve vector capacity
	ArrayOfVariables(const unsigned maxSize) {m_array.reserve(maxSize);}
	// free memory of vector's pointers
	~ArrayOfVariables()
	{
		for(unsigned i=0; i<m_array.size(); i++)
			delete m_array[i];
	}

	// template method, push (and return) new element to vector
	template<typename T>
	Variable<T>* CreateAndAdd(const std::string& name, const T value)
	{
		Variable<T>* newObject= new Variable<T>(name, value);
		m_array.push_back(newObject);
		return newObject;
	}

	// print all elements of vector
	void Print() const
	{
		for(unsigned i=0; i<m_array.size(); i++)
			m_array[i]->Print();
	}

private:
	std::vector<Type*> m_array;
};