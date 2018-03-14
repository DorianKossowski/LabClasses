#pragma once
#include "Product.h"

// klasa vehicle, dziedziczy po klasie product
// opisuje rozne rodzaje pojazdow
class Vehicle: public Product
{
 public:
 	// wywoluje konstruktor klasy bazowej z otrzymanym argumentem
 	Vehicle(const unsigned id);
 	// wirtualny destruktor
 	virtual ~Vehicle() {};
 	// ustawia cene za posrednictwem metody klasy bazowej
 	void SetPrice(const unsigned price);
 	// ustawia maksymalna predkosc
 	void SetMaxSpeed(const unsigned speed);
 	// wypisuje informacje na temat maksymalnej predkosci
 	void Print() const;
 	// wirtualna metoda, wypisuje predkosc poruszania
 	virtual void Move() const;
 	// zwraca maksymalna predkosc
 	unsigned GetMaxSpeed() const;
 	
 private:
 	unsigned m_maxSpeed;
};
