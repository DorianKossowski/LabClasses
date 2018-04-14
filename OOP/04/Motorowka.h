#pragma once
#include "Pojazd.h"
#include "PredkoscMaksymalna.h"

//klasa reprezentujaca motorowke, dziedziczaca po klasie pojazd
class Motorowka: public Pojazd
{

 public:
 	//konstruktor przyjmujacy obiekt klasy predkosc maksymalna i przypisujacy wartosc predkosci maksymalnej
 	Motorowka(const PredkoscMaksymalna& pred) : m_pred(pred) {}
 	//funkcja wypisujaca rodzaj pojazdu
 	virtual std::string rodzaj() const;
 	//funkcja wypisujaca predkosc maksymalna
 	std::string predkoscMaksymalna() const;
 private:
 	//predkosc maksymalna
 	PredkoscMaksymalna m_pred;
};
