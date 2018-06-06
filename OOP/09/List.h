#pragma once
#include "Tnode.h"

// class represents polymorphic list
class List
{
public:
	List() : m_head(NULL) {}
	~List() {delete m_head;}

	// adding new element to beginning of the list
	template<typename T>
	void add(const T value)
	{
		Node* toAdd = new TNode<T>(value);
		toAdd->setNext(m_head);
		m_head = toAdd;
	}

	// return beginning of the list
	Node* head() const {return m_head;}

	// static method, return value of the first T type element of the received list
	template<typename T>
	static const T get(Node* toGet)
	{
		while(!dynamic_cast<const TNode<T>*>(toGet))
			toGet = toGet->next();
		return dynamic_cast<const TNode<T>*>(toGet)->get();
	}

private:
	Node* m_head;	
};