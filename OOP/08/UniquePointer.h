#pragma once
#include <iostream>

// template class, contains specific object's adress
template<typename T>
class UniquePointer
{
	// template friend overload operator, print object's adress
	template<typename U>
	friend std::ostream& operator<< (std::ostream& out, const UniquePointer<U>& obj);
public:
	// constructor, assign adress
	UniquePointer(T* pointer) : m_pointer(pointer) {}
	// const copy constructor
	UniquePointer(const UniquePointer<T>& toCopy) {}
	// copy constructor, reassign object's adress
	UniquePointer(UniquePointer<T>& toCopy)
	{
		m_pointer = toCopy.m_pointer;
		toCopy.m_pointer = 0;
	}
	// destructor, free pointer
	~UniquePointer() {delete m_pointer;}

	// overload operator*, return content of pointer
	T operator* () const {return *m_pointer;}
	// operator T*, return pointer
	operator T*() const {return m_pointer;}

	// overload operator=, reassign pointers
	UniquePointer<T>& operator= (UniquePointer<T>& toCopy)
	{

		if(toCopy == *this)
			return *this;
		if(m_pointer)
			delete m_pointer;
		m_pointer = toCopy.m_pointer;
		toCopy.m_pointer = 0;
		return *this;
	}
	// overload operator->, return pointer
	T* operator-> () const {return m_pointer;}

private:
	T* m_pointer;
};

template<typename T>
std::ostream& operator<< (std::ostream& out, const UniquePointer<T>& obj)
{
	return out << "[" << obj.m_pointer << "]";
}