#pragma once
#include <iostream>

//klasa podstawowa, juz z gotowymi parametrami dopasowanej funkcji
class FitResult
{
public:
	//konstruktor przypisujacy nazwe oraz ilosc parametrow
	FitResult(const std::string& name);
	//zwraca postac ogolna prostej
	std::string expression() const;
	//zwraca liczbe parametrow opisujacych prosta
	unsigned nParams() const;
	//zwraca nazwy kolejnych parametrow
	char parameterName(const unsigned index) const;
	//zwraca wartosci kolejnych parametrow
	float parameterValue(const unsigned index) const;

protected:
	std::string _name;
	float _pValues[2]; 

private:
	unsigned _numberParams;
	char _pNames[2];
};
//##########################################################//
//klasa dziedziczaca po FitResult, odpowiada za dodawanie kolejnych punktow
//do prostej oraz za zwracanie juz obliczonych parametrow
class Fit: public FitResult
{
public:
	//konstruktor, wywoluje konstruktor klasy bazowej oraz zeruje sumy pomocnicze
	Fit(const std::string& name);
	//wypisuje rodzaj prostej
	void print() const;
	//dodaje punkt do sum pomocniczych
	void appendPoint(const float x, const float y);
	//wyswietla komunikat o stalym obiekcie 
	void appendPoint(const float x, const float y) const;
	//oblicza parametry oraz zwraca prosta
	Fit& result();

private:
	unsigned _counter;
    float _xxsum;
    float _xysum;
    float _xsum;
	float _ysum;
};
//########################################################//
//klasa dziedziczaca po Fit, rodzaj prostej o b=0
class SlopeFit: public Fit
{
public:
	//konstruktor, odpowiada za wywolanie konstruktora klasy bazowej z odebranym stringiem
	SlopeFit(std::string name);
};
