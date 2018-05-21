#pragma once
#include <string>

// common class which contains object's name
class Object
{
public:
	Object(const std::string& name) : m_name(name) {}

	void Print() const {std::cout << "Printing object named \"" << m_name << "\"." << std::endl;}
private:
	const std::string m_name;
};