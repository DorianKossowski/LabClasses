#pragma once
#include <string>
class PredkoscMaksymalna;

//klasa abstrakcyjna reprezentujaca pojazd
class Pojazd{

 public:
 	//funkcja czysto wirtualna zwracajaca rodzaj pojazdu
 	virtual std::string rodzaj() const = 0;
 	//dektruktor wirtualny
 	virtual ~Pojazd() {}

};
