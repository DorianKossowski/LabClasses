#include "Vehicle.h"

Vehicle::Vehicle(const unsigned id): Product::Product(id)
{}
void Vehicle::SetPrice(const unsigned price)
{
	std::cout << price << " is the new cost of the vehicle" << std::endl;
	Product::SetPrice(price);
}
void Vehicle::SetMaxSpeed(const unsigned speed)
{
	m_maxSpeed = speed;
}
void Vehicle::Print() const
{
	std::cout << "This is a vehicle with max speed of " << m_maxSpeed << std::endl;
}
unsigned Vehicle::GetMaxSpeed() const
{
	return m_maxSpeed;
}
void Vehicle::Move() const
{
	std::cout << "Moving with speed " << m_maxSpeed << std::endl;
}


