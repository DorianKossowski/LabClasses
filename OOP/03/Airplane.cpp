#include "Airplane.h"

Airplane::Airplane(const unsigned id): Vehicle::Vehicle(id)
{
	Vehicle::SetMaxSpeed(100);
}
void Airplane::SetPrice(const unsigned price)
{
	std::cout << "The plane price is changed" << std::endl;
	Product::SetPrice(price);
}
void Airplane::SetWingspan(const unsigned wingspan)
{
	m_wingspan = wingspan;
}
void Airplane::Fly() const
{
	std::cout << "Flying the airplane with ID=" << Product::Id() << std::endl;
}
void Airplane::Print() const
{
	std::cout << "A vehicle with ID=" << Product::Id() << " is an airplane with max speed of " << Vehicle::GetMaxSpeed() << " and wignspan " << m_wingspan << std::endl;
}
void Airplane::Move() const
{
	this->Fly();
}