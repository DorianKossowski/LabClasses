#pragma once
#include "Vehicle.h"

// klasa opisujaca airplane, dziedziczy po vehicle 
class Airplane: public Vehicle
{
 public:
 	// wywoluje konstruktor klasy bazowej z otrzymanym argumentem, ustawia domyslna maksymalna predkosc
 	Airplane(const unsigned id);
 	// ustawia cene za posrednictwem metody klasy bazowej
 	void SetPrice(const unsigned price);
 	// ustawia wartosc wingspan
 	void SetWingspan(const unsigned wingspan);
 	// wypisuje informajce o id samolotu
 	void Fly() const;
 	// wypisuje informacje o samolocie
  	void Print() const;
  	// wirtualna metoda, wywoluje Fly()
  	void Move() const;
  	
 private:
 	unsigned m_wingspan;
};
