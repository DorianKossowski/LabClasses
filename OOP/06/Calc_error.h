#pragma once

#include <stdexcept>
#include <iostream>

// klasa wyjatku, dziedziczy po std::runtime_error, rzucana gdy pojawia sie blad w oblczeniach
class Calc_error: public std::runtime_error
{
 public:
 	// konstruktor przypisujacy otrzymane wartosci 
 	Calc_error(std::runtime_error* err, const std::string& info, const std::string& file, int line);
 	// metoda wypisujaca informacje o wyjatku
 	void print() const;
 	// statyczna metoda obslugujaca wyjatki
 	static void handler();

 private:
 	std::runtime_error* m_err;
 	const std::string m_file;
 	const int m_line;
};
