#pragma once
#include <string>

#include "PojazdLadowy.h"
#include "PredkoscMaksymalna.h"

//klasa reprezentujaca samochod, dziedziczaca wirtualnie po klasie pojazd ladowy
class Samochod: virtual public PojazdLadowy
{
 public:
 	//konstruktor przyjmujacy obiekt klasy predkosc maksymalna i przypisujacy wartosc predkosci maksymalnej
 	Samochod(const PredkoscMaksymalna& pred) : m_pred(pred) {}
 	//funkcja wypisujaca rodzaj pojazdu
 	virtual std::string rodzaj() const;
 	//funkcja wypisujaca predkosc maksymalna
 	std::string predkoscMaksymalna() const;
 private:
 	//predkosc maksymalna
 	PredkoscMaksymalna m_pred;
};
