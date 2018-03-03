#pragma once
#include <string>
#include <iostream>

//abstrakcyjna klasa bazowa
class Wrapper
{
public:
	virtual ~Wrapper() {};
	//czysto wirtualna metoda sluzaca do wypisywania wartosci
	virtual void print(std::ostream& out) const = 0;
};

//###########################################################//

//klasa przechowujaca liczbe calkowita, dziedziczy po Wrapper
class IntWrapper: public Wrapper
{
public:
	//konstruktor inicjalizujacy przechowywana wartosc
	IntWrapper(const int value) : _value(value) {}
	//wypisuje przechowywana wartosc 
	void print(std::ostream& out) const;
	
private:
	const int _value;
};

//###########################################################//

//klasa przechowujaca liczbe rzeczywista, dziedziczy po Wrapper
class FloatWrapper: public Wrapper
{
public:
	//konstruktor inicjalizujacy przechowywana wartosc
	FloatWrapper(const float value) : _value(value) {}
	//wypisuje przechowywana wartosc 
	void print(std::ostream& out) const;
	
private:
	const float _value;
};

//###########################################################//

//klasa przechowujaca string, dziedziczy po Wrapper
class StringWrapper: public Wrapper
{
public:
	//konstruktor inicjalizujacy przechowywany string
	StringWrapper(const std::string text) : _text(text) {}
	//wypisuje przechowywana tekst 
	void print(std::ostream& out) const;
	
private:
	const std::string _text;
};

//###########################################################//

//wektor sluzacy do przechowywania obiektow typu Wrapper
class PVec
{
	//przyjazn z przeladowanym operatorem <<
	friend std::ostream& operator<< (std::ostream& out, const PVec& vec);
public:
	//konstruktor inicjalizujacy tablice wskaznikow
	PVec() : _size(0) {_vec = 0;}
	//destruktor zwalniajacy pamiec
	~PVec();
	//dodaje kolejne wskazniki na obiekty typu Wrapper, zwraca *this
	PVec& push_back(Wrapper* new_object);
	//dodaje kolejne wskazniki na obiekty typu Wrapper
	void operator<< (Wrapper* new_object);
	//zwraca referencje do obiektu Wrapper pod danym indeksem w wektorze
	const Wrapper& operator[] (const unsigned index) const;
private:
	void adding(Wrapper* new_object);
	Wrapper** _vec;
	unsigned _size;
	
};
//wypisuje wektor
std::ostream& operator<< (std::ostream& out, const PVec& vec);