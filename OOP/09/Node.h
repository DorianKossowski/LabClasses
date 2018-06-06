#pragma once
#include <typeinfo>

// class represents element of the list
class Node
{
public:
	Node() : m_next(NULL) {}
	virtual ~Node() {delete m_next;}
	
	// return next element of the list
	Node* next() {return m_next;}
	// assigning next element of the list
	void setNext(Node* nextOne) {m_next = nextOne;}

	// pure virtual method, return containing value's type
	virtual const std::type_info& getType() const = 0;

	// comparing containing value's type with type T
	template<typename T>
	bool isType() const
	{
		return (getType() == typeid(T));
	}
	
private:
	Node* m_next;
};