#pragma once
#include <string>
#include <iostream>

// Type represents all possible variables
class Type
{
public:
	virtual ~Type() {}
	// abstract method, printing info about object
	virtual void Print() const = 0;
};

// template class, represents specific variable based on T
template<typename T>
class Variable: public Type
{
public:
	// assigning informations about object
	Variable(const std::string& name, const T value) : m_name(name), m_value(value) {}

	// printing info about object
	virtual void Print() const {std::cout << m_name << ": " << m_value << std::endl;}

	// setting new value of object
	void SetValue(const T newValue) {m_value = newValue;}

protected:
	std::string m_name;
	T m_value;
};

// template class, represents specific variables with their units
template<typename T>
class VariableWithUnits: public Variable<T>
{
public:
	// assigning informations about object, call Variable constructor
	VariableWithUnits(const std::string& name, const T value, const std::string& unit) : Variable<T>(name, value), m_unit(unit) {}

	// printing info about object
	void Print() const {std::cout << Variable<T>::m_name << ": " << Variable<T>::m_value << " [" << m_unit << "]" << std::endl;}

private:
	std::string m_unit;
};
