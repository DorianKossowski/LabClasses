#pragma once

#include "SlopeFit.h"

//klasa dziedziczaca po Fit, rodzaj prostej o b!=0
class LineFit: public Fit
{
public:
	//konstruktor, odpowiada za wywolanie konstruktora klasy bazowej z odebranym stringiem
	LineFit(std::string name);
};