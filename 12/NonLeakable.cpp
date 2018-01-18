#include "NonLeakable.h"
#include <stdlib.h>

int NonLeakable::_counter = 0;

NonLeakable::NonLeakable() : _index(_counter)
{
	std::cout<< "Constructing object " << _counter++ << std::endl;
}

NonLeakable::~NonLeakable()
{
	std::cout<< "Destroying object " << _index << std::endl;
}

void NonLeakable::Print() const
{
	std::cout << "This is object with ID=" << _index << std::endl;
}

void* NonLeakable::operator new(size_t size)
{
	return malloc(size);
}

void NonLeakable::operator delete (void* ptr)
{
	free(ptr);
}
