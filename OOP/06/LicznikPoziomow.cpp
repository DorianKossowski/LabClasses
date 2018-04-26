#include "LicznikPoziomow.h"

int LicznikPoziomow::m_licznik = 1;

LicznikPoziomow::LicznikPoziomow()
{
	std::cout << "Rozpoczynamy poziom numer " << m_licznik++ << "." << std::endl;
}
LicznikPoziomow::~LicznikPoziomow()
{
	std::cout << "Konczymy poziom numer " << --m_licznik << "." << std::endl;
}