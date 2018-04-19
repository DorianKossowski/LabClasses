#pragma once
#include <stdexcept>
#include <string>
#include <iostream>

class numerical_exception: public std::runtime_error
{
public:
	numerical_exception(const char* info, const char* file = "NULL", const int line = 0, const std::string& name = "numerical_exception")
		: std::runtime_error(info), m_name(name), m_file(file), m_line(line){}
	
	// virtual ~numerical_exception() throw() {}	//just for C++03

	std::string getName() const {return m_name;}
	std::string getFile() const {return m_file;}
	int getLine() const {return m_line;}
private:
	const std::string m_name;
	const std::string m_file;
	const int m_line;
};

class calculation_exception: public numerical_exception
{
public:
	calculation_exception(const char* info, const char* file = "NULL", const int line = 0, const std::string& name = "calculation_exception")
		: numerical_exception(info, file, line, name) {}
};

class myexcept
{
public:
	static void handler(const char* info);
};
