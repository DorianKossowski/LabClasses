#pragma once
#include "Samochod.h"
#include "Motorowka.h"
#include "PredkoscMaksymalna.h"

//klasa reprezentujaca amfibie, dzidziczaca po klasie samochod i po klasie motorowka
class Amfibia: public Samochod, public Motorowka
{
 public:
 	//konstruktor przyjmujacy dwa obiekty predkosci maksymalnej i przypisujacy odpowiednie wartosci predkosci maksymalnej klasom bazowym
 	Amfibia(const PredkoscMaksymalna& predSam, const PredkoscMaksymalna& predMot) : Samochod(predSam), Motorowka(predMot) {}
 	//funkcja wypisujaca rodzaj pojazdu
 	virtual std::string rodzaj() const;
};
