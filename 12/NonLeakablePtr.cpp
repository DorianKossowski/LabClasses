#include "NonLeakablePtr.h"
#include "NonLeakable.h"

#include <iostream>

NonLeakablePtr::NonLeakablePtr()
{
	_pointer = 0;
}

NonLeakablePtr::NonLeakablePtr(NonLeakablePtr& toCopy)
{
	_pointer = toCopy._pointer;

	toCopy._pointer = 0;
}

NonLeakablePtr::~NonLeakablePtr()
{
	if(_pointer)
	{
		delete _pointer;
		_pointer = 0; 
	}
}

void NonLeakablePtr::MakeNewObject()
{
	if(_pointer)
		delete _pointer;

	_pointer = new NonLeakable();
}

void NonLeakablePtr::Print() const
{
	if(_pointer)
		std::cout << "Object pointing to " << _pointer << std::endl;
	else
		std::cout << "Object pointing to nothing" << std::endl;	
}

NonLeakable* NonLeakablePtr::operator->() const
{
	return _pointer;
}

NonLeakablePtr& NonLeakablePtr::operator=(NonLeakablePtr& toCopy)
{
	if((*this)._pointer == toCopy._pointer)
		return *this;

	if(_pointer)
		delete _pointer;
	_pointer = toCopy._pointer;

	toCopy._pointer = 0;
	
	return *this;
}

NonLeakable& NonLeakablePtr::operator*() const
{
	return *_pointer;
}

NonLeakable* NonLeakablePtr::operator&() const
{
	return _pointer;
}

