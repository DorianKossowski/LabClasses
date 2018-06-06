#pragma once
#include "Node.h"

// template class, contains T type value
template<typename T>
class TNode: public Node
{
public:

	TNode(const T value) : m_value(value) {}

	// return containing value
	const T get() const {return m_value;}

	// return containing value's type
	const std::type_info& getType() const
	{
		return typeid(m_value);
	}
	
private:
	const T m_value;
};