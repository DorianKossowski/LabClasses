#pragma once

class NonLeakable;

//class containing pointer to object
class NonLeakablePtr
{
public:
	//constructor - assign null to pointer
	NonLeakablePtr();
	//copy constructor - assign toCopy's pointer to this' pointer
	NonLeakablePtr(NonLeakablePtr& toCopy);
	//destructor - call pointer destructor
	~NonLeakablePtr();
	//create object and assign it to pointer
	void MakeNewObject();		
	//print pointer's address
	void Print() const;
	//overloading -> - return pointer object
	NonLeakable* operator->() const;
	//overloading = - assign toCopy's pointer to this' pointer
	NonLeakablePtr& operator=(NonLeakablePtr& toCopy);
	//overloading * - return object
	NonLeakable& operator*() const;
	//overloading & - return pointer to object
	NonLeakable* operator&() const;
private:
	NonLeakable* _pointer;
};