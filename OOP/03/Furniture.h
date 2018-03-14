#pragma once
#include "Product.h"

// klasa opisujaca furniture, dzedziczy po product
class Furniture: public Product
{
 public:
 	// wywoluje konstruktor klasy bazowej z otrzymanym argumentem
 	Furniture(const unsigned id);
 	// ustawia cene za posrednictwem metody klasy bazowej
 	void SetPrice(const unsigned price);
 	// wypisuje prosty komunikat
 	void Sit() const;
 	// wypisuje informacje o meblu
 	void Print() const;

};
