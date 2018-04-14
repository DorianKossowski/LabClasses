#pragma once
#include <iostream>

//klasa zawierajaca wartosc predkosci maksymalnej
class PredkoscMaksymalna{

 public:
 	//kontruktor przyjmujacy wartosc predkosci maksymalnej
 	PredkoscMaksymalna(int wart) : m_wart(wart) {}
 	//funkcja zwracajaca predkosc maksymalna
 	int getWart() const {return m_wart;}
 private:
 	//predkosc maksymalna
 	int m_wart;
};
std::string operator<< (std::ostream& wyj, const PredkoscMaksymalna& obiekt);
