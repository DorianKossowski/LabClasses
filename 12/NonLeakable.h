#pragma once
#include <iostream>

//class containing objects' index and amount of objects
class NonLeakable
{
	friend class NonLeakablePtr;
public:
	//constructor - print information about creating, increase counter
	NonLeakable();
	//destructor - print information about destroying
	~NonLeakable();
	//print object's index
	void Print() const;
	//overloading delete - using free
	void operator delete(void* ptr);
private:
	//overloading new - using malloc
	void* operator new(size_t size);
	
	int _index;
	static int _counter;
};

