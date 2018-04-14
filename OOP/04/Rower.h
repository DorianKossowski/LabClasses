#pragma once
#include "PojazdLadowy.h"

//klasa reprezentujaca rower, dziedziczaca wirtualnie po klasie pojazd ladowy
class Rower: virtual public PojazdLadowy
{
 public:
 	//funkcja wirtualna wypisujaca rodzaj pojazdu
 	virtual std::string rodzaj() const;
};
