#pragma once
#include <iostream>

// klasa informujaca na ktorym poziomie aktualnie jestesmy
class LicznikPoziomow
{
 public:
 	// glosny konstruktor, informuje o danym poziomie
 	LicznikPoziomow();
 	// glosny destruktor, informuje o wyjsciu z danego poziomu
 	~LicznikPoziomow();
 private:
 	static int m_licznik;
};